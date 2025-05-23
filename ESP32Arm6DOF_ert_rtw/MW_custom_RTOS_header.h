#ifndef _MW_CUSTOM_RTOS_HEADER_H_
#define _MW_CUSTOM_RTOS_HEADER_H_
#define MW_BASERATE_PRIORITY           14
#define MW_BASERATE_PERIOD             0.033333333333333333
#define MW_NUMBER_SUBRATES             0
#define MW_NUMBER_APERIODIC_TASKS      0
#define MW_IS_CONCURRENT               0
#define MW_NUMBER_TIMER_DRIVEN_TASKS   0

extern void exitFcn(int sig);
extern void *terminateTask(void *arg);
extern void *baseRateTask(void *arg);
extern void *subrateTask(void *arg);
extern mw_thread_t schedulerThread;
extern mw_thread_t baseRateThread;
extern mw_thread_t subRateThread[];
extern SemaphoreHandle_t stopSem;
extern SemaphoreHandle_t baserateTaskSem;
extern SemaphoreHandle_t subrateTaskSem[];
extern int taskId[];
extern int subratePriority[];

#endif

#define MW_MAX_TASKNAME                16
