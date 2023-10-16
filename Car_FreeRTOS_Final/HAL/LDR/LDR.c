#include "LDR.h"

void LDR_Init(void)
{
    GPIO_InitTypeDef LDR_Sensor = { 0U };

    /*Enable the ADC0 Module*/
    Enable_Peripheral_Clock(ADC0_CLOCK_OFFSET);
    Enable_Peripheral_Clock(GPIOE_CLOCK_OFFSET);

    LDR_Sensor.Analog = On;
    LDR_Sensor.Pin = PE1 | PE2;

    /*Enable PORTE and Set PE2 as analog input*/
    GPIO_Init(GPIOE, &LDR_Sensor);

    ADC_Sequencer_InitTypeDef LDR = { 0U };
    LDR.Sequencer = ADC_SEQUENCER1;
    LDR.Trigger = ADC_PROCESSOR_TRIGGER;
    LDR.Oversampling = ADC_OVERSAMPLING_64X;

    ADC_SequencerInit(ADC0, &LDR);

    ADC_Sequencer_ConfigTypeDef Seq = { 0U };
    Seq.Sequence1_Control[1] = ADC_SAMPLE_INTERRUPT | ADC_END_OF_SEQUENCE;
    Seq.Sequence1[0] = ADC_AIN2;
    Seq.Sequence1[1] = ADC_AIN1;
    Seq.Sequencer = ADC_SEQUENCER1;

    ADC_SequencerConfig(ADC0, &Seq);

    ADC_SequencerEnable(ADC0, ADC_SEQUENCER1);
}

void LDR_Read(uint32_t *arr)
{
    ADC_StartConversion(ADC0, ADC_SEQUENCER1);

    arr[0] = ADC_GetData(ADC0, ADC_SEQUENCER1);
    arr[1] = ADC_GetData(ADC0, ADC_SEQUENCER1);
    ADC_Clear_Interrupt(ADC0, ADC_SEQUENCER1);
}

