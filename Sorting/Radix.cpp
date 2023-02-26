#include<iostream>
#include<vector>
using namespace std;

void countSort(int arr[],int n,int exp) {
	int cp[10] = { 0 };
	int* temp = new int[n];
	for (int i = 0; i < n; i++) {
		cp[(arr[i] / exp) % 10]++;
	}
	for (int i = 1; i < 10; i++) {
		cp[i] += cp[i - 1];
	}
	for (int i = n-1; i >= 0; i--) {
		temp[--cp[(arr[i] / exp) % 10]] = arr[i];
	}
	for (int i = 0; i < n; i++) {
		arr[i] = temp[i];
	}
}

void radixSort(int arr[], int n) {
	int min = 0, max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < min) {
			min = arr[i];
		}
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	if (min != 0) {
		for (int i = 0; i < n; i++) {
			arr[i] = arr[i] + abs(min);
		}
		max += abs(min);
	}
	for (int i = 1; max / i >= 1; i *= 10) {
		countSort(arr, n, i);
	}
	if (min != 0) {
		for (int i = 0; i < n; i++) {
			arr[i] = arr[i] - abs(min);
		}
	}
}

int main() {
	int n;
	cout << "Enter size of Array : "; cin >> n; cout << endl << "Enter Values : ";
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	radixSort(arr,n);
	cout << endl << "After Sorting : ";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
}