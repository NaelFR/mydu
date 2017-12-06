cmake_minimum_required(VERSION 3.8)
project(mydu)

set(CMAKE_CXX_STANDARD 11)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} lboost_system -lboost_filesystem")

FIND_PACKAGE( Boost 1.65.1 COMPONENTS program_options system filesystem REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

ADD_EXECUTABLE( mydu main.cpp )

if (LINUX)
    configure_file(${OpenMW_SOURCE_DIR}/files/plugins.cfg.linux
            "${OpenMW_BINARY_DIR}/plugins.cfg")
endif (LINUX)

TARGET_LINK_LIBRARIES( mydu LINK_PUBLIC ${Boost_LIBRARIES} )

# set(SOURCE_FILES main.cpp)
# add_executable(mydu ${SOURCE_FILES})