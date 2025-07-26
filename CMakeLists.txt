# Copyright 2013,2019 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#
cmake_minimum_required(VERSION 3.20)
project(pmt)

set(CMAKE_CXX_STANDARD 20)

SET(PMT_LIBRARY_DIR     lib${LIB_SUFFIX} CACHE PATH "Path to install libraries")
SET(GR_INCLUDE_DIR     include CACHE PATH "Path to install gnuradio header files")
SET(PMT_INCLUDE_DIR     include CACHE PATH "Path to install pmt header files")
SET(PMT_CMAKE_DIR       ${CMAKE_MODULES_DIR}/pmt)
SET(PMT_DATA_DIR        share CACHE PATH "Base location for data")
SET(PMT_PKG_DATA_DIR    ${PMT_DATA_DIR}/${CMAKE_PROJECT_NAME} CACHE PATH "Path to install package data")
SET(PMT_EXAMPLES_DIR    ${PMT_PKG_DATA_DIR}/examples CACHE PATH "Path to install PMT examples")

########################################################################
# Add subdirectories
########################################################################
add_subdirectory(include)
add_subdirectory(lib)

if(ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif()

install(TARGETS gnuradio-pmt
        EXPORT gnuradio-pmtTargets
        LIBRARY DESTINATION lib)

include(CMakePackageConfigHelpers)

# Generate version file
write_basic_package_version_file(
        "${CMAKE_CURRENT_BINARY_DIR}/gnuradio-pmtConfigVersion.cmake"
        VERSION 1.0.0
        COMPATIBILITY AnyNewerVersion
)

# Create the config file for find_package()
configure_package_config_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/gnuradio-pmtConfig.cmake.in"
        "${CMAKE_CURRENT_BINARY_DIR}/gnuradio-pmtConfig.cmake"
        INSTALL_DESTINATION lib/cmake/gnuradio-pmt
)

# Install both
install(FILES
        "${CMAKE_CURRENT_BINARY_DIR}/gnuradio-pmtConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/gnuradio-pmtConfigVersion.cmake"
        DESTINATION lib/cmake/gnuradio-pmt
)

# Install the target export file
install(EXPORT gnuradio-pmtTargets
        FILE gnuradio-pmtTargets.cmake
        NAMESPACE gnuradio::
        DESTINATION lib/cmake/gnuradio-pmt
)
