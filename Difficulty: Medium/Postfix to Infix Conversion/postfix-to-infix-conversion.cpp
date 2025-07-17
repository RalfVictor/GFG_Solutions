// User function Template for C++

class Solution {
  public:
    string postToInfix(string pre) {
        int n = pre.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if((pre[i]>='A' && pre[i]<='Z') || (pre[i]>='a' && pre[i]<='z')){
                st.push(string(1, pre[i]));
            }
            else{
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = "("+y+pre[i]+x+")";
                st.push(z);
            }
        }
        return st.top();
    }
};