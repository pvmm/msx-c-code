#!/bin/sh
#zcc +msx -create-app -compiler sccz80 htimi_hook.c -zorg=0xf000 -o htimi_hook.msx
#zcc +msx -compiler sccz80 htimi_hook.c -o htimi_hook.com
zcc +msx -create-app -subtype=disk htimi_hook.c -o htimi_hook
cp htimi_hook.msx dsk/
zcc +msx -create-app -subtype=msxdos htimi_hook.c -o htimi_hook
#cp htimi_hook.com dsk/
