cmake_minimum_required(VERSION 2.8.4)
project(P2P)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    include/controller/Controller.hpp
    include/controller/ControllerStrategy.hpp
    include/controller/Events.hpp
    include/utils/EventQueue.hpp
    include/network/protocol/broadcast/BroadcastAllResources.hpp
    include/network/protocol/broadcast/BroadcastMessage.hpp
    include/network/protocol/broadcast/BroadcastResource.hpp
    include/network/protocol/broadcast/BroadcastRevoke.hpp
    include/network/protocol/broadcast/BroadcastRevert.hpp
    include/network/protocol/unicast/UnicastMessage.hpp
    include/network/protocol/unicast/UnicastResource.hpp
    include/network/protocol/unicast/UnicastPartRequest.hpp
    include/network/protocol/unicast/UnicastPart.hpp
    include/network/BroadcastReceiver.hpp
    include/network/BroadcastSender.hpp
    include/network/UnicastReceiver.hpp
    include/network/UnicastSender.hpp
    include/resourcemanager/LocalResource.hpp
    include/resourcemanager/Part.hpp
    include/resourcemanager/DownloadedResource.hpp
    include/resourcemanager/ResourceIdentifier.hpp
    include/resourcemanager/RemoteResource.hpp
    include/resourcemanager/ResourceManager.hpp
    include/resourcemanager/Source.hpp
    include/utils/EventQueue.hpp
    include/utils/Lock.hpp
    include/utils/ScopedLock.hpp
    include/utils/Thread.hpp
    include/utils/Configuration.hpp
    src/controller/Controller.cpp
    src/controller/ControllerStrategy.cpp
    src/controller/Events.cpp
    src/utils/EventQueue.cpp
    src/network/protocol/broadcast/BroadcastResource.cpp
    src/network/protocol/broadcast/BroadcastRevoke.cpp
    src/network/protocol/broadcast/BroadcastRevert.cpp
    src/network/protocol/unicast/UnicastPart.cpp
    src/network/protocol/unicast/UnicastPartRequest.cpp
    src/network/protocol/unicast/UnicastResource.cpp
    src/network/BroadcastReceiver.cpp
    src/network/BroadcastSender.cpp
    src/network/UnicastReceiver.cpp
    src/network/UnicastSender.cpp
    src/network/main.cpp
    src/resourcemanager/LocalResource.cpp
    src/resourcemanager/Part.cpp
    src/resourcemanager/DownloadedResource.cpp
    src/resourcemanager/ResourceIdentifier.cpp
    src/resourcemanager/RemoteResource.cpp
    src/resourcemanager/ResourceManager.cpp
    src/resourcemanager/Source.cpp
    src/utils/Thread.cpp)

add_executable(P2P ${SOURCE_FILES})

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost 1.45.0 COMPONENTS system thread filesystem)

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(P2P ${Boost_LIBRARIES})
endif()

find_package(Threads)
target_link_libraries (P2P ${CMAKE_THREAD_LIBS_INIT})