#include <iostream>
#include <vector>

void prod(const std::vector<std::string>& Data, int i, int j){
    if (i == j){
        std::cout << Data[i] << "\n";
    } else {
        int k = j;
        for (k = j; k <= i; k++){
            std::cout << Data[k] << " ";
        }
        std::cout << "\n";
        prod(Data, i, j + 1);
    }
}

int main(){
    std::vector <std::string> Data;
    std::string tmp;

    while (std::cin >> tmp){
        Data.push_back(tmp);
    }

    int l = 0;

    for (l = 0; l < Data.size(); l ++){
        prod(Data, l, 0);
    }

    return 0;
}
