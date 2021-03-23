cmake_minimum_required(VERSION 3.1)
project(wt-example)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

find_package(wt REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
target_link_libraries(${PROJECT_NAME} Wt::Wt Wt::HTTP)
