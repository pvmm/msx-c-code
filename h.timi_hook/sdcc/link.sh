#!/bin/sh

sdasz80 -plogs htimi_hook.asm
#sdasz80 -o htimi_hook2 htimi_hook.asm
#sdld -i htimi_hook.ihx htimi_hook.rel fusion-c/include/printf.rel --code-loc=0xC000
sdld -i htimi_hook.ihx htimi_hook.rel fusion-c/include/printf.rel -l fusion-c/lib/fusion.lib #fusion-c/include/putchar.rel 

hex2bin -e msx -b htimi_hook.ihx
