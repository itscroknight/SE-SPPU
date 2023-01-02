#include <iostream>
using namespace std;
class queue
{
    int *arr;
    int size;
    int rear;
    int front;

public:
    queue(int size)
    {
        this->size = size;
        arr = new int[size];
        rear = front = -1;
    }

    void enqueue(int id)
    {
        if ((rear == size - 1 && front == 0) || (rear == (front - 1) % (size - 1)))
        {
            cout << "order is full " << endl;
        }
        else if (front == -1)
        {
            rear = front = 0;
            arr[rear] = id;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = id;
        }
        else
        {
            rear++;
            arr[rear] = id;
        }
    }

    void dequeue()
    {
        if (front == -1)
        {
            cout << "order is finish" << endl;
        }
        else if (rear == front)
        {
            arr[front] = -1;
            rear = front = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = -1;
            front = 0;
        }
        else
        {
            arr[front] = -1;
            front++;
        }
    }

    bool isEmpty()
    {
        if (front == -1)
            return true;
        else
            return false;
    }

    void display()
    {

        int i;
        if (isEmpty())
        {
            cout << endl
                 << "Empty Queue" << endl;
        }
        else
        {
          
            
            for (i = front; i != rear; i = (i + 1) % size)
                cout << arr[i] << " ";
            cout << arr[i] << " ";
           
        }

        cout << endl;
    }
};

int main()
{
    queue pizza(100);
    cout << "WELCOM TO PIZZA PARLER" << endl;
    while (1)
    {
        cout << "===================================PIZZA MANIA========================================"<< endl;
        cout << "1)Order a Pizza " << endl;
        cout << "2)Served pizza" << endl;
        cout << "3)Total orders : " << endl;
        cout << "4)Exit" << endl;

        cout << "========================================================================================"<< endl;

        int choise;
        cout << "Enter choice : ";
        cin >> choise;

        cout << endl;

        switch (choise)
        {
        case 1:
            int id;
            cout << "Enter ID : ";
            cin >> id;
            pizza.enqueue(id);
            break;
        case 2:
            pizza.dequeue();
            break;
        case 3:
            pizza.display();
            break;
        case 4:
            exit(0);
            break;
        }

        cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
}