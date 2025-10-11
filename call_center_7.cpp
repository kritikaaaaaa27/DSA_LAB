#include <iostream>
using namespace std;

struct Request {
    int id;
    string name;
    string ser;
    string status;
    Request* next;
    Request(int i, string n, string s) {
        id = i;
        name = n;
        ser = s;
        status = "Pending";
        next = NULL;
    }
};
class Queue {
    Request* head;
    Request* tail;
    Request* newhead;
public:
    Queue() {
        head = tail = NULL;
        newhead = NULL;
    }
    void add(int id, string name, string ser) {
        Request* newReq = new Request(id, name, ser);
        if (tail == NULL) {
            head = tail = newReq;
        } else {
            tail->next = newReq;
            tail = newReq;
        }
        cout << "Added: Request ID: " << id 
             << ", Name: " << name 
             << ", Service: " << ser 
             << ", Status: Pending" << endl;
    }
    void preload(int id, string name, string ser) {
        Request* newReq = new Request(id, name, ser);
        if (tail == NULL) {
            head = tail = newReq;
        } else {
            tail->next = newReq;
            tail = newReq;
        }
    }
    void process() {
        if (head == NULL) {
            cout << "No requests to process." << endl;
            return;
        }
        Request* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        temp->status = "Completed";
        cout << "Processed: Request ID: " << temp->id 
             << ", Name: " << temp->name 
             << ", Service: " << temp->ser 
             << ", Status: " << temp->status << endl;
        temp->next = newhead;
        newhead = temp;
    }
    void pending() {
        if (head == NULL) {
            cout << "No pending requests." << endl;
            return;
        }
        cout << "Pending Requests:" << endl;
        Request* temp = head;
        while (temp != NULL) {
            cout << "Request ID: " << temp->id 
                 << ", Name: " << temp->name 
                 << ", Service: " << temp->ser 
                 << ", Status: " << temp->status << endl;
            temp = temp->next;
        }
    }
    void display() {
        cout << "All Requests:" << endl;
        Request* t = newhead;
        while (t != NULL) {
            cout << "Request ID: " << t->id 
                 << ", Name: " << t->name 
                 << ", Service: " << t->ser 
                 << ", Status: " << t->status << endl;
            t = t->next;
        }
        Request* p = head;
        while (p != NULL) {
            cout << "Request ID: " << p->id 
                 << ", Name: " << p->name 
                 << ", Service: " << p->ser 
                 << ", Status: " << p->status << endl;
            p = p->next;
        }
    }
};
int main() {
    Queue q;
    int choice, id;
    string name, ser;
    q.preload(101,"John Doe","Technical Support");
    q.preload(102,"Jane Smith","Billing Inquiry");
    q.preload(103,"David Brown","Product Information");
    while (true) {
        cout << "\n--- Call Center ---\n"<< "1. Add Request\n"<< "2. Process Request\n"<< "3. Show Pending Requests\n"<< "4. Show All Requests\n"<< "5. Exit\n"<< "Enter choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Enter Request ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Customer Name: ";
                getline(cin, name);
                cout << "Enter Service Type: ";
                getline(cin, ser);
                q.add(id, name, ser);
                break;
            case 2:
                q.process();
                break;
            case 3:
                q.pending();
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid." << endl;
        }
    }
}
