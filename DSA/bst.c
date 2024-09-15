#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct BinaryTreeNode {
	int key;
	struct BinaryTreeNode *left, *right;
};

// Function to create a new node with a given value
struct BinaryTreeNode* newNodeCreate(int value)
{
	struct BinaryTreeNode* temp
		= (struct BinaryTreeNode*)malloc(
			sizeof(struct BinaryTreeNode));
	temp->key = value;
	temp->left = temp->right = NULL;
	return temp;
}

// Function to search for a node with a specific key in the tree
struct BinaryTreeNode* searchNode(struct BinaryTreeNode* root, int target)
{
	if (root == NULL || root->key == target) {
		return root;
	}
	if (root->key < target) {
		return searchNode(root->right, target);
	}
	return searchNode(root->left, target);
}

// Function to insert a node with a specific value in the tree
struct BinaryTreeNode* insertNode(struct BinaryTreeNode* node, int value)
{
	if (node == NULL) {
		return newNodeCreate(value);
	}
	if (value < node->key) {
		node->left = insertNode(node->left, value);
	}
	else if (value >= node->key) {
		node->right = insertNode(node->right, value);
	}
	return node;
}
struct BinaryTreeNode*mean(struct BinaryTreeNode* node)
{
    if(node==NULL)
    {
        return node;
    }
    else
    {
        return  mean(node->left);
    }

}
struct BinaryTreeNode*delete(struct BinaryTreeNode* node,int value)
{
    struct BinaryTreeNode*temp=searchNode(root, value);
    if(temp->left==NULL && temp->right==NULL)
    {
        struct BinaryTreeNode*t=temp;
        free(temp);
        return t;
    }
    else if(temp->left!=NULL && temp->right!=NULL)
    {
        struct BinaryTreeNode*t;

        t=mean(temp->right);
        temp->key=t->key;
        temp->right=delete(temp->right,temp->key);
    }
    else
    {
        if(temp->right==NULL)
        {
            temp=temp->left;
            free(temp->left);

        }
        else if(temp->left==NULL)
        {
            temp=temp->right;
            free(temp->right);
        }
        return temp;
    }
    return temp;
}

int main()
{
	// Initialize the root node
	struct BinaryTreeNode* root = NULL;
    struct BinaryTreeNode* t;

	// Insert nodes into the binary search tree
	root = insertNode(root, 50);
	insertNode(root, 30);
	insertNode(root, 20);
	insertNode(root, 40);
	insertNode(root, 70);
	insertNode(root, 60);
	insertNode(root, 80);

    t=mean(root);
    printf("%d\n",t->key);
    
    t=delete(70);
    printf("%d\n",t->key);

	return 0;
}
