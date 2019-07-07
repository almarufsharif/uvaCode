#include <iostream>
#include <map>
#include <string>
std::string name[15];
int arr[15];

int main()
{
    int group, amount, people, rate;
    std::map<std::string, int> m;
    std::string str, ppl;
    int f = 0;
    while(std::cin >> group) {
        std::fill(arr, arr + group, 0);
        for(int i = 0; i < group; i++) {
            std::cin >> name[i];
            m.insert(std::make_pair(name[i], m.size()));
        }

        for(int i = 0; i < group; i++) {
            std::cin >> str >> amount >> people;
            if(people == 0) rate = amount ;
            else rate = amount / people;
            for(int j = 0; j < people; j++) {
                std::cin >> ppl;
                arr[m[ppl]] += rate;
                arr[m[str]] -= rate;
            }
        }
        m.clear();
        if(f) std::cout << std::endl;
        for(int i = 0; i < group; i++) {
            std::cout << name[i] << " " << arr[i] << std::endl;
        }
        f = 1;
    }

    return 0;
}
