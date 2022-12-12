#!/bin/bash

BIN_DIR=bin
CHAPTER_PROGRAMS=${BIN_DIR}/c*

for prog in ${CHAPTER_PROGRAMS}; do
    echo "Running $prog"
    ./$prog
done
