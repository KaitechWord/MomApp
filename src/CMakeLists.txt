find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/EmployeesTab.cpp
    src/TabsWidget.cpp
    src/AddEmployeePopup.cpp
)

set(HEADERS
    src/MainWindow.h
    src/EmployeesTab.h
    src/TabsWidget.h
    src/AddEmployeePopup.h
    src/Employee.h
)

qt6_add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(MomApp PRIVATE 
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets)