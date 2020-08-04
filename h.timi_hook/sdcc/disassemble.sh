#!/bin/sh
z80dasm -g 0xbff9 -b block.txt -t $1 | less
#z80dasm -g 0xbff9 -t $1 | less
