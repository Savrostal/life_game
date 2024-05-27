cmake_minimum_required(VERSION 3.2)
set(PROJECT_NAME LifeGame)
project(${PROJECT_NAME})
add_compile_options(-lncurses)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
set(SRCS
	life.cpp
	check_neighbour.cpp
	count_live_neighbours.cpp
	next_generation.cpp
	cmp_fields.cpp
	get_live_count.cpp
	print.cpp
	init_field.cpp
	copy_field.cpp
)
set(HDRS
	check_neighbour.h
	count_live_neighbours.h
	next_generation.h
	cmp_fields.h
	get_live_count.h
	print.h
	init_field.h
	copy_field.h
	constants.h
)

add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY})
