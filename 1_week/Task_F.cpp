#include <vector>
#include <iostream>

std::vector<int> Data;
int n;

int Position(const std::vector<int>& vec_1, const std::vector<int>& vec_2, int len){

    if (Data[len] != -1){
        return Data[len];
    }

    int a, b, res;
    a = 0;
    b = 0;

    if (len <= 1){
        if (len == 0){
            return 1;
        } else {
            if (vec_1[1] == vec_1[0] || vec_1[1] == vec_2[0]){
                return 1;
            } else {
                return 0;
            }
        }
    }
    if (len > 1){
        if (vec_1[len] == vec_1[len - 1] ||
            vec_1[len] == vec_2[len - 1]){
                a = Position(vec_1, vec_2, len - 1) % 947;
            }
        if (vec_1[len] == vec_1[len - 2] ||
            vec_1[len] == vec_2[len - 2]){
                b = Position(vec_1, vec_2, len - 2) % 947;
            }
        res = (a + b)% 947;
        Data[len] = res;
        return res;
    }
}

int main(){

    std::cin >> n;
    Data.resize(n, -1);

    std::vector<int> First_vec;
    std::vector<int> Second_vec;

    First_vec.resize(n);
    Second_vec.resize(n);

    int i = 0;

    for (i = 0; i < n; i++){
        std::cin >> First_vec[i];
    }
    i = 0;
    for (i = 0; i < n; i++){
        std::cin >> Second_vec[i];
    }

    std::cout << Position(First_vec, Second_vec, n - 1) << "\n";
    return 0;
}
