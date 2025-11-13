cmake_minimum_required(VERSION 3.10)
project(1Uzduotis VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
	add_compile_options(/W4)
else()
	add_compile_options(-Wall -Wextra -pedantic)
endif()

set(SOURCES
	main.cpp
	Failai.cpp
	Ivedimas.cpp
	Utils.cpp
)

set(HEADERS
	Studentas.h
	Failai.h
	Ivedimas.h
	Utils.h
)

add_executable(1Uzduotis ${SOURCES} ${HEADERS})

set(CMAKE_CXX_FLAGS_RELEASE "-03")

# (Pasirinkimai) list arba vector
# add_definitions(-DNAUDOTI_LIST)
# add_definitions(-DNAUDOTI_VECTOR)