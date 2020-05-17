#!/bin/bash
set -x
echo "Testing program against valgrind ."
valgrind --leak-check=full ./part$1 workload.txt

