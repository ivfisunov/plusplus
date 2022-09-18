add_executable(${BINARY}
    main.cpp
    product/command_proc.cpp
    product/console_processing.cpp
    product/file_processing.cpp)

target_include_directories(${BINARY} PRIVATE
    ${CMAKE_SOURCE_DIR}/lib/include
)

target_link_libraries(${BINARY} PRIVATE
    ${BINARY}_version
)

install(TARGETS ${BINARY} RUNTIME DESTINATION bin)
