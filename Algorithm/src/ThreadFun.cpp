#include "ThreadFun/ThreadFun.h"



/// @brief 
/// @param arg 
/// @return 

void thread_task(void *arg)
{
  
    auto share_ptr = (reinterpret_cast<std::pair<spdlog::logger*,int>*>(arg));
    auto sink = share_ptr->first;
    auto num = share_ptr->second;
    if(num <1)
    {
        return;
    }

    std::unique_lock<std::mutex> ul(odd_num_mtx);
    for(int i =0; i < 10000; i++)
    {
        
        if(is_Pause)
        {
           
            con_variable.wait(ul);
           
        }
        
        con_variable.wait(ul, [](){return !is_Pause;});
        int printNum = (i % 2 == 1) ? i * num + 1 : 0;
            int id  = static_cast<int>(std::hash<std::thread::id>()(std::this_thread::get_id()));
            if(printNum >0)
            {
                    sink->info("thread ID:{}  print num:{} run thread :{}",id, printNum, num);
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
    }
   
}

void thread_task2(void *arg)
{
  
    auto share_ptr = (reinterpret_cast<std::pair<spdlog::logger*,int>*>(arg));
    auto sink = share_ptr->first;
    auto num = share_ptr->second;
    if(num <1)
    {
        return;
    }

    std::unique_lock<std::mutex> ul(even_num_mtx);
    for(int i =0; i < 10000; i++)
    {
        
        if(is_Pause)
        {
           
            //con_variable.wait(ul);
           
        }
        
        con_variable.wait(ul, [](){return !is_Pause;});
        int printNum = (i % 2 == 0) ? i * num : 0;
            
            int id  = static_cast<int>(std::hash<std::thread::id>()(std::this_thread::get_id()));
            if(printNum >0)
            {
                    sink->info("thread ID:{}  print num:{} run thread :{}",id, printNum, num);
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
            }
            
   
    }

   
}

/*
extern std::condition_variable con_variable;
extern std::mutex odd_num_mtx;
extern std::mutex even_num_mtx;
extern bool is_Pause;
extern int count = 0;*/

void task_odd_num()
{   
    auto logger = spdlog::get("logger");
     std::unique_lock<std::mutex> cv(odd_num_mtx); 
     while(count<10000)
     {
        
       

        if(count%2  == 0 && !is_Pause)
        {
            logger.get()->info("odd:{}", count);
           // std::cout<<"odd: "<<count<<std::endl;
            ++count;
            cv_even.notify_one();
            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            

        }
        else
        {
            cv_odd.wait(cv);
            

        }
        

     }   



}

void task_even_num()
{
    auto logger = spdlog::get("logger");
     std::unique_lock<std::mutex> cv(odd_num_mtx); 
     while(count<10000)
     {
        if(count%2  == 1 && !is_Pause)
        {
            
            logger.get()->info("even:{}",count);
          // std::cout<<"even: "<<count<<std::endl;
            ++count;
            cv_odd.notify_one();
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        else
        {
            cv_even.wait(cv);
            

        }
        

     }      
    

}