cmake_minimum_required(VERSION 3.10)

project(SatelliteListDemo
    VERSION 1.0.0
    DESCRIPTION "Qt 卫星列表多级目录演示程序"
    LANGUAGES CXX
)

# C++ 标准配置
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Qt 自动处理配置
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# ##############################
#  关键修复：告诉 uic 工具 .ui 文件在哪里
# ##############################
# 替换为你的 .ui 文件实际所在目录（例如 ui/ 文件夹）
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

# 查找 Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

# 源文件配置
include_directories(include)

set(SOURCES
    src/main.cpp
    src/sidepanel.cpp
    include/sidepanel.h
)

# 显式列出 UI 文件（避免 GLOB 可能的遗漏）
set(UI_FILES
    UI/SidePanel.ui  # 确保这里的路径和实际一致
)

file(GLOB_RECURSE RESOURCES "resources/qrc/*.qrc")

# 输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# 构建可执行程序
add_executable(
    ${PROJECT_NAME}
    ${SOURCES}
    ${UI_FILES}
    ${RESOURCES}
)

# 链接 Qt 库
target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Widgets
)

# 包含生成文件目录
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
)
