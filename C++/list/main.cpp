#include <iostream>

using namespace std;

typedef struct node
{
	int cur_add;
	int data;
	int next_add;
	struct node *next;
}node,*Nlist;


Nlist reverse(Nlist head,int k)
{
	int cnt = 1;
	Nlist now = head->next;
	Nlist old = now->next;
	while(cnt < k)
	{
		Nlist tmp = old->next;
		old->next = now;
		now = old;
		old = tmp;
		++cnt;
	}
	head->next->next = old;
	old = head->next;
	head->next = now;
	return old;
}
	
int main()
{
	Nlist head = new node;
	head->next = NULL;
	Nlist rear = head;
	for(int i=0;i<10;i++)
	{
		node *temp = new node;
		temp->cur_add = i;
		temp->data    = 1+i;
		temp->next_add= 1+i;
		temp->next = NULL;		
		rear->next = temp;
		rear = temp; 
	}
	rear->next_add = -1;
	rear = head;
	while(rear->next)
	{
		cout << rear->next->cur_add << " " << rear->next->data << " " << rear->next->next_add << endl;
		rear = rear->next;
	}
	cout << endl;
	int k = 5;
	int s = 10/k;
	rear = head;
	for(int i=0;i<s;++i)
		rear = reverse(rear,k);
		rear = head;
	while(rear->next->next)
	{
		cout << rear->next->cur_add << " " << rear->next->data << " " << rear->next->next->cur_add << endl;
		rear = rear->next;
	}
	cout << rear->next->cur_add << " " << rear->next->data << " " << -1 << endl;
	return 0;
}
