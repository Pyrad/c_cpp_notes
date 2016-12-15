#!/bin/sh -

if [ $# -ne 1 ]; then
    echo "Should give ONE issue name to create file & dir"
    return
fi

DIR=$1
# i=0
for dir in $(ls .)
do
    # i=$(($i + 1))
    [ -d $dir ] && [ "$DIR" = "$dir" ] && echo "Duplicated dir name $DIR, please specify another one" && return
done

FILE_TEMPLATE="cpp_source_template.cpp"
mkdir $DIR && [ -f "./$FILE_TEMPLATE" ] && cp -rf "./$FILE_TEMPLATE" "./$DIR/${DIR}.cpp"
