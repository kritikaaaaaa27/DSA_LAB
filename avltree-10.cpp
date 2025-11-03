#include <iostream>
#include <string>
using namespace std;
struct Contact {
    int id;
    string name;
    string phone;
    string email;
};
struct Node {
    Contact info;
    Node* left;
    Node* right;
    int height;
};
int getHeight(Node* n) {
    if (n == NULL)
        return 0;
    else
        return n->height;
}
int getMax(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}
Node* createNode(Contact c) {
    Node* temp = new Node;
    temp->info = c;
    temp->left = NULL;
    temp->right = NULL;
    temp->height = 1;
    return temp;
}
Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* t2 = x->right;
    x->right = y;
    y->left = t2;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* t2 = y->left;
    y->left = x;
    x->right = t2;
    x->height = getMax(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = getMax(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}
int getBalance(Node* n) {
    if (n == NULL)
        return 0;
    else
        return getHeight(n->left) - getHeight(n->right);
}
Node* addContact(Node* root, Contact c) {
    if (root == NULL)
        return createNode(c);
    if (c.name < root->info.name)
        root->left = addContact(root->left, c);
    else if (c.name > root->info.name)
        root->right = addContact(root->right, c);
    else {
        cout << "Contact with same name already exists!\n";
        return root;
    }
    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);
    if (balance > 1 && c.name < root->left->info.name)
        return rotateRight(root);
    if (balance < -1 && c.name > root->right->info.name)
        return rotateLeft(root);
    if (balance > 1 && c.name > root->left->info.name) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && c.name < root->right->info.name) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}
void showContacts(Node* root) {
    if (root == NULL)
        return;
    showContacts(root->left);
    cout << "\nContact ID: " << root->info.id;
    cout << "\nName: " << root->info.name;
    cout << "\nPhone: " << root->info.phone;
    cout << "\nEmail: " << root->info.email;
    showContacts(root->right);
}
Node* searchByName(Node* root, string name) {
    if (root == NULL)
        return NULL;
    if (name == root->info.name)
        return root;
    else if (name < root->info.name)
        return searchByName(root->left, name);
    else
        return searchByName(root->right, name);
}
Node* searchByPhone(Node* root, string phone) {
    if (root == NULL)
        return NULL;
    if (root->info.phone == phone)
        return root;

    Node* left = searchByPhone(root->left, phone);
    if (left != NULL)
        return left;

    return searchByPhone(root->right, phone);
}

Node* searchByEmail(Node* root, string email) {
    if (root == NULL)
        return NULL;
    if (root->info.email == email)
        return root;

    Node* left = searchByEmail(root->left, email);
    if (left != NULL)
        return left;

    return searchByEmail(root->right, email);
}

void updateContact(Node* root) {
    cin.ignore();
    string name;
    cout << "Enter the name of the contact to update: ";
    getline(cin, name);

    Node* found = searchByName(root, name);
    if (found == NULL) {
        cout << "Contact not found!\n";
        return;
    }
    cout << "\nCurrent Phone: " << found->info.phone;
    cout << "\nCurrent Email: " << found->info.email;
    cout << "\nEnter new phone: ";
    getline(cin, found->info.phone);
    cout << "Enter new email: ";
    getline(cin, found->info.email);

    cout << "\nContact updated successfully!\n";
}
void showMenu() {
    cout << "\nCONTACT MANAGEMENT SYSTEM";
    cout << "\n1. Add New Contact";
    cout << "\n2. Display All Contacts";
    cout << "\n3. Search by Name";
    cout << "\n4. Search by Phone";
    cout << "\n5. Search by Email";
    cout << "\n6. Update Contact";
    cout << "\n7. Exit";
    cout << "\nEnter your choice: ";
}
int main() {
    Node* root = NULL;
    int choice;
    do {
        showMenu();
        cin >> choice;

        if (choice == 1) {
            Contact c;
            cout << "Enter Contact ID: ";
            cin >> c.id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, c.name);
            cout << "Enter Phone: ";
            getline(cin, c.phone);
            cout << "Enter Email: ";
            getline(cin, c.email);
            root = addContact(root, c);
            cout << "Contact added successfully!\n";
        }
        else if (choice == 2) {
            if (root == NULL)
                cout << "\nNo contacts found. Please add some contacts first!\n";
            else {
                cout << "\nAll Contacts:\n";
                showContacts(root);
            }
        }

        else if (choice == 3) {
            cin.ignore();
            string name;
            cout << "Enter Name to Search: ";
            getline(cin, name);
            Node* res = searchByName(root, name);
            if (res != NULL) {
                cout << "\nContact Found!";
                cout << "\nID: " << res->info.id;
                cout << "\nPhone: " << res->info.phone;
                cout << "\nEmail: " << res->info.email << "\n";
            } else
                cout << "Contact not found!\n";
        }

        else if (choice == 4) {
            cin.ignore();
            string phone;
            cout << "Enter Phone Number to Search: ";
            getline(cin, phone);
            Node* res = searchByPhone(root, phone);
            if (res != NULL) {
                cout << "\nContact Found!";
                cout << "\nName: " << res->info.name;
                cout << "\nID: " << res->info.id;
                cout << "\nEmail: " << res->info.email << "\n";
            } else
                cout << "Contact not found!\n";
        }

        else if (choice == 5) {
            cin.ignore();
            string email;
            cout << "Enter Email to Search: ";
            getline(cin, email);
            Node* res = searchByEmail(root, email);
            if (res != NULL) {
                cout << "\nContact Found!";
                cout << "\nName: " << res->info.name;
                cout << "\nPhone: " << res->info.phone;
                cout << "\nID: " << res->info.id << "\n";
            } else
                cout << "Contact not found!\n";
        }

        else if (choice == 6) {
            if (root == NULL)
                cout << "No contacts to update!\n";
            else
                updateContact(root);
        }

        else if (choice == 7) {
            cout << "Thank you!\n";
        }

        else {
            cout << "Invalid choice\n";
        }

    } while (choice != 7);

    return 0;
}

