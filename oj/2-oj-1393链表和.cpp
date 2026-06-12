# include <iostream>
using namespace std;

class Node{
    public:
        int num;
        Node *next;

        Node(){next=NULL;};
        Node(int a,Node *p=NULL): num(a), next(p){};
};

//头插，先算个位
Node *create(int len){
    Node *p=new Node();
    for (int i=0;i<len;i++){
        int x;
        cin>>x;
        p->next=new Node(x,p->next);
    } 
    return p;
}

// 还是头插，正好反过来
Node *add (Node *p1, Node *p2){
    Node *res=new Node();
    p1=p1->next;
    p2=p2->next;
    int carry=0;
    while(p1!=NULL && p2!=NULL){
        int dig=(p1->num+p2->num+carry)%10;
        carry=(p1->num+p2->num+carry)/10;
        res->next=new Node(dig,res->next);
        p1=p1->next;
        p2=p2->next;
    }
    while (p1!=NULL){
        int dig=(p1->num+carry)%10;
        carry=(p1->num+carry)/10;
        res->next=new Node(dig,res->next);
        p1=p1->next;
    }
    while (p2!=NULL){
        int dig=(p2->num+carry)%10;
        carry=(p2->num+carry)/10;
        res->next=new Node(dig,res->next);
        p2=p2->next;
    }
    if (carry>0){
        res->next=new Node(carry,res->next);
    }
    return res;
}

void show(Node*p){
    p=p->next;
    while(p!=NULL){
        cout<<p->num<<" ";
        p=p->next;
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    Node *p1=create(a);
    Node *p2=create(b);
    show(add(p1,p2));
    return 0;
}