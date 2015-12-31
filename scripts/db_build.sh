#!/bin/bash
# db_build.sh
# version 1.2

# First parameter ${1} is Path to DB, e.g. /xxx/yyy/db

ITEM_COUNT=22
DB_PATH=${1}

# Checking empty parameter
if [[ -z "${DB_PATH}" ]]; then
  echo "Usage: db_build path_to_db"
  exit
fi

# Constants
SEP="/" # Path Separator
SRC_DIR=".src"
FILE_1="item_g.htm"
FILE_2="item_t.htm"
I_FIRST=1
I_LAST=${ITEM_COUNT}
ITEM_PATH=""
SRC_PATH=""

# Building
for (( I=I_FIRST; I<=I_LAST; I++ ))
do
  ITEM_PATH="${DB_PATH}${SEP}${I}"
  SRC_PATH="${DB_PATH}${SEP}${I}${SEP}${SRC_DIR}"
  FILE_1_PATH="${SRC_PATH}${SEP}"

  html_item_game ${SRC_PATH} ${SRC_PATH}
  cp "${SRC_PATH}${SEP}${FILE_1}" "${ITEM_PATH}${SEP}${FILE_1}"
  cp "${SRC_PATH}${SEP}${FILE_2}" "${ITEM_PATH}${SEP}${FILE_2}"
done