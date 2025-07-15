// User function Template for C++

class Solution {
  public:
    int pageFaults(int n, int c, int pages[]) {
    int count = 0;
	vector<int> v;

	for (int i = 0; i < n ; i++) {
		auto it = find(v.begin(), v.end(), pages[i]);
		if (it == v.end()) {
			if (v.size() == c) {
				v.erase(v.begin());
			}
			v.push_back(pages[i]);
			count++;
		}
		else {
			v.erase(it);
			v.push_back(pages[i]);
		}
	}
	return count;
    }
};