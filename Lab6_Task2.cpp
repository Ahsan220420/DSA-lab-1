#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class List {
    Node* head;

public:
    List() { head = nullptr; }

    void insertBegin(int value) {
        Node* n = new Node();
        n->data = value;
        n->next = head;
        head = n;
    }

    void insertEnd(int value) {
        Node* n = new Node();
        n->data = value;
        n->next = nullptr;

        if (head == nullptr) {
            head = n;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = n;
    }

    void deleteValue(int value) {
        if (head == nullptr) return;

        if (head->data == value) {
            Node* t = head;
            head = head->next;
            delete t;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != value)
            temp = temp->next;

        if (temp->next != nullptr) {
            Node* t = temp->next;
            temp->next = t->next;
            delete t;
        }
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    List l;
    l.insertBegin(10);
    l.insertBegin(5);
    l.insertEnd(20);
    l.insertEnd(30);
    l.display();
    l.deleteValue(20);
    l.display();
    return 0;
}