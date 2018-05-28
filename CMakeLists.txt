cmake_minimum_required(VERSION 3.9)
project(dot)

set(CMAKE_CXX_STANDARD 11)

include_directories(C:/mysql-5.6.21-win32/include)
link_directories(C:/mysql-5.6.21-win32/lib/)
link_libraries(mysql)

add_executable(dot main.cpp Wrapper.cpp Wrapper.h AbstractBase.cpp AbstractBase.h Season.cpp Season.h Example.cpp Example.h Supere.cpp Supere.h Sub.cpp Sub.h)