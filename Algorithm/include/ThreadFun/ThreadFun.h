#ifndef _THREADFUN_H_
#define _THREADFUN_H_
#include <iostream>
#include <thread>
#include <condition_variable>
#include <mutex>
//uusing spdlog sink
#include <spdlog/spdlog.h>
#include <spdlog/logger.h>
#include "spdlog/sinks/base_sink.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"




extern std::condition_variable con_variable;
extern std::condition_variable cv_odd;
extern std::condition_variable cv_even;
extern std::mutex odd_num_mtx;
extern std::mutex even_num_mtx;
extern bool is_Pause;
extern int count;

void thread_task(void *arg);
void thread_task2(void *arg);

void task_odd_num();
void task_even_num();

#endif