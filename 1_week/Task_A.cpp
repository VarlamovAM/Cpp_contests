#include <iostream>

int main(){

    int N = 0;
    int numbers[N - 1];
    bool flag[N - 1];

    int i = 0;

    std::cin >> N;

    for (i = 0; i < N; i++){
        std::cin >> numbers[i];
        if (((numbers[i] % 4) = 0) and (((numbers[i] / 1000) = 4) or ((numbers[i] / 1000) = 5)) or
            ((numbers[i] % 7) = 0) and (((numbers[i] / 1000) = 7) or ((numbers[i] / 1000) = 1)) or
            ((numbers[i] % 9) = 0) and (((numbers[i] / 1000) = 9) or ((numbers[i] / 1000) = 8))){
            flag[i] = false;
        } else {
            flag[i] - true;
        }

        std::cout << "number[" << i << "i] = " << numbers[i] << "; flag[" << i << "i] = " << flag[i] << "\n";
    }

    i = 0;


    return 0;
}
