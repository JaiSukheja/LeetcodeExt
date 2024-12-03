/*Can you solve this real interview question? Take K of Each Character From Left and Right - You are given a string s consisting of the characters 'a', 'b', and 'c' and a non-negative integer k. Each minute, you may take either the leftmost character of s, or the rightmost character of s.

Return the minimum number of minutes needed for you to take at least k of each character, or return -1 if it is not possible to take k of each character.

 

Example 1:


Input: s = "aabaaaacaabc", k = 2
Output: 8
Explanation: 
Take three characters from the left of s. You now have two 'a' characters, and one 'b' character.
Take five characters from the right of s. You now have four 'a' characters, two 'b' characters, and two 'c' characters.
A total of 3 + 5 = 8 minutes is needed.
It can be proven that 8 is the minimum number of minutes needed.


Example 2:


Input: s = "a", k = 1
Output: -1
Explanation: It is not possible to take one 'b' or 'c' so return -1.


 

Constraints:

 * 1 <= s.length <= 105
 * s consists of only the letters 'a', 'b', and 'c'.
 * 0 <= k <= s.length*/


class Solution {
public:
    int takeCharacters(string s, int k) {
        int a=0,b=0,c=0,n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='a')a++;
            if(s[i]=='b')b++;
            if(s[i]=='c')c++;
        }
        if(k>a || k>b || k>c)return -1;
        int i=0,j=0,result=0;
        while(j<n){
            if(s[j]=='a'){
                a--;
            }
            else if(s[j]=='b'){
                b--;
            }
            else{
                c--;
            }
            while(i<=j && (a<k || b<k || c<k)){
                if(s[i]=='a'){
                    a++;
                }
                else if(s[i]=='b'){
                    b++;
                }
                else{
                    c++;
                }
                i++;
            }
            result = max(result,j-i+1);
            j++;
        }
        return n-result;
    }
};