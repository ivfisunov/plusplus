add_executable(${BINARY} main.cpp)

target_include_directories(${BINARY} PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/include
)

target_link_libraries(${BINARY} PRIVATE
    ${BINARY}_version
    # ${BINARY}_utils
)

install(TARGETS ${BINARY} RUNTIME DESTINATION bin)
