MESSAGE(STATUS "CMAKE_CURRENT_SOURCE_DIR" ${CMAKE_CURRENT_SOURCE_DIR})

SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

AUX_SOURCE_DIRECTORY(. PROTOCOL_SRC)
ADD_LIBRARY(protocol STATIC ${PROTOCOL_SRC}) 
