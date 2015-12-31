#!/bin/bash
# md5_create.sh
# version 1.2

#cd /folder_to_be_checked
PATH_OUT=/tmp/x

#Creating Hash Sums
find . -type f -print0 | xargs -0 rhash --percents --md5 -p"%m %p\n" > ${PATH_OUT}/md5.txt

#Creating Attributes
find . -type f -print0 | xargs -0 rhash -p"%{mtime} %s %p\n" > ${PATH_OUT}/attrib.txt