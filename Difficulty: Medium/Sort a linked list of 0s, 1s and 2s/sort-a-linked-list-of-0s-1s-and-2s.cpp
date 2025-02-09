//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends
/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {
        if(head==NULL){
            return NULL;
        }
    Node* zero = new Node(0);
    Node* zt = zero;
    Node* one = new Node(0);
    Node* ot = one;
    Node* two = new Node(0);
    Node* tt = two;
    while(head!=NULL){
        Node* temp = new Node(head->data);
        if(head->data==0){
            zero->next = temp;
            zero = zero->next;
        }
        else if(head->data==1){
            one->next = temp;
            one = one->next;
        }
        else{
            two->next = temp;
            two = two->next;
        }
        head = head->next;
    }
    if(ot->next==NULL){
    zero->next = tt->next;
    return zt->next;
    }
    zero->next = ot->next;
    one->next = tt->next;
    return zt->next;
    }
};


//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends