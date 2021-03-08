cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(TestSystem CXX)
add_subdirectory(test)

# add these environment settings to "cmake_vars.txt"
# wxWidgets_ROOT_DIR=d:/install/wx/3.1.4
# wxWidgets_LIB_DIR=d:/install/wx/3.1.4/lib/vc14x_x64_dll
file(STRINGS cmake_vars.txt ConfigContents)
foreach(NameAndValue ${ConfigContents})
  # Strip leading spaces
  string(REGEX REPLACE "^[ ]+" "" NameAndValue ${NameAndValue})
  string(REGEX MATCH "^[^=]+" Name ${NameAndValue})
  string(REPLACE "${Name}=" "" Value ${NameAndValue})
  set(${Name} "${Value}")
endforeach()

file(GLOB_RECURSE test_system_src CONFIGURE_DEPENDS 
	${PROJECT_SOURCE_DIR}/src/*.cpp
	${PROJECT_SOURCE_DIR}/src/*.h
	${PROJECT_SOURCE_DIR}/libs/*.hpp
)

add_executable(${PROJECT_NAME} WIN32 ${test_system_src})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/libs)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/src)

# SET(wxWidgets_ROOT_DIR "d:/install/wx/3.1.4")
# SET(wxWidgets_LIB_DIR "d:/install/wx/3.1.4/lib/vc14x_x64_dll")
SET(wxWidgets_CONFIGURATION "mswu")
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
