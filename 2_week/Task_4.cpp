#include <iostream>
#include <vector>


int main(){

    std::vector<int> numb = {1, 3, 9};

    int i = numb.size() - 1;
    int remainder = 1;

    for (i = numb.size() - 1; i >= 0; i--){
        if (numb[i] + remainder == 10){
            numb[i] = 0;
            remainder = 1;
        } else {
            numb[i] = numb[i] + remainder;
            remainder = 0;
            break;
        }
    }

    if (numb[0] == 0){
        numb.emplace(numb.begin(), 1);
        //std::cout << numb.size();
    }

    for (int k = 0; k < numb.size(); k++){
        std::cout << numb[k];
    }
    return 0;
}
