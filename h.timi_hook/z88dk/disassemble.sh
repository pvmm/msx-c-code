#!/bin/sh
#z80dasm timi_hook.com -t | less
z80dasm -g 0x9c39 -b block.txt -t $1 | less
