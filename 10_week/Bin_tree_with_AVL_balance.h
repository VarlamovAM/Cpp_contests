#include <iostream>
#include <vector>
#include <queue>
#include <functional>

template<typename Key, typename Comp = std::less<Key>>
class Tree {
private:
    struct Node {
        Key key;
        Node *left;
        Node *right;
        Node *parent;
        short factor; // h(left) - h(right)
    };


    void right_rotation(Node* x) {
        if (x == nullptr && x->left == nullptr) { // ���� �� � ����� ��� ��� ������ ���������, ������ ������
            printf("error");
            return;
        }
        // ����� �������� �������, �.�. �������, ��������� � ��������� ��������� �� ��� ��� ���� ������, don't be confused
        Node *left = x->left; // ����� ������� �
        Node *parent = x->parent; // ��������
        Node *y = left->right; // ������ ������� ������ ������� �


        if (parent != nullptr) { // �������� �� ������
            if (parent->left == x) parent->left = left; // ���� ������ �����, ����� �������� ������� "��������" ���������� ������ ��� ��������� "�����"
            else parent->right = left; // ���� ������ ������, �� "�����" ���� ���������� ������ �������� "��������"
        }
        else root = left; // �������� ������=�������� � ������ ������� �
        left->parent = parent; // ������������ ����� ������ ����� ����� �������� � � ������ ��������� �
        left->right = x; // � ���������� ������ �������� ������� ������ ������� �
        x->parent = left; // ������ ����� ������� � ������ ��� ����� ��������
        x->left = y; // ������ ������� ������� ������ ������� � ���������� ����� �������� �
        if (y != nullptr) y->parent = x; // ���� ��� ������ ����������, �� ������������ ����� ��������������� �� �
    }


    void left_rotation(Node* x) {
        if (x == nullptr && x->right == nullptr) { // ���� �� � ����� ��� ��� ������� ���������, ������ ������
            printf("error");
            return;
        }

        Node *right = x->right; // ������ ������� �
        Node *parent = x->parent; // ��������
        Node *z = right->left; // ����� ������� ������� ������� �

        if (parent != nullptr) { // �������� �� ������
            if (parent->right == x) parent->right = right; // ���� ������ ������
            else {
                parent->left = right;
            }
        } else root = right;
        right->parent = parent;

        right->left = x;
        x->parent = right;

        x->right = z;
        if (z != nullptr) z->parent = x;
    }

    void right_left_rotation(Node* x) {
        right_rotation(x->right); // ������ ������� ���������� ��� ������� ������� �, �� ���� ��� ����� �������
        left_rotation(x); // ����� �������, ���������� ��� ������ �
    }
    void left_right_rotation(Node* x) {
        left_rotation(x->left); // ����� ������� ��� ������ ������� �
        right_rotation(x); // ������ ������� ��� �
    }


    Node* lookfor(Node* x, Key k) const { //����� ���� � ��������� � ������ x � �������� ������, nullptr ���� �� ������
        while (x != nullptr and ((k > x->key) or (k < x->key))) { // � �� ���� � ����������� ���� ����<k, ���� ����>k
            if (k < x->key) // ���� ����>k, �� ���� �� ������ �����, ��� ��� ����� ��������, ������� �����
                x = x->left;
            else x = x->right; // ���� ��������, �� ���� ������ � ������� ����� ���������
        }
        return x;
    }

    Node* minimum(Node* x) const { //��������������� ��������� ����,���� ����� ����� �������, ��� ��� ��� ���, ��� ������ �����
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }
    Node* maximum(Node* x) const { //���� ����� ������ �������, ��� ��� �� �������������� ������, ��� ����������� ��� ��������, ������ ���, ��� ������ �����
        while (x->right != nullptr) {
            x = x->right;
        }
        return x;
    }

