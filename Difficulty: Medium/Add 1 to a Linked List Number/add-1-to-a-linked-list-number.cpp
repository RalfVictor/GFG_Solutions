//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* addOne(Node* head) {
        if(head==NULL){
            return NULL;
        }
        
        Node* prev = NULL;
        while(head!=NULL){
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        head = prev;
        Node* extras = new Node(0);
        extras->next = head;
        int carry = 1;
        while(head!=NULL && carry==1){
            if(head->data == 9){
                head->data = 0;
                carry = 1;
            }
            else{
                head->data = head->data + 1;
                carry = 0;
            }
            head = head->next;
            extras = extras->next;
        }
        
        if(carry == 1){
            Node* extra = new Node(1);
            extras->next = extra;
        }
        
        head = prev;
        prev = NULL;
        
        while(head!=NULL){
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        
        
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends