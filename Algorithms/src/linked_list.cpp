#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

node* initialize_node(int data);
bool isEmpty(node* head);
int count_sum(node* head);
int get_element_length(node* head);
void insert_at_head(node* &head, int data);
void insert_at_queue(node* &head, int data);
bool is_in_list(node* head,int target_data);
node* find_element(node* head,int target_data);
void print_list(node* head);
void delete_element(node* &head,int val);
node* invert_list(node* head);

int main(){

    // Run the wanted script here
    return 0;
            
}

node* initialize_node(int data){
    node* tmp;
    tmp->data = data;
    tmp->next = NULL;
    return;
}

bool is_empty(node* head){
    return (head == NULL);
}

int get_element_length(node* head){
    if(head->next == NULL)
        return 1;
    return get_element_length(head->next)+1;
}

int count_sum(node* head){
    if(head->next == NULL)
        return head->data;
    return count_sum(head->next)+head->data;
}

void insert_at_head(node* &head, int data){

    node* tmp;
    tmp = initialize_node(data);
    tmp->next = head;
    head = tmp;

}

void insert_at_queue(node* &head, int data){
    
    node* new_node = initialize_node(data);
    while(head->next != NULL)
        head = head->next;
    head->next = new_node;

}

bool is_in_list(node* head,int target_data){

    while(head != NULL){
        if(head->data == target_data)
            return true;
        head = head->next;
    }
    return false;

}

node* find_element(node* head,int val){

    while(head->next != NULL){
        if(head->data == val)
            return head;
        head = head->next;
    }
    return NULL;

}

void print_list(node* head){
    while(head->next != NULL){
        cout<<head->data<<" ";
    }
}

void delete_element(node* &head, int val){

    //Case where the first element is the element to be deleted
    if(head->data == NULL){
       head = head->next; 
        return;
    }

    node* cur = head;
    node* prev;
    while(cur->next != NULL){ //Case where the element is in the middle of the list
        if(cur->data == val){
            prev->next = cur->next;
            cur = cur->next;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    //Case where the element is the last element of the function
    if(cur->next == NULL && cur->data == val){
        prev->next = NULL;
        cur = prev;
    }
    
}

node* invert_list(node* head){

    node* prev = NULL, *cur = NULL;

    while (head != NULL){
        prev = cur;
        head = head->next;
        cur = head;
        cur->next = prev;
    }
    head = cur;
    return head;

}

node* delete_list(node* head){

    node* tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        delete tmp;
    }

}