#!/bin/bash
# item_build.sh
# version 1.2

# First parameter ${1} is Path to DB, e.g. /xxx/yyy/db
# Second parameter ${2} is Item Number, e.g. 5

DB_PATH=${1}
ITEM_NUM=${2}

# Checking empty parameter
if [[ -z "${DB_PATH}" ]]; then
  echo "Usage: item_build path_to_db item_number"
  exit
fi

# Checking empty parameter
if [[ -z "${ITEM_NUM}" ]]; then
  echo "Usage: item_build path_to_db item_number"
  exit
fi

# Constants
SEP="/" # Path Separator
SRC_DIR=".src"
FILE_1="item_g.htm"
FILE_2="item_t.htm"
ITEM_PATH=""
SRC_PATH=""

# Building
I=${ITEM_NUM}

  ITEM_PATH="${DB_PATH}${SEP}${I}"
  SRC_PATH="${DB_PATH}${SEP}${I}${SEP}${SRC_DIR}"
  FILE_1_PATH="${SRC_PATH}${SEP}"

  html_item_game ${SRC_PATH} ${SRC_PATH}
  cp "${SRC_PATH}${SEP}${FILE_1}" "${ITEM_PATH}${SEP}${FILE_1}"
  cp "${SRC_PATH}${SEP}${FILE_2}" "${ITEM_PATH}${SEP}${FILE_2}"
