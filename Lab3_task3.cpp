#include <iostream>
using namespace std;

class myCarStack {
private:
    string arr[8];
    int top;

public:
    myCarStack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == 7;
    }

    void push(string car) {
        if (isFull()) {
            cout << "Parking Full\n";
        } else {
            arr[++top] = car;
            cout << "Car Parked\n";
        }
    }

    string pop() {
        if (isEmpty()) {
            return "";
        } else {
            return arr[top--];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No Cars Parked\n";
        } else {
            cout << "Cars in Parking:\n";
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << endl;
            }
        }
    }

    int count() {
        return top + 1;
    }

    bool search(string car) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == car)
                return true;
        }
        return false;
    }

    void removeCar(string car) {
        if (isEmpty()) {
            cout << "Parking Empty\n";
            return;
        }

        myCarStack temp;
        bool found = false;

        while (!isEmpty()) {
            string x = pop();
            if (x == car) {
                found = true;
                break;
            }
            temp.push(x);
        }

        if (!found) {
            cout << "Car Not Found\n";
        } else {
            cout << "Car Removed\n";
        }

        while (!temp.isEmpty()) {
            push(temp.pop());
        }
    }
};

int main() {
    myCarStack parking;
    int choice;
    string car;

    do {
        cout << "\n1. Park Car\n2. Remove Car\n3. Display Cars\n4. Total Cars\n5. Search Car\n6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Car Number: ";
            cin >> car;
            parking.push(car);
            break;
        case 2:
            cout << "Enter Car Number to Remove: ";
            cin >> car;
            parking.removeCar(car);
            break;
        case 3:
            parking.display();
            break;
        case 4:
            cout << "Total Cars: " << parking.count() << endl;
            break;
        case 5:
            cout << "Enter Car Number to Search: ";
            cin >> car;
            if (parking.search(car))
                cout << "Car Found\n";
            else
                cout << "Car Not Found\n";
            break;
        case 6:
            break;
        default:
            cout << "Invalid Choice\n";
        }

    } while (choice != 6);

    return 0;
}