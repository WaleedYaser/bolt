add_library(bolt)

include(GenerateExportHeader)
generate_export_header(bolt
	EXPORT_FILE_NAME ${CMAKE_CURRENT_SOURCE_DIR}/include/bolt/exports.h
)

target_sources(bolt PRIVATE
	include/bolt/exports.h
	include/bolt/defines.h
	include/bolt/window.h
	src/bolt/winos/window.cpp
)

target_compile_options(bolt PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>: -Werror -Weverything>
	$<$<CXX_COMPILER_ID:GNU>: -Wall -Wextra>
	$<$<CXX_COMPILER_ID:MSVC>: /WX>
)

target_include_directories(bolt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
