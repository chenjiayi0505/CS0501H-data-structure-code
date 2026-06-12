# include <iostream>
using namespace std;

//滑动窗口
//队列用来存储与target一样的数据的位置序号
//如果front的索引与先在索引的差值大于等于10，出队

class Queue{
    public:
        int *data;
        int capacity;
        int front;
        int rear;
        int length;

        Queue (int size=10){
            data=new int[10];
            capacity=size;
            front=rear=0;
            length=0;
        }

        ~Queue(){
            delete []data;
        }

        bool isempty(){
            return length==0;
        }

        bool isfull(){
            return length==capacity;
        }

        void enQueue (int x){
            if(isfull()){
                deQueue();
            }
            data[rear] = x;
            rear = (rear + 1) % capacity;
            ++length;
        }

        void deQueue (){
            if(!isempty()){
                front=(front+1)%capacity;
                --length;
            }
        }

        int getFront(){
            if (!isempty()) {
                return data[front];
            }
            return -1;
        }

        int getsize(){
            return length;
        }
};

int *operate(int limit, int *requests, Queue &window, int n, int target){
    int *res;
    res=new int [n];
    for (int i=0;i<n;i++){
        while (!window.isempty() && i - window.getFront() >= 10) {
            window.deQueue();
        }
        if(requests[i]==target){
            if(window.getsize()<limit){
                window.enQueue(i);
                res[i]=1;
            }
            else res[i]=-1;
        }
        else res[i]=0;
    }
    return res;
}

int main(){
    int target;
    char package;
    int n;
    cin>>target;
    cin>>package;
    cin>>n;
    int limit;
    if (package=='a') limit=3;
    else if (package=='b') limit=6;
    else if(package=='c') limit=9;
    Queue window(10);
    int *res;
    int* requests = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> requests[i];
    }
    res=operate(limit, requests, window, n, target);
    for (int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}