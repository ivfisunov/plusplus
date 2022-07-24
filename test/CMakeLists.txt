find_package(GTest REQUIRED)

add_executable(${BINARY}_test test_alloc.cpp)

target_include_directories(${BINARY}_test PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/include
)

target_link_libraries(${BINARY}_test
    gtest
    gtest_main
    pthread
    ${BINARY}_utils
)

add_test(${BINARY}_test ${BINARY}_test)
