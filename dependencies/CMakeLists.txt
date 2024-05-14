INCLUDE(FetchContent)

SET(FETCHCONTENT_QUIET                OFF)
SET(FETCHCONTENT_UPDATES_DISCONNECTED  ON)

###############################################################################
## devue_plugin_core

FetchContent_Declare(
    devue_plugin_core
    URL https://github.com/dvsku/devue_plugin_core/archive/refs/heads/master.zip
)

FetchContent_MakeAvailable(devue_plugin_core)

SET(DEVUE_PLUGIN_CORE     "${devue_plugin_core_SOURCE_DIR}/core"    PARENT_SCOPE)
SET(DEVUE_PLUGIN_INCLUDES "${devue_plugin_core_SOURCE_DIR}/include" PARENT_SCOPE)
