cmake -B build -DCMAKE_TOOLCHAIN_FILE=./toolchain/arm_toolchain.cmake
cd build
make clean
make
