#include <iostream>
#include <string>
#include <vector>

void String_Print(std::string A){

    int i = 0;

    for (i = 0; i < A.length(); i++){
        std::cout << A[i];
    }
    std::cout << "\n";

    return;
}

int main(){
    std::string version1;
    std::string version2;

    std::cin >> version1;
    std::cin >> version2;

    int position_of_dot = 0;
    int counter_first_string = 0;
    int counter_second_string = 0;
    int search_position = 0;
    int i = 0;
    int j = 0;

    while (position_of_dot <= version1.find_last_of('.')){
        position_of_dot = version1.find('.', search_position);
        search_position = position_of_dot + 1;
        counter_first_string++;
    } // Find numbers of substring in first version string

    position_of_dot = 0;
    search_position = 0;

    while (position_of_dot <= version2.find_last_of('.')){
        position_of_dot = version2.find('.', search_position);
        search_position = position_of_dot + 1;
        counter_second_string++;
    } // Find numbers of substring in second version string

    std::vector <std::string> substring_version_1(counter_first_string);
    std::vector <std::string> substring_version_2(counter_second_string);

    position_of_dot = 0;
    search_position = 0;

    while (position_of_dot <= version1.find_last_of('.')){
        position_of_dot = version1.find('.', search_position);
        std::string substring_1;
        substring_1 = version1.substr(search_position, (position_of_dot - search_position));
        substring_version_1[i] = substring_1;
        search_position = position_of_dot + 1;
        i++;
    } // fill vector for first version substring

    i = 0;
    position_of_dot = 0;
    search_position = 0;

    while (position_of_dot <= version2.find_last_of('.')){
        position_of_dot = version2.find('.', search_position);
        std::string substring_1;
        substring_1 = version2.substr(search_position, (position_of_dot - search_position));
        substring_version_2[i] = substring_1;
        search_position = position_of_dot + 1;
        i++;
    } // fill vector for second version substring

    i = 0;

    bool zero_flag = true;

    for (i = 0; i < substring_version_1.size(); i++){
        zero_flag = true;
        for (j = substring_version_1[i].length() - 1; j >= 0; j--){

            if ((substring_version_1[i][j] != '0')){
                zero_flag = false;
            }

            if (substring_version_1[i][j] == '0'){

                if (zero_flag){
                    zero_flag = true;
                    continue;
                }
                if ((!zero_flag) && (j != 0)){
                    substring_version_1[i].erase(j, 1);
                }
            }
        }
        j = substring_version_1[i + 1].length();
    }

    i = 0;

    zero_flag = true;

    for (i = 0; i < substring_version_2.size(); i++){
        zero_flag = true;
        for (j = substring_version_2[i].length() - 1; j >= 0; j--){

            if ((substring_version_2[i][j] != '0')){
                zero_flag = false;
            }

            if (substring_version_2[i][j] == '0'){

                if (zero_flag){
                    zero_flag = true;
                    continue;
                }
                if ((!zero_flag) && (j != 0)){
                    substring_version_2[i].erase(j, 1);
                }
            }
        }
        j = substring_version_2[i + 1].length();
    }

    i = 0; // for 65 to 126 string -- correct delete zero from substring

    bool flag_first = false;
    bool flag_second = false;



    return 0;
}
