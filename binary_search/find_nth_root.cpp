#include<iostream>
using namespace std;

// Returns:
// 1 if mid^n == m
// 0 if mid^n < m
// 2 if mid^n > m
int helper_function(int mid, int n, int m){
    long long ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}

int linear_approach(int n, int m){
    for(int i=0; i<=m; i++){
        int result = helper_function(i,n,m);
        if(result==1) return i;
        else if(result==2) break;
    }
    return -1;
}

int binary_search_approach(int n, int m){
    int low = 1;
    int high = m;
    while(low<=high){
        int mid = low + (high - low)/2;
        int result = helper_function(mid,n,m);
        if(result==1) return mid;
        else if(result==2) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}

int main(){
    int answer = linear_approach(3,27);
    cout<<answer<<endl;
    int answer2 = binary_search_approach(4,16);
    cout<<answer2<<endl;
}