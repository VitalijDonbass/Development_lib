cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

set(NAME_PROJECT Development_Lib)
project(${NAME_PROJECT} LANGUAGES CXX)

set_target_properties(
	PROPERTIES CXX_STANDARD 14
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
)

set(SRC
	src/lib/Loger.cpp
)

add_subdirectory(example/Loger)