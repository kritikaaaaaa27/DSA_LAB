#include <iostream>
using namespace std;
struct Order {
    int id;
    string name;
    string items;
    string status;
};
class CircularQueue {
    Order* arr;
    int front, rear, s, cap;
public:
    CircularQueue(int c) {
        cap = c;
        arr = new Order[cap];
        front = rear = -1;
        s = 0;
    }
    bool isFull() { return (s == cap); }
    bool isEmpty() { return (s == 0); }
    void addOrder(int id, string name, string items) {
        if (isFull()) {
            cout << "Queue Full.\n";
            return;
        }
        rear = (rear + 1) % cap;
        arr[rear].id = id;
        arr[rear].name = name;
        arr[rear].items = items;
        arr[rear].status = "Pending";
        if (front == -1) front = rear;
        s++;
        cout << "Order Added: ID " << id << ", Customer: " << name 
             << ", Items: " << items << ", Status: Pending\n";
    }
    void pre(int id, string name, string items) {
        if (isFull()) return;
        rear = (rear + 1) % cap;
        arr[rear].id = id;
        arr[rear].name = name;
        arr[rear].items = items;
        arr[rear].status = "Pending";
        if (front == -1) front = rear;
        s++;
    }
    void processOrder() {
        if (isEmpty()) {
            cout << "No orders to process.\n";
            return;
        }
        Order &current = arr[front];
        cout << "Processing Order ID: " << current.id 
             << ", Customer: " << current.name
             << ", Items: " << current.items << endl;
        current.status = "Completed";
        front = (front + 1) % cap;
        s--;
    }
    void showPending() {
        if (isEmpty()) {
            cout << "No pending orders.\n";
            return;
        }
        cout << "--- Pending Orders ---\n";
        int count = 0, i = front;
        while (count < s) {
            cout << "Order ID: " << arr[i].id 
                 << ", Customer: " << arr[i].name
                 << ", Items: " << arr[i].items
                 << ", Status: " << arr[i].status << endl;
            i = (i + 1) % cap;
            count++;
        }
    }
    void showAll() {
        if (isEmpty()) {
            cout << "No orders in system.\n";
            return;
        }
        cout << "--- All Orders ---\n";
        int count = 0, i = front;
        while (count < s) {
            cout << "Order ID: " << arr[i].id << ", Customer: " << arr[i].name<< ", Items: " << arr[i].items<< ", Status: " << arr[i].status << endl;
            i = (i + 1) % cap;
            count++;
        }
    }
};
int main() {
    CircularQueue cq(10); 
    cq.pre(101, "Rahul Sharma", "Burger, Fries, Drink");
    cq.pre(102, "Priya Patel", "Chicken Sandwich, Salad, Drink");
    cq.pre(103, "Aarav Gupta", "Pizza, Wings, Drink");
    int choice, id;
    string name, items;
    while (true) {
        cout << "\n--- Drive-Thru Menu ---\n"<< "1. Add Order\n"<< "2. Process Order\n"<< "3. Show Pending Orders\n"<< "4. Show All Orders\n"<< "5. Exit\n"<< "Enter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter Order ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Customer Name: ";
                getline(cin, name);
                cout << "Enter Items: ";
                getline(cin, items);
                cq.addOrder(id, name, items);
                break;
            case 2:
                cq.processOrder();
                break;
            case 3:
                cq.showPending();
                break;
            case 4:
                cq.showAll();
                break;
            case 5:
                cout << "Thank You!\n";
                return 0;
            default:
                cout << "Invalid choice.\n";
        }}}
