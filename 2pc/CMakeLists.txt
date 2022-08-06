cmake_minimum_required(VERSION 3.15)
project(pmpl_2pc)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -O3")
set(SOURCE_FILES_BASE Constant.h Constant.cpp util/Mat.h util/Mat.cpp util/IOManager.h util/IOManager.cpp util/SocketOnline.h util/SocketOnline.cpp util/SocketManager.h util/SocketManager.cpp core/Secret_Mul.h core/Secret_Mul.cpp core/Boolean_Share.h core/Boolean_Share.cpp core/Secret_Cmp.h core/Secret_Cmp.cpp)
set(Machine_Learning_FILES ml/linear.h ml/linear.cpp ml/logistic.h ml/logistic.cpp ml/nn.h ml/nn.cpp)

add_executable(pmpl_2pc main.cpp ${SOURCE_FILES_BASE} ${Machine_Learning_FILES})
add_executable(one ml/one_logistic.cpp Constant.h Constant.cpp util/Mat.h util/Mat.cpp util/IOManager.h util/IOManager.cpp util/SocketOnline.h util/SocketOnline.cpp util/SocketManager.h util/SocketManager.cpp)

