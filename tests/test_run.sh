#!/bin/bash

make re
gcc tests/tests_memcpy.c -o test_tu -ldl -lcriterion --coverage
LD_PRELOAD=./libasm.so  ./test_tu
