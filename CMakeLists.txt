cmake_minimum_required(VERSION 3.19)
project(editor)

set(CMAKE_CXX_STANDARD 14)
set(PROJECT_NAME editor)
set(SOURCE_FILES main.cpp)

find_package(wxWidgets REQUIRED COMPONENTS net core base)
include(${wxWidgets_USE_FILE})

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})