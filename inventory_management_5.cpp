#include <bits/stdc++.h>
using namespace std;
struct Product {
    int id;
    string name;  
    int quantity;
    float price;
    Product* next;
};
Product* head = nullptr;
void addProd(int id, string name, int quantity, float price) {
    Product* newp = new Product;
    newp->id = id;
    newp->name = name;
    newp->quantity = quantity;
    newp->price = price;
    newp->next = nullptr;
    if (head == nullptr) {
        head = newp;
    }
    else {
        Product* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newp;
    }
}
void disppro() {
    Product* temp = head;
    if (temp == nullptr) {
        cout << "   Inventory Empty.\n";
        return;
    }
    cout << "\n--- Current Inventory ---\n";
    while (temp != nullptr) {
        cout << "ID: " << temp->id
            << ", Name: " << temp->name
            << ", Qty: " << temp->quantity
            << ", Price: $" << temp->price << endl;
        temp = temp->next;
    }
}
void updateProd(int id) {
    Product* temp = head;
    bool found = false;
    while (temp != nullptr) {
        if (temp->id == id) {  
            found = true;
            int option;
            cout << "\nUpdate Options:\n"
                 << "1. New Quantity & Price\n"
                 << "2. Adjust Quantity\n"
                 << "Enter choice: ";
            cin >> option;

            if (option == 1) {
                int qty; float price;
                cout << "New Quantity: ";
                cin >> qty;
                cout << "New Price: ";
                cin >> price;
                temp->quantity = qty;
                temp->price = price;
                cout << "Product updated.\n";
            } 
            else if (option == 2) {
                int change;
                cout << "Enter change in quantity: ";
                cin >> change;
                temp->quantity += change;
                if (temp->quantity < 0) temp->quantity = 0;
                cout << "New Quantity = " << temp->quantity << endl;
            } 
            else {
                cout << "Invalid option.\n";
            }
            break;
        }
        temp = temp->next;
    }
    if (!found) {
        cout << "Product not found.\n";
    }
}
void delPro(int id) {
    if (head == nullptr) {
        cout << "Inventory Empty.\n";
        return;
    }
    if (head->id == id) {
        Product* toDelete = head;
        head = head->next;
        delete toDelete;
        cout << "Product deleted.\n";
        return;
    }
    Product* temp = head;
    while (temp->next != nullptr && temp->next->id != id) {
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Product not found.\n";
    }
    else {
        Product* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "Product deleted.\n";
    }
}
void totalval() {
    float tot = 0;
    Product* temp = head;
    while (temp != nullptr) {
        tot += temp->quantity * temp->price;
        temp = temp->next;
    }
    cout << "Total Value: " << tot << endl;
}
int main() {
    addProd(101, "Laptop", 50, 800);
    addProd(102, "Smartphone", 100, 500);
    addProd(103, "Tablet", 30, 400);

    int choice;
    do {
        cout << "\n-------Iventory Management-------\n"<< "1. Add Product\n"<< "2. Display Products\n"<< "3. Update Product\n"<< "4. Delete Product\n"
             << "5. Total Valuation\n"<< "6. Exit\n"<< "Enter: ";
        cin >> choice;
        if (choice == 1) {
            int id, qty;
            float price;
            string name;
            cout << "ID: ";
            cin >> id;
            cin.ignore();
            cout << "Name: ";
            getline(cin, name);
            cout << "Quantity: ";
            cin >> qty;
            cout << "Price: ";
            cin >> price;
            addProd(id, name, qty, price);
        }
        else if (choice == 2) {
            disppro();
        }
        else if (choice == 3) {
            int id;
            cout << "Product ID: ";
            cin >> id;
            updateProd(id);
        }
        else if (choice == 4) {
            int id;
            cout << "Product ID: ";
            cin >> id;
            delPro(id);
        }
        else if (choice == 5) {
            totalval();
        }
        else if (choice == 6) {
            cout << "Thank you\n";
        }
        else {
            cout << "Invalid.\n";
        }
    } while (choice != 6);
    return 0;
}
