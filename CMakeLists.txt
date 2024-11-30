cmake_minimum_required(VERSION 3.10)

project(justePrixCLI VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
	src/jeu.cpp
	src/menu.cpp
	src/juste_prix.cpp
)

set(HEADERS
	inc/constantes.hpp
	inc/jeu.hpp
	inc/menu.hpp
)

include_directories( ${CMAKE_CURRENT_SOURCE_DIR}/inc )
#file(GLOB SOURCES "*.cpp")
#file(GLOB HEADERS "*.hpp")

add_executable(juste_prix ${SOURCES} ${HEADERS})
