# APPS
SET(app_name app1)
SET(${app_name}_sources
        main.cpp
        app1.h
        app1.cpp
)

generate_cpp_sources(FILES ${${app_name}_sources})

add_executable(${app_name} ${${app_name}_sources})

# target_link_libraries(${app_name} 
#     VisualPerception
# )

