# include <iostream>
using namespace std;

int queue[100000];
int heapsize=0;

void up(int pos){
    while (pos>1 && queue[pos]<queue[pos/2]){
        int temp=queue[pos];
        queue[pos]=queue[pos/2];
        queue[pos/2]=temp;
        pos=pos/2;
    }
}

void down(int pos){
    while (pos*2<=heapsize){
        int child= pos*2;
        if (child+1<=heapsize && queue[child+1]<queue[child]) {
            child++;
        }

        if (queue[child]>=queue[pos]){
            break;
        }

        int temp=queue[pos];
        queue[pos]=queue[child];
        queue[child]=temp;
        pos=child;
    }
}

void push(int x){
    ++heapsize;
    queue[heapsize]=x;
    up(heapsize);
}

int pop(){
    int min=queue[1];
    queue[1]=queue[heapsize];
    heapsize--;
    down(1);
    return min;
}

int main(){
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        int num;
        cin>>num;

        if(num==1){
            int x;
            cin>>x;
            push(x);
        }
        if(num==2){
            cout<<pop()<<endl;
        }
    }
    return 0;
}