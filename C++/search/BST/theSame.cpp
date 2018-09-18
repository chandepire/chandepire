#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct TreeNode *Tree;
struct TreeNode
{
	int data;
	Tree left,right;
	int flag;
};

Tree insert(Tree *T,int v)
{
	if(!(*T))
	{
		(*T) = new struct TreeNode;
		(*T)->data = v;
		(*T)->left = (*T)->right = NULL;
		(*T)->flag = 0;
	}
	else if(v < (*T)->data)
		(*T)->left = insert(&((*T)->left),v);
	else if(v > (*T)->data)
		(*T)->right= insert(&((*T)->right),v);
	return *T;
}

Tree MakeTree(int N)
{
	int v;
	Tree T = NULL;
	for(int i=0;i<N;++i)
	{
		scanf("%d",&v);
		T = insert(&T,v);
	}
	return T;
}

int check(Tree *T,int v)
{
	if((*T)->flag)
	{
		if(v < (*T)->data) return check(&(*T)->left, v);
		else if(v > (*T)->data) return check(&(*T)->right, v);
		return 0;
	}
	else
	{
		if(v == (*T)->data)
		{
			(*T)->flag = 1;
			return 1;
		}
		else
			return 0;
	}
}

int Judge(Tree *T,int N)
{
	int v;
	int flag = 0;
	for(int i=0;i<N;++i)
	{
		scanf("%d",&v);
		if((!flag) && !check(T,v)) 
			flag = 1;
	}
	if(flag) return 0;
	return 1;
}

void Reset(Tree T)
{
	if(T->left)	Reset(T->left);
	if(T->right)	Reset(T->right);
	T->flag = 0;
}

void FreeTree(Tree *T)
{
	if((*T)->left)	FreeTree(&(*T)->left);
	if((*T)->right)	FreeTree(&(*T)->right);
	delete *T;
}

void showtree(Tree T)
{
	if(T)
	{
		cout << T->data << " ";
	
		showtree(T->left);
		
		showtree(T->right);
	}
}
int main()
{
    int N,L,i;
    Tree T;
    scanf("%d", &N);
    while(N)
    {
 	scanf("%d",&L);
	T = MakeTree(N);
	showtree(T);
	cout << endl;
	for(int i=0;i<L;++i)
	{
		if(Judge(&T,N)) cout << "Yes\n";
		else cout << "No" << endl;
		Reset(T);
	}
	FreeTree(&T);
	cout << "input N :" << endl;
	scanf("%d",&N);
    }
    return 0;
}
