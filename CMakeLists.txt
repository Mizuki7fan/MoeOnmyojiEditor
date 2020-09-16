cmake_minimum_required(VERSION 3.7)
project(MoeOnmyojiEditor)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message(STATUS "the compiler is MSVC")
    add_definitions(/DQT_NO_DEBUG)
    add_definitions(/DQT_CORE_LIB)
    add_definitions(/DQT_GUI_LIB)
    add_definitions(/DQT_OPENGL_LIB)
    add_definitions(/DQT_WIDGETS_LIB)
endif()

#QT相关设置
set(CMAKE_INCLUDE_CURRENT_DIR ON) #设置工程包含当前目录，非必须
set(CMAKE_AUTOMOC ON) #设置自动生成moc文件，一定要设置
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
find_package(Qt5Widgets)  
find_package(Qt5Core)
find_package(Qt5Gui)
find_package(Qt5OpenGL)
get_target_property(_qmake_executable Qt5::qmake IMPORTED_LOCATION)# https://zhuanlan.zhihu.com/p/73469206，调用windepolyqt进行自动部署
get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
find_program(DEPLOYQT_EXECUTABLE NAMES windeployqt macdeployqt HINTS "${_qt_bin_dir}")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Zi")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /DEBUG /OPT:REF /OPT:ICF")

set(QRC_SOURCE_FILES src/MOE.qrc) #添加资源文件
qt5_add_resources(QRC_FILES ${QRC_SOURCE_FILES})

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    message(STATUS "the OS is windows")
    #include_directories("D:/LIBRARY/ANN")
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    #link_directories("D:/LIBRARY/freeglut/build/lib/Release")
    endif()
endif()

file (GLOB SRCFILES
    src/*.cpp
)

add_executable(${PROJECT_NAME} ${SRCFILES} ${QRC_FILES})
if(WIN32)
add_custom_command(TARGET ${PROJECT_NAME}
POST_BUILD
COMMAND ${DEPLOYQT_EXECUTABLE} "$<TARGET_FILE:${PROJECT_NAME}>"
    --$<LOWER_CASE:$<CONFIG>> --qmldir ${CMAKE_SOURCE_DIR}
)
endif()
if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::OpenGL
    #optimized opengl32
    )
endif()