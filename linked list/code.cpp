#include <iostream>
#include <string>
using namespace std;

#define MAX 10

// Structure for gym member
struct Member {
int id;
string name;
string type;
};

// ---------- STACK (LIFO) ----------
Member stk[MAX];
int top = -1;

void push() {
if (top == MAX - 1) {
cout << "Stack is Full\n";
return;
}
Member m;
cout << "Enter Member ID: ";
cin >> m.id;
cout << "Enter Name: ";
cin >> m.name;
cout << "Enter Membership Type: ";
cin >> m.type;
stk[++top] = m;
cout << "Member added to Stack\n";
}

void pop() {
if (top == -1) {
cout << "Stack is Empty\n";
return;
}
cout << "Removed Member: ID " << stk[top].id
<< " | " << stk[top].name << endl;
top--;
}

void displayStack() {
if (top == -1) {
cout << "Stack is Empty\n";
return;
}
cout << "--- Members in Stack (Top to Bottom) ---\n";
for (int i = top; i >= 0; i--) {
cout << "ID: " << stk[i].id
<< " | Name: " << stk[i].name
<< " | Membership: " << stk[i].type << endl;
}
}

// ---------- QUEUE (FIFO) ----------
Member que[MAX];
int front = 0, rear = -1;

void enqueue() {
if (rear == MAX - 1) {
cout << "Queue is Full\n";
return;
}
Member m;
cout << "Enter Member ID: ";
cin >> m.id;
cout << "Enter Name: ";
cin >> m.name;
cout << "Enter Membership Type: ";
cin >> m.type;
que[++rear] = m;
cout << "Member added to Queue\n";
}

void dequeue() {
if (front > rear) {
cout << "Queue is Empty\n";
return;
}
cout << "Removed Member: ID " << que[front].id
<< " | " << que[front].name << endl;
front++;
if (front > rear) {   // reset when queue becomes empty
front = 0;
rear = -1;
}
}

void displayQueue() {
if (front > rear) {
cout << "Queue is Empty\n";
return;
}
cout << "--- Members in Queue (Front to Rear) ---\n";
for (int i = front; i <= rear; i++) {
cout << "ID: " << que[i].id
<< " | Name: " << que[i].name
<< " | Membership: " << que[i].type << endl;
}
}

// ---------- MAIN ----------
int main() {
int ch, op;

do {  
    cout << "\n1. Stack (Gym Members)  2. Queue (Gym Members)  3. Exit\n";  
    cout << "Enter choice: ";  
    cin >> ch;  

    if (ch == 1) {  
        cout << "1.Push 2.Pop 3.Display\n";  
        cout << "Enter choice: ";  
        cin >> op;  
        if (op == 1) push();  
        else if (op == 2) pop();  
        else if (op == 3) displayStack();  
        else cout << "Invalid choice\n";  
    }  
    else if (ch == 2) {  
        cout << "1.Add 2.Delete 3.Display\n";  
        cout << "Enter choice: ";  
        cin >> op;  
        if (op == 1) enqueue();  
        else if (op == 2) dequeue();  
        else if (op == 3) displayQueue();  
        else cout << "Invalid choice\n";  
    }  
    else if (ch != 3) {  
        cout << "Invalid choice\n";  
    }  

} while (ch != 3);  

return 0;

}
