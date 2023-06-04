cmake_minimum_required(VERSION 3.0.0)
project(Desktop_Application VERSION 0.1.0)

add_executable(Desktop_Application server.h server.cpp main.cpp)

find_package(websocketpp CONFIG REQUIRED)
target_link_libraries(Desktop_Application PRIVATE websocketpp::websocketpp)