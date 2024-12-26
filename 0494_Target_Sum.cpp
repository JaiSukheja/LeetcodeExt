/*Can you solve this real interview question? Target Sum - You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

 * For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".

Return the number of different expressions that you can build, which evaluates to target.

 

Example 1:


Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3


Example 2:


Input: nums = [1], target = 1
Output: 1


 

Constraints:

 * 1 <= nums.length <= 20
 * 0 <= nums[i] <= 1000
 * 0 <= sum(nums[i]) <= 1000
 * -1000 <= target <= 1000*/


class Solution {
public:
    int solve(vector<int>& nums,int i,int n,int val,int target,unordered_map<string,int>& mp){
        if(i>=n){
            return target == val ? 1:0;
        }
        string key = to_string(i) + '_' + to_string(val);
        if(mp.count(key)){
            return mp[key];
        }
        return mp[key] = solve(nums,i+1,n,val+nums[i],target,mp)+solve(nums,i+1,n,val-nums[i],target,mp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string,int>mp;
        return solve(nums,0,nums.size(),0,target,mp);
    }
};