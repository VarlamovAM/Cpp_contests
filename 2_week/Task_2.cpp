#include <iostream>
#include <vector>

int main(){

    std::vector<int> nums {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int N;

    std::cin >> N;

    int i = 0;
    int j = 0;
    int first_number = 0;
    int second_number = 0;
    bool flag = false;

    std::cout << nums.size() << "\n";
    for (i = 0; i < nums.size() - 1; i++){
        for (j = i + 1; j <= nums.size() - 1; j ++){
            std::cout << nums[i] << " " << nums[j] << "\n";
            if ((nums[i] + nums[j]) == N){
                first_number = nums[i];
                second_number = nums[j];
                flag = true;
                break;
            }
        }
        if (flag){
            break;
        }
        j = i + 1;
    }

    std::vector<int> result = {first_number, second_number};

    for (int n : result){
        std::cout << n << "\n";
    }

    return 0;
}
