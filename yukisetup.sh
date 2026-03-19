#!/bin/bash
set -eu

if [ $# -ne 1 ]; then
  echo "Usage: $0 <number>" 1>&2
  exit 1
fi

# 数字のみ（先頭ゼロOKにしたいならこのまま / NGなら ^[1-9][0-9]*$ に）
if ! [[ "$1" =~ ^[0-9]+$ ]]; then
  echo "Error: number must be digits." 1>&2
  exit 1
fi

ROOT="yukicoder"
TEMPLATE="template.cpp"
DST_DIR="${ROOT}"
DST_FILE="${DST_DIR}/${1}.cpp"

if [ ! -f "$TEMPLATE" ]; then
  echo "Error: '$TEMPLATE' not found." 1>&2
  exit 1
fi

mkdir -p "$DST_DIR"

# -n: 既存なら上書きしない
cp -n "$TEMPLATE" "$DST_FILE" || true

echo "OK: ${DST_FILE}"
