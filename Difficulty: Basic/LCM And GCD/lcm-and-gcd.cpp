//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int gcd (int a, int b){
        if(a == 0){
            return b;
        }
        return gcd(b%a,a);
    }
  
    vector<int> lcmAndGcd(int a, int b) {
        vector<int> ans ;
        int gcdofnum = gcd(a,b);
        int lcm = (a*b)/gcdofnum;
        ans.push_back(lcm);
        ans.push_back(gcdofnum);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int A, B;

        cin >> A >> B;

        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends