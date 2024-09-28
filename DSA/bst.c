#include<stdio.h>
#include<stdlib.h>
struct BinaryTreeNode
{
	int key;
	struct BinaryTreeNode *left, *right;
};
struct BinaryTreeNode* createNewnode(int val)
{
    struct BinaryTreeNode* temp;
    temp=(struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
    temp->key=val;
    temp->left=NULL;
    temp->right=NULL;

    return temp;
}
struct BinaryTreeNode*insert(struct BinaryTreeNode*node,int val)
{
    if(node==NULL)
    {
        return createNewnode(val);
    }
    if(val>node->key)
    {
        node->right=insert(node->right,val);
    }
    else if(val<node->key)
    {
        node->left=insert(node->left,val);
    }
    return node;
}
void inOrder(struct BinaryTreeNode*root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf(" %d ",root->key);
        inOrder(root->right);
    }
}
void preOrder(struct BinaryTreeNode*root)
{
    if(root != NULL)
    {
        printf(" %d ",root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct BinaryTreeNode*root)
{
    if(root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ",root->key);
    }
}
struct BinaryTreeNode*search(struct BinaryTreeNode*root,int target)
{
    if(root==NULL || root->key==target)
    {
        return root;
    }
    if(target>root->key)
    {
        return search(root->right,target);
    }
    return search(root->left,target);
}
struct BinaryTreeNode* search2(struct BinaryTreeNode* root, int target)
{
    struct BinaryTreeNode* cur = NULL;  // Store the node if the target is found
    while(root != NULL)
    {
        if(target == root->key)  // If target is found
        {
            cur = root;  // Store the node
            break;  // Exit the loop
        }
        else if(target > root->key)  // Go to the right subtree
        {
            root = root->right;
        }
        else  // Go to the left subtree
        {
            root = root->left;
        }
    }
    return cur;  // Return the found node, or NULL if not found
}

struct BinaryTreeNode* min(struct BinaryTreeNode* node)
{
    if(node == NULL || node->left==NULL)
    {
        return node;
    }
    return min(node->left);
}
struct BinaryTreeNode* max(struct BinaryTreeNode* node)
{
    if(node == NULL || node->right==NULL)
    {
        return node;
    }
    return max(node->right);
}
struct BinaryTreeNode*delete (struct BinaryTreeNode* root, int x)
{
	if (root == NULL)
		return NULL;

	if (x > root->key) {
		root->right = delete (root->right, x);
	}
	else if (x < root->key) {
		root->left = delete (root->left, x);
	}
	else {
		if (root->left == NULL && root->right == NULL) 
        {
			free(root);
			return NULL;
		}
		else if (root->left == NULL || root->right == NULL) 
        {
			struct BinaryTreeNode* temp;
			if (root->left == NULL)
            {
				temp = root->right;
			}
			else
            {
				temp = root->left;
			}
			free(root);
			return temp;
		}
		else {
			struct BinaryTreeNode* temp = min(root->right);
			root->key = temp->key;
			root->right = delete (root->right, temp->key);
		}
	}
	return root;
}
struct BinaryTreeNode* update(struct BinaryTreeNode* node, int target, int newval) {
    struct BinaryTreeNode* temp = search(node, target);
    if (temp != NULL) {
        node = delete(node, target);
        node = insert(node, newval);
        printf("Updated value from %d to %d.\n", target, newval);
    } else {
        printf("\nValue Not Found!\n");
    }
    return node;
}
struct BinaryTreeNode* secondmax(struct BinaryTreeNode* node)
{
    struct BinaryTreeNode*temp=node;
    struct BinaryTreeNode*cur=NULL;
    while(temp->right!=NULL)
    {
        cur=temp;
        temp=temp->right;
    }
    if (temp->left != NULL) {
        return max(temp->left);
    }
    return cur;
}
struct BinaryTreeNode* secondmin(struct BinaryTreeNode* node)
{
    struct BinaryTreeNode*temp=node;
    struct BinaryTreeNode*cur=NULL;
    while(temp->left!=NULL)
    {
        cur=temp;
        temp=temp->left;
    }
    if (temp->right != NULL) {
        return max(temp->right);
    }
    return cur;
}
struct BinaryTreeNode* findSuccess(struct BinaryTreeNode* root,int newval)
{
    struct BinaryTreeNode* t=search(root,newval);
    struct BinaryTreeNode* t2=min(t->right);
    if(t2->left!=NULL && t2->right!=NULL)
    {
        struct BinaryTreeNode* t3=t2;
        int n=t2->key;
        while (t3->key<n)
        {
            t3=search2(root,t3->key);
        }
        return t3;
        
    }
    return t2;

}
int main()
{
    struct BinaryTreeNode* root=NULL;
    int choice,newval;
    while(1)
    {
        err:
        printf("\n1.Insert\n2.In-order Traversal(Sorting)\n3.Preorder\n4.Post-order\n5.Search\n6.Find min\n7.Find Max\n8.Update\n9.Delete\n10.Find second Max\n11.Find Second Min\n12.Find successor\n");
        printf("\nEnter : ");
        scanf("%d",&choice);
        if(choice == 0)
        {
            printf("\nExited!\n");
            break;
        }
        else if(choice == 1)
        {
            printf("Enter value : ");
            scanf("%d",&newval);
            root = insert(root, newval);
        }
        else if(choice == 2)
        {
            inOrder(root);
        }
        else if(choice == 3)
        {
            preOrder(root);
        }
        else if(choice == 4)
        {
            postOrder(root);
        }
        else if(choice == 5)
        {
            struct BinaryTreeNode* temp;
            printf("Enter value to search : ");
            scanf("%d",&newval);
            temp=search(root,newval);
            if(temp==NULL)
            {
                printf("\nValue not found!\n");
            }
            else
            {
                printf("\nValue %d is found.\n",temp->key);
            }
        }
        else if(choice == 6)
        {
            struct BinaryTreeNode* temp;
            temp=min(root);
            printf("\nThe minimum is : %d\n",temp->key);
        }
        else if(choice == 7)
        {
            struct BinaryTreeNode* temp;
            temp=max(root);
            printf("\nThe maximum is : %d\n",temp->key);
        }
        else if(choice == 8)
        {
            printf("Enter target value to update :");
            int target;
            scanf("%d",&target);
            printf("Enter new value : ");
            scanf("%d",&newval);
            root=update(root,target,newval);
            inOrder(root);
        }
        else if(choice == 9)
        {
            struct BinaryTreeNode* temp;
            printf("Enter value to delete: ");
            scanf("%d", &newval);
            temp = delete(root, newval);
            inOrder(root);
        }
        else if(choice == 10)
        {
            struct BinaryTreeNode* temp;
            temp=secondmax(root);
            printf("\nThe 2nd maximum is : %d\n",temp->key);
        }
        else if(choice == 11)
        {
            struct BinaryTreeNode* temp;
            temp=secondmin(root);
            printf("\nThe 2nd minimum is : %d\n",temp->key);
        }
        else if(choice == 12)
        {
            printf("Enter target mode : ");
            scanf("%d",&newval);
            struct BinaryTreeNode* temp=findSuccess(root,newval);
            printf("%d",temp->key);
        }
        else
        {
            printf("\nWrong choice!\n");
            goto err;
        }
    }
}
