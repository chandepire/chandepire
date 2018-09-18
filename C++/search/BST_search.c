#include <stdio.h>
#include <stdlib.h>

typedef struct BitNode
{
	int data;
	struct BitNode *lchild,*rchild;
}BitNode , *BiTree;

void in_order(BiTree T)
{
	if(!T)
		return ;
	in_order(T->lchild);
	printf("%d ",T->data);
	in_order(T->rchild);
}

int searchBST(BiTree T,int key,BiTree f,BiTree *p)
{
	if(!T)
	{
		*p = f;
		return 0;
	}
	else if(T->data == key)
	{
		*p = T;
		return 1;
	}
	else if(T->data >key)
		searchBST(T->lchild,key,T,p);
	else
		searchBST(T->rchild,key,T,p);
}

int insertBST(BiTree *T,int key)
{
	BiTree temp;
	if(!searchBST(*T,key,NULL,&temp))
	{
		BitNode *s = (BiTree)malloc(sizeof(BitNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if(!temp)
			*T = s;
		else if(temp->data < key)
			temp->rchild = s;
		else
			temp->lchild = s;
		
		return 1;
	
	}
	return 0;
}

int delete(BiTree *p)
{
	BiTree s,q;
	if((*p)->rchild == NULL)
	{
		q = (*p);
		(*p) = (*p)->lchild;		
		free(q);
	}
	else if((*p)->lchild == NULL)
	{
		q = (*p);
		(*p) = (*p)->rchild;		
		free(q);
	}
	else
	{
		q = (*p);
		s = (*p)->lchild;	
		while(s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if(q == (*p))
			q->lchild = s->lchild;
		else
			q->rchild = s->lchild;
		free(s);
	}
	return 1;
}

int deleteBST(BiTree *T,int key)
{
	if(!(*T))
		return 0;
	else if((*T)->data == key)
		delete(T);
	else if((*T)->data < key)
		deleteBST(&(*T)->rchild,key);
	else
		deleteBST(&(*T)->lchild,key);
}

int main()
{
	int i=0;
	int a[10] = {62,88,58,47,88,73,51,99,37,93};
	BiTree T = NULL;
	for(i=0;i<10;++i)
		printf("%d ",insertBST(&T,a[i]));
	printf("\n\n%d\n\n",T->data);
	in_order(T);
	printf("\n\n");
	deleteBST(&T,88);
        in_order(T);
	return 0;
}
