#!/usr/bin/env bash
set -euo pipefail

project_dir="$PWD"
build_dir=/var/tmp/pokeemerald-cassino.kHxlLi

mkdir -p "$build_dir"
rsync -rc \
    --exclude=.git/ \
    --exclude=build/ \
    --exclude='*.gba' \
    --exclude='*.elf' \
    --exclude=pokeemerald.map \
    --exclude='*.sav' \
    --exclude='*.ss[0-9]' \
    ./ "$build_dir/"

cd "$build_dir"
touch .histignore
make -j"$(nproc)"
cp pokeemerald.gba "$project_dir/pokeemerald.gba"
cmp pokeemerald.gba "$project_dir/pokeemerald.gba"
