cmake_minimum_required(VERSION 3.11.0)

# sets project name, recommended to be in snake case
# the project name will be also the venv name and will be created in VEN_DIR
# vscode is preconfigured to set python interpreter in VEN_DIR
project(project_template_cplusplus VERSION 0.1.0)
include(FetchContent)

set(FETCHCONTENT_QUIET off)
# make sure CMakeTools are available
# https://github.com/daaguirre/cmake_tools.git
set(DEPS_DIR "$ENV{HOME}/dev/_deps")
set(FETCHCONTENT_BASE_DIR ${DEPS_DIR})
FetchContent_Declare(
  cmake_tools
  GIT_REPOSITORY https://github.com/daaguirre/cmake_tools.git
  GIT_TAG "main"
)
FetchContent_MakeAvailable(cmake_tools)

# get path to directory where all venvs are located 
get_env_var(VAR_NAME VENVS_DIR DEFAULT "$ENV{HOME}/.venv")
# define project's python virtual environment
set(PROJECT_VENV "${VENVS_DIR}/${CMAKE_PROJECT_NAME}")
activate_virtual_env(VENV_PATH ${PROJECT_VENV})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
message("C++ compiler version ${CMAKE_CXX_COMPILER_VERSION}")
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS "10.3.0")
        message(FATAL_ERROR "Insufficient gcc version")
    endif()
endif()

enable_testing()
add_definitions(-DWORKSPACE_DIR="${CMAKE_CURRENT_LIST_DIR}")
add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(apps)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
