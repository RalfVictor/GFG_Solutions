class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int ans = 1;
        int count=1;
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
        }return ans;
    }
};
