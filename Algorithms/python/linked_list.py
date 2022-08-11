from asyncio.windows_events import NULL
from curses import noecho


class Node:

    #Initializing the new Node
    def __init__(self, data, next=None): 
        self.data = data
        self.next = next

class LinkedList:

    # Initializing the new Linked List
    def __init__(self):  
        self.head = None

    # Check if Linked list is empty
    def is_empty(self):
        return self.head and self.data

    # Return Number of elements in the linked list
    def get_length(self):
        if self.is_empty(): return 0
        ctr = 0
        while(self.head.next):
            ctr += 1
            self.head = self.head.next
        return ctr

    # Return sum of all nodes elements
    def count_value(self):
        if self.is_empty(): return 0
        sum = 0
        while(self.head.next):
            sum += self.head.data
            self.head = self.head.next
        return sum
    
    # Insert node to the queue of the linked list
    def insert_at_head(self,data):
        newNode = Node(data)
        if self.head:
            newNode.next = self.head
        self.head = newNode
        return self

    # Insert node to the queue of the linked list
    def insert_at_queue(self,data):
        newNode = Node(data)
        if(self.head):
            current = self.head
            while(current.next):
                current = current.next
            current.next = newNode
        else:
            self.head = newNode

    # Check if the element is in the list
    def is_in_list(self,data):
        if self.head.is_empty(): 
            return

        while self.head.next :
            if self.head.data == data:
                return True
            self.head = self.head.next
        return False

    # Find an element and return a node
    def find_element(self,data):
        if not self.head.is_empty():
            return
        
        while self.head.next != None:
            if self.head.data == data:
                return self.head
        return NULL


    def delete_element(self,data):

        if self.head.is_empty():
            return self.head
        
        if self.head.data:
            tmp = self.head.next
            del self.head
            self.head = tmp
            return self.head

        prev = self.head
        cur = self.head.next
        while cur.next != None:
            if cur.data == data:
                prev.next = cur.next
                del cur
                cur = prev.next
                return self.head
            prev = cur
            cur = cur.next

        if cur.data == data:
            prev.next = None
            del cur

        return self.head
        

    # Display Linked List
    def display(self):
        if not self.head:
            print("Empty Linked list!")
            return
        while self.head.next:
            print(self.head.data)
            self = self.head.next


def main():
    l = LinkedList()
    

if __name__ == '__main__':
    main()