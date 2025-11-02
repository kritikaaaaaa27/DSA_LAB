#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int val) { data = val; left = right = NULL; }
};

class BST {
public:
    Node* root;
    BST() { root = NULL; }

    void insertNode(int val) {
    Node* temp = new Node(val);
    if (!root) {
        root = temp;
        cout << "Inserted " << val << "\n";
        return;
    }
        Node* parent = NULL;
        Node* curr = root;
        while (curr) {
            parent = curr;
            if (val == curr->data) {
                cout << "Duplicate " << val << " ignored.\n";
                return;
            } else if (val < curr->data)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (val < parent->data) parent->left = temp;
        else parent->right = temp;
        cout << "Inserted\n";
    }

    Node* deleteNode(Node* root, int key) {
        if (!root) return root;
        if (key < root->data)
            root->left = deleteNode(root->left, key);
        else if (key > root->data)
            root->right = deleteNode(root->right, key);
        else {
            if (!root->left) return root->right;
            else if (!root->right) return root->left;
            root->data = findMin(root->right);
            root->right = deleteNode(root->right, root->data);
        }
        return root;
    }
    int findMin(Node* node) {
        while (node->left) node = node->left;
        return node->data;
    }
    bool searchNode(int val) {
        Node* curr = root;
        while (curr) {
            if (curr->data == val) return true;
            else if (val < curr->data) curr = curr->left;
            else curr = curr->right;
        }
        return false;
    }
    void inorder(Node* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void postorder(Node* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
    int depth(Node* node) {
        if (!node) return 0;
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
    Node* mirror(Node* node) {
        if (!node) return NULL;
        Node* temp = node->left;
        node->left = mirror(node->right);
        node->right = mirror(temp);
        return node;
    }

    Node* copyTree(Node* node) {
        if (!node) return NULL;
        Node* newNode = new Node(node->data);
        newNode->left = copyTree(node->left);
        newNode->right = copyTree(node->right);
        return newNode;
    }

    void displayParents(Node* node) {
        if (!node) return;
        if (node->left)
            cout << "Parent " << node->data << " → Left Child " << node->left->data << endl;
        if (node->right)
            cout << "Parent " << node->data << " → Right Child " << node->right->data << endl;
        displayParents(node->left);
        displayParents(node->right);
    }

    void displayLeaves(Node* node) {
        if (!node) return;
        if (!node->left && !node->right)
            cout << node->data << " ";
        displayLeaves(node->left);
        displayLeaves(node->right);
    }

    void levelWise() {
        if (!root) return;
        Node* queue[100];
        int front = 0, rear = 0;
        queue[rear++] = root;
        while (front < rear) {
            Node* curr = queue[front++];
            cout << curr->data << " ";
            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
    }
};

int main() {
    BST tree;
    int choice, val;
    do {
        cout << "1.Insert  2.Delete  3.Search  4.Traversal  5.Depth  6.Mirror  7.Copy  8.Parent-Child  9.Leaf  10.Level-wise  0.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter value to insert: ";
                cin >> val;
                tree.insertNode(val);
                break;
            }
            case 2: {
                cout << "Enter value to delete: ";
                cin >> val;
                tree.root = tree.deleteNode(tree.root, val);
                cout << "Node deleted.\n";
                break;
            }
            case 3: {
                cout << "Enter value to search: ";
                cin >> val;
                cout << (tree.searchNode(val) ? "Element found.\n" : "Element not found.\n");
                break;
            }
            case 4: {
                cout << "Inorder: ";
                tree.inorder(tree.root);
                cout << "\nPreorder: ";
                tree.preorder(tree.root);
                cout << "\nPostorder: ";
                tree.postorder(tree.root);
                cout << endl;
                break;
            }
            case 5: {
                cout << "Depth of tree: " << tree.depth(tree.root) << endl;
                break;
            }
            case 6: {
                tree.root = tree.mirror(tree.root);
                cout << "Mirror image\n";
                break;
            }
            case 7: {
                Node* cloneRoot = tree.copyTree(tree.root);
                cout << "Inorder of copy tree: ";
                tree.inorder(cloneRoot);
                cout << endl;
                break;
            }
            case 8: {
                cout << "Displaying parent-child relationships:\n";
                tree.displayParents(tree.root);
                break;
            }
            case 9: {
                cout << "Leaf nodes are: ";
                tree.displayLeaves(tree.root);
                cout << endl;
                break;
            }
            case 10: {
                cout << "Level-wise tree display:\n";
                tree.levelWise();
                cout << endl;
                break;
            }
        }
    } while (choice != 0);

    return 0;
}


