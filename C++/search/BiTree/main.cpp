#include <iostream>
#include <queue>

using namespace std;

typedef struct node
{
	char data;
	struct node *left;
	struct node *right;
}node, *Bitree;

void create(Bitree *T)
{
	char c;
	cin >> c;
	if(c == '#')
		*T = NULL;
	else
	{
		(*T) = new node;
		(*T)->data = c;
		create(&((*T)->left));
		create(&((*T)->right));
	}
}

void preorder(Bitree T)
{
	if(T)
	{
		cout << T->data << " ";
		preorder(T->left);
		preorder(T->right);
	}	
}

void inorder(Bitree T)
{
	if(T)
	{
		inorder(T->left);
		cout << T->data << " ";
		inorder(T->right);
	}	
}

void proorder(Bitree T)
{
	if(T)
	{
		proorder(T->left);
		proorder(T->right);
		cout << T->data << " ";		
	}	
}

int depth(Bitree T)
{
	if(!T)
		return 0;
	int ld = depth(T->left);
	int rd = depth(T->right);
	return (ld>rd?ld:rd) + 1;
}

void layerorder(Bitree T)
{
	queue<node*> buffer;
	if(T) buffer.push(T);
	while(!buffer.empty())
	{
		node* temp = buffer.front();
		cout << temp->data << " ";
		buffer.pop();		
		if(temp->left) buffer.push(temp->left);
		if(temp->right) buffer.push(temp->right);
	}
}

void layerdepth(Bitree T)
{
	queue<node*> buffer;
	if(T) buffer.push(T);
	int buffer_len = 0;
	int depth = 0;
	while(!buffer.empty())
	{
		buffer_len = buffer.size();
		while(buffer_len--)
		{
			node* temp = buffer.front();
			cout << temp->data << " ";
			buffer.pop();	
			if(temp->left) buffer.push(temp->left);
			if(temp->right) buffer.push(temp->right);
		}
	
		++depth;
	}
	cout << endl << "layer_depth:" << depth << endl;
}

int main(int argc,char **argv)
{
	Bitree T;
	create(&T);
	preorder(T);
	cout << endl;
	inorder(T);
	cout << endl;
	proorder(T);
	cout << endl;
	layerorder(T);
	cout << endl;
	cout << "depth : " << depth(T) << endl;
	layerdepth(T);
	return 0;
}
