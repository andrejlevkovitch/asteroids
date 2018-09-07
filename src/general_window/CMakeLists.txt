# cmake

find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)

set(GENERAL_WINDOW_LIB "g_win")
file(GLOB GENERAL_WINDOW_SRC "include/*.hpp" "sources/*.cpp")
set(LIST_TARGETS "${LIST_TARGETS};${GENERAL_WINDOW_LIB}" CACHE STRING "add_target" FORCE)

add_library(${GENERAL_WINDOW_LIB} ${GENERAL_WINDOW_SRC})

target_link_libraries(${GENERAL_WINDOW_LIB} Qt5::Widgets)

target_include_directories(${GENERAL_WINDOW_LIB} PUBLIC "./include")
target_include_directories(${GENERAL_WINDOW_LIB} PRIVATE "../game/include")
