cmake_minimum_required(VERSION 3.16)

project(CLI_Task_Manager LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(CLI_Task_Manager main.cpp)

include(GNUInstallDirs)
install(TARGETS CLI_Task_Manager
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
