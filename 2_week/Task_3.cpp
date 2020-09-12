#include <iostream>
#include <string>
#include <vector>


void Print_string(std::string A){
    int j = 0;
    for (j = 0; j < A.length(); j++){
        std::cout << A[j];
    }
    std::cout << "\n";
}

int main(){
    std::string input;

    std::cin >> input;

    std::vector<std::string> data();

    //std::cout << " \n" << input << "\n";

    int i = 0;
    int sublength = 0;
    int substring_counter = 0;
    int results = 0;

    while (input.length() != 0){
        if (input[i] == 'R'){
            sublength++;
            substring_counter++;
            //std::cout << "sublength = " << sublength << " substring_counter = " << substring_counter << " i = " << i <<  "\n";
            i++;
            continue;
        }

        if (input[i] == 'L'){
            sublength++;
            substring_counter--;
            //std::cout << "sublength = " << sublength << " substring_counter = " << substring_counter << "\n";
            i++;
        }
        if (substring_counter == 0){
            std::string substring = input.substr(0, sublength);
            input.erase(0, sublength);
            //Print_string(substring);
            sublength = 0;
            substring_counter = 0;
            i = 0;
            results++;
        }
    }

    std::cout << results;
    return 0;
}
