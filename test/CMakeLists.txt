
include(CTest)

#set (GTEST_ROOT d:\\install\\googletest)
#set (GTEST_INCLUDE_DIR d:\\install\\googletest\\googletest\\include)
find_package(GTest REQUIRED)

file(GLOB_RECURSE tests_src CONFIGURE_DEPENDS 
	${PROJECT_SOURCE_DIR}/test/*.cpp
	${PROJECT_SOURCE_DIR}/test/*.h
)
add_executable(alltests ${tests_src})
target_link_libraries(alltests GTest::gtest GTest::gtest_main)
add_test(Name RunAllTests Command alltests)