     Node* next(Node* x) const { //��������� �� �������� ������� �� �
        if (x->right != nullptr) { // ���� ���� ������ �������, �� ������������ ���� ���������� "����� �������" � ���� ���������, �.�., ��������� �� ������ ������ �� ����� ������, ����� ����� ����� ������� � ������ �� ����� ��������� �� �������� ����� �
            return minimum(x->right); //(����� ���, ���������� ����� � �������� ���� ��������� ��� ����� ������������ � �� �������� � ��� ��� �������� ���������� ��������� � ���� ���)
        }
        Node* n = x->parent; // ����� n - ������������ ���� �
        while (n != nullptr and x == n->right) { // �������� ������ � � - ��� ������ �������
            x = n; // ���� ������, ���� �� ��������� �� ����� �� �����. ���� �� �������� ������ ������, �� ���������� �� �������� �� � � �� ��� ��� ���������, �� ���� ��� ����� ���������� �� ������ ����, �� ����������� ��� ���������, ����� ������� ����� ��������� �� �������� �������
            n = n->parent;
        }
        return n;
    }
    Node* prev(Node* x) const { // �������������� �� �������� ������� �� �
        if (x->left != nullptr) { // ���� ���� ����� �������, �� ������������ ���� ���������� "����� ��������" � ���� ���������, �.�., ��������� �� ������ ������ �� ����� ������, ����� ����� ������ ������� � ������ �� ����� �������������� �� �������� �
            return maximum(x->left);
        }
        Node* n = x->parent;
        while (n != nullptr and x == n->left) {
            x = n;
            n = n->parent;
        }
        return n;
    }

    Comp const cmp;
    unsigned long long int c = 0;

    bool insert_node(Node* z) {
        Node* y = nullptr; // � - ������ ������
        Node* x = root; // � - ������ ������, ���� ���� �������� ���� z � ��������� ��������� key
        while (x != nullptr) { //����� ����� ��� �������
            y = x; // ����� �����, � ����� ����� �� �����. ����� � ������ �� �����, � ��������� � ��������� ���� ����� null
            if (cmp(z->key, x->key)) // ���������� �������� ������ � ���� ���������
                x = x->left; // ���� ��, ��� ���� ��������, ������, ��� �������� ����� � ���������� �, �� �������, ��� ��� ����� �������� ����-�� �����, ��� ��� ���� �����
            else if (!cmp(z->key, x->key)) // ���� ��, ��� ���� ��������, ������ ����� � �, ���� ����������� ��� ������
                x = x->right;
            else return false; //��������� ������ = ������� �� �������
        }
        z->parent = y; // ���������� �������� ��� ������������ ����
        if (y == nullptr) { //������ ���� ������
            root = z; // �� ����������� ���� ���� ������������ ������ �������
            c++; // �������� ��������� ��������� �������������
            return true; // ������� �������
        }
        else {
            if (cmp(z->key, y->key)) // ���� ������ ��������� ����� ��� ������
                y->left = z; // ���� z < ����� � � = z ���������� ����� �������� �
            else y->right = z; // �����, ������
            balance_after_insert(z); // ������ ������������
            c++; // �������� �������������
            return true; // ������� �������
        }
    }

