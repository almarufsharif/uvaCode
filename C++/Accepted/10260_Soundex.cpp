#include <iostream>
#include <string>
#include <queue>

int main()
{
    std::string str;
    std::queue<int> Q;
    while(std::cin >> str) {
        for(int i = 0; i < str.size();) {
            if ( str[i] == 'B' || str[i] == 'F' || str[i] == 'P' || str[i] == 'V') {
                    Q.push(1);
                    while(i<str.size() && (str[i] == 'B' || str[i] == 'F' || str[i] == 'P' || str[i] == 'V')) i++;
            }
            else if ( str[i] == 'C' || str[i] == 'G' || str[i] == 'J' || str[i] == 'K' ||
                     str[i] == 'Q' || str[i] == 'S' || str[i] == 'X' || str[i] == 'Z') {
                    Q.push(2);
                    while( i <str.size() && (str[i] == 'C' || str[i] == 'G' || str[i] == 'J' || str[i] == 'K' ||
                     str[i] == 'Q' || str[i] == 'S' || str[i] == 'X' || str[i] == 'Z')) i++;
            }
            else if ( str[i] == 'D' || str[i] == 'T') {
                Q.push(3);
                while (i < str.size() && (str[i] == 'D' || str[i] == 'T')) i++;
            }
            else if ( str[i] == 'L') {
                Q.push(4);
                while ( i < str.size() && str[i] == 'L') i++;
            }
            else if ( str[i] == 'M' || str[i] == 'N') {
                Q.push(5);
                while(i < str.size() && (str[i] == 'M' || str[i] == 'N')) i++;
            }
            else if ( str[i] == 'R') {
                Q.push(6);
                while(i < str.size() && str[i] == 'R') i++;
            } else i++;
        }

        while(!Q.empty()) {
            std::cout << Q.front();
            Q.pop();
        }
        std::cout << std::endl;
    }

    return 0;
}
