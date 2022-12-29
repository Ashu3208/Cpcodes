/**
Question Link:https://leetcode.com/problems/subsets/
Given an integer array nums of unique elements, return all possible 
subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.


**/


class Solution {
public:
    void find_sub(vector<int>nums,int i,int n,vector<vector<int>>&s,vector<int>vec){
        if(i==n){
            s.push_back(vec);
            return;
        }
        find_sub(nums,i+1,n,s,vec);
        vec.push_back(nums[i]);
        find_sub(nums,i+1,n,s,vec);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> s;
        vector<int> vec;
        find_sub(nums,0,nums.size(),s,vec);
        return s;
    }
};
