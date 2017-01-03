#include <stdint.h>

uint16_t fun(uint8_t a, uint8_t b)
{
    return a * b;
}

int main(void)
{
    while (1)
    {
        fun(0xab, 0xcd);
    }
}
