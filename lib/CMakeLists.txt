add_library(${BINARY}_version version.cpp)
add_library(${BINARY}_utils utils.cpp)

target_include_directories(${BINARY}_version PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_BINARY_DIR}/config
)

target_include_directories(${BINARY}_utils PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
