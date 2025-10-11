#include <bits/stdc++.h>
using namespace std;
struct Node {
    string n;
    int a;
    string c;
    Node* next;
};
Node* head = nullptr;
void addp() {
    string nm, cond;
    int age;
    cout << "Enter patient name, age, condition:"<<endl;
    cin >> nm >> age >> cond;
    Node* p = new Node{nm, age, cond, nullptr};
    if (!head)
        head = p;
    else {
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = p;
    }
    cout << "Patient added!\n";
}
void remove() {
    if (!head) {
        cout << "Queue empty!\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Patient removed from front.\n";
}
void showQueue() {
    if (!head) {
        cout << "No patients in queue.\n";
        return;
    }
    Node* temp = head;
    cout << "Current Queue:\n";
    while (temp) {
        cout << "Name: " << temp->n << ", Age: " << temp->a << ", Condition: " << temp->c << endl;
        temp = temp->next;
    }
}
void search() {
    if (!head) {
        cout << "Queue is empty.\n";
        return;
    }
    string nm;
    cout << "Enter name to search: ";
    cin >> nm;
    Node* temp = head;
    while (temp) {
        if (temp->n == nm) {
            cout << "Found! Name: " << temp->n << ", Age: " << temp->a << ", Condition: " << temp->c << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Patient not found.\n";
}
void update() {
    if (!head) {
        cout << "Queue is empty.\n";
        return;
    }
    string nm;
    cout << "Enter patient name to update: ";
    cin >> nm;
    Node* temp = head;
    while (temp) {
        if (temp->n == nm) {
            cout << "Enter new age and condition: ";
            cin >> temp->a >> temp->c;
            cout << "Patient info updated.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Patient not found.\n";
}
void priortize() {
    if (!head) {
        cout << "Queue empty!\n";
        return;
    }
    string nm;
    cout << "Enter patient name to prioritize: ";
    cin >> nm;
    Node* prev = nullptr;
    Node* curr = head;
    while (curr && curr->n != nm) {
        prev = curr;
        curr = curr->next;
    }
    if (!curr) {
        cout << "Patient not found.\n";
        return;
    }
    if (prev) {
        prev->next = curr->next;
        curr->next = head;
        head = curr;
        cout << "Patient moved to front.\n";
    } else {
        cout << "Patient already at front.\n";
    }
int main() {
    int ch;
    cout<<"--------Hospital Management System--------";
    cout<<"\nChoose from the below options:";
    do {
        cout << "\n 1.Add Patient"<<endl<<" 2.Remove Patient"<<endl<<" 3.Show Queue"<<endl<<" 4.Search"<<endl<<" 5.Update"<<endl<<" 6.Prioritize"<<endl<<" 7.Exit"<<endl;
        cin >> ch;
        switch(ch) {
            case 1: addp(); break;
            case 2: remove(); break;
            case 3: showQueue(); break;
            case 4: search(); break;
            case 5: update(); break;
            case 6: priortize(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (ch != 7);
    return 0;
}
