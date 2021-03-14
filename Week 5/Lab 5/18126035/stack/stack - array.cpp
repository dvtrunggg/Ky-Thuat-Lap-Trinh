#include<iostream>
using namespace std;
int top = -1;
bool isEmpty()
{
	if (top == -1)
		return true;
	return false;
}
bool isFull(int n)
{
	if (top >= n - 1)
		return true;
	return false;
}

void Push(int stack[], int x, int n)	// x is value, n is capacity
{
	if (isFull(n) == true)
	{
		cout << "Stack is full! " << endl;
		return;
	}
	top++;
	stack[top] = x;
}

void Pop()
{
	if (isEmpty() == true)
	{
		cout << "Stack is empty!" << endl;
		return;
	}
	top--;
}
void printStack(int stack[], int n)
{
	if (isEmpty() == true)
	{
		cout << "stack is empty" << endl;
		return;
	}
	for (int i = top; i >= 0; i--)
	{
		cout << stack[i]<<" \t";
	}
}
int Peek(int stack[])
{
	if (isEmpty() == true)
	{
		cout << "stack is empty" << endl;
	}
	return stack[top];
}

int main()
{
	int n = 20;
	int stack[20];
	Push(stack, 1, n);
	Push(stack, 2, n);
	Push(stack, 3, n);
	Push(stack, 4, n);
	Push(stack, 5, n);
	Pop();
	printStack(stack, n);	// last in first out:)
	return 0;

}