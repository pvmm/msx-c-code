#include <stdio.h>


#define HTIMI_HOOK              0xfd9f
#define enable_interrupts       asm("ei")
#define disable_interrupts      asm("di")
#define preserve_context        asm("push af")
#define restore_context         asm("pop af")


int count = 0;


void update()
{
    // Update game elements
    preserve_context;
    count = count == 999 ? 1 : count + 1;
    printf("counting: %03d\r", count);
    restore_context;
}


void set_hook(void) {
    disable_interrupts;
#asm
    ld hl, HTIMI_HOOK;
    ld (hl), 0xc3;
    inc hl;
    ld bc, _update;
    ld (hl), c;
    inc hl;
    ld (hl), b;
#endasm
    enable_interrupts;
}


int main(int argc, char *argv)
{
    argc; argv;
    printf("Setting a H.TIMI hook...\n");
    set_hook();
    while (1); // infinite loop
    return 0;
}
