#include <iostream>
#include <map>
#include <string>

int main()
{
    int m, n;
    std::cin >> m >> n;
    std::map<std::string, int> mapp;
    std::string str;
    int num;
    for(int i = 0; i < m; i++){
        std::cin >> str >> num;
        mapp.insert(std::make_pair(str, num));
    }
    long long sum;
    for(int i = 0; i < n; i++) {
            sum = 0;
        while(std::cin >> str) {
            if (str[0] == '.') break;
            sum += mapp[str];
        }

        std::cout << sum << std::endl;
    }

    return 0;
}
