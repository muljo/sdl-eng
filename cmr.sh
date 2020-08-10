#!/bin/bash
# clears the terminal, runs make and runs run.exe if make returns 0
clear
make
make_exit=$?
if [ $make_exit -eq 0 ]; then 
	./run.exe
fi
