#include<iostream>
#include<vector>
using namespace std;

int brute_force_answer(vector<int>& nums){
    int n = nums.size();
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];
    for(int i=1; i<=n-2; i++){
        if(nums[i]!=nums[i-1] && nums[i]!=nums[i+1]){
            return nums[i];
        }
    }
    return -1;
}

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n==1) return nums[0];
    if(nums[0]!=nums[1]) return nums[0];
    if(nums[n-1]!=nums[n-2]) return nums[n-1];
    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(nums[mid]!=nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
        if((mid%2==1 && nums[mid]==nums[mid-1]) || (mid%2==0 && nums[mid]==nums[mid+1])){
            low = mid + 1;
        } 
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,1,2,2,3,3,4,5,5,6,6};
    int brute_ans = brute_force_answer(nums);
    int optimized_ans = singleNonDuplicate(nums);
    cout << optimized_ans << endl;
    cout << brute_ans << endl;
    return 0;
}
