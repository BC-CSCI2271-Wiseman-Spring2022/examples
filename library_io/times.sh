#!/bin/bash

set -x 
set -eo pipefail

rm -rf data sys_buf.times lib_buf.times

dd if=/dev/urandom of=data bs=1M count=100

for x in 1 2 4 8 16 32 64 128; do /usr/bin/time -f "%e" -a -o sys_buf.times ./cat_sys_buf $x < data > /dev/null; done
for x in 1 2 4 8 16 32 64 128; do /usr/bin/time -f "%e" -a -o lib_buf.times ./cat_lib_buf $x < data > /dev/null; done

rm -rf data
