#!/bin/bash

# Compile the FdF program
gcc *.c get_next_line/*.c -I./includes -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# Run the FdF program with the provided argument and redirect output to log.txt
./a.out "$1"
