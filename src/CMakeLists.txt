find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt6_standard_project_setup()

qt6_add_executable(MomApp
    src/main.cpp
)

target_link_libraries(MomApp PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets)