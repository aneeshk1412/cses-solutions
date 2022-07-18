#!/bin/sh

rm -f $(ls | grep -ve "\.cpp\|\.sh\|\.c\|\.cc\|\.py")
touch input.txt output.txt