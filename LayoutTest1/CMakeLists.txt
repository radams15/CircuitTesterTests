cmake_minimum_required(VERSION 3.5)

project(LayoutTest1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(ANDROID)
    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    if (ANDROID_ABI STREQUAL "armeabi-v7a")
        set(ANDROID_EXTRA_LIBS
            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
    endif()
endif()

find_package(QT NAMES Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

if(ANDROID)
  add_library(LayoutTest1
          Arrow.cpp Arrow.h
          SceneItem.cpp SceneItem.h
          Scene.cpp Scene.h
          SceneText.cpp SceneText.h
      main.cpp
          MainWindow.cpp MainWindow.h
          layouttest1.qrc
  )
else()
  add_executable(LayoutTest1
          Arrow.cpp Arrow.h
          SceneItem.cpp SceneItem.h
          Scene.cpp Scene.h
          SceneText.cpp SceneText.h
      main.cpp
          MainWindow.cpp MainWindow.h
          layouttest1.qrc
          Components/Resistor.cpp Components/Resistor.h Components/Component.cpp Components/Component.h Components/Battery.cpp Components/Battery.h)
endif()

target_link_libraries(LayoutTest1 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
