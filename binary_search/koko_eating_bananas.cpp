// Leetcode 875 - Koko Eating Bananas
// Answer lies in between minimum and maximum of array
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

bool canFinishinLessthanh(vector<int>& nums, int h, int k){
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += (nums[i] + k -1)/k;
    }
    if(sum<=h) return true;
    return false;
}

int findMax(vector<int>& nums){
    int maxi = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        maxi = max(maxi,nums[i]);
    }
    return maxi;
}

int minEatingSpeedLinear(vector<int>& piles , int h){
    int maxi = findMax(piles);
    for(int i=1; i<=maxi; i++){
        bool isPossible = canFinishinLessthanh(piles,h,i);
        if(isPossible) return i;
    }
    return -1;
}

int minEatingSpeedBinarySearch(vector<int>& piles, int h){
    int low = 1;
    int high = findMax(piles);
    while(low<=high){
        int mid = low + (high-low)/2;
        bool isPossible = canFinishinLessthanh(piles,h,mid);
        if(isPossible){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return low;
}



int main(){
    vector<int> piles = {30,11,23,4,20};
    int h = 6;
    int linear_answer = minEatingSpeedLinear(piles,h);
    int binary_answer = minEatingSpeedBinarySearch(piles,h);
    cout<<"Linear Answer : "<<linear_answer<<endl;
    cout<<"Binary Answer : "<<binary_answer<<endl;
    return 0;
}