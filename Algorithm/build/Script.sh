#!/bin/bash

# 运行cmake ..
function cmake_build() {
    cmake ..
}

# 运行make
function make_build() {
    make
}

# 执行Algorithm_test
function run_algorithm_test() {
    ./Algorithm_test
}

# 判断命令行参数是否正确
if [ $# -ne 1 ]; then
    echo "使用方法：./my_shell.sh <command>"
    exit 1
fi

# 根据命令行参数来调用相应的函数
case $1 in
    1)
        cmake_build
        make_build
        run_algorithm_test
        ;;
    *)
        echo "无效的命令！"
        exit 1
        ;;
esac





  