#!/usr/bin/env bash
set -euo pipefail

CXX=${CXX:-g++}
STD=${STD:-gnu++17}

$CXX -std=$STD -O2 -pipe -Wall -Wextra main.cpp -o main
$CXX -std=$STD -O2 -pipe -Wall -Wextra naive.cpp -o naive

i=0
while true; do
  i=$((i+1))

  python3 generate.py > in.txt

  ./main < in.txt > out_main.txt
  ./naive < in.txt > out_naive.txt

  if ! diff -u out_main.txt out_naive.txt > diff.txt; then
    echo "WA found at test #$i"
    echo "===== input ====="
    cat in.txt
    echo
    echo "===== main output ====="
    cat out_main.txt
    echo
    echo "===== naive output ====="
    cat out_naive.txt
    echo
    echo "===== diff ====="
    cat diff.txt
    exit 1
  fi

  if (( i % 100 == 0 )); then
    echo "$i tests passed"
  fi
done
