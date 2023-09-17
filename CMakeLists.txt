cmake_minimum_required(VERSION 3.0.0)
project(cub3d VERSION 0.1.0)

include(CTest)
enable_testing()

project(cubproj)

file(GLOB PROJ_SRC "bonus/*.c")
add_executable(cubproj ${PROJ_SRC})

target_link_libraries(cubproj PRIVATE libmlx.dylib)
target_link_directories(cubproj PRIVATE /Users/juyojeon/Desktop/Cub3D/mlx)
target_include_directories(cubproj PRIVATE /Users/juyojeon/Desktop/Cub3D/mlx)

target_link_libraries(cubproj PUBLIC "-framework OpenGL")
target_link_libraries(cubproj PUBLIC "-framework AppKit")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# libmlx.dylib를 build폴더에도 넣어주어야 동작합니다....ㅠㅠㅠ