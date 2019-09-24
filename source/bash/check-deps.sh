#!/bin/bash
export LD_LIBRARY_PATH=.
export QT_VERSION=5.13.0
export QT_DEBUG_PLUGINS=1

files=($(find . -iname "lib*.so.*"))
for item in ${files[*]}
do
    echo "$item:"
    ldd $item | grep libQt
done
