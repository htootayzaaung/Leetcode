#include <iostream>

using namespace std;


class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        ~LinkedList() {
            Node* temp = head;
            while (head) {
                head = head->next;
                delete temp;
                temp = head;
            }
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        void getHead() {
            if (head == nullptr) {
                cout << "Head: nullptr" << endl;
            } else {
                cout << "Head: " << head->value << endl;
            }
        }

        void getTail() {
            if (tail == nullptr) {
                cout << "Tail: nullptr" << endl;
            } else { 
                cout << "Tail: " << tail->value << endl;
            }  
        }

        void getLength() {
            cout << "Length: " << length << endl;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            length++;
        }

        void deleteLast() {
            // Nothing to delete
            if (length == 0) return;

            // Create a copy of the current linked-list from head node
            Node* temp = head;
            if (length == 1) {
                head = nullptr;
                tail = nullptr;
            } else {

                // pre is the node before the tail node
                Node* pre = head;
                while (temp->next) {
                    pre = temp;
                    temp = temp->next;
                }
                tail = pre;
                tail->next = nullptr;
            }
            // temp is created to permenatly delete the last node from memory
            delete temp;
            length--;
        }

        void prepend(int value) {
            Node* newNode = new Node(value);
            if (length == 0) {
                head = newNode;
                tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
            length++;
        }

        void deleteFirst() {

            // Nothing to delete
            if (length == 0) return;

            // Create a copy of the current linked-list from head node
            Node* temp = head;

            // If there is only one node in the linked-list
            if (length == 1) {
                // Assinging nullptr to head and tail pointers results in deletion of the only node in the linked-list
                head = nullptr;
                tail = nullptr;
            } else {
                // head becomes the next node in the linked-list
                head = head->next;
            }
            delete temp;
            length--;
        }

        Node* get(int index) {
            if (index < 0 || index >= length) return nullptr;
            Node* temp = head;
            for (int i = 0; i < index; ++i) {
                temp = temp->next;
            }
            return temp;
        }

        void set(int index, int value) {
            Node* temp = get(index);
            if (temp != nullptr) {
                temp->value = value;
            }
        }

 		// WRITE INSERT MEMBER FUNCTION HERE //
        void insert(int index, int value)
        {
            if (index < 0 || index > length)
            {
                return;
            }
            else if (index == 0)
            {
                prepend(value);
            }
            else if (index == length) // Assuming that in at the end of the linked-list, the index is equal to the length of the linked-list since it stars from 0
            {
                append(value);
            }
            else 
            {
                // Creating a new single node
                Node *newNode = new Node(value);

                // Creating a copy of the existing linked-list
                Node *temp = get(index - 1);
                
                /*
                // Iterating through each node from the original linked-list until the node before the index
                for (int i = 0; i < index - 1; i++)
                {
                    temp = temp->next;
                }
                */
                newNode->next = temp->next;
                temp->next = newNode;
                length++;
            }
        }

        // WRITE DELETENODE MEMBER FUNCTION HERE //
        void deleteNode(int index)
        {
            if (index < 0 || index >= lenth)
            {
                return;
            }
            else if (index == 0)
            {
                deleteFirst();
            }
            else if (index = length - 1)
            {
                deleteLast()
            }
            else
            {
                /*
                    Suppose: 1 -> 2 -> 3 -> 4 -> 5
                
                    And suppose we want to delete the node "3"

                    Then, we need to access the node before the node to be deleted "2"
                    temp = 2

                    We then need to access the node to be deleted "3"
                    nodeToDelete = 3

                */ 

                // Accessing the node before the node to be deleted
                Node *temp = get(index - 1);

                // Accessing the node to be deleted
                Node *nodeToDelete = temp->next;

                // Bridging the gap by skipping nodeToDelete
                temp->next = nodeToDelete->next;

                // Deleting the node
                delete nodeToDelete;
                length--;
            }
        }
};



int main() {
        
    LinkedList* myLinkedList = new LinkedList(1);
    myLinkedList->append(2);
    myLinkedList->append(3);
    myLinkedList->append(4);
    myLinkedList->append(5);


    cout << "LL before deleteNode():\n";
    myLinkedList->printList();


    myLinkedList->deleteNode(2);
    cout << "\nLL after deleteNode() in middle:\n";
    myLinkedList->printList();


    myLinkedList->deleteNode(0);
    cout << "\nLL after deleteNode() of first node:\n";
    myLinkedList->printList();


    myLinkedList->deleteNode(2);
    cout << "\nLL after deleteNode() of last node:\n";
    myLinkedList->printList();


    /* 
        EXPECTED OUTPUT:
        ----------------
        LL before deleteNode():
        1
        2
        3
        4
        5

        LL after deleteNode() in middle:
        1
        2
        4
        5

        LL after deleteNode() of first node:
        2
        4
        5

        LL after deleteNode() of last node:
        2
        4

    */
        
}

