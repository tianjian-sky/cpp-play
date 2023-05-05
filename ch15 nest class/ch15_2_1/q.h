#ifndef TV_H_
#define TV_H_

template <class Item>
class Queue {
    public:
        Queue(int qs = Q_SIZE);
        ~Queue();
        bool isEmpty() const {
            return items == 0;
        }
        bool isFull () const {
            return items == Q_SIZE;
        }
        int queuecount () const {
            return items;
        }
        bool enqueue (const Item & item);
        bool dequeue(Item &item);
    private:
        enum {Q_SIZE = 10};
        class Node {
            public:
                Item item;
                Node * next;
                Node(const Item & i) : item(i), next(0) {}
        };
        Node *front;
        Node *rear;
        int items;
        const int qsize;
        Queue(const Queue &q):qsize(0) {};
        Queue & operator=(const Queue & q) {return *this;}

};

#endif