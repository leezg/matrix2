cmake_minimum_required(VERSION 3.20)
project(matrix2)

set(CMAKE_CXX_STANDARD 14)

add_executable(matrix2 main.cpp matrix.h matrix.cpp matrixOperation.h matrixOperation.cpp hessenbergMatrix.cpp QRMethod.cpp)
