# include <iostream>
using namespace std;

void bubbleSort(int a[], int n){
    bool flag=true;
    for (int j=n-1;j>0 && flag;j--){
        flag=false;
        for(int i=0;i<j;i++){
            if(a[i]>a[i+1]){
                int tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
                flag=true;
            }
        }
    }
}

int change(int a[], int n, int out[]){
    if(n==0) return 0;
    int index=0;
    out[index++]=a[0];
    for (int i=1;i<n;i++){
        if(a[i]!=out[index-1]) out[index++]=a[i];
    }
    return index;
}

int binarySearch(int a[], int len, int target){
    int left=0;
    int right=len-1;
    while(left<=right){
        int mid=(left+right)/2;
        if(a[mid]==target) return mid;
        else if(a[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return -1;
}

int main(){
    int n;
    cin>>n;

    int *a= new int [n];
    int *sorted = new int [n];
    int *changed = new int [n];

    for(int i=0;i<n;i++){
        cin>>a[i];
        sorted[i]=a[i];
    }

    bubbleSort(sorted, n);
    int newlen=change(sorted,n,changed);
    for(int i=0;i<n;i++){
        int index=binarySearch(changed,newlen,a[i]);
        cout<<index+1<<" ";
    }

    delete[] a;
    delete[] sorted;
    delete[] changed;
}