find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
)

set(HEADERS
    src/MainWindow.h
)

qt6_add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(MomApp PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets)