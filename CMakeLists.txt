cmake_minimum_required(VERSION 3.1.4)
project(c_ci_sample VERSION 0.1.0)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(c_ci_sample src/main.cpp)

target_link_libraries(c_ci_sample gtest pthread gtest_main)
add_test(NAME example_test COMMAND c_ci_sample)
