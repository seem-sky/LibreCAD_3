CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)
PROJECT (LC)

option(WITH_UNITTESTS "Build unit tests" ON)
option(WITH_LCDXFDWG "Build dxf/dwg support" ON)

if(WITH_LCDXFDWG)
endif(WITH_LCDXFDWG)

ADD_SUBDIRECTORY("lckernel")
ADD_SUBDIRECTORY("lcDXFDWG")
add_definitions(-DUSE_lcDXFDWG=1)

ADD_SUBDIRECTORY("lcviewernoqt")
ADD_SUBDIRECTORY("lcviewerqt")
ADD_SUBDIRECTORY("lcadluascript")
ADD_SUBDIRECTORY("lcUI")
ADD_SUBDIRECTORY("luacmdinterface")

if(WITH_UNITTESTS)
    ADD_SUBDIRECTORY("unittest")
endif()
