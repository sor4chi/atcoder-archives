#!/bin/bash

ESC=$(printf '\033')

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

g++ -std=c++17 -o $OUTPUT_FILE_PATH $CPP_FILE_PATH

TESTCASE_COUNT=0
SUCCESS_COUNT=0
for TESTCASE_PATH in "$TESTCASE_DIR"/*.in
do
    TESTCASE_COUNT=$((TESTCASE_COUNT + 1))
    INPUT=$(cat $TESTCASE_PATH)
    OUTPUT=$(cat ${TESTCASE_PATH%.in}.out)

    echo "Testcase: ${TESTCASE_PATH%.in}"

    echo "Input: $INPUT"
    echo "Output: $OUTPUT"
    echo "Result: $(echo $INPUT | $OUTPUT_FILE_PATH)"
    if [ "$OUTPUT" = "$(echo $INPUT | $OUTPUT_FILE_PATH)" ]; then
        SUCCESS_COUNT=$((SUCCESS_COUNT + 1))
        echo "${ESC}[32m SUCCESS${ESC}[m"
    else
        echo "${ESC}[31m FAILED${ESC}[m"
    fi
    INPUT=""
    OUTPUT=""
done

echo "-----------------"

if [ "$TESTCASE_COUNT" = "$SUCCESS_COUNT" ]; then
    echo "${ESC}[32m ALL SUCCESS${ESC}[m"
else
    if [ "$SUCCESS_COUNT" = "0" ]; then
        echo "${ESC}[31m ALL FAILED${ESC}[m"
    else
        echo "${ESC}[32m Success: $SUCCESS_COUNT/$TESTCASE_COUNT ${ESC}[m"
        echo "${ESC}[31m Failed: $((TESTCASE_COUNT - SUCCESS_COUNT))/$TESTCASE_COUNT ${ESC}[m"
    fi
fi

rm $OUTPUT_FILE_PATH
