/*Can you solve this real interview question? Word Subsets - You are given two string arrays words1 and words2.

A string b is a subset of string a if every letter in b occurs in a including multiplicity.

 * For example, "wrr" is a subset of "warrior" but is not a subset of "world".

A string a from words1 is universal if for every string b in words2, b is a subset of a.

Return an array of all the universal strings in words1. You may return the answer in any order.

 

Example 1:


Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]


Example 2:


Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]


 

Constraints:

 * 1 <= words1.length, words2.length <= 104
 * 1 <= words1[i].length, words2[i].length <= 10
 * words1[i] and words2[i] consist only of lowercase English letters.
 * All the strings of words1 are unique.*/


class Solution {
public:
    bool helper(vector<int> &a,vector<int> &b){
        for(int i=0;i<26;i++){
            if((a[i]-b[i])<0){
                return false;
            }
        }
        return true;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n = words1.size(),m = words2.size();
        vector<string>result;
        vector<vector<int>>a(n,vector<int>(26,0));
        vector<int>b(26,0);
        for(int i=0;i<n;i++){
            for(int j:words1[i]){
                a[i][j-97]++;
            }
        }
        for(int i=0;i<m;i++){
            vector<int>t(26,0);
            for(int j:words2[i]){
                t[j-97]++;
                b[j-97] = max(b[j-97],t[j-97]);
            }
        }
        for(int i=0;i<n;i++){
            if(helper(a[i],b)){
                result.push_back(words1[i]);
            }
        }
        return result;
    }
};