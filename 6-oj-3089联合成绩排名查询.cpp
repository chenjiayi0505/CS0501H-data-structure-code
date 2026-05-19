# include <iostream>
using namespace std;

void createList(int n,int *&markList){
    markList=new int [n+1];
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        markList[i]=x;
    }
}

// 在 a[la..n] 和 b[lb..m] 中找第 k 小
int findKth(int* a, int la, int n, int* b, int lb, int m, int k){
    // 保证 a 的剩余长度 <= b 的剩余长度,f方便后续处理
    // 如果 a 长度更大，则交换
    if(n - la + 1 > m - lb + 1){
        return findKth(b, lb, m, a, la, n, k);
    }
    // 边界情况：a 数组已空
    if(la > n){
        return b[lb + k - 1];
    }
    // 边界情况：k == 1，找两个数组当前第一个元素的最小值
    if(k == 1){
        return min(a[la], b[lb]);
    }
    // 取 pa = min(k/2, a剩余长度)
    int pa = min(k / 2, n - la + 1);
    int pb = k - pa; 
    
    // 比较 a[la + pa - 1] 和 b[lb + pb - 1]
    if(a[la + pa - 1] <= b[lb + pb - 1]){
        // 丢弃 a 的前 pa 个元素
        return findKth(a, la + pa, n, b, lb, m, k - pa);
    } else {
        // 丢弃 b 的前 pb 个元素
        return findKth(a, la, n, b, lb + pb, m, k - pb);
    }
}

int search(int n, int m, int* a, int* b, int k){
    return findKth(a, 1, n, b, 1, m, k);
}

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    int *a, *b;
    createList(n,a);
    createList(m,b);
    for(int i=1;i<=q;i++){
        int k;
        cin>>k;
        cout<<search(n,m,a,b,k)<<endl;
    }
    delete []a;
    delete []b;
    return 0;
}