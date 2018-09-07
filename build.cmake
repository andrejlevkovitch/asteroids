# build.cmake

IF(NOT CMAKE_BUILD_TYPE)
  SET(CMAKE_BUILD_TYPE Release)
ENDIF(NOT CMAKE_BUILD_TYPE)

enable_testing()
include(CTest)

option(leak_check "set leak_check" 0)
option(profiling "set profiling" 0)

if(${CMAKE_BUILD_TYPE} STREQUAL Debug AND leak_check)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
  message(STATUS "Leack check ON")
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL Debug AND profiling)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -pg")
  set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} -pg")
  set(CMAKE_SHARED_LINKER_FLAGS_DEBUG "${CMAKE_SHARED_LINKER_FLAGS_DEBUG} -pg")
  message(STATUS "Profiling ON")
endif()

message(STATUS "buid type    " ${CMAKE_BUILD_TYPE})
message(STATUS "Project      " ${PROJECT_NAME})
message(STATUS "c compiler   " ${CMAKE_C_COMPILER})
message(STATUS "cxx compiler " ${CMAKE_CXX_COMPILER})
message(STATUS "build tests  " ${BUILD_TESTING})
message(STATUS "build shared " ${BUILD_SHARED_LIBS})

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")

foreach(DIR ${LIST_SUBDIRS})
  add_subdirectory("src/${DIR}")
endforeach()
