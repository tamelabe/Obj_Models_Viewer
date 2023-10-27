cmake_minimum_required(VERSION 3.5)

project(3DViewer VERSION 2.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_FLAGS  "-std=c++17 -O2 -Wall")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets OpenGLWidgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets OpenGLWidgets)
add_subdirectory(resources/GIFCreation)

set(MACOSX_BUNDLE_ICON_FILE viewer.icns)
set(app_icon_macos "${CMAKE_CURRENT_SOURCE_DIR}/viewer.icns")
set_source_files_properties(${app_icon_macos} PROPERTIES
        MACOSX_PACKAGE_LOCATION "resources")

set(PROJECT_SOURCES
        main.cc
        model/model.h
        model/model.cc
        model/opening/parser.h
        model/opening/parser.cc
        model/opening/normalizer.cc
        model/opening/normalizer.h
        model/processing/base_movement.cc
        model/processing/base_movement.h
        model/processing/transformer.h
        controller/controller.h
        view/mainwindow.cc
        view/mainwindow.h
        view/mainwindow.ui
        view/widgets/widget_settings.cc
        view/widgets/widget_settings.h
        view/widgets/widget_settings.ui
        view/widgets/widget_info.cc
        view/widgets/widget_info.h
        view/widgets/widget_info.ui
        view/widgets/widget_actions.cc
        view/widgets/widget_actions.h
        view/widgets/widget_actions.ui
        view/widgets/widget_view_settings.cc
        view/widgets/widget_view_settings.h
        view/widgets/widget_view_settings.ui
        view/render/ogl_render.cc
        view/render/ogl_render.h
        helpers/data_objects.h
        helpers/view_data_objects.h
        resource.qrc
        ${app_icon_macos}
        )

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(3DViewer
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET 3DViewer APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(3DViewer SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(3DViewer
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(3DViewer PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                                       Qt${QT_VERSION_MAJOR}::Core
                                       Qt${QT_VERSION_MAJOR}::Gui
                                       Qt${QT_VERSION_MAJOR}::OpenGLWidgets GIFLIB)

set_target_properties(3DViewer PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(3DViewer)
endif()
