# CMake 最低版本号要求
cmake_minimum_required (VERSION 3.13)

if(CMAKE_SYSTEM_NAME MATCHES "Android")
	set(CMAKE_SYSTEM_VERSION 21)
	set(CMAKE_ANDROID_API 21) 
	set(CMAKE_ANDROID_ARCH_ABI armeabi-v7a)
	set(CMAKE_ANDROID_STL_TYPE gnustl_static)
endif()

# 项目信息
project (gbEngine)
 
#设置模块搜索路径
set (CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/CMake")

#设置编译配置类型
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" )

set(CMAKE_CXX_COMPILER_WORKS "true")

set(CMAKE_C_COMPILER_WORKS "true")

include(common_files)



