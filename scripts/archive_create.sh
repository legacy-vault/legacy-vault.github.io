#!/bin/bash
# archive_create.sh
# version 1.2

# First Parameter ( ${1} ) is a Folder that will be archived
# Do NOT use this script with Files! Only for Folders!
#PATH_OUT=/tmp/x

#TAR // TAR is Base for many Archives, as they can compress only single File.
tar -c --format=posix -W -f ${1}.tar ${1}

#7-ZIP
7z a -mhc=off -mmt=2 -mx1 ${1}.7z ${1} > /dev/null

#ARJ
arj a -r -m4 -hk9 ${1}.arj ${1} > /dev/null

#BZIP2 // Requires TAR!
cat ${1}.tar | bzip2 -1 > ${1}.tar.bz2

#CAB
lcab -r ${1} ${1}.cab > /dev/null

#GZIP // Requires TAR!
cat ${1}.tar | gzip -1 > ${1}.tar.gz

#LHZ
jlha aqo5 ${1}.lhz ${1}

#LZIP // Requires TAR!
lzip --member-size=100kB --keep --match-length=273 ${1}.tar

#LZO // Requires TAR!
cat ${1}.tar | lzop -q -1 -o ${1}.tar.lzo

#RAR
rar a -t -inul -m1 ${1}.rar ${1}

#XZ // Requires TAR!
cat ${1}.tar | xz -zf --format=xz --check=crc64 -1 > ${1}.tar.xz

#ZIP
zip -qr1 ${1}.zip ${1}

