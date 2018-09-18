#include <stdio.h>
#include <malloc.h>

typedef int element;

typedef struct bt_node
{
	element data;
	struct bt_node *left;
	struct bt_node *right;
}bt_node,*btree;

typedef  btree position;


position find(element x, btree T)
{
	if(!T)
		return T;
	else if(x < T->data)
		return find(x,T->left);
	else if(x > T->data)
		return find(x,T->right);
	else
		return T;
}

position findMin(btree T)
{
	if(!T)
		return T;
	else if(!T->left)
		return T;
	else
		return findMin(T->left);
}

position findMax(btree T)
{
	if(!T)
		return T;
	else if(!T->right)
		return T;
	else
		return findMax(T->right);
}

void pre_order(btree T)
{
	if(!T) return ;
	
	pre_order(T->left);
	printf("%d ",T->data);
	pre_order(T->right);
}

btree Insert(element x, btree* T)
{
	if(!(*T))
	{
		*T = (bt_node*)malloc(sizeof(bt_node));
		(*T)->data = x;
		(*T)->left = NULL;
		(*T)->right= NULL; 
	}
	else
	{
		if(x < (*T)->data)
			(*T)->left = Insert(x, &(*T)->left);
		else if(x >(*T)->data)
			(*T)->right= Insert(x,&(*T)->right);
	}
	return *T;
}


btree Delete(element x,btree* T)
{
	position temp;
	if(!T) printf("not find!");
	else if(x < (*T)->data)
		(*T)->left = Delete(x,&(*T)->left);
	else if(x > (*T)->data)
		(*T)->right= Delete(x,&(*T)->right);
	else
	{
		if((*T)->left && (*T)->right)
		{
			temp = findMin((*T)->right);
			(*T)->data = temp->data;
			(*T)->right= Delete(temp->data,&(*T)->right);
		}
		else
		{
			temp = *T;
			if(!temp->left)
				(*T) = (*T)->right;
			else if(!temp->right)
				(*T) = (*T)->left;
			free(temp);
		}
		
	}
	return *T;
}

int main()
{
	btree T = NULL;
	int a[10] = {9,2,3,10,5,4,8,55,32,7};
	for(int i=0;i<10;++i)
		Insert(a[i],&T);
	pre_order(T);
	printf("\n");
	Delete(2,&T);
	pre_order(T);
	printf("\n");
	return 0;
}
