# include <iostream>
using namespace std;

struct Student{
    int id;
    int theory;
    int lab;
    int total;
};

bool better (Student &s1, Student &s2){
    if (s1.total!=s2.total) return s1.total>s2.total;
    if (s1.lab!=s2.lab) return s1.lab>s2.lab;
    else return s1.id<s2.id;
}

void merge(Student stu[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Student* L = new Student[n1];
    Student* R = new Student[n2];
    for (int i = 0; i < n1; i++) L[i] = stu[left + i];
    for (int i = 0; i < n2; i++) R[i] = stu[mid + 1 + i];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (better(L[i], R[j])) {
            stu[k++] = L[i++];
        } else {
            stu[k++] = R[j++];
        }
    }
    while (i < n1) stu[k++] = L[i++];
    while (j < n2) stu[k++] = R[j++];
    delete[] L;
    delete[] R;
}

void mergeSort(Student stu[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(stu, left, mid);
        mergeSort(stu, mid + 1, right);
        merge(stu, left, mid, right);
    }
}

int main(){
    int n;
    cin>>n;

    Student *students=new Student[n];
    for(int i=0; i<n; i++){
        cin>>students[i].id>>students[i].theory>>students[i].lab;
        students[i].total=students[i].theory+students[i].lab;
    }

    mergeSort(students,0,n-1);
    for(int i=0;i<n;i++){
        cout<<students[i].id<<" "<<students[i].total<<endl;
    }

    delete[] students;
    return 0;
}