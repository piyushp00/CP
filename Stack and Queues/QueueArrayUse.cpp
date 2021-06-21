#include <iostream>
//#include "QueueArrayClass.h"
//#include "DynamicQueue.h"
#include "QueueLLClass.h"
using namespace std;

int main(){
    Queue<int> q;

    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);

    cout << q.front() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;
    cout << q.deQueue() << endl;

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl;
}