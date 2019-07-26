cmake_minimum_required(VERSION 3.0)

project(gSOAP)

if(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
  include("${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
else()
  include(conanbuildinfo.cmake)
endif()
conan_basic_setup(TARGETS)

message("Generate gSOAP from sources at ${GSOAP_PATH}")

# Tools
include(${CMAKE_SOURCE_DIR}/src/soapcpp2.cmake)
include(${CMAKE_SOURCE_DIR}/src/wsdl2h.cmake)

# Libraries
include(${CMAKE_SOURCE_DIR}/src/gsoap.cmake)

install(FILES ${CMAKE_SOURCE_DIR}/${GSOAP_PATH}/gsoap/typemap.dat DESTINATION .)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/${GSOAP_PATH}/gsoap/import DESTINATION .)
