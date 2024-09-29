#include <iostream>
#include <iomanip>
using namespace std;

class node{
    public:
    node* right;
    node* left;
    int data;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

class BinarySearchTree {
    private:
    node* findnode(node* root){
        if(root->right){
            root=root->right;
        }
        while(root->left){
            root=root->left;
        }
        return root;
    }

    public:
    void insert(int d,node* &root){
        
        if(root==NULL){
            root=new node(d);
            return;
        }
        else if(d>=root->data){
           insert(d,root->right);
        }
        else{
            insert(d,root->left);
        }
    }

    

    node* remove( node* root,int x) {
        if (root==NULL) {
            cout << "Node not found! " << endl;
            return root;
        }
        if(root->data==x){
            //0 child, leaf node
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            // 1 child

            // left child
            if(root->left!=NULL && root->right==NULL){
                node* temp=root->left;
                delete root;
                return temp;
            }
            //right child
            if(root->left==NULL && root->right!=NULL){
                node* temp=root->right;
                delete root;
                return temp;
            }

            //two childs
            if(root->left!=NULL && root->right!=NULL){
                //find minimum node from the right subtree
                node* pred= findnode(root);
                cout<<"data to be replaced : "<<pred->data<<endl;
                root->data=pred->data;
                remove(root->right,pred->data);
                return root;
            }
            
        }
        else if(root->data>x){
            root->left=remove(root->left,x);
        }
        else{
            root->right=remove(root->right,x);
        }
        return root;
    }


    void postorder(node* p, int indent) {
        if (p != NULL) {
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
    int inp, ins, del;
    node* root=NULL;
    while (true) {
        cout << "\n\n Binary Search Tree Operations \n";
        cout << " ----------------------------- \n";
        cout << " 1. Insertion/Creation \n";
        cout << " 2. Printing \n";
        cout << " 3. Removal \n";
        cout << " 4. Exit \n";
        cout << " Enter your choice: ";
        cin >> inp;

        switch (inp) {
        case 1:
            cout << " Enter Number to be inserted: ";
           
            cin >> ins;
            bst.insert(ins,root);
            break;
        case 2:
            cout << " Printing in Tree \n";
            cout << " -------------------------------\n";
            if(root==NULL){
                cout<<"Tree is empty "<<endl;
                break;
            }
            bst.postorder(root,0);
            break;
        case 3:
            cout << " Enter data to be deleted: ";
            cin >> del;
            if(root==NULL){
                cout<<"Tree is empty "<<endl;
                break;
            }
            bst.remove(root,del);
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid option! Please try again.\n";
        }
    }

    return 0;
}
