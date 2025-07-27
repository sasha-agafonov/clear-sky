cmake_minimum_required(VERSION 3.16)
project(World LANGUAGES CXX)

if(NOT WIN32)
  message(FATAL_ERROR "Windows only")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 6.9 REQUIRED COMPONENTS Core Gui Widgets OpenGL OpenGLWidgets)

set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

set(SRC
    ${SRC_DIR}/world/aero.cpp
    ${SRC_DIR}/world/cloud.cpp
    ${SRC_DIR}/world/contrail.cpp
    ${SRC_DIR}/world/fence.cpp
    ${SRC_DIR}/world/house.cpp
    ${SRC_DIR}/world/icosahedron.cpp
    ${SRC_DIR}/world/pine.cpp
    ${SRC_DIR}/world/shape.cpp
    ${SRC_DIR}/world/simple_shape.cpp
    ${SRC_DIR}/world/turbo.cpp

    ${SRC_DIR}/main/main.cpp

    ${SRC_DIR}/widgets/world_widget.cpp
    ${SRC_DIR}/widgets/gui.cpp
)

set(HDR
    ${SRC_DIR}/world/aero.hpp
    ${SRC_DIR}/world/cloud.hpp
    ${SRC_DIR}/world/contrail.hpp
    ${SRC_DIR}/world/fence.hpp
    ${SRC_DIR}/world/house.hpp
    ${SRC_DIR}/world/icosahedron.hpp
    ${SRC_DIR}/world/pine.hpp
    ${SRC_DIR}/world/shape.hpp
    ${SRC_DIR}/world/simple_shape.hpp
    ${SRC_DIR}/world/turbo.hpp

    ${SRC_DIR}/utilities/materials.hpp

    ${SRC_DIR}/widgets/world_widget.hpp
    ${SRC_DIR}/widgets/gui.hpp
)

qt_add_executable(World WIN32 ${SRC} ${HDR})

target_include_directories(World PRIVATE ${SRC_DIR})

target_link_libraries(World PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::OpenGL Qt6::OpenGLWidgets opengl32 glu32)

source_group(TREE ${SRC_DIR} FILES ${SRC} ${HDR})
