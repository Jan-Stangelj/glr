cmake_minimum_required(VERSION 3.16)

project("glr" LANGUAGES CXX C)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED On)

set("GLRHI_BUILD_EXAMPLES" OFF CACHE BOOL "")
add_subdirectory("vendor/glrhi")

file(GLOB_RECURSE "SOURCES" CONFIGURE_DEPENDS "src/*.cpp")
add_library("glr" "${SOURCES}")

# Enable ALL warnings
if(MSVC)
  target_compile_options(glr PRIVATE /W4 /WX)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNUc")
  target_compile_options(glr PRIVATE -Wall -Wextra -Wpedantic)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  target_compile_options(glr PRIVATE -Wall -Wextra -Wpedantic)
endif() 

target_include_directories("glr" PUBLIC ${PROJECT_SOURCE_DIR}/include)

target_link_libraries("glr" PUBLIC glrhi)

option("GLR_BUILD_EXAMPLES" "Build examples for glr" ON)

if (GLR_BUILD_EXAMPLES)
    add_executable("test" "examples/test/src/main.cpp")
    target_link_libraries("test" glr)
endif()