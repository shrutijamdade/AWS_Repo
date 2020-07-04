#include <iostream>
#include <cstring>

using namespace std;

class Queue
{
    private:
        int size;
        int front, rear;
        int *store;

    public:
        Queue(int size)
        {
            this->size = size;
            front = rear = -1;
            store = new int[size];
        }

        int isEmpty()
        {
            if(rear == -1)
                return 1;
            return 0;
        }

        int isFull()
        {
            if((rear+1)%size == front)
                return 1;
            return 0;
        }
        
        void enQueue(int data)
        {
            if(!isFull())
            {
                if(front == -1)
                    front++;
                rear = (rear+1)%size;
                store[rear] = data;
            }
            
            else
                cout << "FULL" << endl;
        }
        
        void deQueue()
        {
            if(!isEmpty())
            {
                int data = store[front];
                if(rear == front)
                    front = rear = -1;
                else
                    front = (front+1)%size;
                    
                cout << data << endl;
            }
            
            else
                cout << "EMPTY" << endl;
        }

        ~Queue()
        {
            delete store;
        }
};

int main()
{
 /*   
    Queue q(5);
    
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.enQueue(60);
    q.enQueue(70);	
cout<<"Dequeue Operations"    
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
    q.deQueue();
*/    
    int size;
    cin >> size;
    
    Queue  q(size);
    string cmd;

    while(true)
    {
        cin >> cmd;
        
        if(cmd == "exit")
            break;
            
        if(cmd == "enque")
        {
            int data;
            cin >> data;
            q.enQueue(data);
        }
        
        if(cmd == "deque")
        {
            q.deQueue();
        }
        
    }
    
    
    
    
    
    return 0;
}