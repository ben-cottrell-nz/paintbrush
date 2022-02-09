cmake_minimum_required(VERSION 3.21)
project(paintbrush)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(paintbrush main.cpp mainwindow.cpp mainwindow.h toolbar.cpp toolbar.h resources.qrc canvas.cpp colorpalette.cpp colorpalette.h)
target_link_libraries(paintbrush
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

