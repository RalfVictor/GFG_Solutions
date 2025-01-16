//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int finddivisorsum(int a){
        int sum = 0;
        for(int i=1;i<=a;i++){
            if(a%i==0){
                sum+=i;
            }
        }
        return sum;
    }
  
    int sumOfDivisors(int n) {
        int ans = 0;
        for(int i = 0;i<=n;i++){
            ans+=finddivisorsum(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.sumOfDivisors(N);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends