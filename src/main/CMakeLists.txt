# cmake

find_package(Qt5Widgets REQUIRED)

set(MAIN_SRC "main.cpp")

add_executable(${PROJECT_NAME} ${MAIN_SRC})

foreach(SOME_TARGET ${LIST_TARGETS})
  target_link_libraries(${PROJECT_NAME} ${SOME_TARGET})
endforeach()

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
