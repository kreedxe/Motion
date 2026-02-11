cmake_minimum_required(VERSION 3.28)
project(MotionEngine)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)


#------------------------------------------------
# FIND REQUIRED LIBRARIES
#------------------------------------------------
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
find_package(glm CONFIG REQUIRED)


#------------------------------------------------
# BUILD GLAD STATIC LIBRARY
#------------------------------------------------
add_library(glad ${CMAKE_SOURCE_DIR}/dependencies/glad/src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/glad/include)


#------------------------------------------------
# BUILD STB IMAGE STATIC LIBRARY
#------------------------------------------------
add_library(stb_image ${CMAKE_SOURCE_DIR}/dependencies/stb/stb_image_impl.c)
target_include_directories(stb_image PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/stb)


#------------------------------------------------
# BUILD IMGUI STATIC LIBRARY
#------------------------------------------------
add_library(imgui STATIC
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_draw.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_tables.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_widgets.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/imgui_demo.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/backend/imgui_impl_glfw.cpp
    ${CMAKE_SOURCE_DIR}/dependencies/imgui/backend/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC ${CMAKE_SOURCE_DIR}/dependencies/imgui)


#------------------------------------------------
# BUILD ENGINE
#------------------------------------------------
set(MOTION_SOURCES 
    ${CMAKE_SOURCE_DIR}/src/Motion/Engine.cpp
)
add_library(Motion STATIC ${MOTION_SOURCES})
target_link_libraries(Motion PUBLIC glfw glad OpenGL::GL imgui glm::glm stb_image)
target_include_directories(Motion PUBLIC ${CMAKE_SOURCE_DIR}/include)


#------------------------------------------------
# MAIN EXECUTABLE
#------------------------------------------------
add_executable(Demo ${CMAKE_SOURCE_DIR}/examples/demo.cpp)
target_link_libraries(Demo PRIVATE Motion)
