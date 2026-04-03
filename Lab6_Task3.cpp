#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void insertAtPos(int val, int pos) {
    Node* n = new Node{val, nullptr};
    if (pos == 1) {
        n->next = head;
        head = n;
        return;
    }
    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++)
        temp = temp->next;
    if (temp == nullptr) return;
    n->next = temp->next;
    temp->next = n;
}

void deleteAtPos(int pos) {
    if (head == nullptr) return;
    if (pos == 1) {
        Node* t = head;
        head = head->next;
        delete t;
        return;
    }
    Node* temp = head;
    for (int i = 1; temp->next != nullptr && i < pos - 1; i++)
        temp = temp->next;
    if (temp->next == nullptr) return;
    Node* t = temp->next;
    temp->next = t->next;
    delete t;
}

void search(int key) {
    Node* temp = head;
    int pos = 1;
    while (temp != nullptr) {
        if (temp->data == key) {
            cout << "Found at position " << pos << endl;
            return;
        }
        temp = temp->next;
        pos++;
    }
    cout << "Not Found" << endl;
}

void countNodes() {
    Node* temp = head;
    int count = 0;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    cout << "Total nodes: " << count << endl;
}

void display() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, val, pos;
    while (1) {
        cout << "\n1.Insert 2.Delete 3.Search 4.Count 5.Display 6.Exit\n";
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> val >> pos;
                insertAtPos(val, pos);
                break;
            case 2:
                cin >> pos;
                deleteAtPos(pos);
                break;
            case 3:
                cin >> val;
                search(val);
                break;
            case 4:
                countNodes();
                break;
            case 5:
                display();
                break;
            case 6:
                return 0;
        }
    }
}