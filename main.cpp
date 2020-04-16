#include <iostream>
#define SIZE 5
using namespace std;

class myqueue
{
    int *arr;
    int first;
    int last;

public:
    myqueue( int Size = SIZE);
    ~myqueue();
    int Size;
    void push (int x);
    void pop();
    void get_queue();
    bool isEmpty();
    int front();
    int back();
    int size();

};
myqueue::myqueue(int Size){
    arr = new int [Size];
    first = 0;
    last = 0;
}

myqueue::~myqueue(){
delete arr;
}
void myqueue::push(int x) {
    if((last+1 == first)||((last+1 == Size) && (!first) )) {
        cout << "full\n";
        return;
    }
    last++;
    if (last == Size) last = 0;
    arr[last] = x;
}
void myqueue::pop(){
    if (first == last) {
        cout << "empty\n";
        return;
    }
    first++;
    if (first == Size) first = 0;
}
int myqueue::size(){
    int sum = 0;
    for (int i = first; i < last; i++)
        sum++;
    return sum;
}
int myqueue::back(){
    return arr[last];
}
int myqueue::front(){
    return arr[first+1];
}
void myqueue::get_queue(){
    for (int i = first + 1; i <= last; i++)
        cout << arr[i] << "\t";
}
bool myqueue::isEmpty(){
    return first==last;
}
int main()
{
    myqueue queuee;
    int k;
    cout << "enter the number of queue items: ";
    cin >> k;
    for (int i = 1; i <= k; i++)
       {queuee.push(i);}

    if (!queuee.isEmpty())
    {
        queuee.get_queue();
        cout << "\nfirst number: " << queuee.front() << endl;
        cout << "last number: " << queuee.back() << endl;
        cout << "size of queue: " << queuee.size()<< endl << endl;

        int m;
        cout << "enter the number you want to add to the queue: ";
        cin >> m;
        queuee.push(m);
        queuee.pop();
        cout << "queue with a new element, but without the first:\n";
        queuee.get_queue();
        cout << "\nnew first number: " << queuee.front() << endl;
        cout << "new last number: " << queuee.back() << endl;
        cout << "new size of queue: " << queuee.size() << endl;
    }
    else cout << "\nyour queue is empty";

    return 0;
}

