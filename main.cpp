#include <iostream>
#include "include/1004.hpp"

int main() {
    std::vector<int> v1004 = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    std::cout << longestOnes(v1004, 3) << std::endl;
    return 0;
}
