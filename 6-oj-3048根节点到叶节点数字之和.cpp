# include <iostream>
using namespace std;

class treenode{
    public:
    int val;
    treenode *left;
    treenode *right;

    treenode(int x):val(x),left(NULL),right(NULL){};
};


treenode *buildtree(int n){

    int *val = new int [n];
    int *right = new int [n];
    int *left = new int [n];

    for (int i=0;i<n;i++){
        cin>>val[i]>>left[i]>>right[i];
    }

    treenode **binarytree = new treenode *[n];

    for (int i=0;i<n;i++){
        binarytree[i]=new treenode(val[i]);
    }

    for (int i=0;i<n;i++){
        if(left[i]!=0){
            binarytree[i]->left=binarytree[left[i]-1];
        }
        if (right[i]!=0){
            binarytree[i]->right=binarytree[right[i]-1];
        }
    }

    treenode *root= binarytree[0];

    delete []val;
    delete []left;
    delete []right;
    delete []binarytree;

    return root;
}


void deletetree(treenode *root){
    if (!root) return;
    deletetree(root->left);
    deletetree(root->right);
    delete root;
}


int sum(treenode *node, int currentsum=0){
    if(!node) return 0;

    currentsum=currentsum*10+node->val;

    if (!node->left && !node->right) {
        return currentsum;
    }

    return sum(node->left, currentsum) + sum(node->right, currentsum);
}


int main() {
    int n;
    cin >> n;
    treenode* root = buildtree(n);
    int result = sum(root);
    cout << result << endl;
    deletetree(root); 
    return 0;
}