class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int n = arr.size();
        int ans = 1;
        int count = 1;
        int i=1,j=0;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                i++;
                count++;
            }
            else{
                j++;
                count--;
            }
            ans = max(ans,count);
        }
        return ans;
    }
};
