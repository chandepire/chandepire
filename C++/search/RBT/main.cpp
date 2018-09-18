#include <iostream>
#include <stdio.h>

using namespace std;

#define RED 0
#define BLACK 1

typedef int Type

typedef struct RBTreeNode
{
	unsigned char color;
	Type key ;
	struct RBTreeNode *left;
	struct RBTreeNode *right;
	struct RBTreeNode *parent; 
}Node,*RBTree;

typedef struct rb_root
{
	Node *node;
}RBRoot;

void left_R(RBRoot *tree,Node *x)
{
	Node* y = x->right;
	x->right = y->left;
	if(!y->left)
		y->left->parent = x;
	y->parent = x->parent;
	if(!x->parent)
	{
		tree->node = y;
	}
	else{
		if(x->parent->left == x)
			x->parent->left = y;
		else
			x->parent->right= y;
	}
	y->left = x;
	x->parent = y;
}

void right_R(RBRoot *tree,Node *y)
{
	Node* x = y->left;
	y->left = x->right;
	if(!x->right)
		x->right->parent = y;
	x->parent = y->parent;
	if(!y->parent)
	{
		tree->node = x;
	}
	else{
		if(y->parent->left == y)
			y->parent->left = x;
		else
			y->parent->right= x;
	}
	x->right = y;
	y->parent = x;
}

void insert(RBRoot *root, Node *node)
{
	Node *y = NULL;
	Node *x = root->node;
	
	while(!x)
	{
		y = x;
		if(node->key < x->key)
			x = x->left;
		else
			x = x->right;
	}
	node->parent = y;
	if(!y)
		root->node = node;
	else
	{
		if(node->key < y->key)
			y->left = node;
		else
			y->right= node;
	}

	node->color = RED;
	insert_fixup(root, node);
}

void insert_fixup(RBRoot *root,Node *node)
{
	Node *parent,*gparent;
	while((parent=node->parent) && rb_is_red(parent))
	{
		gparent = parent->parent;
		if(parent == gparent->left)
		{
			{
				Node *uncle = gparent->right;
				if(uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
                    			rb_set_black(parent);
                    			rb_set_red(gparent);
                    			node = gparent;
                    			continue;
				}
			}
			if (parent->right == node)
           		{
                		Node *tmp;
                		rbtree_left_rotate(root, parent);
                		tmp = parent;
                		parent = node;
                		node = tmp;
            		}

            		// Case 3条件：叔叔是黑色，且当前节点是左孩子。
            		rb_set_black(parent);
            		rb_set_red(gparent);
            		rbtree_right_rotate(root, gparent);
			
		}
		else
		{
			{
				Node *uncle = gparent->left;
				if(uncle && rb_is_red(uncle))
				{
					rb_set_black(uncle);
                    			rb_set_black(parent);
                    			rb_set_red(gparent);
                    			node = gparent;
                    			continue;
				}
			}
			if (parent->left == node)
           		{
                		Node *tmp;
                		rbtree_right_rotate(root, parent);
                		tmp = parent;
                		parent = node;
                		node = tmp;
            		}

            		// Case 3条件：叔叔是黑色，且当前节点是左孩子。
            		rb_set_black(parent);
            		rb_set_red(gparent);
            		rbtree_left_rotate(root, gparent);
		}
	}
	rb_set_black(root->node);
}


int main()
{
	
	return 0;
}
