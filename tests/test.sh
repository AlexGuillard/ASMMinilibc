#!/bin/bash

make re
gcc tests/main.c tests/fonction.c -o test_main -ldl
LD_PRELOAD=./libasm.so  ./test_main
