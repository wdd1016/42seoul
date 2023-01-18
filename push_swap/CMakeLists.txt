cmake_minimum_required(VERSION 3.0.0)
project(
	push_swap
	VERSION 0.1
	DESCRIPTION "push_swap"
	LANGUAGES C)

include(CTest)
enable_testing()

add_library(push_swap push_swap.c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
