# Copyright 2013 Free Software Foundation, Inc.
#
# This file is part of GNU Radio
#
# SPDX-License-Identifier: GPL-3.0-or-later
#

# Create a version.h with the project version
configure_file(version.h.in
        version.h)
# Install version.h in include/gnuradio
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/version.h
        DESTINATION ${GR_INCLUDE_DIR}/gnuradio)
########################################################################
# Install header files
########################################################################
install(
        FILES api.h
        attributes.h
        DESTINATION ${GR_INCLUDE_DIR}/gnuradio)