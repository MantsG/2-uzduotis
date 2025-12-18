cmake_minimum_required(VERSION 3.14)
project(studentu_rusiavimas LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.11.0
)
FetchContent_MakeAvailable(Catch2)


add_library(core
  Studentas.cpp
  Utils.cpp
  Ivedimas.cpp
  Failai.cpp
)


target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Optimizacija (vietoj global CMAKE_CXX_FLAGS)
target_compile_options(core PRIVATE -O1)


if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
  add_executable(studentu_rusiavimas main.cpp)
elseif (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp")
  add_executable(studentu_rusiavimas src/main.cpp)
  target_include_directories(studentu_rusiavimas PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
else()
  message(WARNING "Nerastas main.cpp (nei šaknyje, nei src/main.cpp). Bus galima kompiliuoti tik tests targetą.")
endif()

if (TARGET studentu_rusiavimas)
  target_link_libraries(studentu_rusiavimas PRIVATE core)
  target_compile_options(studentu_rusiavimas PRIVATE -O1)
endif()


add_executable(tests Testai.cpp)
target_link_libraries(tests PRIVATE core Catch2::Catch2WithMain)
target_compile_options(tests PRIVATE -O1)


include(CTest)
include(Catch)
catch_discover_tests(tests)
