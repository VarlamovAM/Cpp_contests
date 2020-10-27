#include <iostream>
#include <string>
#include <vector>

std::string symbol_changer(std::string& string){
        int i = 0;
        for (i = 0; i < string.size(); i++){
            if ((string[i] >= 'A') && (string[i] <= 'Z')){
                string[i] += 'a' - 'A';
            }
        }
    return string;
}

int main(){
    std::vector<std::string> Data;
    int Size;
    std::cin >> Size;

    int i = 0;

    for (i = 0; i < Size; ++i){
        std::string tmp;
        std::cin >> tmp;
        Data.push_back(tmp);
    }

    i = 0;

    for (i = 0; i < Data.size(); i++){
        Data[i] = symbol_changer(Data[i]);
    }

    i = 0;
    int k = 0;

    for (k = 0; k < Size; k++){
        for (i = 0; i < Size - k - 1; i++){
            if (Data[i] < Data[i + 1]){
                std::string tmp;
                tmp = Data[i];
                Data[i] = Data[i + 1];
                Data[i + 1] = tmp;
            }
        }
    }

    i = 0;
    k = 0;
    bool flag = false;
    std::vector<std::string> New_Data;
    New_Data.push_back(Data[0]);

    for (i = 1; i < Data.size(); i++){
        flag = false;
        for (k = 0; k < New_Data.size(); k++){
            if (Data[i] == New_Data[k]){
                flag = true;
            }
        }
        if (flag) {
            continue;
        } else {
            New_Data.push_back(Data[i]);
        }
    }

    for(i = 0; i < New_Data.size(); i++){
        std::cout << New_Data[i] << " ";
    }
}
