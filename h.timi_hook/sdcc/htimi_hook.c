#include <stdio.h>

#define HTIMI_HOOK              0xfd9f
#define enable_interrupts       __asm__ ("ei")
#define disable_interrupts      __asm__ ("di")
#define preserve_context        __asm__ ("push af")
#define restore_context         __asm__ ("pop af")

#define	SKIP_ROUTINE	__asm  \
             			pop hl \
            			pop af \
            			pop bc \
            			pop de \
             			pop hl \
             			__endasm

int count = 0;


void update()
{
    preserve_context;
    count = count == 999 ? 1 : count + 1;
    printf("counting: %03d\r", count);
    restore_context;
}


void set_hook() __critical {
__asm
    ld hl, #HTIMI_HOOK;
    ld (hl), #0xc3;
    inc hl;
    ld bc, #_update;
    ld (hl), c;
    inc hl;
    ld (hl), b;
__endasm;
}


int main(int argc, char *argv)
{
    argc; argv;
    printf("Setting a H.TIMI hook...\n");
    set_hook();
    while (1); // infinite loop
}
