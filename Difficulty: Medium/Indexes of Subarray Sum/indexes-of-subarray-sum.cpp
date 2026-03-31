class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int k) {
        int n = arr.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        while(j<n){
            sum += arr[j];
            while(sum>k){
                sum-=arr[i];
                i++;
            }
            if(sum==k) return {i+1,j+1};
        j++;
        }
        return {-1};
    }
    
};