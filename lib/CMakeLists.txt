add_library(${BINARY}_version version.cpp)

target_include_directories(${BINARY}_version PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/config
)

