/*Can you solve this real interview question? Rotate String - Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

 * For example, if s = "abcde", then it will be "bcdea" after one shift.

 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true


Example 2:

Input: s = "abcde", goal = "abced"
Output: false


 

Constraints:

 * 1 <= s.length, goal.length <= 100
 * s and goal consist of lowercase English letters.*/


class Solution {
public:
    bool isCircularSentence(string s) {
        int n=s.size();
        if(s[0]!=s[n-1]){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(s[i]==' ' && s[i-1] != s[i+1])return 0;
        }
        return 1;
    }
};