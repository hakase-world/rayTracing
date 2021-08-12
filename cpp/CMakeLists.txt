#CMakeの最小バージョンの指定
cmake_minimum_required(VERSION 3.8)

#プロジェクトの名前の設定
project(Raytracing)

#ソースファイルと実行ファイルの指定
add_executable(rt main.cpp)

#C++標準規格の指定
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
