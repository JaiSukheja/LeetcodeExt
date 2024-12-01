class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n;i++){
            int s=i+1,e=n-1;
            if(arr[i]<0){
                while(s<=e){
                    int m=s+(e-s)/2;
                    if(arr[m]==arr[i]/2.0){