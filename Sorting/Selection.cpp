#include<iostream>
using namespace std;

void selectionSort(int n,int arr[]){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            int temp =arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
}

int main(){
    int n;
    cout<<"Enter size of Array : ";cin>>n;cout<<endl<<"Enter Values : ";
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    selectionSort(n,arr);
    cout<<endl<<"After Sorting : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}