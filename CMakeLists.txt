cmake_minimum_required(VERSION 3.30)

project(KInd)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR)
	set(KIND_STANDALONE ON)
else()
	set(KIND_STANDALONE OFF)
endif()

if(KIND_STANDALONE)
	set(KIND_BUILD_TESTS ON CACHE BOOL "Build tests")
else()
	set(KIND_BUILD_TESTS OFF CACHE BOOL "Build tests")
endif()


add_library(
	KInd
	INTERFACE
)

target_include_directories(
	KInd
	INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(KIND_BUILD_TESTS)
	add_subdirectory(test)
endif()