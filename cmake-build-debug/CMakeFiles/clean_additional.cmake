# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/paintbrush_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/paintbrush_autogen.dir/ParseCache.txt"
  "paintbrush_autogen"
  )
endif()
