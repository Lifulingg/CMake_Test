#include <iostream>

//--
#include "MaoPao/MaoPao.hpp"
#include "BinarySearch/BinarySearch.h"
extern "C"
{
#include "FastSort/FastSort.h"
}

#include "ioPrint/simplePrint.hpp"

//uusing spdlog sink
#include <spdlog/spdlog.h>
#include <spdlog/logger.h>
#include "spdlog/sinks/base_sink.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include <ThreadFun/ThreadFun.h>

//HAVE_CONFIG_H是一个常见的预定义宏，在许多使用Autotools和CMake等自动化构建工具的开源项目中都有使用。它通常用于检查是否已经生成了config.h文件，并在条件分支内包含该文件
#ifdef HAVE_COONFIG_H
    #include "config.h"
#endif


//test console & file both input content
std::condition_variable con_variable;

std::condition_variable cv_odd;
std::condition_variable cv_even;
std::mutex odd_num_mtx;
std::mutex even_num_mtx;
bool is_Pause;
int count = 1;



int main()
{

#ifdef ALGO_DEBUG
    int arr[5] = {6,3,7,2,5};
    int len = sizeof(arr)/sizeof(arr[0]);
      
    spdlog::warn("MaoPao Sort: {}", len);
    MaoPaoSort(arr, len); 
    arrPrint(arr, len);

    int arr1[5] = {6,3,7,1,5};
    spdlog::warn("FastSort: {}", 5);
    vFastSort(arr1, 0, 4);
    arrPrint(arr1, 5);

    BinarySearch(arr1, 5, 3);
#endif



#ifdef THREAD_DEBUG
//test Thhread 
/**/
    auto file_sink = std::make_shared<spdlog::sinks::daily_file_sink_mt>("test.txt", 12, 0,0);
    auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    spdlog::sinks_init_list sink{file_sink, console_sink};
    auto my_logger = std::make_shared<spdlog::logger>("logger", sink.begin(), sink.end());
    
    spdlog::register_logger(my_logger);


    std::thread t1(task_odd_num);
    std::thread t2(task_even_num);


    while(1)

    {
        char input;
        std::cin >> input;
        if(input == 's')
        {
            is_Pause = true;
        }
        else if(input == 'c')
        {
            is_Pause = false;
            cv_even.notify_one();
            cv_odd.notify_one();
        }
        else
        {
            my_logger.get()->warn("Input error!");
        }


    }
    t1.join();
    t2.join();


#else
    spdlog::info("type is the same? :{}",  (std::is_same<const char*, char *const>::value));
#endif
    return 0;
}