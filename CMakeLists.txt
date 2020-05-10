cmake_minimum_required(VERSION 3.15)
project(Linear_Algebra_master)

set(CMAKE_CXX_STANDARD 14)

add_executable(Linear_Algebra_master
        main.cpp matrix.h vector3D.h vector3D.cpp matrix.cpp)
