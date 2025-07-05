// Leetcode 1283 - Find Smallest Divisor

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

bool isBelowThreshold(vector<int>& nums, int threshold, int num){
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += (nums[i] + num - 1) / num ;       
    }
    return sum<=threshold;
}

int findSmallestDivisor(vector<int>& nums, int threshold){
    int maximum = findMax(nums);
    for(int i=1; i<=maximum; i++){
        if(isBelowThreshold(nums,threshold,i)) return i;
    }
    return -1;
}

int findSmallestDivisorOptimal(vector<int>& nums, int threshold){
    int low = 1;
    int high = findMax(nums);
    while(low<=high){
        int mid = low + (high-low)/2;
        bool result = isBelowThreshold(nums,threshold,mid);
        if(result) high = mid - 1;
        else low = mid + 1;
    }
    return low;
}


int main(){
    vector<int> nums = {1,2,5,9};
    int threshold = 6;
    int min_divisor = findSmallestDivisor(nums,threshold);
    int min_divisor_1 = findSmallestDivisorOptimal(nums,threshold);
    cout<<"Minimum Divisor "<<min_divisor<<endl;
    cout<<"Minimum Divisor "<<min_divisor_1<<endl;
    return 0;
}