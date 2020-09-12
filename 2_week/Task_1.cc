#include <iostream>
#include <string>


int main(){

    std::string a;
    std::string b;
    std::string buf;

    std::cin >> a;
    std::cin >> b;


    int length_min = 0;
    int length_max = 0;

    if (a.length() >= b.length()){
        length_min = b.length();
        length_max = a.length();
        std::string buf(length_max - length_min, '0');
        b = buf + b;
    } else {
        length_min = a.length();
        length_max = b.length();
        std::string buf(length_max - length_min, '0');
        a = buf + a;
    }

    std::string result (length_max + 1, '0');

    int i = length_min;
    int remainder = 0;

    for (i = length_max - 1; i >= 0; i--){
        if (a.length() >= b.length()){
            if ((a[i + (a.length() - b.length())] == '0') && (b[i] == '0') && (remainder == 0)){
                result[i + (a.length() - b.length()) + 1] = '0';
                remainder = 0;
                continue;
            }

            if ((a[i + (a.length() - b.length())] == '0') && (b[i] == '0') && (remainder == 1)){
                result[i + (a.length() - b.length()) + 1] = '1';
                remainder = 0;
                continue;
            }

            if ((((a[i + (a.length() - b.length())] == '1') && (b[i] == '0')) ||
                ((a[i + (a.length() - b.length())] == '0') && (b[i] == '1'))) &&
                (remainder == 0)){
                result[i + (a.length() - b.length()) + 1] = '1';
                remainder = 0;
                continue;
            }

            if ((((a[i + (a.length() - b.length())] == '1') && (b[i] == '0')) ||
                ((a[i + (a.length() - b.length())] == '0') && (b[i] == '1'))) &&
                (remainder == 1)){
                result[i + (a.length() - b.length()) + 1] = '0';
                remainder = 1;
                continue;
            }

            if ((a[i + (a.length() - b.length())] == '1') && (b[i] == '1') && (remainder == 0)){
                result[i + (a.length() - b.length()) + 1] = '0';
                remainder = 1;
                continue;
            }

            if ((a[i + (a.length() - b.length())] == '1') && (b[i] == '1') && (remainder == 1)){
                result[i + (a.length() - b.length()) + 1] = '1';
                remainder = 1;
                continue;
            }
        } else {

            if ((a[i] == '0') && (b[i + (b.length() - a.length())] == '0') && (remainder == 0)){
                result[i + (b.length() - a.length()) + 1] = '0';
                remainder = 0;
                continue;
            }

            if ((a[i] == '0') && (b[i + (b.length() - a.length())] == '0') && (remainder == 1)){
                result[i + (b.length() - a.length()) + 1] = '1';
                remainder = 0;
                continue;
            }

            if ((((a[i] == '1') && (b[i + (b.length() - a.length())] == '0')) ||
                ((a[i] == '0') && (b[i + (b.length() - a.length())] == '1'))) &&
                (remainder == 0)){
                result[i + (b.length() - a.length()) + 1] = '1';
                remainder = 0;
                continue;
            }

            if ((((a[i] == '1') && (b[i + (b.length() - a.length())] == '0')) ||
                ((a[i] == '0') && (b[i + (b.length() - a.length())] == '1'))) &&
                (remainder == 1)){
                result[i + (b.length() - a.length()) + 1] = '0';
                remainder = 1;
                continue;
            }

            if ((a[i] == '1') && (b[i + (b.length() - a.length())] == '1') && (remainder == 0)){
                result[i + (b.length() - a.length()) + 1] = '0';
                remainder = 1;
                continue;
            }

            if ((a[i] == '1') && (b[i + (b.length() - a.length())] == '1') && (remainder == 1)){
                result[i + (b.length() - a.length()) + 1] = '1';
                remainder = 1;
                continue;
            }
        }
    }

    if (remainder == 1){
        result[0] = '1';
    } else {
        result.erase(result.begin());
    }

    std::cout << result << "\n";


    return 0;
}
