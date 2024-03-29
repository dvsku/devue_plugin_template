﻿CMAKE_MINIMUM_REQUIRED (VERSION 3.8)

PROJECT(plugins CXX)

SET(PLUGIN_LIB_DIR	   "${CMAKE_SOURCE_DIR}/lib")
SET(PLUGIN_SOURCE_DIR  "${CMAKE_SOURCE_DIR}/src")

FILE(GLOB_RECURSE PLUGIN_CORE CONFIGURE_DEPENDS 
	"${PLUGIN_CORE_DIR}/*.cpp"
)

IF(WIN32 AND "${CMAKE_SIZEOF_VOID_P}" STREQUAL "8")
	ENABLE_LANGUAGE("RC")

    SET(OUTPUT_DIR "binaries/windows/${CMAKE_CXX_COMPILER_ID}/${CMAKE_BUILD_TYPE}")
    STRING(TOLOWER ${OUTPUT_DIR} OUTPUT_DIR_LOWER)

    SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/${OUTPUT_DIR_LOWER}")
    SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/${OUTPUT_DIR_LOWER}")
    SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/${OUTPUT_DIR_LOWER}")

	IF (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
	    ADD_DEFINITIONS(-D_WINDOWS)
	
	    SET(CMAKE_C_FLAGS			"/W3 /utf-8")
	    SET(CMAKE_C_FLAGS_DEBUG		"/MTd /Od /Ob0 /RTC1 /Zi")
	    SET(CMAKE_C_FLAGS_RELEASE	"/MT /O2 /Ob2 /GL /DNDEBUG")
	
	    SET(CMAKE_CXX_FLAGS			"/std:c++20 /W3 /EHsc /utf-8 /we4297")
	    SET(CMAKE_CXX_FLAGS_DEBUG	"/MTd /Od /Ob0 /RTC1 /Zi")
	    SET(CMAKE_CXX_FLAGS_RELEASE	"/MT /O2 /Ob2 /GL /DNDEBUG")
	
	    IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
	        ADD_LINK_OPTIONS("/DEBUG")
	    ELSEIF(CMAKE_BUILD_TYPE STREQUAL "Release")
	        ADD_LINK_OPTIONS("/LTCG")
	    ENDIF()
	ENDIF()

	ADD_SUBDIRECTORY("dependencies")
    ADD_SUBDIRECTORY("src")
ENDIF()