cmake_minimum_required(VERSION 3.0.0)
project(Desktop_Application VERSION 0.1.0)


add_executable(Desktop_Application GUI.h server.h server.cpp main.cpp)


find_package(websocketpp CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(Boost REQUIRED)
include_directories("C:\\Program Files\\VCPKG\\vcpkg\\scripts\\boost")
target_link_libraries(Desktop_Application PRIVATE websocketpp::websocketpp imgui::imgui glfw glad::glad)