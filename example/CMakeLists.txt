add_executable(example src/main.cpp)

target_link_libraries(example PRIVATE bolt)

target_compile_options(example PRIVATE
	$<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>: -Werror -Weverything>
	$<$<CXX_COMPILER_ID:GNU>: -Wall -Wextra>
	$<$<CXX_COMPILER_ID:MSVC>: /WX>
)
