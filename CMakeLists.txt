cmake_minimum_required(VERSION 3.0)

project(limonp
        LANGUAGES CXX)

################
# cmake config #
################

set(CMAKE_CXX_STANDARD 11 CACHE STRING "C++ Standard")
set(CMAKE_CXX_STANDARD_REQUIRED ON CACHE BOOL "")
set(CMAKE_CXX_EXTENSIONS OFF ON CACHE BOOL "")

option(BUILD_TESTING "Build Testing" OFF)

##########
# target #
##########

add_library(${PROJECT_NAME} INTERFACE)
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
                           INTERFACE
                               $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
                               $<INSTALL_INTERFACE:${CMAKE_INSTALL_FULL_INCLUDEDIR}>)

# IF(APPLE) # Mac OS
#     target_compile_options(${PROJECT_NAME} INTERFACE -std=c++0x)
# endif()

if(BUILD_TESTING)
    include(CTest)
    enable_testing()
    add_subdirectory(test)
    add_test(NAME test/test.run COMMAND test/test.run)
    add_test(NAME test/demo COMMAND test/demo)
    add_test(NAME test/thread_pool_demo COMMAND test/thread_pool_demo)
endif()

###########
# install #
###########

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
        EXPORT ${PROJECT_NAME})

install(EXPORT ${PROJECT_NAME}
        DESTINATION ${CMAKE_INSTALL_DATADIR}/${PROJECT_NAME}/cmake/
        NAMESPACE ${PROJECT_NAME}::
        FILE ${PROJECT_NAME}-config.cmake)

install(DIRECTORY include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
