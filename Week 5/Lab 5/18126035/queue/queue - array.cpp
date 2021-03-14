#include<iostream>
using namespace std;

int n = 20;	// size of queue[]
int queue[20];
int front = 0;	
int rear = -1;	


bool isEmpty()
{
	if (front < 0 || front > rear)
		return true;
	return false;

}
bool isFull()
{
	if (rear == n - 1)
		return true;
	return false;
}

void Enqueue(int data)
{
	if (isFull() == true)
	{
		cout << "Queue is full!" << endl;
		return;
	}
	rear++;
	queue[rear] = data;
}

void Dequeue()
{
	if (isEmpty() == true)
	{
		cout << "Queue is emty!" << endl;
		return;
	}
	queue[front] = 0;
	front++;
}
int Peek() 
{
	return queue[front];
}
void printQueue()
{
	if (isEmpty() == true)
	{
		cout << "Queue is empty!";
		return;
	}
	for (int i = front; i < rear; i++)
	{
		cout << queue[i] << "\t";
	}
}

int main()
{
	Enqueue(1);
	Enqueue(2);
	Enqueue(3);
	Enqueue(4);
	Enqueue(5);
	Enqueue(6);
	Dequeue();
	printQueue();	// first in frist out
	return 0;
}