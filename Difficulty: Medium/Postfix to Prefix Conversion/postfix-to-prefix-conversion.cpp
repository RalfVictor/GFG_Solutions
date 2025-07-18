// User function Template for C++

class Solution {
  public:
    string postToPre(string post) {
        int n = post.size();
        stack<string> st;
        for(int i=0;i<n;i++){
            if((post[i]>='A' && post[i]<='Z') || (post[i]>='a' && post[i]<='z')){
                st.push(string(1,post[i]));
            }
            else{
                string x = st.top();
                st.pop();
                string y = st.top();
                st.pop();
                string z = post[i]+y+x;
                st.push(z);
            }
        }
        return st.top();
    }
};