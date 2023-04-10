cmake_minimum_required(VERSION 3.26.1)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
#set(CMAKE_CXX_STANDARD 11)
project(Algorithm)


option(THREAD_DEBUG "THREAD_DEBUG switch" ON)
option(ALGO_DEBUG "ALGO_DEBUG switch" OFF)

add_compile_definitions(HAVE_COONFIG_H)
#generate config.h
configure_file("${PROJECT_SOURCE_DIR}/include/config.h.in"
"${PROJECT_SOURCE_DIR}/include/config.h"
)





#build --Create the build dir
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/build)
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)

#include MaoPao or FastSort directories
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)

add_library(BinarySearch STATIC ${PROJECT_SOURCE_DIR}/src/BinarySearch.cpp)
set_target_properties(BinarySearch PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib) #static lib

add_library(FastSort SHARED ${PROJECT_SOURCE_DIR}/src/FastSort.c)
#input to appoint path
set_target_properties(FastSort PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)  
# static lib ->[PROPERTIES ARCHIVE_OUT_PUT_DIRECTORY  ${PROJECT_SOURCE_DIR}/path]   
# shred lib  ->[PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/path]
#include SPDlog directories
include_directories(${CMAKE_SOURCE_DIR}/include/spdlog/include/)


add_library(Thread_task SHARED ${PROJECT_SOURCE_DIR}/src/ThreadFun.cpp)
set(GlobalValue ${PROJECT_SOURCE_DIR}/include/ThreadFun/ThreadFun.h)
set_target_properties(Thread_task PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)





file(GLOB SOURCE_CPP ${PROJECT_SOURCE_DIR}/src/*.cpp )
#file(GLOB SOURCE_C ${PROJECT_SOURCE_DIR}/src/*.c)
#aux_source_directory(${PROJECT_SOURCE_DIR}/src SOURCES)
#${GlobalValue}
add_executable(Algorithm_test ${SOURCE_CPP} )




include_directories(${PROJECT_SOURCE_DIR}/src)
#include_directories(${PROJECT_SOURCE_DIR}/build)
#tar_link_spdlog.a
target_link_libraries(Algorithm_test PRIVATE 
    spdlog
    FastSort
    BinarySearch
    Thread_task
    pthread
    )   #appoint to libFastSort

target_link_directories(Algorithm_test PRIVATE 
        ${PROJECT_SOURCE_DIR}/lib #because the lib include all lib(generatered lib)
) 





