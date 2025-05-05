cmake_minimum_required(VERSION 3.16)

project(mediaPlayer VERSION 0.1 LANGUAGES CXX C)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets Multimedia MultimediaWidgets Core Gui)
file(GLOB AI_SOURCES src/ai/*.cpp src/ai/*.h)
file(GLOB UI_SOURCES src/ui/*.cpp src/ui/*.h src/ui/*.ui)
file(GLOB CORE_SOURCES src/core/*.cpp src/core/*.h)
# file(GLOB TEST_FILES tests/*.cpp)
file(GLOB INCLUDE_FILES include/*.h)
file(GLOB WEB_FILES web/py/*.py)


###
#set(Python_INCLUDE_DIRS "C:/Users/23979/AppData/Local/Programs/Python/Python312/include")
###
#set(Python_LIBRARIES "C:/Users/23979/AppData/Local/Programs/Python/Python312/libs/python312.lib")

#python依赖的绝对路径
# set(Python_INCLUDE_DIRS "E:/XYG/mediaplayer-main/mediaplayer-main/Python312/include")
# set(Python_LIBRARIES "E:/XYG/mediaplayer-main/mediaplayer-main/Python312/libs/python312.lib")

# #python依赖的相对路径
set(Python_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/Python312/include")
set(Python_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/Python312/libs/python312.lib")

##
include_directories(${Python_INCLUDE_DIRS})
##
link_directories(${Python_LIBRARIES})


set(PROJECT_SOURCES
    ${AI_SOURCES}
    ${UI_SOURCES}
    ${CORE_SOURCES}
    ${WEB_FILES}
    src/main.cpp
    src/sonic.c
    ${INCLUDE_FILES}
)
set_source_files_properties(src/sonic.c PROPERTIES LANGUAGE C)


# 添加资源文件
SET(RCC_FILES icons.qrc)

#绝对路径
# include_directories("E:/Anaconda/envs/py38/include")
# link_directories("E:/Anaconda/envs/py38/libs")

#相对路径
include_directories("${CMAKE_CURRENT_SOURCE_DIR}/Python312/include")
link_directories("${CMAKE_CURRENT_SOURCE_DIR}/Python312/libs")

qt5_add_resources(qrc_FILES icons.qrc)


# 添加头文件目录（include/ 目录）到编译器的搜索路径中
include_directories(${CMAKE_SOURCE_DIR}/include)



add_executable(mediaPlayer ${PROJECT_SOURCES}
    src/core/decode.h
    src/core/player.h
    src/core/player.cpp
    src/core/player.h src/core/player.cpp
    src/core/glwidget.h src/core/glwidget.cpp
    src/ui/historyitem.cpp src/ui/historyitem.h
    ${qrc_FILES}
    src/core/sumTester.h
)


# 判断操作系统平台
if(WIN32)
    # find_program(FFMPEG_EXECUTABLE NAMES ffmpeg.exe)
    #注意对ffmpeg文件路径的修改


    set(FFMPEG_HOME "${CMAKE_CURRENT_SOURCE_DIR}/ffmpeg-7.1-full_build-shared")


    # 设置 FFmpeg 的头文件目录

    include_directories(${FFMPEG_HOME}/include)
    file(GLOB FFMPEG_LIBRARIES "${FFMPEG_HOME}/lib/*.dll.a")
endif()

target_link_libraries(mediaPlayer PRIVATE Qt5::Widgets Qt5::Multimedia Qt5::MultimediaWidgets Qt5::Core Qt5::Gui ${FFMPEG_LIBRARIES} ${Python_LIBRARIES})

include(GNUInstallDirs)
install(TARGETS mediaPlayer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


