set(SOURCES
    test.cpp
)

add_executable(unit_tests ${SOURCES})

add_test(
    NAME
        all_tests
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/unit_tests
)