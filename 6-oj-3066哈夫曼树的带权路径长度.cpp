# include <iostream>
using namespace std;

class Node{
    public:
    int left;
    int right;
    long long weight;
};

Node tree[100000];
bool hasparent[100000]={false};

void create(int n){
    for (int i=1;i<=n;i++){
        int l,w,r;
        cin>>l>>w>>r;
        tree[i].left=l;
        tree[i].weight=w;
        tree[i].right=r;

        if(l!=0) hasparent[l]=true;
        if(r!=0) hasparent[r]=true;
    }
}

int findroot(int n){
    for(int i=1;i<=n;i++){
        if(!hasparent[i]) return i;
    }
    return 1;
}

long long wpl(int root){
    long long ans=0;
    int queue[100000];
    int depth[100000];
    int head=0;
    int tail=0;

    queue[tail]=root;
    depth[tail]=0;
    tail++;

    while (head<tail){
        int u=queue[head];
        int d=depth[head];
        head++;

        if (tree[u].left==0 && tree[u].right==0){
            ans+=tree[u].weight*d;
        }

        else{
            if (tree[u].left!=0){
                queue[tail]=tree[u].left;
                depth[tail]=d+1;
                tail++;
            }
            if (tree[u].right!=0){
                queue[tail]=tree[u].right;
                depth[tail]=d+1;
                tail++;
            }
        }
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    create (n);
    int root = findroot(n);
    long long result=wpl(root);
    cout<<result<<endl;
    return 0;
}
