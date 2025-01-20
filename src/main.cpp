#include <iostream>
#include <string>
#include <vector>

#include "custom_string.h"

int main() {
    kirillidk_containers::string str;

    std::string s;

    std::cout << str.capacity() << std::endl;

    std::cout << str[0] << " " << str[1] << " " << str[15];

    return 0;
}