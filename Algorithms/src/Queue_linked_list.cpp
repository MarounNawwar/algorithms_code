#include <iostream>
using namespace std;

class Queue {

    private:
        class node {
            public:
                int data;
                node* next;
        };

        node* node_init(int val = -99999) {
            node* newNode = new node();
            if (val != -99999)
                newNode->data = val;
            newNode->next = NULL;
            return newNode;
        }

    public:

        node* rear;
        node* front;

        void init() {
            this->front = NULL;
            this->rear = NULL;
        }

        Queue() {
            init();
        }

        bool is_empty() {
            return (this->front == NULL);
        }

        void enqueue(int val) {

            node* newNode = node_init(val);

            if (this->is_empty()) {
                this->front = newNode;
                this->rear = newNode;
                return;
            }

            this->rear->next = newNode;
            this->rear = newNode;

        }

        void dequeue() {

            node* tmp = this->front;
            this->front = this->front->next;
            delete tmp;

        }

        int get_front() {
            return this->front->data;
        }

        int size() {

            if (this->is_empty()) {
                return 0;
            }

            int ctr = 0;
            node* cur = this->front;

            while (cur != NULL) {
                ctr++;
                cur = cur->next;
            }

            return ctr;

        }

        void display() {

            if (is_empty()) {
                cout << "Queue is empty!" << endl;
                return;
            }

            cout << "Queue: ";
            
            node* cur = this->front;
            while (cur->next != NULL)
            {
                cout << cur->data << ", ";
                cur = cur->next;
            }
            
            cout << cur->data<< endl;


        }

};

int main() {

    Queue* q = new Queue();
    // Write Your Code Here!

    q->enqueue(6);
    q->enqueue(9);
    q->enqueue(3);
    q->enqueue(7);
    q->enqueue(4);

    q->display();
    cout << "Size: " << q->size() << endl;

    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();
    q->dequeue();

    q->display();
    cout << "Size: " << q->size() << endl;

    return 0;

}