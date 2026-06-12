# include <iostream>
using namespace std;

//双指针从头到尾遍历；

class Stack{
    public:
        int *data;
        int capacity;
        int top;

        Stack(int size){
            capacity=size;
            data=new int [size];
            top=-1;
        }

        ~Stack(){
            delete [] data;
        }

        bool isempty(){
            return top==-1;
        }

        void pop(){
            if (!isempty()){
                top--;
            }
        }
        
        void push(int x){
            if(top+1<capacity){
                top++;
            }
            data[top]=x;
        }

        int gettop(){
            return data[top];
        }
};

bool judge (int *in, int *out, int n, Stack &s){
    int i=0;
    int j=0;
    while (j<n){
        if(i<n && in[i]==out[j]){
            i++;
            j++;
        }
        else if(!s.isempty() && out[j]==s.gettop()){
            s.pop();
            j++;
        }
        else if(i<n){
            s.push(in[i]);
            i++;
        }
        else return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int *in, *out;
    in=new int[n];
    out=new int[n];
    for (int i=0;i<n;i++){
        cin>>in[i];
    }
    for (int i=0;i<n;i++){
        cin>>out[i];
    }
    Stack res(n);
    if (judge(in,out,n,res)){
        cout<<"YES";
    }
    else cout<<"NO";
    return 0;
}