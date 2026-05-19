# include <iostream>
using namespace std;

class TreeNode {
    public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x,TreeNode*l,TreeNode *r):data(x),left(l),right(r){};
};

void insert (TreeNode *&t, int x){
    if(t==NULL) t = new TreeNode(x,NULL,NULL);
    else if(x<t->data) insert(t->left,x);
    else insert(t->right,x);
}

void createBinarySearchTree(int n,TreeNode *&t){
    for (int i=0;i<n;i++){
        int x;
        cin>>x;
        insert(t,x);
    }
}

void search(int k, TreeNode *t){
    bool flag=false;
    while(t!=NULL){
        if(t->data==k) {
            cout<<t->data<<" ";
            flag=true;
            break;
        }
        else if (t->data>k){
            cout<<t->data<<" ";
            t=t->left;
        }
        else {
            cout<<t->data<<' ';
            t=t->right;
        }
    }
    if (!flag) cout<<"-1";
}

int main(){
    int n,k;
    cin>>n>>k;

    TreeNode *t=NULL;
    createBinarySearchTree(n,t);
    search(k,t);

    delete t;
    return 0;
}