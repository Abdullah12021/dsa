// BASED ON ARRAY

#include <iostream>
using namespace std;
#define SIZE 5

class Stack{
    int items[SIZE] = {};
    int top;
public:
    Stack(){
        top = -1;
    }

    bool isFull(){
        if (top == SIZE - 1){
            return true;
        } else {
            return false;
        }
    }

    bool isEmpty(){
        if (top == -1){
            return true;
        } else {
            return false;
        }
    }

    // return for "void" means: exiting function
    void push(int value){
        if (isFull()){
            cout << "Stack is FULL, try to Pop.";
            return;
        }
        top++;
        items[top] = value;
        cout << "Pushed value: " << items[top] << endl;
    }

    int pop(){
        if (isEmpty()){
            cout << "Stack is EMPTY, try to Push.";
            return -1;
        }
        int poppedValue = items[top];
        top--;
        cout << "Popped Value: " << poppedValue << endl;
        return poppedValue;
    }

    void menu(){
        int choice, num;
        while(choice != 3){
            cout << "1. Push \n";
            cout << "2. Pop \n";
            cout << "3. Exit \n";\
            cout << "Choose option: ";
            cin >> choice;
            
            switch(choice){
                case 1:
                    cout << "Enter a value: ";
                    cin >> num;
                    push(num);
                    break;
                case 2:
                    pop();
                    break;
                case 3:
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid selection! Try again.\n\n" << endl;
                    break;
            }
        }
    }

};

int main (){
    Stack mystack;
    mystack.menu();
}