    void balance_after_insert(Node* x) {
        while (x->parent != nullptr) { // ���� �������� ���� �� ����, ����������� ������, ������ ������ ������
            if (x == x->parent->left) { // ���� ������ � �������� �����, ��� ����������� ������ ������ �� 1
                x->parent->factor += 1;
            }
            else {
                x->parent->factor -= 1; // ������ ������ - ��������� ������ �� 1
            }
            if (x->parent->factor == 0) // ���� ������� ������ � ������ = 0, ������ ������������� �� �����
                break;
            else if (x->parent->factor == 1 or x->parent->factor == -1) { // ���� ��������� � �������� ������ +-1, ����� � ����, ��� ��� ����� �������� ���������� ���������
                x = x->parent;
                continue;
            }  // ����� 6 ��������� �������� ����������, �� ����� ��������� ����������� ������� � ����������� ����� �������� ��������
                else {
                    if (x->parent->factor == 2 and x->factor == 1) { // ���� �� ������ ���� ������ 1, � ���������� �� ������� ����, �������� 2
                        right_rotation(x->parent); // �� ���������� ��������� ������ ������� ��� ������������� ������ �
                        x->factor = 0; // ����� ����� � ������ �� ������� ���� � ��� ���� � ��� ������ ������� ������� � ������ ������ 0
                        x->right->factor = 0;
                }
                else if (x->parent->factor == 2 and x->factor == 0) { // ������ �� �������� 2, �� � - 0, ��������� ������ ������� � ��������
                    right_rotation(x->parent);
                    x->factor = 1; // ������ ���� ���������� 1, ������� ������� -1
                    x->right->factor = -1;
                }
                else if (x->parent->factor == 2 and x->factor == -1) {// ��� ���� �������� ���������� �������� ��������, ����� �������� ������� ������� ������� ����� 1, 0 � -1
                    if (x->right != nullptr) {
                        if (x->right->factor == 1) {
                            left_right_rotation(x->parent);
                            x->parent->factor = 0;
                            x->factor = 0;
                            x->parent->right->factor = 0;
                        }
                    }
                    if (x->right != nullptr) {
                        if (x->right->factor == -1) {
                            left_right_rotation(x->parent);
                            x->parent->factor = 0;
                            x->factor = 1;
                            x->parent->right->factor = 0;
                        }
                    }
                    if (x->right != nullptr) {
                        if (x->right->factor == 0) {
                            left_right_rotation(x->parent);
                            x->parent->factor = 0;
                            x->factor = 0;
                            x->parent->right->factor = 0;
                        }
                    }
                }
                else if (x->parent->factor == -2 and x->factor == -1) {// ���������� ��������, ������ ������� �����, �������� ������� ����� �� �������������
                    left_rotation(x->parent);
                    x->factor = 0;
                    x->left->factor = 0;
                }
                else if (x->parent->factor == -2 and x->factor == 0) {
                    left_rotation(x->parent);
                    x->factor = -1;
                    x->left->factor = 1;
                }
                else if (x->parent->factor == -2 and x->factor == 1) {
                    if (x->left != nullptr) {
                        if (x->left->factor == 1) {
                            right_left_rotation(x->parent);
                            x->parent->factor = 0;
                            x->factor = -1;
                            x->parent->left->factor = 0;
                        }
                    }
                    if (x->left != nullptr) {
                        if (x->left->factor == -1) {
                            right_left_rotation(x->parent);
                            x->parent->factor = 0;
                            x->factor = 0;
                            x->parent->left->factor = 1;
                        }
                    }
                    if (x->left != nullptr) {
                        if (x->left->factor == 0) {
                            right_left_rotation(x->parent);
                            x->parent->factor = 0;
                            x->factor = 0;
                            x->parent->left->factor = 0;
                        }
                    }
                }
                if (x->parent != nullptr)
                    x = x->parent;
            }

        }
    }
    void balance_after_erase(Node* x) {
        while (x->parent != nullptr) {
            //��������
            if (x == x->parent->left) {//���� ������ ����� �� � � �������� �� ������� ����, ��� ��������� ������ ������ �� 1, ��� ��� �� ������ ��� ������� ��� ������, ������ ������� ������� � ������ �������
                x = x->parent;
                x->factor -= 1;
            }
            else {//���� ������ ������ �� � � �������� �� ������� ����, ��� ����������� ������ �� 1 �� ��� �� �������
                x = x->parent;
                x->factor += 1;
            }
            if (x->factor == 1 or x->factor == -1)
                break; //
            else if (x->factor == 0) {
                continue; // ������������ �� �����, ���� ������
            }
            else { // ����� ������������� 6 ��������� ��������, ��������� �������� ������� � � ������� ������, � ����� � ������� ������� �
                if (x->factor == 2 and x->left->factor == 1) {
                    right_rotation(x);
                    x->factor = 0;
                    x->parent->factor = 0;
                }
                else if (x->factor == 2 and x->left->factor == 0) {
                    right_rotation(x);
                    x->factor = 1;
                    x->parent->factor = -1;
                }
                else if (x->factor == 2 and x->left->factor == -1) { // ��� ��������� �, ��� ����� � ������, ��������� ����������� �������� � ����������� ����� �������� ��������
                    if (x->left->right->factor == 1) {
                        left_right_rotation(x);
                        x->factor = -1;
                        x->parent->factor = 0;
                        x->parent->left->factor = 0;
                    }
                    if (x->left->right->factor == -1) {
                        left_right_rotation(x);
                        x->factor = 0;
                        x->parent->factor = 0;
                        x->parent->left->factor = 1;
                    }
                    if (x->left->right->factor == 0) {
                        left_right_rotation(x);
                        x->parent->factor = 0;
                        x->factor = 0;
                        x->parent->right->factor = 0;
                    }

                }
                else if (x->factor == -2 and x->right->factor == -1) {
                    left_rotation(x);
                    x->factor = 0;
                    x->parent->factor = 0;
                }
                else if (x->factor == -2 and x->right->factor == 0) {
                    left_rotation(x);
                    x->factor = 0;
                    x->parent->factor = 1;
                }
                else if (x->factor == -2 and x->right->factor == 1) {
                    if (x->right->left->factor == 1) {
                        right_left_rotation(x);
                        x->factor = 1;
                        x->parent->factor = 0;
                        x->parent->right->factor = 0;
                    }
                    if (x->right->left->factor == -1) {
                        right_left_rotation(x);
                        x->factor = 0;
                        x->parent->factor = 0;
                        x->parent->right->factor = -1;
                    }
                    if (x->right->left->factor == 0) {
                        right_left_rotation(x);
                        x->factor = 0;
                        x->parent->factor = 0;
                        x->parent->right->factor = 0;
                    }
                }

            }
        }
    }

