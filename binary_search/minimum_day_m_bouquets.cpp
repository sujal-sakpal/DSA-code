// Leetcode 1482 - Minimum number of bouquets
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findMin(vector<int>& nums){
    int mini = INT_MAX;
    for(int i=0; i<nums.size(); i++){
        mini = min(nums[i],mini);
    }
    return mini;
}

int findMax(vector<int>& nums){
    int maxi = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        maxi = max(maxi,nums[i]);
    }
    return maxi;
}

bool isPossible(vector<int>  bloomDay, int m, int k, int day){
    int count = 0;
    int n=0;
    for(int i=0; i<bloomDay.size(); i++){
        if(day>=bloomDay[i]){
            count++;
        }
        else{
            n += count/k;
            count = 0;
        }
    }
    n += count/k;
    return n>=m;
}

int minDays(vector<int>& bloomDay, int m, int k){
    int minimum_day = findMin(bloomDay);
    int maximum_day = findMax(bloomDay);
    for(int i = minimum_day; i<=maximum_day; i++){
        if(isPossible(bloomDay,m,k,i)) return i;
    }
    return -1;
}

int minDaysOptimal(vector<int>& bloomDay, int m, int k){
    int low = findMin(bloomDay);
    int high = findMax(bloomDay);
    int n = bloomDay.size();
    if((m*k)>n) return -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(isPossible(bloomDay,m,k,mid)) high = mid -1;
        else low = mid + 1; 
    }
    return low;
}

int main(){
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 2;
    int minimum_days = minDays(bloomDay,m,k);
    int optimal_answer = minDaysOptimal(bloomDay,m,k);
    cout<<"Minimum Days "<<minimum_days<<endl;
    cout<<"Minimum Days "<<optimal_answer<<endl;
    return 0;
}