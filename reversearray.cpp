#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int start=0;
    int end=n-1;
    while(start<end){
        int temp=arr[start]; 
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
    cout << "Array in reverse order: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}