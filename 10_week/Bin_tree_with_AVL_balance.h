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
        if (x == nullptr && x->left == nullptr) { // если мы в корне или нет левого поддерева, выдаст ошибку
            printf("error");
            return;
        }
        // здесь название объекта, т.е. листика, совпадает с названием указателя на тот или иной объект, don't be confused
        Node *left = x->left; // левый потомок х
        Node *parent = x->parent; // родитель
        Node *y = left->right; // правый потомок левого потомка х


        if (parent != nullptr) { // родитель не пустой
            if (parent->left == x) parent->left = left; // если пришли слева, левым потомком листика "родитель" становится листик под названием "левый"
            else parent->right = left; // если пришли справа, то "левый" лист становится правым потомком "родителя"
        }
        else root = left; // родитель пустой=начинаем с левого потомка х
        left->parent = parent; // родительская связь теперь между левым потомком х и бывшим родителем х
        left->right = x; // х становится правым потомком бывшего левого потомка х
        x->parent = left; // бывший левый потомок х теперь его новый родитель
        x->left = y; // правый потомок бывшего левого потомка х становится левым потомком х
        if (y != nullptr) y->parent = x; // если оно вообще существует, то родительская связь устанавливается на х
    }


    void left_rotation(Node* x) {
        if (x == nullptr && x->right == nullptr) { // если мы в корне или нет правого поддерева, выдаст ошибку
            printf("error");
            return;
        }

        Node *right = x->right; // правый потомок х
        Node *parent = x->parent; // родитель
        Node *z = right->left; // левый потомок правого потомка х

        if (parent != nullptr) { // родитель не пустой
            if (parent->right == x) parent->right = right; // если пришли справа
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
        right_rotation(x->right); // правый поворот вызывается для правого потомка х, то есть это малый поворот
        left_rotation(x); // левый поворот, вызываемый для самого х
    }
    void left_right_rotation(Node* x) {
        left_rotation(x->left); // левый поворот для левого потомка х
        right_rotation(x); // правый поворот для х
    }


    Node* lookfor(Node* x, Key k) const { //поиск узла в поддереве с корнем x с заданным ключом, nullptr если не найден
        while (x != nullptr and ((k > x->key) or (k < x->key))) { // х не пуст и выполняется либо ключ<k, либо ключ>k
            if (k < x->key) // если ключ>k, то идем по дереву влево, так как слева элементы, меньшие корня
                x = x->left;
            else x = x->right; // если наоборот, то идем вправо к большим корня элементам
        }
        return x;
    }

    Node* minimum(Node* x) const { //последовательно спускаясь вниз,ищем самый левый элемент, так как там все, что меньше корня
        while (x->left != nullptr) {
            x = x->left;
        }
        return x;
    }
    Node* maximum(Node* x) const { //ищем самый правый элемент, так как на горизонтальной прямой, где расположены все элементы, справа все, что больше корня
        while (x->right != nullptr) {
            x = x->right;
        }
        return x;
    }

     Node* next(Node* x) const { //следующий по величине элемент за х
        if (x->right != nullptr) { // если есть правый потомок, то относительно него вызывается "найти минимум" в этом поддереве, т.е., спускаясь на нижние уровни до конца дерева, найти самый левый элемент и именно он будет следующим по значению после х
            return minimum(x->right); //(здесь ось, проходящая через х является осью симметрии для своих поддеревеьев и их потомков и все эти элементы бесконечно стремятся к этой оси)
        }
        Node* n = x->parent; // пусть n - родительский лист х
        while (n != nullptr and x == n->right) { // родитель непуст и х - его правый потомок
            x = n; // идем наверх, пока не наткнемся на выход из цикла. Пока мы приходим наверх справа, мы отдаляемся по значению от х и от его оси симметрии, но один раз затем поднявшись по левому пути, мы перепрыгнем ось симметрии, таким образом найдя следующий по значению элемент
            n = n->parent;
        }
        return n;
    }
    Node* prev(Node* x) const { // предшествующий по величине элемент за х
        if (x->left != nullptr) { // если есть левый потомок, то относительно него вызывается "найти максимум" в этом поддереве, т.е., спускаясь на нижние уровни до конца дерева, найти самый правый элемент и именно он будет предшествующим по значению х
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
        Node* y = nullptr; // у - пустой листик
        Node* x = root; // х - корень дерева, куда надо вставить лист z с указанным значением key
        while (x != nullptr) { //поиск места под вставку
            y = x; // ходим иксом, а игрек тянем за собой. Когда х выйдет из цикла, у останется в последнем узле перед null
            if (cmp(z->key, x->key)) // сравниваем значения ключей в этих листочках
                x = x->left; // если то, что надо вставить, меньше, чем значение ключа в конкретном х, то понятно, что его нужно вставить куда-то левее, так что идем влево
            else if (!cmp(z->key, x->key)) // если то, что надо вставить, больше ключа в х, надо расположить его правее
                x = x->right;
            else return false; //равенство ключей = вставка не удалась
        }
        z->parent = y; // определили родителя для вставляемого узла
        if (y == nullptr) { //дерево было пустым
            root = z; // то вставляемый узел есть единственный первый элемент
            c++; // мощность множества элементов увеличивается
            return true; // вставка удалась
        }
        else {
            if (cmp(z->key, y->key)) // надо понять вставлять влево или вправо
                y->left = z; // ключ z < ключа в у = z становится левым потомком у
            else y->right = z; // иначе, правым
            balance_after_insert(z); // теперь сбалансируем
            c++; // мощность увеличивается
            return true; // вставка удалась
        }
    }

    void balance_after_insert(Node* x) {
        while (x->parent != nullptr) { // пока родитель икса не пуст, поднимаемся наверх, считая баланс фактор
            if (x == x->parent->left) { // если пришли к родителю слева, это увеличивает баланс фактор на 1
                x->parent->factor += 1;
            }
            else {
                x->parent->factor -= 1; // пришли српава - уменьшает фактор на 1
            }
            if (x->parent->factor == 0) // если подняли наверх и фактор = 0, ничего балансировать не нужно
                break;
            else if (x->parent->factor == 1 or x->parent->factor == -1) { // если поднялись и получили фактор +-1, тянем х выше, так как такие значения разбаланса допустимы
                x = x->parent;
                continue;
            }  // всего 6 различных ситуаций разбаланса, мы можем подобрать необходимый поворот и предсказать новые значения факторов
                else {
                    if (x->parent->factor == 2 and x->factor == 1) { // если на уровне икса фактор 1, а поднявшись на уровень выше, получили 2
                        right_rotation(x->parent); // то необходимо совершить правый поворот для родительского листка х
                        x->factor = 0; // после этого х станет на уровень выше и для него и для нового правого потомка х фактор станет 0
                        x->right->factor = 0;
                }
                else if (x->parent->factor == 2 and x->factor == 0) { // фактор на родителе 2, на х - 0, применяем правый поворот к родителю
                    right_rotation(x->parent);
                    x->factor = 1; // фактор икса становится 1, правого потомка -1
                    x->right->factor = -1;
                }
                else if (x->parent->factor == 2 and x->factor == -1) {// для этой ситуации рассмотрим отдельно варианты, когда значения фактора правого потомка равны 1, 0 и -1
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
                else if (x->parent->factor == -2 and x->factor == -1) {// зеркальная ситуация, только поворот левый, значения фактора после мы предсказываем
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
            //пересчёт
            if (x == x->parent->left) {//если пришли слева от х к родителю на уровень выше, это уменьшает баланс фактор на 1, так как мы только что удалили там листик, создав перевес баланса в правую сторону
                x = x->parent;
                x->factor -= 1;
            }
            else {//если пришли справа от х к родителю на уровень выше, это увеличивает фактор на 1 по той же причине
                x = x->parent;
                x->factor += 1;
            }
            if (x->factor == 1 or x->factor == -1)
                break; //
            else if (x->factor == 0) {
                continue; // балансировка не нужна, идем дальше
            }
            else { // опять рассматриваем 6 известных ситуаций, используя значения фактора х и сначала левого, а потом и правого потомка х
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
                else if (x->factor == 2 and x->left->factor == -1) { // тут проверяем х, его детей и внуков, применяем необходимые повороты и присваиваем новые значения факторов
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

    Node* erase(Node* r, Key z) { // r - корень дерево, из которого производится удаление, z - значение ключа, которое надо стереть
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
    iterator next1(iterator i) const { //следующий элемент
        return next(i);
    }
    iterator prev1(iterator i) const {//предыдущий элемент
        return prev(i);
    }


    };
