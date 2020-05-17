#!/bin/bash
set -x

echo "This should run for 9-10 seconds, never with <pid,number> and <pid,number2> , number != number2"
./part$1 easy.txt 

