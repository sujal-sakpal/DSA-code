#include<iostream>
#include<vector>
using namespace std;
// Brute Force
    int findPeak(vector<int>& nums){
        int n = nums.size();
        if(n==1) return nums[0];
        for(int i=0; i<n; i++){
            if(i==0 && nums[i]>nums[i+1]) return nums[0];
            if(i==n-1 && nums[i]>nums[i-1]) return nums[n-1];
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1]) return nums[i];
        }
        return -1;
    }

// Optimized with binary search

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        // Single Element in array
        if(n==1) return 0;
        // Checking if first and last element is peak
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;

        // Binary search to remaining search space 
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = low + (high-low)/2;
            // Checking if mid is peak
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]) return mid;
            // Checking if in increasing slope the eliminationg left half
            else if(nums[mid-1]<nums[mid]) low = mid + 1;
            // Checking if in decreasing slope , eliminating right half
            else if(nums[mid-1]>nums[mid]) high = mid - 1;
            // If valley element , eliminating either one half
            else {
                high = mid - 1;
            }
            // Instad of last two else if and els , we can also write a single else block with eliminating right half
        }
        return -1;
    }

int main(){
    vector<int> nums = {0,0,0,0,1};
    int peak_element = findPeak(nums);
    if(peak_element!=-1){
        cout<<"Peak Element in Array is "<<peak_element<<endl;
    }
    else{
        cout<<"No Peak Element"<<endl;
    }
    return 0;
}