#include <iostream>
#include <vector>
#include <map>


int main() {

    int A, N, M;
    std::cin >> A >> N >> M;

    std::map <std::pair <int, char>, int> data;

    int i = 0;
    int a;
    int b;
    char c;

    while (i < M)
    {
        std::cin >> a >> b >> c;

        data[{a,c}]= b;


        i++;

    }


    int T;
    std::cin >> T;

    bool term[61];

    for (int i = 0; i <= 60; i++) {
        term[i] = false;
    }

    for (int i = 0; i < T; i++) {
        int t;
        std::cin >> t;
        term[t] = true;
    }


    int K;
    std::cin >> K;



    char k;

    i = 0;

    while (i < K) {
        int cond = 0;
        int ans = 1;
        std::string data_string;
        std::cin >> data_string;
        int j = 0;

        for (j = 0; j < data_string.size(); j++){

            k = data_string[j];
            if (ans == 0){
                continue;
            }
            auto it = data.find({cond, k});

            if (it != data.end()){
                cond = data[{cond, k}];
            } else {
                ans = 0;
            }
        }

        j = 0;

        if ((ans == 0) || (term[cond] == false)){
            std::cout << "0 ";
        } else {
            std::cout << "1 ";
        }

        i++;
    }
    return 0;
}
