#include <iostream>
#include <string>
#include <vector>

int main() {

    int n;
    std::cin >> n;

    std::string Data;

    std::vector<std::pair<int, char>> encod;

    char symb;

    int counter;

    for (int i = 0; i < 8*n; ++i) {
        std::cin >> counter >>  symb;
        encod.push_back({counter, symb});
    }
    std::cin >> Data;

    int k = 1;
    bool flag;
    int i = 0;

    for (i = 0; i < Data.size(); ++i) {

        flag = true;
        int j = 0;

        for (j = 1 + 8 * (k-1); j < 8 * n; j+=2){
            if ((Data[i] == encod[j].second) && (k == encod[j-1].first && (flag))) {

                k = encod[j].first;
                std::cout << encod[j - 1].second;
                flag = false;
            }
        }
        j = 0;
    }
    return 0;
}
