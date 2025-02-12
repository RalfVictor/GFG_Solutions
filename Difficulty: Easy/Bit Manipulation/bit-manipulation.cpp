//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        // int y = num&((int)(pow(2,i-1)));
        num&((int)(pow(2,i-1)))?cout<<1<<" ":cout<<0<<" ";;
        // if(y==0){
        //     cout<<0<<" ";
        // }else{
        //     cout<<1<<" ";
        // }
        int x = num|((int)(pow(2,i-1)));
        cout<<x<<" ";
        int y = (int)(pow(2,i-1));
        y = INT_MAX^y;
        x = num&(y);
        cout<<x;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends