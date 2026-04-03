#include <iostream>
using namespace std;

class Node {
public:
    string name;
    Node* next;
};

class Queue {
    Node* head;

public:
    Queue() { head = nullptr; }

    void addPatient(string n) {
        Node* p = new Node{n, nullptr};
        if (!head) {
            head = p;
            return;
        }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = p;
    }

    void removePatient(string n) {
        if (!head) return;
        if (head->name == n) {
            Node* t = head;
            head = head->next;
            delete t;
            return;
        }
        Node* t = head;
        while (t->next && t->next->name != n)
            t = t->next;
        if (t->next) {
            Node* d = t->next;
            t->next = d->next;
            delete d;
        }
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->name << " ";
            t = t->next;
        }
        cout << endl;
    }

    void count() {
        int c = 0;
        Node* t = head;
        while (t) {
            c++;
            t = t->next;
        }
        cout << c << endl;
    }
};

int main() {
    Queue q;
    q.addPatient("Ali");
    q.addPatient("Sara");
    q.addPatient("Ahmed");
    q.display();
    q.count();
    q.removePatient("Sara");
    q.display();
    q.count();
    return 0;
}