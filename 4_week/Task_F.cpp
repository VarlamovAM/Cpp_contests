#include <iostream>
#include <vector>


int main(){

    std::vector<std::vector<int>> graph;

    int n = 0;

    std::cin >> n;

    int i = 0;
    int max_f_t = 0;

    for (i = 0; i < n; i++){
        int first_t;
        int second_t;
        int weight;

        std::cin >> first_t >> second_t >> weight;
        std::vector<int> tmp = {first_t, second_t, weight};
        graph.push_back(tmp);
        if (first_t > max_f_t){
            max_f_t = first_t;
        }
    }

    i = 0;
    int k = 0;
    std::vector<std::vector<int>> final_data;
    int counter = 0;
    bool flag = false;


    for (k = 0; k <= max_f_t; k++){
        flag = false;
        for (i = 0; i < graph.size(); i++){
            if (k == graph[i][0]){
                if (!flag){
                    std::vector<int> tmp = {k, 1, graph[i][2]};
                    final_data.push_back(tmp);
                    counter++;
                } else {
                    final_data[counter-1][1]++;
                    final_data[counter-1][2] = final_data[counter-1][2] + graph[i][2];
                }
                flag = true;
            }
        }
    }

    k = 0;

    for (k = 0; k < final_data.size(); k++){
        std::cout << final_data[k][0] << " " << final_data[k][1] << " " << final_data[k][2] << "\n";
    }

    return 0;
}
