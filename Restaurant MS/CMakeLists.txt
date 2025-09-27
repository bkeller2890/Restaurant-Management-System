cmake_minimum_required(VERSION 3.14)
project(RestaurantManagementSystem VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Application sources
set(APP_SOURCES
    main.cpp
    Restaurant.cpp
    Order.cpp
    MenuItem.cpp
    Employee.cpp
    Expense.cpp
    DateTimeFormatter.cpp
)

add_executable(restaurant_app ${APP_SOURCES})
target_include_directories(restaurant_app PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
    enable_testing()
    include(FetchContent)

    # Fetch GoogleTest
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.14.0
    )
    # For Windows: prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Test target
    set(TEST_SOURCES
        tests/test_datetime.cpp
        DateTimeFormatter.cpp
        Order.cpp
        MenuItem.cpp
        Employee.cpp
        Expense.cpp
        Restaurant.cpp
    )

    add_executable(run_tests ${TEST_SOURCES})
    target_include_directories(run_tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    target_link_libraries(run_tests PRIVATE gtest_main)

    include(GoogleTest)
    gtest_discover_tests(run_tests)
endif()
