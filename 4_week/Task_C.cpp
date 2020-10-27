
#include <iostream>
#include <vector>

class MinStack{
    public:
        MinStack(){
            std::vector <int> a;
            members_ = a;
            minimum_ = a;
        };
        ~MinStack(){

        };

        void push(int x){
            members_.push_back(x);
            if (members_.size() > 1){
                if (minimum_[minimum_.size() - 1] > x){
                    minimum_.push_back(x);
                } else {
                    minimum_.push_back(minimum_[minimum_.size() - 1]);
                }
            } else {
                minimum_.push_back(x);
            }
        };
        void pop(){
            if(members_.size() >= 1){
                members_.pop_back();
                minimum_.pop_back();
            }
        };
        int top(){
            if(members_.size() >= 1){
                int value = members_[members_.size() - 1];
                return value;
            }
        };
        int getMin(){
            if(members_.size() >= 1){
                int value = minimum_[minimum_.size() - 1];
                return value;
            }
        };

    private:
        std::vector <int> members_;
        std::vector <int> minimum_;
};

int main(){

    MinStack st = MinStack();

    st.push(2);
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.push(1);
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.push(3);
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.push(5);
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.push(0);
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.push(4);
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.pop();
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.pop();
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.pop();
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.pop();
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.pop();
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";
    st.pop();
    std::cout << "top = " << st.top() << " min = " << st.getMin() << "\n";


    return 0;
}
