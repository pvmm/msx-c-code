#!/bin/env python3
"Write MSX-BASIC's binary file header"

import sys

CODE_ADDR = 0xC000
EXEC_ADDR = 0xC000

with open(sys.argv[1], 'rb') as inp:
    contents = inp.read()
    size = CODE_ADDR + len(contents)
    size_msb, size_lsb = (size >> 8) & 0xff, size & 0xff
    with open(sys.argv[2], 'wb') as out:
        out.write(b'\xfe')
        out.write(b''.fromhex(hex(CODE_ADDR & 0xff)[2:].rjust(2, '0')))
        out.write(b''.fromhex(hex(CODE_ADDR >> 8)[2:].rjust(2, '0')))
        out.write(b''.fromhex(hex(size_lsb)[2:].rjust(2, '0')))
        out.write(b''.fromhex(hex(size_msb)[2:].rjust(2, '0')))
        out.write(b''.fromhex(hex(EXEC_ADDR & 0xff)[2:].rjust(2, '0')))
        out.write(b''.fromhex(hex(EXEC_ADDR >> 8)[2:].rjust(2, '0')))
        out.write(contents)
