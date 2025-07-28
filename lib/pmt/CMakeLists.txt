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

########################################################################
# Find dependencies
########################################################################
find_package(Volk REQUIRED)
find_package(Boost REQUIRED)

########################################################################
# Linking dependencies
########################################################################
target_link_libraries(
    gnuradio-pmt
    PUBLIC Boost::boost
    PRIVATE volk)

target_include_directories(
        gnuradio-pmt
        PUBLIC $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../../include>
        PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/)

install(TARGETS gnuradio-pmt LIBRARY DESTINATION lib)
