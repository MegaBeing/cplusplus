# Created by the script cgal_create_cmake_script
# This is the CMake script for compiling a CGAL application.

cmake_minimum_required(VERSION 3.1...3.23)
project( Distributed_computing )

find_package(CGAL REQUIRED QUIET OPTIONAL_COMPONENTS Core )

create_single_source_cgal_program( "test.cpp" )

