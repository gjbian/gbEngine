# CMake 最低版本要求
cmake_minimum_required (VERSION 3.13)

include(cmake_lib)

add_definitions(-std=c++11)

# 公共头文件
file(GLOB_RECURSE SOURCE_CODE_FILES ${PROJECT_SOURCE_DIR}/gbEngine/*.h ${PROJECT_SOURCE_DIR}/gbEngine/*.cpp)

# 创建分组
set(DIR_GROUP "")
make_source_group(SOURCE_CODE_FILES DIR_GROUP)

# 设置目标
if(APPLE)
add_library(gbEngineNative STATIC
${SOURCE_CODE_FILES}
)
else()

set(CMAKE_BUILD_TYPE "Release")
set(CMAKE_CXX_FLAGS_REALEASE "${CMAKE_C_FLAGS_RELEASE} -s -O3")

if (CMAKE_SYSTEM_NAME MATCHES "Android")
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfpu=neon")
	add_definitions(-DARM)
endif()

# add_library(libGbEngine SHARED ${SOURCE_CODE_FILES})

add_executable(libGbEngine ${SOURCE_CODE_FILES})

endif()

set_target_properties(libGbEngine PROPERTIES LINKER_LANGUAGE CXX)

# 添加头文件
foreach (FILE ${DIR_GROUP})
	target_include_directories(libGbEngine PUBLIC ${PROJECT_SOURCE_DIR}/${FILE})
endforeach()

set_property(DIRECTORY ${PROJECT_SOURCE_DIR}/build PROPERTY VS_STARTUP_PROJECT libGbEngine)

