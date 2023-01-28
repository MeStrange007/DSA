#include<iostream>
using namespace std;

void insertionSort(int n,int arr[]){
    for(int i=1;i<n;i++){
        int j=i-1;
        int temp= arr[i];
        while(j>=0 && arr[j]>temp){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main(){
    int n;
    cout<<"Enter size of Array : ";cin>>n;cout<<endl<<"Enter Values : ";
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    insertionSort(n,arr);
    cout<<endl<<"After Sorting : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}