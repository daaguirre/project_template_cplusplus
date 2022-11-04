add_definitions(-DRESOURCES_DIR_PATH="${CMAKE_CURRENT_LIST_DIR}/resources")

SET(app_name ProjectTests)

SET(${app_name}_sources
    test_base.h
    test_base.cpp
    project_name/project_test.h
    project_name/project_test.cpp
)

generate_cpp_sources(FILES ${${app_name}_sources})

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_CURRENT_BINARY_DIR})

# Test dependencies
conan_cmake_configure(
    REQUIRES 
    gtest/1.12.1
    GENERATORS cmake_find_package)
conan_cmake_autodetect(settings)
conan_cmake_install(PATH_OR_REFERENCE .
                    BUILD missing
                    REMOTE conancenter
                    SETTINGS ${settings})
find_package(GTest)

add_executable(${app_name} ${${app_name}_sources})

target_include_directories(${app_name} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
) 

target_link_libraries(${app_name}
  GTest::gtest_main
  ProjectName
)

add_test(project_name_gtest ${app_name})


include(GoogleTest)
gtest_discover_tests(${app_name})
