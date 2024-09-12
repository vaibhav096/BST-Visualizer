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
