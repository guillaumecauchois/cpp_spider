cmake_minimum_required(VERSION 3.5.1)
project(cpp_spider)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES_COMMON
        src/common/Event.cpp
        src/common/EventFactory.cpp
        src/common/FileManager.cpp
        src/common/MouseButton.cpp
        src/common/Position.cpp
        src/common/Process.cpp
        src/common/SpiderException.cpp
        #src/common/TcpConnection.cpp
        src/common/SpiderSession.cpp)

set(SOURCE_FILES_SERVER
        # src/server/DecryptManager.cpp
        src/server/EventBeautifuler.cpp
        src/server/Log.cpp
        src/server/main.cpp
        # src/server/ServerCommand.cpp
        src/server/ServerCore.cpp
        )

set(HEADER_FILES_SERVER
        # inc/server/DecryptManager.hpp
        inc/server/EventBeautifuler.hpp
        inc/server/Log.hpp
        inc/server/ServerCommand.hpp
        inc/server/ServerCore.hpp
        )

set(HEADER_FILES_COMMON
        inc/common/Event.hpp
        inc/common/EventFactory.hpp
        inc/common/EventType.hpp
        inc/common/Process.hpp
        inc/common/Position.hpp
        inc/common/FileManager.hpp
        # inc/common/ICryptoManager.hpp
        inc/common/MouseButton.hpp
        inc/common/Position.hpp
        inc/common/Process.hpp
        inc/common/SerializeHandler.hpp
        inc/common/SpiderException.hpp
        inc/common/TcpConnection.hpp
        inc/common/SpiderSession.hpp)

include_directories("inc/common")
include_directories("inc/server")

set(CMAKE_CXX_FLAGS "-g")

add_executable(spider ${SOURCE_FILES_SERVER} ${HEADER_FILES_SERVER} ${SOURCE_FILES_COMMON} ${HEADER_FILES_COMMON})
set(Boost_USE_STATIC_LIBS       ON) # only find static libs
set(Boost_USE_MULTITHREADED     ON)
set(Boost_USE_STATIC_RUNTIME    OFF)

find_package(Boost 1.65.1 COMPONENTS date_time filesystem system thread serialization)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(spider  ${Boost_LIBRARIES})
endif()

find_package(Threads)
if (Threads_FOUND)
    target_link_libraries(spider ${CMAKE_THREAD_LIBS_INIT})
endif()
