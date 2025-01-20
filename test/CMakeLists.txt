include(FetchContent)

FetchContent_Declare(
  ktest
  GIT_REPOSITORY https://github.com/ketexon/ktest
  GIT_TAG main
)

FetchContent_MakeAvailable(ktest)

add_executable(
  KIndTest
  Simple.cpp
)

target_link_libraries(
	KIndTest
	PRIVATE
	KInd
	KTestWithMain
)

set_target_properties(
	KIndTest
	PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
)