MESSAGE(STATUS "CMAKE_CURRENT_SOURCE_DIR" ${CMAKE_CURRENT_SOURCE_DIR})
#设置编译好程序存放路径
INCLUDE_DIRECTORIES(
    ${CMAKE_CURRENT_SOURCE_DIR}
)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../run)
AUX_SOURCE_DIRECTORY(. SRC)
ADD_EXECUTABLE(my_test ${SRC})
TARGET_LINK_LIBRARIES(my_test ${STATIC_LIBS} ${DYN_LIBS})
TARGET_LINK_LIBRARIES(my_test ${STATIC_LIBS} ${DYN_LIBS})

