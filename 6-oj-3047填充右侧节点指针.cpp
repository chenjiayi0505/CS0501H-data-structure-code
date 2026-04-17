#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node(int x): val(x), left(NULL), right(NULL), next(NULL) {}  
};

Node **createTree(int n, Node*& root){
    int *lefts = new int [n];
    int *rights = new int [n];
    int *vals = new int [n];

    for (int i=0; i<n; i++){
        cin>>vals[i]>>lefts[i]>>rights[i];
    }

    Node ** binarytree = new Node *[n];
    for (int i=0; i<n; i++){
        binarytree[i] = new Node(vals[i]);
    }

    for (int i=0;i<n;i++){
        if(lefts[i]!=0){
            binarytree[i]->left=binarytree[lefts[i]-1];
        }
        if(rights[i]!=0){
            binarytree[i]->right=binarytree[rights[i]-1];
        }
    }

    root = binarytree[0];

    delete[] vals;
    delete[] lefts;
    delete[] rights;

    return binarytree;
}

void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

void connect(Node *root){
    if (!root) return;
    Node *rowstart = root;

    while (rowstart->left){
        Node *cur = rowstart;
        while (cur){
            cur->left->next = cur->right;
            if (cur->next){
                cur->right->next = cur->next->left;
            }
            cur = cur->next;
        }
        rowstart = rowstart->left;
    }
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    Node** nodes = createTree(n, root);
    connect(root);
    
    for (int i = 0; i < n; i++) {
        if (nodes[i]->next) {
            int nextId = 0;
            for (int j = 0; j < n; j++) {
                if (nodes[j] == nodes[i]->next) {
                    nextId = j + 1;  
                    break;
                }
            }
            cout << nextId << endl;
        } 
        else {
            cout << 0 << endl;
        }
    }
    
    for (int i = 0; i < n; i++) {
        delete nodes[i];
    }
    delete[] nodes;
    
    return 0;
}