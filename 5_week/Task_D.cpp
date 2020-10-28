#include<iostream>
#include<vector>
#include<set>
#include<map>


int main() {
    int A, N, M;
    std::cin >> A >> N >> M;
    std::map <std::pair <int, char>, std::vector<int>> data;

    int i = 0;
    int a;
    int b;
    char c;

    while (i < M){
        std::cin >> a >> b >> c;
        data[{a,c}].emplace_back(b);
        i++;
    }

    int T;
    std::cin >> T;

    bool term[61];
    i = 0;

    for (i = 0; i <= 60; i++) {
        term[i] = false;
    }

    i = 0;

    for (i = 0; i < T; i++) {
        int t;
        std::cin >> t;
        term[t] = true;
    }

    int K;
    std::cin >> K;
    char k;
    i = 0;

    while (i < K){
        std::set<int> condtn_f;
        std::set<int> condtn_s;
        condtn_f.insert(0);

        std::string data_string;
        std::cin >> data_string;

        int j = 0;

        for (j = 0; j < data_string.size(); j++) {
            k = data_string[j];
            condtn_s.clear();

            for (auto it = condtn_f.begin(); it != condtn_f.end(); it++) {
                int t = 0;
                for (t = 0; t < (int) data[{*it, k}].size(); t++) {
                    condtn_s.insert(data[{*it, k}][t]);
                }
                t = 0;
            }
            condtn_f = condtn_s;
        }

        j = 0;

        bool flag = true;

        for (auto it = condtn_f.begin(); it != condtn_f.end(); it++) {
            if (term[*it]) {
                std::cout << "1 ";
                flag = false;
                break;
            }
        }
        if (flag) std::cout << "0 \n";

        i++;
    }
    return 0;
}

