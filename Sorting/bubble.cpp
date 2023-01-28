#include<iostream>
using namespace std;

void bubbleSort(int n,int arr[]){
    for(int i=0;i<n-1;i++){
        int j=0;
        int max=j;
        while(j<n-i){
            if(arr[max]>arr[j]){
                int temp=arr[j];
                arr[j]=arr[max];
                arr[max]=temp;
            }
            max=j;
            j++;
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
    bubbleSort(n,arr);
    cout<<endl<<"After Sorting : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\t";
    }
}