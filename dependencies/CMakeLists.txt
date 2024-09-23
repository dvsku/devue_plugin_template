INCLUDE(FetchContent)

SET(FETCHCONTENT_QUIET                OFF)
SET(FETCHCONTENT_UPDATES_DISCONNECTED  ON)

###############################################################################
## devue_sdk

FetchContent_Declare(
    devue_sdk
    URL https://github.com/dvsku/devue_sdk/archive/ac3f30cad8ec2de130d6880e4e2f70e243fc10e9.zip
)

FetchContent_MakeAvailable(devue_sdk)
