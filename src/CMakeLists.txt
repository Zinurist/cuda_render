set(SOURCES
    main.cpp
    RenderApp.cpp
)

add_subdirectory(math)
add_subdirectory(scene)
add_subdirectory(camera)
add_subdirectory(entity)

add_executable(${TARGET} ${SOURCES})

find_package(glfw3 REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(${TARGET} glfw)

find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${OPENGL_LIBRARIES})

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
target_link_libraries(${TARGET} ${GLEW_LIBRARIES})

target_link_libraries(${TARGET}
    math
    scene
    camera
    entity
)