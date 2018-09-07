# cmake

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)

set(GAME_LIB "game")
file(GLOB GAME_SRC "include/*.hpp" "sources/*.cpp")

set(LIST_TARGETS "${LIST_TARGETS};${GAME_LIB}" CACHE STRING "add_target" FORCE)

add_library(${GAME_LIB} ${GAME_SRC})

target_link_libraries(${GAME_LIB} Qt5::Widgets)

target_include_directories(${GAME_LIB} PUBLIC "./include")

if(BUILD_TESTING)
  find_package(Boost COMPONENTS unit_test_framework)
  if(Boost_FOUND)
    set(BOOST_TEST_GAME "boost_game_test")
    set(BOOST_TEST_SRC "test/boost_game_test.cpp")

    add_executable(${BOOST_TEST_GAME} ${BOOST_TEST_SRC})

    target_link_libraries(${BOOST_TEST_GAME} ${GAME_LIB} ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

    add_test(NAME ${BOOST_TEST_GAME} COMMAND ${BOOST_TEST_GAME})
  else()
    message(STATUS "for testing Boost required")
  endif()
endif()
