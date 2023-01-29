#include <iostream>
#include <gtest/gtest.h>

// int main(int, char**) {
//     std::cout << "Hello, world!\n";
// }

TEST(HelloTest, test) {
    EXPECT_EQ(1, 1);
}