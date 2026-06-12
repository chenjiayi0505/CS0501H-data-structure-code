# include <iostream>
using namespace std;

class Node{
    public:
        int num;
        Node *next;

        Node(){next=NULL;};
        Node(int n,Node *p=NULL){num=n;next=p;};
};

//尾插
Node *create(int len){
    Node *p=new Node();
    Node *res=p;
    for (int i=0;i<len;i++){
        int x;
        cin>>x;
        p->next=new Node(x);
        p=p->next;
    } 
    return res;
}

Node *compare(Node *p1, Node *p2){
    Node *res = new Node();
    Node *current = res;
    p1 = p1->next;
    p2 = p2->next;
    
    while (p1 != NULL && p2 != NULL) {
        if (p1->num < p2->num) {
            current->next = new Node(p1->num);
            current = current->next;
            int val = p1->num;
            while (p1 != NULL && p1->num == val) {
                p1 = p1->next;//跳过相同元素
            }
        }
        else if (p2->num < p1->num) {
            current->next = new Node(p2->num);
            current = current->next;
            int val = p2->num;
            while (p2 != NULL && p2->num == val) {
                p2 = p2->next;
            }
        }
        else {
            int val = p1->num;
            while (p1 != NULL && p1->num == val) p1 = p1->next;
            while (p2 != NULL && p2->num == val) p2 = p2->next;
        }
    }
    
    while (p1 != NULL) {
        current->next = new Node(p1->num);
        current = current->next;
        int val = p1->num;
        while (p1 != NULL && p1->num == val) p1 = p1->next;
    }
    
    while (p2 != NULL) {
        current->next = new Node(p2->num);
        current = current->next;
        int val = p2->num;
        while (p2 != NULL && p2->num == val) p2 = p2->next;
    }
    return res;
}

void show(Node *p) {
    p = p->next;
    if (p == NULL) {
        cout << "Empty" << endl;
    }
    else{
        while(p!=NULL){
            cout<<p->num<<" ";
            p=p->next;
        }
    }
}

int main(){
    int a,b;
    cin>>a>>b;
    Node *p1=create(a);
    Node *p2=create(b);
    show(compare(p1,p2));
    return 0;
}

