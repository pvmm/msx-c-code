#!/bin/sh
sdcc -mz80 htimi_hook.c -o htimi_hook.hex
hex2bin -s 0xc000 -l 0xffff -e com -b htimi_hook.hex
#Tools/Dsk2Rom/source/dsk2rom htimi_hook.com htimi_hook.rom
#appmake +msx --org 0xf000 -b htimi_hook.com -o htimi_hook.msx
