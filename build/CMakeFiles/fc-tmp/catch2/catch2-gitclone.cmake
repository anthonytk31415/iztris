# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/Users/anthonytk/Desktop/coding/repos/iztris/build/CMakeFiles/fc-stamp/catch2/catch2-gitclone-lastrun.txt" AND EXISTS "/Users/anthonytk/Desktop/coding/repos/iztris/build/CMakeFiles/fc-stamp/catch2/catch2-gitinfo.txt" AND
  "/Users/anthonytk/Desktop/coding/repos/iztris/build/CMakeFiles/fc-stamp/catch2/catch2-gitclone-lastrun.txt" IS_NEWER_THAN "/Users/anthonytk/Desktop/coding/repos/iztris/build/CMakeFiles/fc-stamp/catch2/catch2-gitinfo.txt")
  message(VERBOSE
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/Users/anthonytk/Desktop/coding/repos/iztris/build/CMakeFiles/fc-stamp/catch2/catch2-gitclone-lastrun.txt'"
  )
  return()
endif()

# Even at VERBOSE level, we don't want to see the commands executed, but
# enabling them to be shown for DEBUG may be useful to help diagnose problems.
cmake_language(GET_MESSAGE_LOG_LEVEL active_log_level)
if(active_log_level MATCHES "DEBUG|TRACE")
  set(maybe_show_command COMMAND_ECHO STDOUT)
else()
  set(maybe_show_command "")
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/Users/anthonytk/Desktop/coding/repos/iztris/build/_deps/catch2-src"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/Users/anthonytk/Desktop/coding/repos/iztris/build/_deps/catch2-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/opt/homebrew/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/catchorg/Catch2.git" "catch2-src"
    WORKING_DIRECTORY "/Users/anthonytk/Desktop/coding/repos/iztris/build/_deps"
    RESULT_VARIABLE error_code
    ${maybe_show_command}
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(NOTICE "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/catchorg/Catch2.git'")
endif()

execute_process(
  COMMAND "/opt/homebrew/bin/git"
          checkout "v3.0.1" --
  WORKING_DIRECTORY "/Users/anthonytk/Desktop/coding/repos/iztris/build/_deps/catch2-src"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v3.0.1'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/opt/homebrew/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/Users/anthonytk/Desktop/coding/repos/iztris/build/_deps/catch2-src"
    RESULT_VARIABLE error_code
    ${maybe_show_command}
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/Users/anthonytk/Desktop/coding/repos/iztris/build/_deps/catch2-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/Users/anthonytk/Desktop/coding/repos/iztris/build/CMakeFiles/fc-stamp/catch2/catch2-gitinfo.txt" "/Users/anthonytk/Desktop/coding/repos/iztris/build/CMakeFiles/fc-stamp/catch2/catch2-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  ${maybe_show_command}
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/Users/anthonytk/Desktop/coding/repos/iztris/build/CMakeFiles/fc-stamp/catch2/catch2-gitclone-lastrun.txt'")
endif()