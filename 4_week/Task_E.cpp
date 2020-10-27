#include<iostream>
#include<stack>

int main(){
	int tmp;
	std::stack<int> s;
	while (true){
		std::cin >> tmp;
		if (!tmp) break;
		if (tmp > 0) {
			s.push(tmp);
		} else {
			if (!s.empty()) {
				if (abs(tmp) < s.top()){
					s.top()+= tmp;
				} else {
					s.pop();
				}
			}
		}
	}
	if (s.empty()) {
	       	std::cout << s.size() << " -1";
	} else {
	       	std::cout << s.size() << " " << s.top();
	}
	return 0;
}
