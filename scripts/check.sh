#!/bin/bash

PROJECT_DIR=$(cd $(dirname $0)/..; pwd)
if [ ! -f "$PROJECT_DIR/.contest" ]; then
    echo "Please set the contest dir"
    echo "$ sh scripts/set.sh <contest dir name>"
    exit 1
fi

CONTEST_DIR=$(cat "$PROJECT_DIR"/.contest)
echo "Contest dir: $CONTEST_DIR"

if [ ! -d "$PROJECT_DIR/$CONTEST_DIR" ]; then
    echo "The contest dir is not exist"
    echo "Input path: $PROJECT_DIR/$CONTEST_DIR"
    exit 1
fi

if [ -z "$1" ]; then
    echo "Please input the problem name"
    echo "Example: $ sh scripts/check.sh a"
    exit 1
fi

CPP_FILE_PATH="$PROJECT_DIR/$CONTEST_DIR/$1.cpp"
OUTPUT_FILE_PATH="$PROJECT_DIR/$CONTEST_DIR/$1.out"
TESTCASE_DIR="$PROJECT_DIR/$CONTEST_DIR/$1"

if [ ! -f "$CPP_FILE_PATH" ]; then
    echo "The cpp file is not exist"
    echo "Input path: $CPP_FILE_PATH"
    exit 1
fi
if [ ! -d "$TESTCASE_DIR" ]; then
    echo "The testcase dir is not exist"
    echo "Input path: $TESTCASE_DIR"
    exit 1
fi

g++ -o $OUTPUT_FILE_PATH $CPP_FILE_PATH

for TESTCASE_PATH in "$TESTCASE_DIR"/*
do
    echo ""
    echo "CASE: $(basename $TESTCASE_PATH)"
    FLAG=0
    while IFS= read -r line
    do
        if [ "$line" = "---" ]; then
            FLAG=1
            continue
        fi
        if [ $FLAG -eq 0 ]; then
            INPUT="$INPUT$line"
        else
            OUTPUT="$OUTPUT$line"
        fi
    done < "$TESTCASE_PATH"
    echo "Input: $INPUT"
    echo "Output: $OUTPUT"
    echo "Result: $(echo $INPUT | $OUTPUT_FILE_PATH)"
    if [ "$OUTPUT" = "$(echo $INPUT | $OUTPUT_FILE_PATH)" ]; then
        echo "\e[32m SUCCESS\e[m\n"
    else
        echo "\e[31m FAILED\e[m"
    fi
    INPUT=""
    OUTPUT=""
done

rm $OUTPUT_FILE_PATH
