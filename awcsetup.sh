#!/bin/bash

if [ $# -ne 1 ]; then
  echo "Usage: $0 2xx" 1>&2
  exit 1
fi

if ! [[ "$1" =~ ^[1-9][0-9]{0,3}$ ]]; then
  echo "Usage: $0 2xx (x=[0-9])" 1>&2
  exit 1
fi

if [ ! -e AWC ]; then
  echo "Error: directory 'AWC' not exists." 1>&2
  exit 1
fi

mkdir -p AWC/$1

cp -n template.cpp AWC/$1/a.cpp
cp -n template.cpp AWC/$1/b.cpp
cp -n template.cpp AWC/$1/c.cpp
cp -n template.cpp AWC/$1/d.cpp
cp -n template.cpp AWC/$1/e.cpp

exit 0
