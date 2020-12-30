cmake_minimum_required(VERSION 3.17)
project(VMTriangle)

set(CMAKE_CXX_STANDARD 14)

add_executable(VMTriangle main.cpp back/Matrix.h back/Quaternion.h back/Vector.h back/Rb/RigidBody.h back/Triangle.h back/DynamicSystem.h back/ContextDynamic.h back/Rb/RigidBody.cpp)
target_link_libraries(VMTriangle -lglut -lGL -lGLU)