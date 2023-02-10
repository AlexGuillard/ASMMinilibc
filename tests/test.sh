#!/bin/bash

make
gcc main.c -o test -ldl
LD_PRELOAD=./libasm.so  ./test
