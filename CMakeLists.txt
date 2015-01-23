cmake_minimum_required(VERSION 2.8.4)
project(P2P)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/network/protocol/broadcast/BroadcastAllResources.hpp
    include/network/protocol/broadcast/BroadcastMessage.hpp
    include/network/protocol/broadcast/BroadcastResource.hpp
    include/network/protocol/broadcast/BroadcastRevoke.hpp
    include/network/protocol/unicast/UnicastMessage.hpp
    include/network/protocol/unicast/UnicastRequest.hpp
    include/network/protocol/unicast/UnicastConfirmation.hpp
    include/network/protocol/unicast/UnicastPartRequest.hpp
    include/network/protocol/unicast/UnicastPart.hpp
    include/network/BroadcastReceiver.hpp
    include/network/BroadcastSender.hpp
    include/network/UnicastReceiver.hpp
    include/network/UnicastSender.hpp
    include/utils/Lock.hpp
    include/utils/ScopedLock.hpp
    include/utils/SynchronizedQueue.hpp
    include/utils/Thread.hpp
    src/network/BroadcastReceiver.cpp
    src/network/BroadcastSender.cpp
    src/network/UnicastReceiver.cpp
    src/network/UnicastSender.cpp
    src/network/main.cpp
    src/utils/Thread.cpp)

add_executable(P2P ${SOURCE_FILES})

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost 1.45.0 COMPONENTS system thread)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(P2P ${Boost_LIBRARIES})
endif()

find_package(Threads)
target_link_libraries (P2P ${CMAKE_THREAD_LIBS_INIT})