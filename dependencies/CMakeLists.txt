INCLUDE(FetchContent)

SET(FETCHCONTENT_QUIET                OFF)
SET(FETCHCONTENT_UPDATES_DISCONNECTED  ON)

###############################################################################
## devue_sdk

FetchContent_Declare(
    devue_sdk
    URL https://github.com/dvsku/devue_sdk/archive/d9aa4f994b0a46e6689fab91a9bddedf3a56cc5c.zip
)

FetchContent_MakeAvailable(devue_sdk)
