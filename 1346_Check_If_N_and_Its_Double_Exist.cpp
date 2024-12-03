/*Can you solve this real interview question? Check If N and Its Double Exist - Given an array arr of integers, check if there exist two indices i and j such that :

 * i != j
 * 0 <= i, j < arr.length
 * arr[i] == 2 * arr[j]

 

Example 1:


Input: arr = [10,2,5,3]
Output: true
Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]


Example 2:


Input: arr = [3,1,7,11]
Output: false
Explanation: There is no i and j that satisfy the conditions.


 

Constraints:

 * 2 <= arr.length <= 500
 * -103 <= arr[i] <= 103*/


class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            int s=i+1,e=n-1;
            if(arr[i]<0){
                while(s<=e){
                    int m=s+(e-s)/2;
                    if(arr[m]==arr[i]/2.0){
                        return 1;
                    }
                    else if(arr[m]<arr[i]/2.0){
                        s=m+1;
                    }
                    else{
                        e=m-1;
                    }
                }
            }
            else{
                while(s<=e){
                    int m=s+(e-s)/2;
                    if(arr[m]==arr[i]*2){
                        
                        return 1;
                    }
                    else if(arr[m]<arr[i]*2){
                        s=m+1;
                    }
                    else{
                        e=m-1;
                    }
                }
            }
            
        }
        return 0;
    }
};