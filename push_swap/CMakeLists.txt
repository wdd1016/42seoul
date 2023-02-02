cmake_minimum_required(VERSION 3.0.0)
project(push_swap VERSION 0.1.0)

include(CTest)
enable_testing()

file(GLOB PROJ_SRC "srcs/*.h" "srcs/*.c")
add_executable(push_swap ${PROJ_SRC})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
