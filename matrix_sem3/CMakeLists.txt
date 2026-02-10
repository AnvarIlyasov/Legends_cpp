cmake_minimum_required(VERSION 3.20)
project(matrix LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(matrix_functions
    src/check_square.cpp
    src/is_symmetric.cpp
    src/output_transpose.cpp
    src/read_matrix.cpp
    src/transpose.cpp
)

target_include_directories(matrix_functions
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(matrix_app
    src/main.cpp
)

target_link_libraries(matrix_app
    PRIVATE
        matrix_functions
)

include(CTest)
if(BUILD_TESTING)
    find_package(Catch2 3 QUIET)
    if(NOT Catch2_FOUND)
        include(FetchContent)
        FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v3.5.4
        )
        FetchContent_MakeAvailable(Catch2)
        list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
    endif()

    include(Catch)

    add_executable(matrix_tests
        tests/test_matrix.cpp
    )

    target_link_libraries(matrix_tests
        PRIVATE
            matrix_functions
            Catch2::Catch2WithMain
    )

    catch_discover_tests(matrix_tests)
endif()