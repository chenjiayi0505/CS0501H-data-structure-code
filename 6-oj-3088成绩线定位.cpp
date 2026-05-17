# include <iostream>
using namespace std;

void createList(int n,int *&markList){
    markList = new int[n+1];
    for (int i=1; i<=n; i++){
        int x;
        cin>>x;
        markList[i]=x;
    }
}

int BinarySearch(int *marklist, int target, int num){
    int low=1;
    int high=num;
    int ans=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(marklist[mid]>=target){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}

int main(){
    int studentNum,checkNum;
    cin>>studentNum>>checkNum;
    int *markList;
    createList(studentNum,markList);
    for (int i=0; i<checkNum; i++){
        int x;
        cin>>x;
        cout<<BinarySearch(markList,x,studentNum)<<endl;
    }
    delete[] markList;
    return 0;
}