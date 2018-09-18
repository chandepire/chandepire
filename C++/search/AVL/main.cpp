#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdio.h>
using namespace std;

typedef int Type;

typedef struct AVLTreeNode
{
	Type key;
	int height;
	struct AVLTreeNode *left;
	struct AVLTreeNode *right;
}Node,*AVLTree;

Node* create(Type key, Node *left,Node *right)
{
	Node* p;
	if((p = (Node*)malloc(sizeof(Node))) == NULL)
		return NULL;
	p->key = key;
	p->height = 0;
	p->left = left;
	p->right = right;
	return p;
}

#define HEIGHT(p) ((p == NULL)?0:(((Node*)(p))->height))

int avltree_height(AVLTree tree)
{
	return HEIGHT(tree);
}

#define MAX(a,b) (((a)>(b))?(a):(b))

AVLTree LLR(AVLTree T)
{
	if(!T) return NULL;
	Node* k1 = T;
	Node* k2 = T->left;
	k1->left = k2->right;
	k2->right= k1;
	
	k1->height = MAX(HEIGHT(k1->left),HEIGHT(k1->right))+1;
	k2->height = MAX(HEIGHT(k2->left),HEIGHT(k2->right))+1;
	return k2;
}

AVLTree RRR(AVLTree T)
{
	if(!T) return NULL;
	Node* k1 = T;
	Node* k2 = T->right;
	k1->right = k2->left;
	k2->left = k1;
	
	k1->height = MAX(HEIGHT(k1->left),HEIGHT(k1->right))+1;
	k2->height = MAX(HEIGHT(k2->left),HEIGHT(k2->right))+1;
	return k2;
}

AVLTree LRR(AVLTree T)
{
	if(!T) return NULL;
	T->left = RRR(T->left);
	return LLR(T);
}

AVLTree RLR(AVLTree T)
{
	if(!T) return NULL;
	T->right = LLR(T->right);
	return RRR(T);
}

AVLTree insert(AVLTree T,Type value)
{
	if(T == NULL)
	{
		T = create(value,NULL,NULL);
	}
	else if(value < T->key)
	{
		T->left = insert(T->left, value);
		if(HEIGHT(T->left) - HEIGHT(T->right) == 2)
		{
			if(value < T->left->key)
				T = LLR(T);
			else
				T = LRR(T);
		}
	}
	else if(value > T->key)
	{
		T->right = insert(T->right, value);
		if(HEIGHT(T->right) - HEIGHT(T->left) == 2)
		{
			if(value < T->right->key)
				T = RLR(T);
			else
				T = RRR(T);
		}
	}
	else
	{
		cout << "the num is exists\n";
	}
	T->height = MAX(HEIGHT(T->left),HEIGHT(T->right))+1;
	return T;
}

void print_avl(AVLTree T,Type key,int direction)
{
	if(T)
	{
		if(direction == 0)
		{
			cout << key << " is root\n";
		}	
		else
		{
			if(direction == -1)
				cout << key << "'s left child :"  << T->key << endl;
			else
				cout << key << "'s right child :" << T->key << endl;
		}
		print_avl(T->left, T->key,-1);
	        print_avl(T->right,T->key, 1);
	}
	
}

void preorder(AVLTree T)
{
	if(T)
	{
		cout << T->key << " ";
		preorder(T->left);
		preorder(T->right);
	}
}

void inorder(AVLTree T)
{
	if(T)
	{
		inorder(T->left);
		cout << T->key << " ";
		inorder(T->right);
	}
}

void proorder(AVLTree T)
{
	if(T)
	{
		proorder(T->left);
		proorder(T->right);
		cout << T->key << " ";
	}
}

Node* search(AVLTree T,Type key)
{
	if(T == NULL || T->key == key)
		return T;
	if(key < T->key)
		return search(T->left, key);
	else
		return search(T->right,key);
}

Node* findMin(AVLTree T)
{
	if(!T) return NULL;
	while(T->left)
		T = T->left;
	return T;
}

Node* findMax(AVLTree T)
{
	if(!T) return NULL;
	while(T->right)
		T = T->right;
	return T;
}

AVLTree del_node(AVLTree T, Node* n)
{
	if(T == NULL)
	{
		cout << "the avl is none" << endl;
	}
	else if(n->key < T->key)
	{
		T->left = del_node(T->left, n);
		if(HEIGHT(T->right)-HEIGHT(T->left)==2)
		{
			Node* r = T->right;
			if(HEIGHT(r->right) > HEIGHT(r->left))
				T = RRR(T);
			else
				T = RLR(T);
		}
	}
	else if(n->key > T->key)
	{
		T->right = del_node(T->right, n);
		if(HEIGHT(T->right)-HEIGHT(T->left)==2)
		{
			Node* r = T->left;
			if(HEIGHT(r->right) > HEIGHT(r->left))
				T = LRR(T);
			else
				T = LLR(T);
		}
	}
	else
	{
		if(T->left && T->right)
		{
			if(HEIGHT(T->left) > HEIGHT(T->right))
			{
				Node* max = findMax(T->left);
				T->key = max->key;
				T->left = del_node(T->left,max);
			}
			else 
			{
				Node* min = findMax(T->left);
				T->key = min->key;
				T->left = del_node(T->right,min);
			}
		}
		else
		{
			Node* tmp = T;
			T = T->left?T->left:T->right;
			free(tmp);
		}
	}
	return T;
}

Node* avl_delNode(AVLTree T,Type key)
{
	Node* z;
	if((z=search(T,key)) != NULL)
		del_node(T,z);
	return T;
}

int main()
{
	Type v[16] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
	AVLTree T = NULL;
	for(int i=0;i<16;++i)
	{
		T = insert(T,v[i]);
	}
	preorder(T);
	cout << endl;
	inorder(T);
	cout << endl;
	proorder(T);
	cout << endl;
	cout << HEIGHT(T) << endl;
	Node* mi = findMin(T);
	Node* ma = findMax(T);	
	cout << mi->key << endl;
	cout << ma->key << endl;
	print_avl(T,T->key,0);
	T =avl_delNode(T,8);
	inorder(T);
	cout << endl;
	return 0;
}
