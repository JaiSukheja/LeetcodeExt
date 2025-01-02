/*Can you solve this real interview question? Count Vowel Strings in Ranges - You are given a 0-indexed array of strings words and a 2D array of integers queries.

Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.

Return an array ans of size queries.length, where ans[i] is the answer to the ith query.

Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:


Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
Output: [2,3,0]
Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
The answer to the query [0,2] is 2 (strings "aba" and "ece").
to query [1,4] is 3 (strings "ece", "aa", "e").
to query [1,1] is 0.
We return [2,3,0].


Example 2:


Input: words = ["a","e","i"], queries = [[0,2],[0,1],[2,2]]
Output: [3,2,1]
Explanation: Every string satisfies the conditions, so we return [3,2,1].

 

Constraints:

 * 1 <= words.length <= 105
 * 1 <= words[i].length <= 40
 * words[i] consists only of lowercase English letters.
 * sum(words[i].length) <= 3 * 105
 * 1 <= queries.length <= 105
 * 0 <= li <= ri < words.length*/


class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        vector<int>v(n,0);
        vector<int>prefix(n+1,0);
        char vowels[5] = {'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            int l = words[i].size();
            for(int j=0;j<5;j++){
                if(words[i][0] == vowels[j]){
                    v[i]+=1;
                }
                if(words[i][l-1] == vowels[j]){
                    v[i]+=1;
                }
            }
            if(i>0){
                prefix[i] += v[i-1]/2 + prefix[i-1];
            }
        }
        prefix[n] += v[n-1]/2 + prefix[n-1];
        int q = queries.size();
        vector<int>result(q,0);
        for(int i=0;i<q;i++){
            int lt = queries[i][0];
            int rt = queries[i][1];
            result[i] = prefix[rt+1] - prefix[lt];
        }
        return result;
    }
};