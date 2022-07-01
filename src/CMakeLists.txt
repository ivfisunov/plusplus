add_executable(${BINARY}_cli main.cpp)

target_include_directories(${BINARY}_cli PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/include
)

target_link_libraries(${BINARY}_cli PRIVATE
    ${BINARY}_version
)

install(TARGETS ${BINARY}_cli RUNTIME DESTINATION bin)
