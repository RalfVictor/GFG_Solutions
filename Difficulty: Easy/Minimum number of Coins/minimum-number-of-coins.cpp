class Solution {
  public:
    int loop(vector<int>& temp,int n,int i){
        if(n==0) return 0;
        if(i==0) return n;
        int x;
        if(n>=temp[i]) x = 1+loop(temp,n-temp[i],i);
        else x = loop(temp,n,i-1);
        return x;
    }
    int findMin(int n) {
        vector<int> temp = {1,2,5,10};
        return loop(temp,n,3);
    }
};