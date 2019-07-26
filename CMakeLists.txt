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
include(${CMAKE_CURRENT_SOURCE_DIR}/src/soapcpp2.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/src/wsdl2h.cmake)

# Libraries
include(${CMAKE_CURRENT_SOURCE_DIR}/src/gsoap.cmake)

install(FILES ${GSOAP_PATH}/gsoap/typemap.dat DESTINATION /)
install(DIRECTORY ${GSOAP_PATH}/gsoap/import DESTINATION /)
