CMAKE_MINIMUM_REQUIRED (VERSION 3.8)

FILE(GLOB_RECURSE INCLUDES CONFIGURE_DEPENDS 
	"${CMAKE_SOURCE_DIR}/include/*.hpp"
)

# Change lib name
# Name must begin with dv_plg_
ADD_LIBRARY(dv_plg_template SHARED
	${INCLUDES}
	"devue_plugin.cpp"
)

TARGET_LINK_LIBRARIES(dv_plg_template devue_plugin_core)

TARGET_INCLUDE_DIRECTORIES(dv_plg_template PRIVATE "${PLUGINS_LIB_DIR}")
TARGET_INCLUDE_DIRECTORIES(dv_plg_template PRIVATE "${PLUGINS_LIB_DIR}/glm")