# Some Tests
#Creating Archives with various custom Settings
#mkdir -p var
#7-ZIP
#echo 'Creating custom Archives: 7-ZIP'
#mkdir -p var/7z
#7z a -mhc=off -mmt=2 -mx0 var/7z/cl0.${1}.7z ${1} > /dev/null
#7z a -mhc=off -mmt=2 -mx1 var/7z/cl1.${1}.7z ${1} > /dev/null
#7z a -mhc=off -mmt=2 -mx3 var/7z/cl3.${1}.7z ${1} > /dev/null
#7z a -mhc=off -mmt=2 -mx5 var/7z/cl5.${1}.7z ${1} > /dev/null
#7z a -mhc=off -mmt=2 -mx7 var/7z/cl7.${1}.7z ${1} > /dev/null
#7z a -mhc=off -mmt=2 -mx9 var/7z/cl9.${1}.7z ${1} > /dev/null
#ARJ
#echo 'Creating custom Archives: ARJ'
#mkdir -p var/arj
#arj a -r -m4 -hk1 var/arj/m4_hk1.${1}.arj ${1} > /dev/null
#arj a -r -m4 -hk2 var/arj/m4_hk2.${1}.arj ${1} > /dev/null
#arj a -r -m4 -hk3 var/arj/m4_hk3.${1}.arj ${1} > /dev/null
#arj a -r -m4 -hk4 var/arj/m4_hk4.${1}.arj ${1} > /dev/null
#arj a -r -m4 -hk5 var/arj/m4_hk5.${1}.arj ${1} > /dev/null
#arj a -r -m4 -hk6 var/arj/m4_hk6.${1}.arj ${1} > /dev/null
#arj a -r -m4 -hk7 var/arj/m4_hk7.${1}.arj ${1} > /dev/null
#arj a -r -m4 -hk8 var/arj/m4_hk8.${1}.arj ${1} > /dev/null
#arj a -r -m4 -hk9 var/arj/m4_hk9.${1}.arj ${1} > /dev/null
#BZIP2
#echo 'Creating custom Archives: BZIP2'
#mkdir -p var/bzip2
#cat ${1}.tar | bzip2 -1 > var/bzip2/cl1.${1}.tar.bz2
#cat ${1}.tar | bzip2 -2 > var/bzip2/cl2.${1}.tar.bz2
#cat ${1}.tar | bzip2 -3 > var/bzip2/cl3.${1}.tar.bz2
#cat ${1}.tar | bzip2 -4 > var/bzip2/cl4.${1}.tar.bz2
#cat ${1}.tar | bzip2 -5 > var/bzip2/cl5.${1}.tar.bz2
#cat ${1}.tar | bzip2 -6 > var/bzip2/cl6.${1}.tar.bz2
#cat ${1}.tar | bzip2 -7 > var/bzip2/cl7.${1}.tar.bz2
#cat ${1}.tar | bzip2 -8 > var/bzip2/cl8.${1}.tar.bz2
#cat ${1}.tar | bzip2 -9 > var/bzip2/cl9.${1}.tar.bz2
#GZIP
#echo 'Creating custom Archives: GZIP'
#mkdir -p var/gzip
#cat ${1}.tar | gzip -1 > var/gzip/cl1.${1}.tar.gz
#cat ${1}.tar | gzip -2 > var/gzip/cl2.${1}.tar.gz
#cat ${1}.tar | gzip -3 > var/gzip/cl3.${1}.tar.gz
#cat ${1}.tar | gzip -4 > var/gzip/cl4.${1}.tar.gz
#cat ${1}.tar | gzip -5 > var/gzip/cl5.${1}.tar.gz
#cat ${1}.tar | gzip -6 > var/gzip/cl6.${1}.tar.gz
#cat ${1}.tar | gzip -7 > var/gzip/cl7.${1}.tar.gz
#cat ${1}.tar | gzip -8 > var/gzip/cl8.${1}.tar.gz
#cat ${1}.tar | gzip -9 > var/gzip/cl9.${1}.tar.gz
#LHZ
#echo 'Creating custom Archives: LHZ'
#mkdir -p var/lhz
#jlha aqo5 var/lhz/o5.${1}.lhz ${1}
#jlha aqo6 var/lhz/o6.${1}.lhz ${1}
#jlha aqo7 var/lhz/o7.${1}.lhz ${1}
#LZO
#echo 'Creating custom Archives: LZO'
#mkdir -p var/lzo
#LZO with ADLER32 Corection Check
#cat ${1}.tar | lzop -q -1 -o var/lzo/adler32_cl1.${1}.tar.lzo
#cat ${1}.tar | lzop -q -3 -o var/lzo/adler32_cl3.${1}.tar.lzo
#cat ${1}.tar | lzop -q -7 -o var/lzo/adler32_cl7.${1}.tar.lzo
#cat ${1}.tar | lzop -q -8 -o var/lzo/adler32_cl8.${1}.tar.lzo
#cat ${1}.tar | lzop -q -9 -o var/lzo/adler32_cl9.${1}.tar.lzo
#LZO with CRC32 Corection Check
#cat ${1}.tar | lzop -q --crc32 -1 -o var/lzo/crc32_cl1.${1}.tar.lzo
#cat ${1}.tar | lzop -q --crc32 -3 -o var/lzo/crc32_cl3.${1}.tar.lzo
#cat ${1}.tar | lzop -q --crc32 -7 -o var/lzo/crc32_cl7.${1}.tar.lzo
#cat ${1}.tar | lzop -q --crc32 -8 -o var/lzo/crc32_cl8.${1}.tar.lzo
#cat ${1}.tar | lzop -q --crc32 -9 -o var/lzo/crc32_cl9.${1}.tar.lzo
#RAR
#echo 'Creating custom Archives: RAR'
#mkdir -p var/rar
#rar a -t -inul -m0 var/rar/cl0.${1}.rar ${1}
#rar a -t -inul -m1 var/rar/cl1.${1}.rar ${1}
#rar a -t -inul -m1 var/rar/cl1.${1}.rar ${1}
#rar a -t -inul -m2 var/rar/cl2.${1}.rar ${1}
#rar a -t -inul -m3 var/rar/cl3.${1}.rar ${1}
#rar a -t -inul -m4 var/rar/cl4.${1}.rar ${1}
#rar a -t -inul -m5 var/rar/cl5.${1}.rar ${1}
#XZ
#echo 'Creating custom Archives: XZ'
#mkdir -p var/xz
#XZ with CRC64 Corection Check
#cat ${1}.tar | xz -zf --format=xz --check=crc64 -1 > var/xz/crc64_cl1.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=crc64 -2 > var/xz/crc64_cl2.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=crc64 -3 > var/xz/crc64_cl3.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=crc64 -4 > var/xz/crc64_cl4.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=crc64 -5 > var/xz/crc64_cl5.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=crc64 -6 > var/xz/crc64_cl6.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=crc64 -7 > var/xz/crc64_cl7.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=crc64 -8 > var/xz/crc64_cl8.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=crc64 -9 > var/xz/crc64_cl9.${1}.tar.xz
#XZ with SHA256 Corection Check
#cat ${1}.tar | xz -zf --format=xz --check=sha256 -1 > var/xz/sha256_cl1.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=sha256 -2 > var/xz/sha256_cl2.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=sha256 -3 > var/xz/sha256_cl3.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=sha256 -4 > var/xz/sha256_cl4.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=sha256 -5 > var/xz/sha256_cl5.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=sha256 -6 > var/xz/sha256_cl6.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=sha256 -7 > var/xz/sha256_cl7.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=sha256 -8 > var/xz/sha256_cl8.${1}.tar.xz
#cat ${1}.tar | xz -zf --format=xz --check=sha256 -9 > var/xz/sha256_cl9.${1}.tar.xz
#ZIP
#echo 'Creating custom Archives: ZIP'
#mkdir -p var/zip
#zip -qr0 var/zip/cl0.${1}.zip ${1}
#zip -qr1 var/zip/cl1.${1}.zip ${1}
#zip -qr2 var/zip/cl2.${1}.zip ${1}
#zip -qr3 var/zip/cl3.${1}.zip ${1}
#zip -qr4 var/zip/cl4.${1}.zip ${1}
#zip -qr5 var/zip/cl5.${1}.zip ${1}
#zip -qr6 var/zip/cl6.${1}.zip ${1}
#zip -qr7 var/zip/cl7.${1}.zip ${1}
#zip -qr8 var/zip/cl8.${1}.zip ${1}
#zip -qr9 var/zip/cl9.${1}.zip ${1}
#END
#echo 'Creation finished!'
