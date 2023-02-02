cmake_minimum_required(VERSION 3.0.0)
project(fractol VERSION 0.1.0)

include(CTest)
enable_testing()

project(fractolprog)

INCLUDE_DIRECTORIES(srcs)

file(GLOB PROJ_SRC "srcs/*.c")
add_executable(fractolprog ${PROJ_SRC})

FIND_LIBRARY(UNIT_LIB NAMES mlx PATHS /Users/juyojeon/Desktop/42seoul/fractol/minilibx)
target_link_libraries(fractolprog PRIVATE ${UNIT_LIB})

target_link_libraries(fractolprog PRIVATE "-framework OpenGL")
target_link_libraries(fractolprog PRIVATE "-framework AppKit")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
