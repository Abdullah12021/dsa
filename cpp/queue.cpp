/*
 * Array based queue
 * 
 * This is "Linear queue", a better version is "Circular queue"
 * 
 * Stack philosophy: It removes the one who just entered.
 * Queue philosophy: It is a bit more generous—
 * it removes who came long ago and keeps who arrived just now.
 * 
 * rear is similar to stack's top
 * front is the one waiting at 0 index to delete
 */

#include <iostream>
using namespace std;
#define SIZE 5

class Queue{
    int items[SIZE] = {};
    int front = 0;
    int rear = -1;
public:

    bool isFull(){
        if(rear == 4){
            return true;
        } else {
            return false;
        }
    }
    bool isEmpty(){
        if(front == -1){
            return true;
        } else {
            return false;
        }
    }

    void enqueue(int addValue){
        if(isFull()){
            cout << "Queue is Full." << endl;
            return;
        }
        rear++;
        items[rear] = addValue;
        cout << "Added value: " << addValue << endl;
    }
    int dequeue(){
        if(isEmpty()){
            cout << "Queue is Empty" << endl;
            return -1;
        }
        int removeValue = items[front];
        front++;
        cout << "Removed value: " << removeValue << endl;
        return removeValue;
    }

    void showQueue(){
        cout << "[";
        for (int i = 0; i < 5; i++){
            cout << items[i];
            cout << ",";
        }
        cout << "]" << endl;
    }
    
    void menu(){
        int choice, num;
        while(choice != 4){
            cout << "1. Enqueue\n";
            cout << "2. Dequeue\n";
            cout << "3. Show Queue\n";
            cout << "4. Exit\n";\
            cout << "Choose option: ";
            cin >> choice;

            switch(choice){
                case 1:
                    cout << "Enter a value: ";
                    cin >> num;
                    enqueue(num);
                    break;
                case 2:
                    dequeue();
                    break;
                case 3:
                    showQueue();
                    break;
                case 4:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid selection! Try again.\n\n" << endl;
                    break;
            }
        }
    }

};


int main(){
    Queue myqueue;
    myqueue.menu();
}
