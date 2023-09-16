cmake_minimum_required(VERSION 3.0.0)
project(cub3d VERSION 0.1.0)

include(CTest)
enable_testing()

project(cubproj)

file(GLOB PROJ_SRC "bonus/*.c")
add_executable(cubproj ${PROJ_SRC})

FIND_LIBRARY(UNIT_LIB NAMES mlxtest PATHS /Users/juyojeon/Desktop/Cub3D)
target_link_libraries(cubproj PRIVATE ${UNIT_LIB})

target_link_libraries(cubproj PRIVATE "-framework OpenGL")
target_link_libraries(cubproj PRIVATE "-framework AppKit")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
