#!/bin/bash

PROJECT_DIR=$(cd $(dirname $0)/..; pwd)

if [ -z "$1" ]; then
    echo "Please input the contest dir name"
    exit 1
fi

CONTEST_DIR=$1
if [ ! -d "$PROJECT_DIR/$CONTEST_DIR" ]; then
    echo "The contest dir is not exist"
    echo "Input path: $PROJECT_DIR/$CONTEST_DIR"
    exit 1
fi

echo $CONTEST_DIR > $PROJECT_DIR/.contest

