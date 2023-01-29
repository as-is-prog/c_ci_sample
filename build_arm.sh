cmake -B build_arm -DCMAKE_TOOLCHAIN_FILE=./toolchain/arm_toolchain.cmake
cd build_arm
make
