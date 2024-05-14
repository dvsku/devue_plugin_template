#pragma once

#define PLG_TO_STRING_1(s) #s
#define PLG_TO_STRING_2(s) PLG_TO_STRING_1(s)

#define PLG_NAME         "devue plugin template"
#define PLG_AUTHOR       "Nikola Stojsin"
#define PLG_VERSION_MAJOR 1
#define PLG_VERSION_MINOR 0
#define PLG_VERSION_REV   0

#define PLG_VERSION     PLG_VERSION_MAJOR, PLG_VERSION_MINOR, PLG_VERSION_REV, 0
#define PLG_VERSION_STR PLG_TO_STRING_2(PLG_VERSION_MAJOR) "." PLG_TO_STRING_2(PLG_VERSION_MINOR) "." PLG_TO_STRING_2(PLG_VERSION_REV) ".0"
#define PLG_COPYRIGHT   "Copyright (C) " PLG_AUTHOR
