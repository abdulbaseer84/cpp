//in best complexity and space complexity

#include<iostream>
using namespace std;

int main(){
    for(int num=2; num<100; num++){
        bool isPrime = true;
        for(int div=2; div*div<=num; div++){
            if(num % div == 0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            cout << num << " ";
        }
    }
    return 0;
}