#include <iostream>

class vector{
    public:
        vector(){
            length_ = 0;
            capacity_ = 1;
            int *A = new int[length_];
            Arr_ = A;
        };
        /*vector(int lenght, int* Elements){
            capacity_ = 2*lenght;
            length_ = lenght;
            for (k_ = 0; k_ < lenght, k_++){
                *(Arr_ + k_) = *(Elements + k_);
            }
        }*/

        void pushback(int a){
            if (length_ == capacity_){
                capacity_ = 2 * capacity_;
                int *New_Arr = new int[capacity_];
                arr_copy(Arr_, New_Arr, length_);
                Arr_ = New_Arr;
                *(Arr_ + length_) = a;
                length_++;
            } else {
                *(Arr_ + length_) = a;
                length_++;
            }
        }

        void popback(){
            if (length_ == 0){
                length_ = 0;
            } else {
                length_--;
            }
        }

        int length(){
            return length_;
        }

        int capacity(){
            return capacity_;
        }

        int operator[](int i){
            return *(Arr_ + i);
        }

    private:

        void arr_copy(int* Arr, int* New_Arr, int length_){
            for (int i = 0; i < length_; i++){
                *(New_Arr + i) = *(Arr + i);
            }
            delete[] Arr_;
            return;
        }

        int length_;
        int capacity_;
        int* Arr_ = new int[capacity_];
};

void Print(vector a){
    for (int j = 0; j < a.length(); j++){
        std::cout << a[j] << " ";
    }
    std::cout << "\n";
}

int main(){

    vector a = vector();

    std::cout << " " <<  a.length() << " " << a.capacity() << " elements in vector:" << "\n";

    a.pushback(3);

    Print(a);

    std::cout << a.length() << " " << a.capacity() << " elements in vector:" << "\n";

    a.pushback(3);

    Print(a);

    std::cout << a.length() << " " << a.capacity() << " elements in vector:" << "\n";

    a.pushback(3);

    Print(a);

    std::cout << a.length() << " " << a.capacity() << " elements in vector:" << "\n";

    a.pushback(3);

    Print(a);

    std::cout << a.length() << " " << a.capacity() << " elements in vector:" << "\n";

    a.pushback(3);

    Print(a);

    std::cout << a.length() << " " << a.capacity() << " elements in vector:" << "\n";

    a.pushback(3);

    Print(a);

    std::cout << a.length() << " " << a.capacity() << " elements in vector:" << "\n";

    a.pushback(3);

    Print(a);

    /*for (int ghgh = 0; ghgh < 10; ghgh++){
        std::cout << "test";
    }*/


    return 0;
}
