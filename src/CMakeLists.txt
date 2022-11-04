set(lib_name ProjectName)

set(${lib_name}_sources
    project_name/project.h
    project_name/project.cpp
    project_name/test.h
    project_name/test.cpp
)

generate_cpp_sources(FILES ${${lib_name}_sources})

# find_package(Eigen3 3.3 REQUIRED NO_MODULE)
# find_package(OpenCV REQUIRED)
# find_package(PCL 1.12.1 REQUIRED COMPONENTS visualization)

# add_definitions(${PCL_DEFINITIONS})
add_library(${lib_name} ${${lib_name}_sources})

target_include_directories(${lib_name} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
) 

# target_link_libraries(${lib_name} 
#     Eigen3::Eigen
#     ${OpenCV_LIBS}
#     ${PCL_LIBRARIES}
# )
