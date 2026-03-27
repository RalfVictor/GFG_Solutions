// User function Template for C++
class Solution {
  public:
  long long power(long long x, long long y, int mod){
    long long res = 1;
    x = (x % mod + mod) % mod;
    
    while(y){
        if(y & 1) res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

long long modInverse(long long a, int mod){
    return power(a, mod - 2, mod);
}
    long long int findMaxProduct(vector<int>& arr) {
        int maxin = -1e8;
        int mod = 1e9+7;
        int i = 0 ;
        int count = 0;
        int co = 0;
        int n = arr.size();
        if(n==0) return 0;
        if(n==1) return arr[0];
        long long int ans = 1;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                co++;
                continue;
            }
            ans=(ans * ((arr[i] % mod + mod) % mod)) % mod;
            if(arr[i]<0 ){
                count++;
                if(arr[i]>maxin) maxin = arr[i];
            }
        }
        if(co==n) return 0;
        if(count%2==1){
            if(count==1 && co==n-1) return 0;
            ans = (ans * modInverse(maxin, mod)) % mod;
            return (ans + mod) % mod;
        }
        return ans%mod;
    }
};
