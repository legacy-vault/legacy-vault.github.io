#!/bin/bash
# hash_create.sh
# version 1.2

#cd /folder_to_be_checked
PATH_OUT=/tmp/x

#Creating Hash Sums
find . -type f -print0 | xargs -0 rhash --percents --aich -p"%a %p\n" > ${PATH_OUT}/aich.txt
find . -type f -print0 | xargs -0 rhash --percents --btih -p"%{btih} %p\n" > ${PATH_OUT}/btih.txt
find . -type f -print0 | xargs -0 rhash --percents --crc32 -p"%c %p\n" > ${PATH_OUT}/crc32.txt
find . -type f -print0 | xargs -0 rhash --percents --ed2k -p"%e %p\n" > ${PATH_OUT}/ed2k.txt
find . -type f -print0 | xargs -0 rhash --percents --edonr256 -p"%{edon-r256} %p\n" > ${PATH_OUT}/edonr256.txt
find . -type f -print0 | xargs -0 rhash --percents --edonr512 -p"%{edon-r512} %p\n" > ${PATH_OUT}/edonr512.txt
find . -type f -print0 | xargs -0 rhash --percents --gost -p"%g %p\n" > ${PATH_OUT}/gost.txt
find . -type f -print0 | xargs -0 rhash --percents --gost-cryptopro -p"%{gost-cryptopro} %p\n" > ${PATH_OUT}/gost-cryptopro.txt
find . -type f -print0 | xargs -0 rhash --percents --has160 -p"%{has160} %p\n" > ${PATH_OUT}/has160.txt
find . -type f -print0 | xargs -0 rhash --percents --md4 -p"%{md4} %p\n" > ${PATH_OUT}/md4.txt
find . -type f -print0 | xargs -0 rhash --percents --md5 -p"%m %p\n" > ${PATH_OUT}/md5.txt
find . -type f -print0 | xargs -0 rhash --percents --ripemd160 -p"%r %p\n" > ${PATH_OUT}/ripemd160.txt
find . -type f -print0 | xargs -0 rhash --percents --sha1 -p"%h %p\n" > ${PATH_OUT}/sha1.txt
find . -type f -print0 | xargs -0 rhash --percents --sha256 -p"%{sha-256} %p\n" > ${PATH_OUT}/sha256.txt
find . -type f -print0 | xargs -0 rhash --percents --sha384 -p"%{sha-384} %p\n" > ${PATH_OUT}/sha384.txt
find . -type f -print0 | xargs -0 rhash --percents --sha512 -p"%{sha-512} %p\n" > ${PATH_OUT}/sha512.txt
find . -type f -print0 | xargs -0 rhash --percents --sha3-224 -p"%{sha3-224} %p\n" > ${PATH_OUT}/sha3-224.txt
find . -type f -print0 | xargs -0 rhash --percents --sha3-256 -p"%{sha3-256} %p\n" > ${PATH_OUT}/sha3-256.txt
find . -type f -print0 | xargs -0 rhash --percents --sha3-384 -p"%{sha3-384} %p\n" > ${PATH_OUT}/sha3-384.txt
find . -type f -print0 | xargs -0 rhash --percents --sha3-512 -p"%{sha3-512} %p\n" > ${PATH_OUT}/sha3-512.txt
find . -type f -print0 | xargs -0 rhash --percents --snefru128 -p"%{snefru128} %p\n" > ${PATH_OUT}/snefru128.txt
find . -type f -print0 | xargs -0 rhash --percents --snefru256 -p"%{snefru256} %p\n" > ${PATH_OUT}/snefru256.txt
find . -type f -print0 | xargs -0 rhash --percents --tiger -p"%{tiger} %p\n" > ${PATH_OUT}/tiger.txt
find . -type f -print0 | xargs -0 rhash --percents --tth -p"%t %p\n" > ${PATH_OUT}/tth.txt
find . -type f -print0 | xargs -0 rhash --percents --whirlpool -p"%w %p\n" > ${PATH_OUT}/whirlpool.txt

#Creating Attributes
find . -type f -print0 | xargs -0 rhash -p"%{mtime} %s %p\n" > ${PATH_OUT}/attrib.txt