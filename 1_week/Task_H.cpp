Node *mergeLists(Node *first_node, Node *second_node){
    Node *main = NULL;

        if (second_node == NULL)
            return first_node;
        else if (first_node == NULL)
            return second_node;
        else if (first_node -> value < second_node -> value){
            main = first_node;
            main -> next = mergeLists(first_node -> next, second_node);
        } else {
            main = second_node;
            main -> next = mergeLists(first_node, second_node-> next);
        }

        Node *x = main;
        Node *y;

        while(x -> next != NULL){
            if (x -> value != x -> next -> value){
                x = x -> next;
            } else {
                y = x -> next -> next;
                free(x -> next);
                x -> next = y;
            }
        }
    return main;
}
