# include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node *left;
    Node *right;

    Node(int x):val(x),left(NULL),right(NULL){};
};

Node **binarytree;

Node* create (int n){
    binarytree = new Node * [n+1];
    for (int i=1;i<=n;i++){
        binarytree[i]=new Node(i);
    }

    for (int i=1;i<=n;i++){
        int a,b;
        cin>>a>>b;
        if(a!=0) binarytree[i]->left=binarytree[a];
        if(b!=0) binarytree[i]->right=binarytree[b];
    }

    Node *root=binarytree[1];
    return root;
}

Node* findNode(Node *root, int val) {
    if (root == NULL) return NULL;
    if (root->val == val) return root;
    
    Node *leftResult = findNode(root->left, val);
    if (leftResult != NULL) return leftResult;
    
    return findNode(root->right, val);
}

Node *ans;

// dfs是在root的子树中查找是否有p或者是q
bool dfs(Node* root, Node* p, Node* q) {
        if (root == nullptr) return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        
        // 若x是最近公共祖先，只有两种情况：
        // 1.p,q分别在x的左右子树里，不能同时在一边子树，否则x不是最近的那个公共祖先
        // 2.x=p||x=q 另外一个数在x的左子树或右子树内

        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        } 
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

Node* LCA(Node* root, Node* p, Node* q) {
        dfs(root, p, q);
        return ans;
}

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    Node *root=create(n);
    Node *p = findNode(root,x);
    Node *q = findNode(root,y);
    Node *result=LCA(root, p,q);
    cout<<result->val;
    for (int i = 1; i <= n; i++) {
        delete binarytree[i];
    }
    delete[] binarytree;
    return 0;
}