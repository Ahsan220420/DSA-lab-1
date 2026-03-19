#include <iostream>
using namespace std;

class Stack {
private:
    string arr[100];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(string x) {
        if (top < 99)
            arr[++top] = x;
    }

    string pop() {
        if (isEmpty())
            return "";
        return arr[top--];
    }
};

int main() {
    Stack undoStack, redoStack;
    string text = "";
    string word;
    int choice;

    do {
        cout << "\nCurrent Text: " << text << endl;
        cout << "1. Type Word\n2. Delete Last Word\n3. Undo\n4. Redo\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter word: ";
            cin >> word;
            undoStack.push(text);
            if (text == "")
                text = word;
            else
                text = text + " " + word;
            while (!redoStack.isEmpty()) redoStack.pop();
            break;

        case 2:
            if (text != "") {
                undoStack.push(text);
                int pos = text.find_last_of(' ');
                if (pos == -1)
                    text = "";
                else
                    text = text.substr(0, pos);
                while (!redoStack.isEmpty()) redoStack.pop();
            } else {
                cout << "Nothing to delete\n";
            }
            break;

        case 3:
            if (!undoStack.isEmpty()) {
                redoStack.push(text);
                text = undoStack.pop();
            } else {
                cout << "Nothing to undo\n";
            }
            break;

        case 4:
            if (!redoStack.isEmpty()) {
                undoStack.push(text);
                text = redoStack.pop();
            } else {
                cout << "Nothing to redo\n";
            }
            break;

        case 5:
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}