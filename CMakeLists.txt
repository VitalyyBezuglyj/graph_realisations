cmake_minimum_required(VERSION 3.9)
project(graph_realizations_1)

set(CMAKE_CXX_STANDARD 11)

add_executable(graph_realizations_1 main.cpp i_graph.h list_graph.h list_graph.cpp matrix_graph.h matrix_graph.cpp set_graph.h set_graph.cpp arc_graph.h arc_graph.cpp)