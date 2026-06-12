//注意：时间复杂度为O(n)，即元素只能遍历一次
//元素从开始依次入栈，直到下一个即将入栈的元素比栈顶元素大时开始出栈
//此时从栈顶元素开始依次往下，所有比即将入栈元素小的元素均出栈
//栈顶元素入栈
//遍历结束后所有未出栈的元素即为右边不存在更高箱子的元素
//栈中存什么？存索引值，通过已有数组和索引访问箱子的高度

# include <iostream>
using namespace std;

class Stack{
    public:
        int *data;
        int capacity;
        int top;

        Stack(int size){
            capacity=size;
            data=new int [capacity];
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

        void push(int val){
            if (top+1<capacity){
                top++;
                data[top]=val;
            }
        }

        int get_top() {
            return data[top];
        }
};

int main(){
    int n;
    cin>>n;
    int *array,*res;
    array=new int [n];
    res=new int [n];
    for (int i=0;i<n;i++){
        res[i]=0;
    }
    for (int i=0;i<n;i++){
        cin>>array[i];
    }
    Stack p(n);
    for (int i=0;i<n;i++){
        while(!p.isempty() && array[i]>array[p.get_top()]){
            res[p.get_top()]=i+1;
            p.pop();
        }
        p.push(i);
    }
    for (int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    return 0;
}