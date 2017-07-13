#include "segment.h"

// Mapeamento do microcontrolador
#define SYSCFG 0x03ff0000
#define IOPMOD ((volatile unsigned *)(SYSCFG+0x5000))
#define IOPDATA ((volatile unsigned *)(SYSCFG+0x5008))

static unsigned int numeric_display [16] =
{
    DISP_0, DISP_1, DISP_2, DISP_3, DISP_4, DISP_5, DISP_6, DISP_7, DISP_8, DISP_9,
    DISP_A, DISP_B, DISP_C, DISP_D, DISP_E, DISP_F
};

void init_display() {
    *IOPMOD |= SEG_MASK;
    *IOPDATA |= SEG_MASK;
}

void imprime(unsigned n) {
    if (n <= 0xf) {
        *IOPDATA &= ~SEG_MASK;
        *IOPDATA |= (unsigned) numeric_display[n];
    }
}
