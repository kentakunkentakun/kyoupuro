#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Usage: $0 2xx" 1>&2
  exit 1
fi

if ! [[ "$1" =~ ^[1-9][0-9]{0,2}$ ]]; then
  echo "Usage: $0 2xx (x=[0-9])" 1>&2
  exit 1
fi

if [ ! -e ARC ]; then
  echo "Error: directory 'ARC' not exists." 1>&2
  exit 1
fi

mkdir -p ARC/$1

cp -n template.cpp ARC/$1/a.cpp
cp -n template.cpp ARC/$1/b.cpp
cp -n template.cpp ARC/$1/c.cpp
cp -n template.cpp ARC/$1/d.cpp
cp -n template.cpp ARC/$1/e.cpp
cp -n template.cpp ARC/$1/f.cpp
cp -n template.cpp ARC/$1/g.cpp
cp -n template.cpp ARC/$1/h.cpp

exit 0
