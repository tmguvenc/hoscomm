cmake_minimum_required(VERSION 3.1)

project(sender)

FILE(GLOB TARGET_H 							"include/*.h*" "src/*.h*")
FILE(GLOB TARGET_SRC		 				"src/*.c*")

include_directories(include/)
include_directories(${ZEROMQ_INCLUDE})
link_directories(${ZEROMQ_LIBS})
add_executable(${PROJECT_NAME} 	${TARGET_SRC} 
								${TARGET_H} 
								)

target_link_libraries(${PROJECT_NAME} ${ZEROMQ_LINK})