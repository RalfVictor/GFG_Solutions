// Function to push an integer into the stack.

void MyStack ::push(int x) {
    top++;
    arr[top] = x;
}

// Function to remove an item from top of the stack.
int MyStack ::pop() {
    if(top<0) return -1;
    int ans = arr[top];
    top--;
    return ans;
}