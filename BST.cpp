#include <iostream>
#include <iomanip>
using namespace std;

class BinarySearchTree {
private:
    struct tree_node {
        tree_node* left;
        tree_node* right;
        int data;
    };
    tree_node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    bool isEmpty() const {
        return root == nullptr;
    }

    void insert(int val) {
        tree_node* newNode = new tree_node;
        newNode->data = val;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if (isEmpty()) {
            root = newNode;
        } else {
            tree_node* current = root;
            tree_node* parent = nullptr;
            while (current) {
                parent = current;
                if (val < current->data)
                    current = current->left;
                else
                    current = current->right;
            }
            if (val < parent->data)
                parent->left = newNode;
            else
                parent->right = newNode;
        }
    }

    void remove(int val) {
        if (isEmpty()) {
            cout << "This Tree is empty!" << endl;
            return;
        }

        tree_node* curr = root;
        tree_node* parent = nullptr;
        bool found = false;

        // Locate the node to be deleted and its parent
        while (curr != nullptr) {
            if (curr->data == val) {
                found = true;
                break;
            } else {
                parent = curr;
                if (val > curr->data)
                    curr = curr->right;
                else
                    curr = curr->left;
            }
        }

        if (!found) {
            cout << "Data not found!" << endl;
            return;
        }

        // Case 1: Node with only one child or no child
        if (curr->left == nullptr || curr->right == nullptr) {
            tree_node* temp = (curr->left != nullptr) ? curr->left : curr->right;

            // No child case
            if (temp == nullptr) {
                if (parent == nullptr)
                    root = nullptr;
                else if (curr == parent->left)
                    parent->left = nullptr;
                else
                    parent->right = nullptr;
                delete curr;
            } else {
                // One child case
                if (parent == nullptr)
                    root = temp;
                else if (curr == parent->left)
                    parent->left = temp;
                else
                    parent->right = temp;
                delete curr;
            }
        } else {
            // Case 2: Node with two children
            tree_node* successor = curr->right;
            tree_node* successorParent = nullptr;

            while (successor->left != nullptr) {
                successorParent = successor;
                successor = successor->left;
            }

            // Copy the inorder successor's data to this node
            curr->data = successor->data;

            // Delete the inorder successor
            if (successorParent != nullptr)
                successorParent->left = nullptr;
            else
                curr->right = nullptr;

            delete successor;
        }
    }

    void print_postorder() {
        postorder(root, 0);
    }

    void postorder(tree_node* p, int indent) {
        if (p != nullptr) {
            if (p->right) {
                postorder(p->right, indent + 6);
            }
            if (indent) {
                cout << setw(indent) << ' ';
            }
            cout << p->data << endl;
            if (p->left) {
                postorder(p->left, indent + 6);
            }
        }
    }

    
};

int main() {
    BinarySearchTree bst;
    int input, insert, del;

    while (true) {
        cout << "\n\n Binary Search Tree Operations \n";
        cout << " ----------------------------- \n";
        cout << " 1. Insertion/Creation \n";
        cout << " 2. Printing \n";
        cout << " 3. Removal \n";
        cout << " 4. Exit \n";
        cout << " Enter your choice: ";
        cin >> input;

        switch (input) {
        case 1:
            cout << " Enter Number to be inserted: ";
            cin >> insert;
            bst.insert(insert);
            break;
        case 2:
            cout << " Printing in Postorder Traversal\n";
            cout << " -------------------------------\n";
            bst.print_postorder();
            break;
        case 3:
            cout << " Enter data to be deleted: ";
            cin >> del;
            bst.remove(del);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
