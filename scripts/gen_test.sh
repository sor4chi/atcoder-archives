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

TESTCASE_DIR="$PROJECT_DIR/$CONTEST_DIR/$1"

if [ -d "$TESTCASE_DIR" ]; then
    echo "The testcase dir is already exist, do you want to delete it? (y/n)"
    read ANSWER
    if [ "$ANSWER" = "y" ]; then
        echo "> y"
        rm -rf "$TESTCASE_DIR"
    else
        echo "> n"
        echo "Testcase generation is canceled"
        exit 1
    fi
fi

mkdir -p "$TESTCASE_DIR"

echo "Testcase dir: $TESTCASE_DIR"

echo "Please input the number of testcases"
read TESTCASE_NUM

for ((i=1; i<=$TESTCASE_NUM; i++))
do
    echo "TESTCASE INPUT: $i"
    INPUT=""
    LINE_COUNT=0
    while read line
    do
        LINE_COUNT=$((LINE_COUNT+1))
        if [ -z "$line" ]; then
            if [ $LINE_COUNT -eq 1 ]; then
                echo "The input is empty, Back to the previous step"
                i=$((i-1))
            fi
            break
        fi
        INPUT="$INPUT$line\n"
    done

    echo "TESTCASE OUTPUT: $i"
    OUTPUT=""
    LINE_COUNT=0
    while read line
    do
        LINE_COUNT=$((LINE_COUNT+1))
        if [ -z "$line" ]; then
            if [ $LINE_COUNT -eq 1 ]; then
                echo "The output is empty, Back to the previous step"
                i=$((i-1))
            fi
            break
        fi
        OUTPUT="$OUTPUT$line\n"
    done

    echo "$INPUT" > "$TESTCASE_DIR/$i.in"
    echo "$OUTPUT" > "$TESTCASE_DIR/$i.out"
done

echo "Testcase generation is completed"


