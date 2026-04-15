cmake_minimum_required(VERSION 3.10)

project(ShapesEditor CXX)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Werror=return-type")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.4.0
)
FetchContent_MakeAvailable(Catch2)

add_library(ShapesLib
    src/circle.cpp
    src/rectangle.cpp
    src/triangle.cpp
)
target_include_directories(ShapesLib PUBLIC include)

add_executable(MyApp src/main.cpp)
target_link_libraries(MyApp PRIVATE ShapesLib)

enable_testing()

add_executable(unit_tests
    tests/test_shapes.cpp
)
target_link_libraries(unit_tests PRIVATE ShapesLib Catch2::Catch2WithMain)

add_test(NAME ShapesTests COMMAND unit_tests)
