#!/bin/bash

# specify the directory path
directory="test_maps"

make bonus && make clean
# loop through each file in the directory
for file in "$directory"/*
do
    # check if the file is a regular file
    if [ -f "$file" ]
    then
        # pass the file as an argument to the command
		echo "$file"
        ./FdF_BONUS "$file"
    fi
done
