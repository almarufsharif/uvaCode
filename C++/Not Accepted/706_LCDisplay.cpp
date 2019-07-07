#include <iostream>
#include <sstream>
#include <string>

std::string arr[10][5]= {
    { " - ", "| |", "   ", "| |", " - "}, // 0
    { "   ", "  |", "   ", "  |", "   "}, // 1
    { " - ", "  |", " - ", "|  ", " - "}, // 2
    { " - ", "  |", " - ", "  |", " - "}, // 3
    { "   ", "| |", " - ", "  |", "   "}, // 4
    { " - ", "|  ", " - ", "  |", " - "}, // 5
    { " - ", "|  ", " - ", "| |", " - "}, // 6
    { " - ", "  |", "   ", "  |", "   "}, // 7
    { " - ", "| |", " - ", "| |", " - "}, // 8
    { " - ", "| |", " - ", "  |", " - "}, // 9
};

int main()
{
    std::string size, str, line;
	int s;
    while(std::getline(std::cin, line)) {
		std::stringstream ss(line);
		ss >> size;
		s = std::stoi(size);
		ss >> str;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < str.size(); j++)
                std::cout << arr[str[j]-'0'][i] << " ";
        std::cout << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
