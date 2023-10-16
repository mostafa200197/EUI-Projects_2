

/**
 * main.c
 */


#include "MCAL/DMA/DMA.h"
#define hello
int main(void)
{

    uint32_t var1[8]={1,2,3,4,5,6,7,8};
    uint32_t var2[8]={0,0,0,0,0,0,0,0};

    uint32_t control=UDMA_DST_INC_32|UDMA_SRC_INC_32|UDMA_ARB_8|UDMA_SIZE_32|UDMA_MODE_AUTO; //UDMA_ARB_8 must be >= number of items

    DMA_init(&var1[7], &var2[7],30); //must send the last array address
    DMA_start_transfere(30, control, 8); //to set control values
    int i=0;
    for(i=0;i<8;i++)
    {
        var1[i]=9;
    }

    DMA_start_transfere(30, control, 8); //restart transmitting after changing the array


	return 0;
}
