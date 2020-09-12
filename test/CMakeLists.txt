set(SOURCES
    test.cpp
)

include_directories(${PROJECT_SOURCE_DIR}/test)

add_executable(unit_tests ${SOURCES})

target_link_libraries(unit_tests
    math
    scene
    camera
    entity
)

add_test(
    NAME
        all_tests
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/unit_tests
)