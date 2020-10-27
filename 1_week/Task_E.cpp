#include <iostream>
#include <vector>

int main(){
    int N, x, y;
    std::cin >> N;
    int tmp = N;
    std::vector<int> First_vec;
    std::vector<int> Second_vec;

    int i = 0;
    for (i = 0; i < N; i++){
        std::cin >> x;
        std::cin >> y;
        First_vec.push_back(x);
        Second_vec.push_back(y);

        if (x + y != N - 1){
            tmp += -1;
        } else {
            int k = 0;
            for (k = 0; k < i; k++){
                if ((First_vec[First_vec.size() - 1] == First_vec[k])    &&
                    (Second_vec[Second_vec.size() - 1] == Second_vec[k]) &&
                    (First_vec[First_vec.size() - 1] != -1)){
                        tmp -= 1;
                        First_vec.pop_back();
                        First_vec.push_back(-1);
                        Second_vec.pop_back();
                        Second_vec.push_back(-1);
                }
            }
        }
    }

    std::cout << tmp << "\n";
    return 0;
}
