# ==============================================
# CMake Version
# ==============================================
cmake_minimum_required(VERSION 3.13)

# ==============================================
# Project Settings
# ==============================================
set (PROJECT_NAME Truffle)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 20)

message(STATUS "Project: ${PROJECT_NAME}")
message(STATUS "C++ Standard: C++${CMAKE_CXX_STANDARD}")

# ==============================================
# Dependencies
# ==============================================
find_package(OpenGL REQUIRED)

# glad (uses C)
enable_language(C)

# GLFW settings (disable unused parts)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable GLFW examples" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable GLFW tests" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable GLFW docs" FORCE)
add_subdirectory(vendor/glfw)
message(STATUS "GLFW added (examples/tests/docs disabled)")

# ==============================================
# Source Files
# ==============================================
# Core sources
set(SRC_CORE
    src/Core/Application/Application.cpp
    src/Core/Time/Time.cpp
    src/Core/Logger/Logger.cpp
)

# Editor sources
set(SRC_EDITOR
    src/Editor/Editor.cpp
    src/Editor/AppInfo.cpp
    src/Editor/Console.cpp
)

# Renderer sources
set(SRC_RENDERER
    src/Renderer/Renderer.cpp
    src/Renderer/RenderAPI.cpp
)

# OpenGL backend sources
set(SRC_OPENGL
    src/OpenGL/OpenGLWindow.cpp
    src/OpenGL/OpenGLRenderAPI.cpp
    src/OpenGL/OpenGLVertexBuffer.cpp
    src/OpenGL/OpenGLIndexBuffer.cpp
    src/OpenGL/OpenGLVertexArray.cpp
    src/OpenGL/OpenGLShader.cpp
)

# Scene sources
set(SRC_SCENE
    src/Scene/HelloTriangle.cpp
)

# Main entry point
set(SRC_MAIN main.cpp)

# Vendor sources (glad & ImGui)
set(VENDOR_SOURCES
    vendor/glad/glad.c
    vendor/imgui/imgui.cpp
    vendor/imgui/imgui_draw.cpp
    vendor/imgui/imgui_tables.cpp
    vendor/imgui/imgui_widgets.cpp
    vendor/imgui/imgui_impl_glfw.cpp
    vendor/imgui/imgui_impl_opengl3.cpp
)

# Merge all sources
set(ALL_SOURCES
    ${SRC_CORE}
    ${SRC_EDITOR}
    ${SRC_RENDERER}
    ${SRC_OPENGL}
    ${SRC_SCENE}
    ${SRC_MAIN}
    ${VENDOR_SOURCES}
)

# ==============================================
# Build Target
# ==============================================
add_executable(${PROJECT_NAME}.out ${ALL_SOURCES})

# Include directories
target_include_directories(${PROJECT_NAME}.out PRIVATE
    src
    vendor
)

# Link Libraries
if(WIN32)
    target_link_libraries(${PROJECT_NAME}.out PRIVATE glfw opengl32)
    message(STATUS "Linking with opengl32 (Windows)")
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME}.out PRIVATE glfw dl GL)
    message(STATUS "Linking with GL and dl (Unix/Linux)")
endif()

message(STATUS "Build configuration complete.")
message(STATUS "To build the project, run 'cmake --build .' in the build directory.")
