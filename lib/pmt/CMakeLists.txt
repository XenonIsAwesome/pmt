# Copyright 2010-2013,2018-2019 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

add_library(
        gnuradio-pmt
        ${CMAKE_CURRENT_SOURCE_DIR}/pmt_unv.cc ${CMAKE_CURRENT_SOURCE_DIR}/pmt.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/pmt_io.cc ${CMAKE_CURRENT_SOURCE_DIR}/pmt_pool.cc
        ${CMAKE_CURRENT_SOURCE_DIR}/pmt_serialize.cc)

find_package(Volk QUIET)
if (Volk_FOUND)
else()
    message(STATUS "Fetching Volk")

    set(ENABLE_VOLK_PYTHON OFF CACHE BOOL "" FORCE)

    include(FetchContent)
    FetchContent_Declare(
        Volk
        GIT_SUBMODULES_RECURSE TRUE
        GIT_REPOSITORY https://github.com/gnuradio/volk.git
    )
    FetchContent_MakeAvailable(Volk)
endif(Volk_FOUND)

find_package(Boost REQUIRED)

target_link_libraries(
    gnuradio-pmt
    PUBLIC Boost::boost
    PUBLIC Volk::volk)

target_include_directories(
        gnuradio-pmt
        PUBLIC $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/)

install(TARGETS gnuradio-pmt
        LIBRARY DESTINATION lib)
