class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int s = 0;
        int e = n-1;
        while(s<e){
            if(mat[s][e]==1) s++;
            else if(mat[e][s]==1) e--;
            else{
                s++;
                e--;
            }
        }
        if(s>e) return -1;
        for(int i=0;i<n;i++){
            if(i==s) continue;
            if(mat[s][i] == 1 ) return -1;
            if(mat[i][s] == 0 ) return -1;
        }
    return s;
    }
};