INCLUDE(FetchContent)

SET(FETCHCONTENT_QUIET OFF)
SET(FETCHCONTENT_UPDATES_DISCONNECTED ON)

# BY DEFAULT SET TO PULL FROM MASTER BRANCH
# TO USE A SPECIFIC COMMIT, SET GIT_TAG TO COMMIT HASH
FetchContent_Declare(
    devue_plugin_core
    GIT_REPOSITORY https://github.com/dvsku/devue_plugin_core.git
    GIT_TAG master
)

FetchContent_MakeAvailable(devue_plugin_core)

SET(DEVUE_PLUGIN_CORE     "${devue_plugin_core_SOURCE_DIR}/core"    PARENT_SCOPE)
SET(DEVUE_PLUGIN_INCLUDES "${devue_plugin_core_SOURCE_DIR}/include" PARENT_SCOPE)
