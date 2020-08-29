cmake_minimum_required(VERSION 3.15)
project(CudaRenderProj VERSION 0.1.0)

cmake_policy(SET CMP0072 NEW)

set(CMAKE_CXX_STANDARD 11)
set(TARGET CudaRender)
include(CTest)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_subdirectory(src)

enable_testing()
add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
