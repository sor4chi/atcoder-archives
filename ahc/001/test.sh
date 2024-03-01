#!/bin/sh

set -eu

function usage {
cat <<EOM
Usage: $(basename "$0") [OPTION]...
  -h         Display help
  -t VALUE   A target c++ file (eg: a.cpp)
  -i VALUE   A input file (eg: 0000.txt)

Example:
  ./test.sh -t a.cpp -i 0000.txt
EOM

  exit 2
}

TARGET=""
INPUT=""

while getopts ":t:i:h" optKey; do
  case "$optKey" in
    t)
        TARGET=$OPTARG
      ;;
    i)
        INPUT=$OPTARG
      ;;
    '-h'|'--help'|* )
      usage
      ;;
  esac
done

if [ -z "$TARGET" ]; then
  echo "Target file is required"
  usage
fi

if [ -z "$INPUT" ]; then
  echo "Input file is required"
  usage
fi

# g++ a.cpp -o a.out && cd tools && ../a.out < in/0000.txt > out/0000.txt && cargo run --release --bin vis in/0000.txt out/0000.txt
function run {
  rm -f a.out
  g++ $TARGET -o a.out
  cd tools
  ../a.out <in/$INPUT >out/$INPUT
  cargo run --release --bin vis in/$INPUT out/$INPUT
}

run || exit 1
exit 0

