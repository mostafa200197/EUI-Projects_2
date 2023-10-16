#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION                    1U
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 0U
#define configUSE_TICKLESS_IDLE                 0U
#define configCPU_CLOCK_HZ                      16000000U
/*#define configSYSTICK_CLOCK_HZ                  16000000 */
#define configTICK_RATE_HZ                      100U
#define configMAX_PRIORITIES                    11U
#define configMINIMAL_STACK_SIZE                200U
#define configMAX_TASK_NAME_LEN                 16U
#define configUSE_16_BIT_TICKS                  0U
#define configTICK_TYPE_WIDTH_IN_BITS           TICK_TYPE_WIDTH_16_BITS
#define configIDLE_SHOULD_YIELD                 1U
#define configUSE_TASK_NOTIFICATIONS            1U
#define configTASK_NOTIFICATION_ARRAY_ENTRIES   3U
#define configUSE_MUTEXES                       0U
#define configUSE_RECURSIVE_MUTEXES             0U
#define configUSE_COUNTING_SEMAPHORES           0U
#define configUSE_ALTERNATIVE_API               0U /* Deprecated! */
#define configQUEUE_REGISTRY_SIZE               10U
#define configUSE_QUEUE_SETS                    0U
#define configUSE_TIME_SLICING                  0U
#define configUSE_NEWLIB_REENTRANT              0U
#define configENABLE_BACKWARD_COMPATIBILITY     0U
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 5U
#define configUSE_MINI_LIST_ITEM                1U
#define configSTACK_DEPTH_TYPE                  uint16_t
#define configMESSAGE_BUFFER_LENGTH_TYPE        size_t
#define configHEAP_CLEAR_MEMORY_ON_FREE         1U

/* Memory allocation related definitions. */
#define configSUPPORT_STATIC_ALLOCATION             1U
#define configSUPPORT_DYNAMIC_ALLOCATION            1U
#define configTOTAL_HEAP_SIZE                       10240U
#define configAPPLICATION_ALLOCATED_HEAP            0U
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP   0U

/* Hook function related definitions. */
#define configUSE_IDLE_HOOK                     0U
#define configUSE_TICK_HOOK                     0U
#define configCHECK_FOR_STACK_OVERFLOW          0U
#define configUSE_MALLOC_FAILED_HOOK            0U
#define configUSE_DAEMON_TASK_STARTUP_HOOK      0U
#define configUSE_SB_COMPLETED_CALLBACK         0U

/* Run time and task stats gathering related definitions. */
#define configGENERATE_RUN_TIME_STATS           0U
#define configUSE_TRACE_FACILITY                0U
#define configUSE_STATS_FORMATTING_FUNCTIONS    0U

/* Co-routine related definitions. */
#define configUSE_CO_ROUTINES                   0U
#define configMAX_CO_ROUTINE_PRIORITIES         1U

/* Software timer related definitions. */
#define configUSE_TIMERS                        1U
#define configTIMER_TASK_PRIORITY               3U
#define configTIMER_QUEUE_LENGTH                10U
#define configTIMER_TASK_STACK_DEPTH            configMINIMAL_STACK_SIZE

/* Interrupt nesting behaviour configuration. */
#define configKERNEL_INTERRUPT_PRIORITY         0U
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    1U
#define configMAX_API_CALL_INTERRUPT_PRIORITY   1U

/* Define to trap errors during development. */
#define configASSERT(x)                   if ((x) == 0U) {taskDISABLE_INTERRUPTS(); for( ;; );}

/* FreeRTOS MPU specific definitions. */
/*
#define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS 0
#define configTOTAL_MPU_REGIONS                                8  Default value.
#define configTEX_S_C_B_FLASH                                  0x07UL  Default value.
#define configTEX_S_C_B_SRAM                                   0x07UL  Default value.
#define configENFORCE_SYSTEM_CALLS_FROM_KERNEL_ONLY            1
#define configALLOW_UNPRIVILEGED_CRITICAL_SECTIONS             1
#define configENABLE_ERRATA_837070_WORKAROUND                  1
#define configUSE_MPU_WRAPPERS_V1                              0
#define configPROTECTED_KERNEL_OBJECT_POOL_SIZE                10
#define configSYSTEM_CALL_STACK_SIZE                           128
*/

/* Optional functions - most linkers will remove unused functions anyway. */
#define INCLUDE_vTaskPrioritySet                1U
#define INCLUDE_uxTaskPriorityGet               1U
#define INCLUDE_vTaskDelete                     1U
#define INCLUDE_vTaskSuspend                    1U
#define INCLUDE_xResumeFromISR                  1U
#define INCLUDE_vTaskDelayUntil                 1U
#define INCLUDE_vTaskDelay                      1U
#define INCLUDE_xTaskGetSchedulerState          1U
#define INCLUDE_xTaskGetCurrentTaskHandle       1U
#define INCLUDE_uxTaskGetStackHighWaterMark     0U
#define INCLUDE_uxTaskGetStackHighWaterMark2    0U
#define INCLUDE_xTaskGetIdleTaskHandle          0U
#define INCLUDE_eTaskGetState                   0U
#define INCLUDE_xEventGroupSetBitFromISR        1U
#define INCLUDE_xTimerPendFunctionCall          0U
#define INCLUDE_xTaskAbortDelay                 0U
#define INCLUDE_xTaskGetHandle                  0U
#define INCLUDE_xTaskResumeFromISR              1U

/* A header file that defines trace macro can be included here. */

#endif /* FREERTOS_CONFIG_H */
