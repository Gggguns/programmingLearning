cmake_minimum_required(VERSION 3.10)

# 设置 Qt 路径（确保与 MSVC 编译器匹配）
set(CMAKE_PREFIX_PATH "E:/ProgramFiles/Qt/Qt5.13.2/5.13.2/msvc2017_64")

project(CounterDemo)

set(CMAKE_CXX_STANDARD 11)

# 查找 Qt 模块（保持你的配置）
find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

# 1. 收集源文件（保持你的写法）
file(GLOB SOURCE "./src/*.cpp")

# 2. 收集头文件（关键：包含 Q_OBJECT 宏的类必须在这里）
file(GLOB HEADERS "./include/*.h")

# 3. 收集 UI 文件（Qt Designer 生成的 .ui 文件）
file(GLOB UI_FILES "./ui/*.ui")  # 假设 UI 文件在项目根目录的 ui 文件夹下

# 4. 处理 UI 文件：将 .ui 转换为 C++ 头文件（如 ui_mainwindow.h）
qt5_wrap_ui(UI_HEADERS ${UI_FILES})

# 5. 处理 moc：为包含 Q_OBJECT 宏的头文件生成元对象代码（解决链接错误的核心）
qt5_wrap_cpp(MOC_SOURCES ${HEADERS})

# 6. 头文件目录（保持你的配置）
include_directories(
    ./include
     ${CMAKE_CURRENT_BINARY_DIR})

# 7. 生成可执行文件：必须包含源文件、头文件、UI 处理结果和 moc 生成的代码
add_executable(
    ${PROJECT_NAME} 
    ${SOURCE} 
    ${HEADERS} 
    ${UI_HEADERS}  # 加入 UI 处理结果
    ${MOC_SOURCES} # 加入 moc 生成的元对象代码
)

# 8. 链接 Qt 库（保持你的配置）
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Gui Qt5::Widgets)
