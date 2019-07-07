#include <iostream>

int main()
{
    int testCase;
    std::cin >> testCase;
    char A[15];
    int banglawash, whitewash, abandoned, tie;
    int n;
    for(int cc = 1; cc <= testCase; cc++) {
        banglawash = whitewash = abandoned = tie = 0;
        std::cin >> n;
        std::cin >> A;
        for(int i = 0; i < n; i++)
            if(A[i] == 'B') banglawash++;
            else if (A[i] == 'W') whitewash++;
            else if (A[i] == 'A') abandoned++;
            else if (A[i] == 'T') tie++;

        std::cout << "Case " << cc << ": ";
        if (abandoned == n)
            std::cout << "ABANDONED" << std::endl;
        else if((banglawash + abandoned) == n)
            std::cout << "BANGLAWASH" << std::endl;
        else if ((whitewash + abandoned) == n)
            std::cout << "WHITEWASH" << std::endl;
        else if ( banglawash == whitewash)
                std::cout << "DRAW " << banglawash << " " << tie << std::endl;
        else if (banglawash > whitewash)
            std::cout << "BANGLADESH " << banglawash << " - " << whitewash << std::endl;
        else if (whitewash > banglawash)
            std::cout << "WWW " << whitewash << " - " << banglawash << std::endl;
    }

    return 0;
}
