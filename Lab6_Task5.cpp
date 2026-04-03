#include <iostream>
using namespace std;

class Node {
public:
    string name;
    int priority;
    Node* next;
};

class BookQueue {
    Node* head;

public:
    BookQueue() { head = nullptr; }

    void addStudent(string n, int p) {
        Node* s = new Node{n, p, nullptr};
        if (!head || p > head->priority) {
            s->next = head;
            head = s;
            return;
        }
        Node* t = head;
        while (t->next && t->next->priority >= p)
            t = t->next;
        s->next = t->next;
        t->next = s;
    }

    void removeStudent(string n) {
        if (!head) return;
        if (head->name == n) {
            Node* d = head;
            head = head->next;
            delete d;
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

    void updatePriority(string n, int p) {
        removeStudent(n);
        addStudent(n, p);
    }

    void serve() {
        if (!head) return;
        Node* d = head;
        head = head->next;
        delete d;
    }

    void display() {
        Node* t = head;
        while (t) {
            cout << t->name << "(" << t->priority << ") ";
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
    BookQueue book1, book2;

    book1.addStudent("Ali",1);
    book1.addStudent("Sara",3);
    book1.addStudent("Ahmed",2);

    book2.addStudent("Usman",2);
    book2.addStudent("Ayesha",1);
    book2.addStudent("Zara",3);

    cout << "Book1: "; book1.display();
    cout << "Book2: "; book2.display();

    book1.updatePriority("Ali",4);
    cout << "Book1 after update: "; book1.display();

    book2.removeStudent("Ayesha");
    cout << "Book2 after removal: "; book2.display();

    cout << "Count Book1: "; book1.count();
    cout << "Count Book2: "; book2.count();

    book1.serve();
    cout << "Book1 after serve: "; book1.display();

    return 0;
}