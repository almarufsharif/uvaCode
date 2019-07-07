#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::string str;
    while(std::cin >> str) {
        if ( str[0] == '#') break;

        if (std::next_permutation(str.begin(), str.end()))
            std::cout << str << std::endl;
        else std::cout << "No Successor" << std::endl;
    }

    return 0;
}
