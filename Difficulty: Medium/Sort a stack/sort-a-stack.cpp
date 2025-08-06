/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */
void sorted(int x,stack<int>& s){
 if(s.empty() || s.top()<x) {s.push(x);
 return;}
 int n = s.top();
 s.pop();
 sorted(x,s);
 s.push(n);
}

void SortedStack ::sort() {
    if(s.empty()) return;
    int num = s.top();
    s.pop();
    sort();
    sorted(num,s);
}