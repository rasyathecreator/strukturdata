#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node *ptr_first = NULL;
Node *ptr_last = NULL;

void add_first(int value) {
    Node *newNode = new Node {value, NULL, ptr_first};
    
    // if (ptr_first == NULL)
        ptr_last = newNode;
    }
    else {
        ptr_first->prev = newNode;
    }
    ptr_first = newNode;


void add_last(int value) {
    Node *newNode = new Node{value, ptr_last, NULL};
    if (ptr_last == NULL) {
        ptr_first = newNode;
    } else {
        ptr_last -> next = newNode;
    }
    ptr_last = newNode;
}

void add_target(int targetValue, int newValue){
    Node *current = ptr_first;
    while (current != NULL && current->data != targetValue){
        current = current->next;
    }

    if (current != NULL){
        add_last(newValue);
    }
    else{
        Node *newNode = new Node{newValue, current, current->next};
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void view(){
    Node *current = ptr_first;
    if (current == NULL){
        cout << "List Kosong\n";
        return;
    }
    while (current != NULL)
    {
        cout << current->data << (current->next != NULL ? " <-> " : "");
        current = current->next;
    }
    cout<< endl;
}

void delete_first(){
    if (ptr_first == NULL)
    return;

    Node *temp = ptr_first;

    if (ptr_first == ptr_last){
        ptr_first = NULL;
        ptr_last = NULL;
    }
    else{
        ptr_first = ptr_first->next;
        ptr_first->prev = NULL;
    }
    delete temp;
}

void delete_last(){
    if (ptr_last == NULL)
    return;

    Node *temp = ptr_last;

    if (ptr_first == ptr_last){
        ptr_first = NULL;
        ptr_last = NULL;
    }
    else{
        ptr_last = ptr_last->prev;
        ptr_last->next = NULL;
    }
    delete temp;
}

void delete_target(int targetValue){
    Node *current = ptr_first;
    while (current != NULL && current->data != targetValue){
        current = current->next;
    }

    if (current != NULL){
        if (current == ptr_first){
            delete_first();
            return;
        }
        if (current == ptr_last)
        {
           delete_last();
           return;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        delete current;

    }
}

void edit_node(int targetVaue, int newValue){
    Node *current = ptr_first;
    while (current != NULL && current->data != targetVaue)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        current->data = newValue;
    }
    
    
}

int main() {
    add_first(10);
    add_first(5);
    add_last(20);
    cout << "Awal\t\t\t: ";
    view();

    delete_first();
    cout << "Setelah delete_first\t: ";
    view();
    delete_last();
    cout << "Setelah delete_last\t: ";
    view();

    add_last(30);
    add_last(40);
    cout << "Setelah tambah\t\t: ";
    view();

    delete_target(30);
    cout << "Setelah delete_target\t: ";
    view();
    
}