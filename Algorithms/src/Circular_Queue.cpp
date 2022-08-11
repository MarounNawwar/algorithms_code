#include <iostream>
using namespace std;


class CircularQueue{

    private:
        int rear;
        int front;

    public:
        int* a;
        int Max;

    //  Constructor
        CircularQueue(int size){
            this->Max = size;
            init(size);
        }

    //  Initialization 
        void init(int size){
            this->rear = 0;
            this->front = 1;
            this->a = new int[size];
        }

    //  Check if Queue is empty
        bool is_empty(){
            return (this->front == (this->rear+1)%this->Max);
        }

    //  Check if Queue is full
        bool is_full(){
            return (this->front == (this->rear+2)%this->Max);
        }       

    //  Insert value to a queue at the end of the queue
        bool enqueue(int val){

            if(this->is_full())
                return false; 
            this->a[((this->rear+1)%this->Max)] = val;
            return true;

        }

    //  Remove the first Element in a queue
        bool dequeue(){

            if(this->is_empty())
                return false;
            this->front = (this->front+1)%this->Max;
            return true;

        }

    //  Return Size of the Queue
        int size(){

            if(this->is_empty()){
                cerr<<"Queue is empty!"<<endl;
                exit(1);
            }

            if(this->front <= this->rear){
           
                return (this->rear - this->front + 1);
           
            }else{
           
                return ((this->Max - this->front) + this->rear);
           
            }

        }

    //  Display Queue
        void display(){
            
            if(this->is_empty()){
                cerr<<"Queue is Empty!"<<endl;
                return;
            }

            if(this->front <= this->rear){
           
                cout<<"Queue: ";
                for(int i = this->front; i <= this->rear; i++){
                    cout<<this->a[i]<<", ";
                }
                cout<<endl;     

            }else{
        
                cout<<"Queue: ";
                for(int i = this->front; i <= this->Max; i++){
                    cout<<this->a[i]<<", ";
                }
                for(int i = 0; i <= this->rear; i++){
                    cout<<this->a[i]<<", ";
                }
                cout<<endl;

            }

        }

    //  Return Front of Queue
        int get_front(){
            return this->a[this->front];
        }

    //  Return Rear of Queue
        int get_rear(){
            return this->a[this->rear];
        }

};