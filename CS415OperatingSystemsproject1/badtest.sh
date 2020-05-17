#!/bin/bash
set -x

echo "Testing Script"

echo "This should exit, bad args."
./part$1 b.txt berr

echo "This should exit, bad file."
./part$1 badfile.txt


