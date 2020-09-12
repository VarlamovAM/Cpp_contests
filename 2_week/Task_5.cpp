#include <iostream>
#include <vector>

int main(){

    std::vector<std::pair<int, int>> data = {{1,4}, {3, 5}, {6, 10}, {7, 8}, {9, 15}, {16, 20}, {19, 24}};

    int i = 0;

    for (i = 0; i < data.size(); i++){
        std::pair<int, int> now = data[i];
        std::cout << now.first;
        std::cout << " " << now.second <<  "\n";
    }

    i = 0;

    while (i < data.size() - 1){

        std::pair <int, int> first_pair, second_pair;
        first_pair = data[i];
        second_pair = data[i + 1];

        if (first_pair.second >= second_pair.first){
            std::cout << "i= " << i << " ok" << "\n";
            std::cout << first_pair.first << " " << first_pair.second << "\n";

            std::pair <int, int> new_pair;

            if (first_pair.second >= second_pair.second){
                new_pair = std::make_pair(first_pair.first, first_pair.second);
            } else {
                new_pair = std::make_pair(first_pair.first, second_pair.second);
            }
            std::cout << new_pair.first << " " << new_pair.second << "\n";
            data.erase(data.begin() + i, data.begin() + i + 2);
            data.insert(data.begin() + i, new_pair);
            continue;
        }

        i++;
    }

    i = 0;

    for (i = 0; i < data.size(); i++){
        std::pair<int, int> now = data[i];
        std::cout << now.first;
        std::cout << " " << now.second <<  "\n";
    }

    return 0;
}
