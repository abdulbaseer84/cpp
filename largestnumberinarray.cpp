#include<iostream>
using namespace std;

// int main(){
//     int arr[]={1,2,3,5,4};
//     int n=5;
//     int largest = arr[0];

//     for(int i=1;i<n;i++){
//         if(arr[i]>largest){
//             largest=arr[i];
//         }
//     }
//     cout<<largest;
//     return 0;
// }

// with user input
int main(){
    int arr[100];
    int n;
    cout<<"enter the size of array:";
    cin>>n;
    cout<<"enter the elements of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int largest = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest=arr[i];
        }
    }
    cout<<largest;
    return 0;
}