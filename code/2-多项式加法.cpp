# include <iostream>
using namespace std;

class Node{
    public:
        int coff,exp; //coff存系数，exp存指数
        Node *next;

    Node(){
        next=NULL;
    }
    Node(int a,int b,Node *p=NULL){
        coff=a; exp=b; next=p;
    }
};

Node *add (Node *p1,Node *p2) {
    Node *result,*p;
    result = p = new Node();

    p1=p1->next;
    p2=p2->next;
    //这个地方的链表与教材一致，即默认有为空的头结点

    while (p1!=NULL && p2!=NULL){
        if (p1->exp > p2->exp){
            p->next= new Node(p2->coff,p2->exp,p->next);
            p=p->next;
            p2=p2->next;
        }
        else if (p1->exp < p2->exp){
            p->next= new Node(p1->coff,p1->exp,p->next);
            p=p->next;
            p1=p1->next;
        }
        else if (p1->coff + p2->coff !=0){
            p->next= new Node(p1->coff+p2->coff,p1->exp,p->next);
            p1=p1->next;
            p2=p2->next;
            p=p->next;
        }
    }
    while (p1!=NULL){
        p->next=new Node(p1->coff,p1->exp,p->next);
        p1=p1->next;
        p=p->next;
    }
    while (p2!=NULL){
        p->next=new Node(p2->coff,p2->exp,p->next);
        p2=p2->next;
        p=p->next;
    }
    return result;
}

// 时间复杂度：O(m+n)  m,n分别是p1和p2的项数，因为遍历了两个链表中所有的结点
// 空间复杂度：O(m+n)  动态内存分配会增大时间复杂度，考虑最坏的情况，一共创建了m+n个新结点