#define STACK_SIZE 0x00000200
__attribute__((section(".stack")))

unsigned long stack;

extern unsigned long __bss_start__;
extern unsigned long __bss_end__;

extern int main(void);
void reset(void);
static void handler(void);

__attribute__((used, section(".vector_table"))) void (*const table[])(void) =
    {
        (void *)(&stack + STACK_SIZE),

        reset,
        handler,
        handler,
        0, 0, 0, 0, 0, 0, 0,
        handler,
        0, 0,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
        handler,
};

static void handler(void)
{
    while (1)
    {
    }
}

void reset(void)
{
    unsigned long *x;

    // zero out bss
    for (x = &__bss_start__; x < &__bss_end__;)
    {
        *(x++) = 0;
    }

    main();
}
