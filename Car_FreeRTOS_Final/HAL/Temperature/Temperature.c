#include "Temperature.h"

uint32_t value;

void Temperature_Init(void)
{
    /*Enable the ADC0 Module*/
    Enable_Peripheral_Clock(ADC0_CLOCK_OFFSET);

    ADC_Sequencer_InitTypeDef Temp = { 0U };
    Temp.Sequencer = ADC_SEQUENCER3;
    Temp.Trigger = ADC_PROCESSOR_TRIGGER;
    Temp.Oversampling = ADC_OVERSAMPLING_64X;

    ADC_SequencerInit(ADC0, &Temp);

    ADC_Sequencer_ConfigTypeDef Seq = { 0U };
    Seq.Sequence3_Control = ADC_TEMP_SENSOR | ADC_SAMPLE_INTERRUPT
            | ADC_END_OF_SEQUENCE;
    Seq.Sequencer = ADC_SEQUENCER3;

    ADC_SequencerConfig(ADC0, &Seq);

    ADC_SequencerEnable(ADC0, ADC_SEQUENCER3);

}
uint8_t Temperature_Read(void)
{
    uint8_t TEMP = 0U;
    ADC_StartConversion(ADC0, ADC_SEQUENCER3);

    value = ADC_GetData(ADC0, ADC_SEQUENCER3);

    TEMP = (uint8_t)((1475U - ((75U * (33U) * value) / 4096U)) / 10U);

    return TEMP;
}

