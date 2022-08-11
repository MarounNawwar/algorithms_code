#include <iostream>
using namespace std;

#define Max 100

// Array-Based Queue Structure

struct Queue{
    int a[Max];
    int front;
    int rear;
};

// Circular Queue Structure

struct CircularQueue{
    int a[Max];
    int front;
    int rear;
};

// LinkedList - Based Queue Structure

struct node{
    int data;
    node* next;
};

struct queue{
    node* front;
    node* rear;
};

// Normal Queue Functions

void init(Queue&);
bool empty(Queue&);
bool full(Queue&);
bool enqueue(Queue&,int);
bool dequeue(Queue&);
int front(Queue&);
int size(Queue&);
void display(Queue&);

// Circular Queue Functions

void init(CircularQueue&);
bool empty(CircularQueue&);
bool full(CircularQueue&);
bool enqueue(CircularQueue&,int);
bool dequeue(CircularQueue&);
int front(CircularQueue&);
int size(CircularQueue&);
void display(CircularQueue&);

// LinkedList Queue
node* node_init(int);
void init(queue&);
bool empty(queue&);
void enqueue(queue&,int);
void dequeue(queue&);
int front(queue&);
int size(queue&);
void display(queue&);

// Main Function

int main(){
    // TODO: Implement program to run
    return 0;
}

///////////////////////////// Array-Based Queue Functions /////////////////////////////

void init(Queue& q){
    q.front = 1;
    q.rear = 0;
}

bool empty(Queue& q){
    return q.front == q.rear+1;
}

bool full(Queue& q){
    return q.rear == Max-1;
}

bool enqueue(Queue& q, int val){
    if(full(q)) 
        return false;
    q.a[++q.rear] = val;
    return true;
}

bool dequeue(Queue& q){
    if(empty(q))
        return false;
    q.front++;
    return true;
}

int front(Queue& q){
    if(empty(q))
        cerr<<"Error"<<endl;
    return q.a[q.front];
}

int size(Queue& q){
    if(empty(q))
        return 0;
    return q.rear-q.front+1;
}

void display(Queue& q){
    
    if(empty(q)){
        cout<<"Queue is Empty!"<<endl;
        return;
    }

    cout<<"Queue: ";
    for(int i = q.front; i <= q.rear;i++)
        cout<<q.a[i]<<", ";
    cout<<endl;

}

///////////////////////////// Circular Queue Functions /////////////////////////////

void init(CircularQueue& q){
    q.front = 1;
    q.rear = 0;
}

bool empty(CircularQueue& q){
    return q.front == (q.rear+1)%Max;
}

bool full(CircularQueue& q){
    return q.rear == (q.rear+2)%Max;
}

bool enqueue(CircularQueue& q,int val){
    if(full(q))
        return false;
    q.rear = (q.rear+1)%Max;
    q.a[q.rear] = val;
    return true;
}

bool dequeue(CircularQueue& q){
    if(empty(q))
        return false;
    q.front = (q.front+1)%Max;
    return true;
}

int front(CircularQueue& q){
    if(empty(q))
        cerr<<"Circular queue is empty!"<<endl;
    return q.a[q.front];
}

int size(CircularQueue& q){
    if(empty(q)){
        cout<<"Circular Queue is empty!"<<endl;
        return;
    }
    if(q.front <= q.rear){
        return (q.rear-q.front+1)%Max;
    }else{
        return (Max-q.front) + (q.rear+1);
    }
}

void display(CircularQueue& q){
    
    if(empty(q)){
        cout<<"Circular Queue is empty!"<<endl;
        return;
    }

    if(q.rear >= q.front){
    
        for(int i=q.front; i<=q.rear;i++)
            cout<<q.a[i]<<" ";
        cout<<endl;
    
    }else{
    
        for(int i=q.front; i<Max;i++)
            cout<<q.a[i]<<" ";
        for(int i=0; i<=q.rear;i++)
            cout<<q.a[i]<<" ";
        cout<<endl;
    
    }

}

///////////////////////////// Linked-List Based Queue Functions /////////////////////////////

node* node_init(int data){
    node* newNode;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void init(queue& q){
    q.front = q.rear = NULL;
}

bool empty(queue& q){
    return q.front == NULL;
}

void enqueue(queue& q,int val){
    
    node* newNode = node_init(val);
    
    if(empty(q)){
        q.front = q.rear = newNode;
        return;  
    }

    q.rear->next = newNode;
    q.rear = q.rear->next;

}

void dequeue(queue& q){
    
    if(empty(q)){
        return;
    }
    
    node* tmp = q.front;
    q.front = q.front->next;
    delete tmp;

}

int front(queue& q){
    
    if(empty(q)){
        cerr<<"Queue is Empty!"<<endl;
        exit(1);
    }
    
    return q.front->data;

}

int size(queue& q){

    if(empty(q)){
        return 0;
    }

    int size = 0;
    node* cur = q.front;
    
    while(cur->next != NULL){
        size++;
        cur = cur->next;
    }
    return size;

}

void display(queue& q){
    
    if(empty(q)){
        cout<<"Queue is Empty!"<<endl;
        return;
    }
    node* cur = q.front;   
    while(cur->next != NULL){
        cout<<cur->data<<", ";
        cur = cur->next;
    }
    cout<<endl; 

}