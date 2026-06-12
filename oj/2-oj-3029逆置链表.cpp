# include <iostream>
using namespace std;

class Node{
    public:
        int num;
        Node *next;

        Node(){next=NULL;};
        Node(int n,Node*p=NULL){num=n;next=p;};
};

Node *create(int len){
    Node *p= new Node();
    for (int i=0;i<len;i++){
        int x;
        cin>>x;
        p->next=new Node(x,p->next);
    }
    return p;
}

void show(Node *p){
    p=p->next;
    while(p!=NULL){
        cout<<p->num<<" ";
        p=p->next;
    }
}

int main(){
    int n;
    cin>>n;
    Node *LinkNode=create(n);
    show (LinkNode);
    return 0;
}