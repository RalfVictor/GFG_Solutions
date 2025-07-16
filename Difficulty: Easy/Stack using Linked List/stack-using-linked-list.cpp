class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode* head = new StackNode(x);
        head->next = top;
        top = head;
    }

    int pop() {
        if(top==NULL) return -1;
        StackNode* temp = top;
        int x = temp->data;
        top = temp->next;
        delete temp;
        return x;
    }

    MyStack() { top = NULL; }
};