//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        int jumps = 0;
        int end = 0;
        int farthest = 0;
  for (int i = 0; i < arr.size() - 1; i++)
  {
    farthest = max(farthest, arr[i] + i);
    if (end == i)
    {
      jumps++;
      end = farthest;
      if (end >= arr.size() - 1)
      {
       return jumps;
      } if (i == end && arr[i] == 0)return -1;
    }
   
  }
  return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl << "~\n";
    }
    return 0;
}

// } Driver Code Ends