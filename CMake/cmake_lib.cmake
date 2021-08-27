# CMake ��Ͱ汾Ҫ��
cmake_minimum_required (VERSION 3.13)

# ȫ�ֺ�������
function (make_source_group arg DIR_GROUP)
	
	set(DIR_GROUP "")

	foreach (FILE ${${arg}})
		get_filename_component(PARENT_DIR "${FILE}" DIRECTORY)
		string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
		
		if (WIN32)
			string(REPLACE "/" "\\" GROUP "${GROUP}")
		endif()

		set(DIR_GROUP ${DIR_GROUP} ${GROUP})

		if ("${FILE}" MATCHES ".*\\.cpp")
			set(GROUP "Source Files${GROUP}")
		elseif("${FILE}" MATCHES ".*\\.hpp")
			set(GROUP "Source Files${GROUP}")
		elseif("${FILE}" MATCHES ".*\\.c")
			set(GROUP "Source Files${GROUP}")
		elseif("${FILE}" MATCHES ".*\\.h")
			set(GROUP "Source Files${GROUP}")
		endif()

		source_group("${GROUP}" FILES "${FILE}")
	endforeach()
	
	
	list(REMOVE_DUPLICATES DIR_GROUP)
	set(DIR_GROUP ${DIR_GROUP} PARENT_SCOPE)

endfunction()


function(get_subdir_list curdir SUBDIRS)
	message(${curdir})
	FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
	SET(dirlist "")
	FOREACH(child ${children})
		IF(IS_DIRECTORY ${curdir}/${child})
			LIST(APPEND dirlist ${child})
		ENDIF()
	ENDFOREACH()
	SET(SUBDIRS ${dirlist} PARENT_SCOPE)
endfunction()
