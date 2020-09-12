#include <iostream>
#include <string>



int main(){

    std::string a;

    getline(std::cin, a);

    std::cout << a;
    int i = 0;
    int j = 0;
    int size_a = a.size();
    char *buff = new char[size_a];
    char buf = " ";



    i = 0;



    for (i = 0; i < size_a; i++){
        //std::cout << a[i] << " ";

        if (a[size_a - 1] == buf){
            continue;
        } else {
            std::cout << a[size_a - 1] << " " << size_a << "\n" ;
            a.pop_back();
            size_a--;
        }
    }

    delete[] buff;

    return 0;
}
