#include <iostream>
#include <map>
#include <string>

int main()
{
    int testCase, comfort, dayNeed, dayToComplete;
    std::string str;
    std::map<std::string, int> m;

    std::cin >> testCase;
    for(int tc = 1; tc <= testCase; tc++) {
        std::cin >> comfort;
        for(int i = 0; i < comfort; i++) {
            std::cin >> str >> dayNeed;
            m.insert(std::make_pair(str, dayNeed));
        }
        std::cin >> dayToComplete;
        std::cin >> str;
        int v = m[str];

        if(!v) std::cout << "Case " << tc << ": Do your own homework!" << std::endl;
        else if (v <= dayToComplete) std::cout << "Case " << tc << ": Yesss" << std::endl;
        else if (v <= dayToComplete + 5) std::cout << "Case " << tc << ": Late" << std::endl;
        else std::cout << "Case " << tc << ": Do your own homework!" << std::endl;
        m.clear();
    }
}
