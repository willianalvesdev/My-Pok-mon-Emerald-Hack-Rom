"""Refresh the read-only Encontros do mapa action in Porymap."""

import json
import re
from collections import defaultdict
from pathlib import Path


ROOT = Path(__file__).resolve().parents[2]
METHODS = {
    "land_mons": "Grama / solo",
    "water_mons": "Surf / água",
    "rock_smash_mons": "Rock Smash",
    "old_rod": "Old Rod",
    "good_rod": "Good Rod",
    "super_rod": "Super Rod",
}
EXTRA_METHODS = {
    "WILD_AREA_LAND": "land_mons",
    "WILD_AREA_WATER": "water_mons",
    "WILD_AREA_ROCKS": "rock_smash_mons",
}

SCRIPT = """
let currentMap = "";

export function onProjectOpened() {
    utility.registerAction("showMapEncounters", "Encontros do mapa");
}

export function onMapOpened(mapName) {
    currentMap = mapName;
}

export function showMapEncounters() {
    const title = currentMap ? "Encontros de " + currentMap : "Encontros do mapa";
    const methods = encounters[currentMap];
    if (!methods) {
        utility.showMessage(title, "Nenhum encontro selvagem listado para este mapa.");
        return;
    }

    const selection = utility.getInputItem(title, "Método de encontro", Object.keys(methods), 0, false);
    if (selection.ok) {
        utility.showMessage(title + " • " + selection.input, methods[selection.input].join("\\n"));
    }
}
"""


def read_json(path):
    return json.loads(path.read_text(encoding="utf-8-sig"))


def read_extras(path):
    source = path.read_text(encoding="utf-8-sig")
    tables = {}
    for name, body in re.findall(r"static const struct ExtraWildEncounter (\w+)\[\]\s*=\s*\{(.*?)\};", source, re.S):
        table = defaultdict(list)
        rows = re.findall(r"\{\s*\{\s*(\d+),\s*(\d+),\s*(SPECIES_\w+)\s*\},\s*(WILD_AREA_\w+),\s*(\w+),\s*(\d+)\s*\}", body)
        if len(rows) != body.count("SPECIES_"):
            raise ValueError(f"Entrada de encontro inválida em {name}")
        for low, high, species, area, rod, chance in rows:
            method = rod.lower() if area == "WILD_AREA_FISHING" else EXTRA_METHODS[area]
            table[method].append((species, int(low), int(high), int(chance)))
        tables[name] = table
    refs = re.findall(r"\{\s*(MAP_\w+),\s*ARRAY_COUNT\((\w+)\),\s*\2\s*\}", source)
    if not refs or len({table for _, table in refs}) != len(tables):
        raise ValueError("As tabelas de encontros extras não correspondem aos mapas.")
    return {map_id: tables[table] for map_id, table in refs}


def describe_slots(mons, rates, indexes, extra_slots):
    chances = defaultdict(float)
    remaining = 10_000
    for species, low, high, chance in extra_slots:
        used = min(chance, remaining)
        chances[species, low, high] += used
        remaining -= used
    # O jogo só sorteia os slots originais se nenhum dos extras for escolhido.
    total = sum(rates[i] for i in indexes)
    for i in indexes:
        mon = mons[i]
        chances[mon["species"], mon["min_level"], mon["max_level"]] += remaining * rates[i] / total

    lines = []
    for (species, low, high), chance in sorted(chances.items(), key=lambda row: (-row[1], row[0])):
        if chance:
            name = species.removeprefix("SPECIES_").replace("_", " ").title()
            level = str(low) if low == high else f"{low}–{high}"
            percent = f"{chance / 100:g}".replace(".", ",")
            lines.append(f"{name} · Nv. {level} · {percent}%")
    return lines


def main():
    source = read_json(ROOT / "src/data/wild_encounters.json")
    group = next(group for group in source["wild_encounter_groups"] if group["label"] == "gWildMonHeaders")
    extras = read_extras(ROOT / "src/data/extra_wild_encounters.h")
    maps = {data["id"]: data["name"] for path in (ROOT / "data/maps").glob("*/map.json") if (data := read_json(path))}
    encounters = defaultdict(dict)
    used_extras = set()
    for table in group["encounters"]:
        if "FireRed" in table["base_label"] or "LeafGreen" in table["base_label"]:
            continue
        map_id = table["map"]
        methods = encounters[maps[map_id]]
        for field in group["fields"]:
            key = field["type"]
            if key not in table:
                continue
            rates = field["encounter_rates"]
            mons = table[key]["mons"]
            for method, indexes in field.get("groups", {key: range(len(rates))}).items():
                label = METHODS[method]
                if map_id == "MAP_ALTERING_CAVE":
                    label += f" (grupo {table['base_label'].removeprefix('gAlteringCave')})"
                extra_slots = extras.get(map_id, {}).get(method, [])
                if extra_slots:
                    used_extras.add((map_id, method))
                methods[label] = describe_slots(mons, rates, indexes, extra_slots)
    absent = {(map_id, method) for map_id, area in extras.items() for method in area} - used_extras
    if absent:
        raise ValueError(f"Encontros extras sem tabela base na ROM: {sorted(absent)}")

    # Os tiles de Feebas são testados antes do sorteio normal de pesca.
    wild_source = (ROOT / "src/wild_encounter.c").read_text(encoding="utf-8-sig")
    spots = re.search(r"#define NUM_FEEBAS_SPOTS\s+(\d+)", wild_source)[1]
    low, high = re.search(r"gWildFeebas\s*=\s*\{\s*(\d+),\s*(\d+)", wild_source).groups()
    encounters["Route119"]["Feebas (pesca em tiles especiais)"] = [
        f"Feebas · Nv. {low}–{high} · 100% nos tiles especiais",
        f"O jogo sorteia {spots} posições de pesca para Feebas.",
    ]

    output = Path(__file__).with_name("encontros.js")
    entries = ",\n".join(
        f"    {json.dumps(map_name)}: {json.dumps(methods, ensure_ascii=False)}"
        for map_name, methods in sorted(encounters.items())
    )
    output.write_text(
        "// Gerado por generate_encounters.py a partir das tabelas da ROM.\n"
        f"const encounters = {{\n{entries}\n}};\n" + SCRIPT,
        encoding="utf-8",
        newline="\n",
    )
    print(f"{output} atualizado com {len(encounters)} mapas.")


if __name__ == "__main__":
    main()
