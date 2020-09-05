#include <iostream>

int main(){

    int N;
    int i = 0;
    int k = 0;
    std::cin >> N;

    int *arr = new int[N];

    i = 0;

    for (i = 0; i < N; i++){
        std::cin >> arr[i];
    }

    for (i = 0; i < N; i++){
        if( ((arr[i] % 4 == 0) && !((arr[i] / 1000 == 4) || (arr[i] / 1000 == 5))) ||
            ((arr[i] % 7 == 0) && !((arr[i] / 1000 == 7) || (arr[i] / 1000 == 1))) ||
            ((arr[i] % 9 == 0) && !((arr[i] / 1000 == 9) || (arr[i] / 1000 == 8)))
           ){
                std::cout << arr[i] << "\n";
                k++;
           }
    }


    i = 0;

    if (k == 0){
        std::cout << 0;
    }

    delete[] arr;

    return 0;
}
