/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

//Function to push an element into the queue.
void MyQueue:: push(int x)
{
       if(front == NULL){
           QueueNode* node = new QueueNode(x);
           rear = node;
           front = node;
       }
       else{
           QueueNode* node = new QueueNode(x);
           rear->next = node;
           rear = node;
       }
}

//Function to pop front element from the queue.
int MyQueue :: pop()
{
    if(front==NULL) return -1;
    QueueNode* temp = front;
    front = front->next;
    temp->next = NULL;
    return temp->data;              
}