    Node* erase(Node* r, Key z) { // r - ������ ������, �� �������� ������������ ��������, z - �������� �����, ������� ���� �������
        if (r == nullptr)
            return r;
        if (z < r->key) {
            r->left = erase(r->left, z);
        }
        else if (z > r->key)
            r->right = erase(r->right, z);
        else if (r->left != nullptr and r->right != nullptr) {
            r->key = minimum(r->right)->key;
            r->right = erase(r->right, r->key);




        }
        else {
            balance_after_erase(r);
            c--;
            if (r->left != nullptr)
                r = r->left;
            else if (r->right != nullptr)
                r = r->right;
            else
                r = nullptr;
        }
        return r;
    }




 public:
    Node* root = nullptr;

    Tree():cmp() {}
    bool insert(Key const x) {
        Node* n = new Node;
        n->key = x;
        n->left = nullptr;
        n->right = nullptr;
        n->parent = nullptr;
        n->factor = 0;
        return insert_node(n);
    }
    bool find(Key const y) const {
        if (lookfor(root, y) == nullptr) {
            return false;
        }
        else return true;
    }
    bool erase(Key z) {
        if (find(z) == false)
            return false;
        else {
            erase(root, z);
            return true;
        }
    }

    void print_tree() {
        std::queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            if (q.front()->left != nullptr) {
                q.push(q.front()->left);
            }
            if (q.front()->right != nullptr) {
                q.push(q.front()->right);
            }
            std::cout << q.front()->key << " ";
            q.pop();
        }
    }




    using iterator = Node*;
    iterator front() const {
        return minimum(root);
    }
    iterator back() const {
        return maximum(root);
    }
    iterator next1(iterator i) const { //��������� �������
        return next(i);
    }
    iterator prev1(iterator i) const {//���������� �������
        return prev(i);
    }


    };
