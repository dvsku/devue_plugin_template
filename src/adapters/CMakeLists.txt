CMAKE_MINIMUM_REQUIRED (VERSION 3.8)

FILE(GLOB_RECURSE INCLUDES CONFIGURE_DEPENDS 
	"${CMAKE_SOURCE_DIR}/include/*.hpp"
)

ADD_LIBRARY(dv_plg_tex_adapter STATIC
	${INCLUDES}
	"dv_plugin_adapter.cpp"
	"dv_texture_plugin_adapter.cpp"
	"dv_model_plugin_adapter.cpp"
)

TARGET_INCLUDE_DIRECTORIES(dv_plg_tex_adapter PRIVATE "${PLUGINS_LIB_DIR}/glm")