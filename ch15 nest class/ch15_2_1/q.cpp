#include <iostream>
#include "q.h"

template <class Item>
Queue<Item>::Queue(int qs): qsize(qs) {
    front = rear = 0;
    items = 0;
}

template <class Item>
Queue<Item>::~Queue() {
   Node * temp;
   while(front != 0) {
    temp = front;
    front = front->next;
    delete temp;
   }
}

template <class Item>
bool Queue<Item>::enqueue(const Item & item) {
    if (isFull()) {
        return false;
    }
    Node * add = new Node(item);
    items++;
    if (front == 0) {
        front = add;
    } else {
        rear->next = add;
    }
    rear = add;
    return true;
}

template <class Item>
bool Queue<Item>::dequeue(Item & item) {
    if (front == 0) {
        return false;
    }
    item = front -> item;
    items--;
    Node *temp = front;
    front = front->next;
    delete temp;
    if(items == 0) {
        rear = 0;
    }
    return true;
}