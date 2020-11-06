#include <iostream>
#include <vector>



class bin_tree{

struct Node{
    int key;
    Node* left;
    Node* right;
};

public:

    bin_tree(){
        root_ = nullptr;
    }

    void push(int x){
        Node* tmp = new Node;   //create temporary Node to add elements
        tmp -> key = x;         //to the tree.
        tmp -> left = nullptr;
        tmp -> right = nullptr;

        int level_counter = 0;  //var, which uses to count deep of tree.

        if (root_ == nullptr){  //add first nodes.
            root_ = &(*(tmp));
            deep_++;
        } else {
            Node** ptr = & root_;
            Node** ptr_t = &(root_);

            while ((*(ptr_t)) != nullptr){ // cycle for finding right position
                if (x > (*(ptr_t))->key){  // of elements in tree
                    ptr = ptr_t;
                    ptr_t = &((*(ptr_t))->right);
                } else {
                    ptr = ptr_t;
                    ptr_t = &((*(ptr_t))->left);
                }
                level_counter++;
            }
            if (x > (*(ptr))->key){
                (*(ptr))->right = tmp;
            } else {
                (*(ptr))->left = tmp;
            }
        }

        if ((level_counter + 1) > deep_){
            deep_ = level_counter + 1;
        }
        capacity_++;
        //print_tree();
    }

    void print_tree(){
        /*std::cout << "\nBegin printing\n";
        std::vector<std::vector<Node*>> levels;
        std::vector<Node*> level;
        //levels.resize(deep_);
        level.push_back(root_);
        levels.push_back(level);
        int max_el_on_level = 1;

        for (int i = 1; i < deep_; i++){
            std::vector<Node*> tmp;
            max_el_on_level=2*max_el_on_level;
            //::cout << "max_el_on_level = " << max_el_on_level << "\n";
            tmp.resize(2*level.size());
            for (int k = 0; k < max_el_on_level/2 ; k++){
                std::cout << " i , k = " << i << "," << k <<"\n";
                if (level[k]->left != nullptr){
                    tmp[2*k] = level[k]->left;
                } else {
                    tmp[2*k] = nullptr;
                }
                if (level[k]->right != nullptr){
                    tmp[2*k + 1] = level[k]->right;
                } else {
                    tmp[2*k] = nullptr;
                }
            }
            levels.push_back(tmp);
            level = tmp;
            std::cout << "levels.size() = " << levels.size()<< "\n";
        }
        std::cout << "levels.size() = " << levels.size()<< "\n\n";

        int i = 0;
        int j = 0;
        max_el_on_level = 1;
        for (i = 0; i < deep_ - 1; i++){
            for (j = 0; j < max_el_on_level; j++){
                if (levels[i][j] != nullptr){
                    std::cout << "level: "<< i <<" position: "<< j << " " << levels[i][j]->key << "\n";
                }
            }
            std::cout << "\n";
            j = 0;
            max_el_on_level = 2 * max_el_on_level;

        }
        std::cout <<"\nEnd printing\n";
        */

        /* Main idea: create std::vector with pointers to nodes of tree
        Fill this vector in cycle with iterator in a range from 0 to deep_ - 1;
        vector will be feeling by other vector of nodes.
        */

        std::vector<std::vector<Node*>> levels;
        long long  numb = 1;
        std::cout << levels.size() << "\n";

        for (long long i = 0; i < deep_; i++){
            std::vector<Node*> level;

            if (i == 0){
                level.push_back(root_);
                levels.push_back(level);
            } else {
                std::vector<Node*> tmp = levels[i - 1];
                std::cout << tmp.size();
                std::cout << levels.size() << "\n";
                for (int j = 0; j < tmp.size(); j++){
                    if (tmp[j] != nullptr){
                        std::cout << j << "\n";
                    }
                }
            }
        }

    }

    void capacity(){
        std::cout << capacity_ << "\n";
    }

    void test_print(){
        Node* tmp = root_;
        int k = 1;

        while (tmp != nullptr){
            std::cout << "level = " << k << " right elements = " << tmp->key << "\n";
            tmp = tmp->right;
            k++;
        }
    }

private:
    int deep_ = 0;
    int capacity_ = 0;
    Node* root_ = nullptr;
};


int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    bin_tree tree;

    tree.push(10);

    tree.capacity();

    tree.test_print();
    tree.print_tree();




    return 0;
}
