class MyCircularQueue {
    private:
     int *queue;
     int front,rear,size,capacity;
public:
    MyCircularQueue(int k) {
        capacity = k;
        queue = new int[k];
        front = -1;
        rear = -1;
        size =0;
    }
    
    bool enQueue(int value) {
        if(isFull())
        return false;
        if(isEmpty()){
            front =0;
            rear =0;
        }else{
            rear = (rear+1) % capacity;
        }
        queue [rear] = value;
        size++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
        return false;
        if(front == rear){
            front =-1;
            rear =-1;
        }else{
            front = (front+1 ) % capacity;
        }
        size--;
        return true;
    }
    
    int Front() {
        if(isEmpty())
        return -1;
        return queue[front];
    }
    
    int Rear() {
        if(isEmpty())
        return -1;
        return queue[rear];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
     ~MyCircularQueue() {
        delete[] queue;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */