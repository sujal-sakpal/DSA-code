#include<iostream>
using namespace std;

int square_root_linear(int n){
    int ans = 1;
    for(int i=1; i<=n; i++){
        if((i*i)<=n){
            ans = i;
        }
        else{
            break;
        }
    }
    return ans;
}

int square_root_binary_search(int n){
    int ans = 1;
    int low = 1;
    int high = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        // found mid which might be an answer but looking for better answer or maximum number
        if((mid*mid)<=n){
            ans = mid;
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}

int main(){
    int number1 = 28;
    int answer1 = square_root_linear(number1);
    cout<<"square root of "<<number1<<" is "<<answer1<<endl;
    int number2 = 49;
    int answer2 = square_root_binary_search(number2);
    cout<<"square root of "<<number2<<" is "<<answer2<<endl;
    return 0;
}