#include <Application/Temperature_Task.h>

void temperature_task(void *pvParameters_Temperature)
{
    QueueHandle_t Data_Handler = *((QueueHandle_t*) pvParameters_Temperature);
    uint8_t data = 0U;
    for (;;)
    {
        Turn_On_LED(BLUE_LED);
        data = Temperature_Read();
        xQueueSend(Data_Handler, (void* ) &data, 0);
        taskYIELD();
    }
}
