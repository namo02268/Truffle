# CMakeバージョン設定
cmake_minimum_required(VERSION 3.13)

# プロジェクト設定
set (PROJECT_NAME OpenGL_TEST)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

# OpenGL ライブラリの検出（Windows でも Linux でも使える）
find_package(OpenGL REQUIRED)

# for glad
enable_language(C)

# GLFWオプション（examples/test/docsは不要）
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "Disable GLFW examples" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "Disable GLFW tests" FORCE)
set(GLFW_BUILD_DOCS OFF CACHE BOOL "Disable GLFW docs" FORCE)

# GLFWのサブディレクトリ追加
add_subdirectory(vendor/glfw)

# Sourceの追加
set(SRC_FILES
    "src/Core/Application/Application.cpp"
    "src/Core/Time/Time.cpp"
    "src/OpenGL/Window.cpp"
    "main.cpp"
)

# Vendorの追加
set(VENDOR_FILES
    "vendor/glad/glad.c"
    "vendor/imgui/imgui_draw.cpp"
    "vendor/imgui/imgui_impl_glfw.cpp"
    "vendor/imgui/imgui_impl_opengl3.cpp"
    "vendor/imgui/imgui_tables.cpp"
    "vendor/imgui/imgui_widgets.cpp"
    "vendor/imgui/imgui.cpp"
)

# コンパイル
add_executable(${PROJECT_NAME}.out
    ${SRC_FILES}
    ${VENDOR_FILES}
)

# インクルードディレクトリ
target_include_directories(${PROJECT_NAME}.out PRIVATE
    src
    vendor
)

# リンカ設定
if(WIN32)
    target_link_libraries(${PROJECT_NAME}.out PRIVATE glfw opengl32)
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME}.out PRIVATE glfw dl GL)
endif()
