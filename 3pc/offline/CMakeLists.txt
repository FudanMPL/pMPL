cmake_minimum_required(VERSION 3.15)
project(accesscontrol)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O3")

set(SOURCE_FILES_BASE ../util/IOManager.cpp ../util/IOManager.h ../util/SocketOnline.cpp ../util/SocketOnline.h ../util/SocketManager.cpp ../util/SocketManager.h ../util/Mat.cpp ../util/Mat.h ../Constant.cpp ../Constant.h )
set(CORE_FILES_BASE ../core/Secret_Mul.cpp ../core/Secret_Mul.h)


add_executable(offline1 offline_step_one.cpp ${SOURCE_FILES_BASE} ${CORE_FILES_BASE})
add_executable(offline2 offline_step_two.cpp ${SOURCE_FILES_BASE} ${CORE_FILES_BASE})