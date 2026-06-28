/*
 * Think of each node like an individual array index
 * but it stores Data and Pointer.
 * Unlike array, in linked list, 
 * nodes are not linked in a 'contiguous' way in memory,
 * instead they are 'linked'
 * 
 * Linked Structures, Contigious Structures.
 * 
 * If it just holds information: We use a struct. 
 * If it makes decisions or runs logic: We use a class.
 * Using Struct for node is standard, good for code readability.
 */

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
    Node* head;
public:
    LinkedList(){
        head = nullptr;     //nullptr - points to nothing
    }

    bool isEmpty(){
        if(head == nullptr){
            return true;
        } else {
            return false;
        }
    }
    // This time isFull is not needed, 
    // since there is no fixed size.

    void insertAtFront(int value){
        Node* helper = new Node();
        helper->data = value;
        helper->next = head;
        head = helper; // head is not pointing to null anymore
    }

    /*
     * helper says: "Hey head, i found this fresh 
     * memory spot in the RAM which you needed!" 
     * head answers: "Good work! Give it to me now, 
     * You are free to go."
     */
    
    void showList(){
        if(isEmpty()){
            cout << "List is Empty." << endl;
            return;
        }
        
        Node* copy = head;
        // We can use head directly but
        // it will destroy data from head.
         
        while(copy != nullptr){
            cout << copy->data << " -> ";
            copy = copy->next;  // jumping to next node
        }
        cout << "NULL" << endl;
    }

    void deleteAtFront(){
        if (isEmpty()) {
            cout << "List is Empty! Nothing to delete." << endl;
            return;
        }

        Node* temp = head;
        head = head->next;

        cout << "Vaporized data value: " << temp->data << endl;
        delete temp;    
    }

    void menu() {
        int choice = 0, num;
        while (choice != 4) {
            cout << "\n1. Insert at Front\n";
            cout << "2. Delete from Front\n";
            cout << "3. Show List\n";
            cout << "4. Exit\n";
            cout << "Choose option: ";
            cin >> choice;
    
            switch (choice) {
                case 1:
                    cout << "Enter a value: ";
                    cin >> num;
                    insertAtFront(num);
                    break;
                case 2:
                    deleteAtFront();
                    break;
                case 3:
                    showList();
                    break;
                case 4:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid option, Try again." << endl;
                    break;
            }
        }
    }
};

int main() {
    LinkedList mylist;
    mylist.menu();
    return 0;
}