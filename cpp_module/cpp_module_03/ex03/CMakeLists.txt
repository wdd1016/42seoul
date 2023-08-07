cmake_minimum_required(VERSION 3.0.0)
project(ex03 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

project(fractolprog)

file(GLOB PROJ_SRC "*.cpp")
add_executable(fractolprog ${PROJ_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
