#include <iostream>
#include <vector>
#include <string>



int main() {
    std::string A, B;

    std::cin >> A >> B;

    std::vector<unsigned long long int> hash_string;

    int i = 0;
    for (i = 0; i < B.size(); ++i) {
        if (i == 0) {
            hash_string.push_back(1);
        } else {
            hash_string.push_back(hash_string.back() * 19);
        }
    }

    i = 0;

    std::vector<unsigned long long> hash_string_B;

    for (i = 0; i < B.size(); ++i) {

        hash_string_B.push_back(B[i] - 'a' + 1);
        hash_string_B.back() *= hash_string[i];

        if (i > 0) {
            hash_string_B.back() += hash_string_B[i - 1];
        }
    }
    i = 0;

    unsigned long long num_hash_string_A = 0;

    for (unsigned int i = 0; i < A.size(); ++i) {
        num_hash_string_A += (A[i] - 'a' + 1) * hash_string[i];
    }

    bool flag = true;

    for (unsigned int i = 0; i < B.size() - A.size() + 1; ++i) {
        unsigned long long current_hash = hash_string_B[A.size() + i - 1];
        if (i > 0) {
            current_hash -= hash_string_B[i - 1];
        }
        if (current_hash == num_hash_string_A * hash_string[i]) {
            bool flags = true;
            for (unsigned int l = 0; l < A.size() && l < 1200; l++) {
                if (A[l] != B[l + i]) {
                    flags = false;
                    break;
                }
            }
            if (flags) {

                std::cout << i << " ";
                flag = false;
            }
        }
    }
    if (flag) {
        std::cout << -1;
    }
}
