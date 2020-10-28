#include <stack>
#include <deque>
#include <string>
#include <iostream>


int main(){

    std::string equation;

    std::getline (std::cin, equation);

    std::stack<std::string> st;
    std::string tmp;

    char sep = ' ';

    for(size_t p=0, q=0; p!=equation.npos; p=q){
        tmp = equation.substr(p+(p!=0), (q=equation.find(sep, p+1))-p-(p!=0));
        if (tmp.length() == 0){
            continue;
        }
        if ((tmp == "+") || (tmp == "-") || (tmp == "*") || (tmp == "/")){
            std::string t2 = st.top();
            st.pop();
            std::string t1 = st.top();
            st.pop();

            int pos1 = t1.find(".");
            int pos2 = t2.find(".");

            /*if (pos1 >= 0 || pos2 >= 0 || tmp == "/"){
                float t1_f = std::stof(t1);
                float t2_f = std::stof(t2);

                if (tmp == "+"){
                    tmp = std::to_string(t1_f + t2_f);
                }

                if (tmp == "-"){
                    tmp = std::to_string(t1_f - t2_f);
                }

                if (tmp == "/"){
                    tmp = std::to_string(t1_f / t2_f);
                }

                if (tmp == "*"){
                    tmp = std::to_string(t1_f * t2_f);
                }
            } else {*/
                int t1_i = stoi(t1);
                int t2_i = stoi(t2);

                if (tmp == "+"){
                    tmp = std::to_string(t1_i + t2_i);
                }

                if (tmp == "-"){
                    tmp = std::to_string(t1_i - t2_i);
                }

                if (tmp == "/"){
                    tmp = std::to_string(t1_i / t2_i);
                }

                if (tmp == "*"){
                    tmp = std::to_string(t1_i * t2_i);
                }
            }
        //}
        //std::cout << tmp << "\n";
        st.push(tmp);

    }

    if (st.size() > 1){
        std::cout << "Error! Incorrect input.";
    }

    std::cout << st.top() << "\n";
    return 0;
}
