#!/bin/bash
# db_build.sh
# version 1.3

# First parameter ${1} is Path to DB, e.g. /xxx/yyy/db
# Second parameter ${2} is First Item Number, e.g. 1
# Third parameter ${3} is Last Item Number, e.g. 22

DB_PATH=${1}
I_FIRST=${2}
I_LAST=${3}

# Checking empty parameter
if [[ -z "${DB_PATH}" ]]; then
  echo "Error: Empty Path to DB."
  echo "Usage: db_build path_to_db item_first item_last\r\n"
  echo "Example: db_build /www/db 1 3"
  exit
fi

# Checking empty parameter
if [[ -z "${I_FIRST}" ]]; then
  echo "Error: Empty First Item Number."
  echo "Usage: db_build path_to_db item_first item_last\r\n"
  echo "Example: db_build /www/db 1 3"
  exit
fi

# Checking empty parameter
if [[ -z "${I_LAST}" ]]; then
  echo "Error: Empty Last Item Number."
  echo "Usage: db_build path_to_db item_first item_last\r\n"
  echo "Example: db_build /www/db 1 3"
  exit
fi

# Checking parameter
if (( ${I_FIRST} <= 0 )); then
  echo "Error: Item Number must be positive (>0)!"
  exit
fi

# Checking parameter
if (( ${I_LAST} <= 0 )); then
  echo "Error: Item Number must be positive (>0)!"
  exit
fi

# Checking parameter
if (( ${I_FIRST} > ${I_LAST} )); then
  echo "Error: First Item Number must be smaller than Second Item Number!"
  exit
fi



# Constants
SEP="/" # Path Separator
SRC_DIR=".src"
FILE_1="item_g.htm"
FILE_2="item_t.htm"

ITEM_PATH=""
SRC_PATH=""
I=0

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