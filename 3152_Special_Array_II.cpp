/*Can you solve this real interview question? Special Array II - An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that subarray nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

 

Example 1:

Input: nums = [3,4,1,2,6], queries = [[0,4]]

Output: [false]

Explanation:

The subarray is [3,4,1,2,6]. 2 and 6 are both even.

Example 2:

Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]

Output: [false,true]

Explanation:

 1. The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
 2. The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.

 

Constraints:

 * 1 <= nums.length <= 105
 * 1 <= nums[i] <= 105
 * 1 <= queries.length <= 105
 * queries[i].length == 2
 * 0 <= queries[i][0] <= queries[i][1] <= nums.length - 1*/


class Solution {
public:
    bool bSearch(vector<int>& vi, int sp, int ep) {
        int l = 0;
        int r = vi.size()-1;

        while(l <= r) {
            int mid = l + (r-l)/2;

            if(vi[mid] < sp) {
                l = mid+1;
            } else if(vi[mid] > ep) {
                r = mid-1;
            } else {
                //we found violating index
                return true;
            }
        }

        return false;

    }

    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int m = queries.size();
        int n = nums.size();

        vector<int> vi; //violating indices ka list hai ye

        for(int i = 1; i < n; i++) { //O(n)
            if(nums[i]%2 == nums[i-1]%2) {
                vi.push_back(i); //it will always be in sorted order
            }
        }

        vector<bool> result(m, false);

        for(int i = 0; i < m; i++) { //O(m)
            int start = queries[i][0];
            int end = queries[i][1];

            bool hasViolatingIndexInRange = bSearch(vi, start+1, end); //log(n)

            if(hasViolatingIndexInRange == false) { //Did not find any violating index
                result[i] = true;
            }
        }

        return result;

    }
};
