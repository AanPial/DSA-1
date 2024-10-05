#include <stdio.h>
#include <stdlib.h>
struct BinaryTreeNode
{
    int key;
    struct BinaryTreeNode *left, *right;
};
struct BinaryTreeNode *createNewnode(int val)
{
    struct BinaryTreeNode *temp;
    temp = (struct BinaryTreeNode *)malloc(sizeof(struct BinaryTreeNode));
    temp->key = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
struct BinaryTreeNode *insert(struct BinaryTreeNode *node, int val)
{
    if (node == NULL)
    {
        return createNewnode(val);
    }
    if (val > node->key)
    {
        node->right = insert(node->right, val);
    }
    else if (val < node->key)
    {
        node->left = insert(node->left, val);
    }
    return node;
}
void inOrder(struct BinaryTreeNode *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf(" %d ", root->key);
        inOrder(root->right);
    }
}
void preOrder(struct BinaryTreeNode *root)
{
    if (root != NULL)
    {
        printf(" %d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct BinaryTreeNode *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf(" %d ", root->key);
    }
}
struct BinaryTreeNode *search(struct BinaryTreeNode *root, int target)
{
    if (root == NULL || root->key == target)
    {
        return root;
    }
    if (target > root->key)
    {
        return search(root->right, target);
    }
    return search(root->left, target);
}
struct BinaryTreeNode *min(struct BinaryTreeNode *node)
{
    if (node == NULL || node->left == NULL)
    {
        return node;
    }
    return min(node->left);
}
struct BinaryTreeNode *max(struct BinaryTreeNode *node)
{
    if (node == NULL || node->right == NULL)
    {
        return node;
    }
    return max(node->right);
}
struct BinaryTreeNode *delete(struct BinaryTreeNode *root, int x)
{
    if (root == NULL)
        return NULL;

    if (x > root->key)
    {
        root->right = delete (root->right, x);
    }
    else if (x < root->key)
    {
        root->left = delete (root->left, x);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        else if (root->left == NULL || root->right == NULL)
        {
            struct BinaryTreeNode *temp;
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
        else
        {
            struct BinaryTreeNode *temp = min(root->right);
            root->key = temp->key;
            root->right = delete (root->right, temp->key);
        }
    }
    return root;
}
struct BinaryTreeNode *update(struct BinaryTreeNode *node, int target, int newval)
{
    struct BinaryTreeNode *temp = search(node, target);
    if (temp != NULL)
    {
        node = delete (node, target);
        node = insert(node, newval);
        printf("Updated value from %d to %d.\n", target, newval);
    }
    else
    {
        printf("\nValue Not Found!\n");
    }
    return node;
}
struct BinaryTreeNode *secondmax(struct BinaryTreeNode *node)
{
    struct BinaryTreeNode *temp = node;
    struct BinaryTreeNode *cur = NULL;
    while (temp->right != NULL)
    {
        cur = temp;
        temp = temp->right;
    }
    if (temp->left != NULL)
    {
        return max(temp->left);
    }
    return cur;
}
struct BinaryTreeNode *secondmin(struct BinaryTreeNode *node)
{
    struct BinaryTreeNode *temp = node;
    struct BinaryTreeNode *cur = NULL;
    while (temp->left != NULL)
    {
        cur = temp;
        temp = temp->left;
    }
    if (temp->right != NULL)
    {
        return min(temp->right);
    }
    return cur;
}
struct BinaryTreeNode *parent(struct BinaryTreeNode *root, int val)
{
    struct BinaryTreeNode *prev = NULL;
    struct BinaryTreeNode *cur = root;
    while (cur->key != val)
    {
        prev = cur;
        if (val < cur->key)
        {
            cur = cur->left;
        }
        else
        {
            cur = cur->right;
        }
    }
    return prev;
}
struct BinaryTreeNode *successor(struct BinaryTreeNode *root, int val)
{
    struct BinaryTreeNode *temp = search(root, val);
    if (temp == NULL)
    {
        return NULL;
    }
    struct BinaryTreeNode *temp2 = min(temp->right);
    if (temp2 == NULL)
    {
        struct BinaryTreeNode *t3 = temp2;
        int n = temp2->key;
        while (n >= t3->key)
        {
            t3 = parent(root, t3->key);
        }
        return t3;
    }
    return temp2;
}
struct BinaryTreeNode *predecessor(struct BinaryTreeNode *root, int val)
{
    struct BinaryTreeNode *temp = search(root, val);
    if (temp == NULL)
    {
        return NULL;
    }
    struct BinaryTreeNode *temp2 = min(temp->left);
    if (temp2 == NULL)
    {
        struct BinaryTreeNode *t3 = temp2;
        int n = temp2->key;
        while (n <= t3->key)
        {
            t3 = parent(root, t3->key);
        }
        return t3;
    }
    return temp2;
}
void transplant(struct BinaryTreeNode **root, struct BinaryTreeNode *u, struct BinaryTreeNode *v)
{
    if (u == *root)
    {
        *root = v; // If u is the root, replace root with v
    }
    else
    {
        struct BinaryTreeNode *parent_node = parent(*root, u->key);
        if (u == parent_node->left)
        {
            parent_node->left = v;
        }
        else
        {
            parent_node->right = v;
        }
    }
}
int countLeaves(struct BinaryTreeNode *node)
{
    if (node == NULL)
    {
        return 0; // If the node is NULL, there are no leaves
    }
    if (node->left == NULL && node->right == NULL)
    {
        return 1; // This is a leaf node
    }
    return countLeaves(node->left) + countLeaves(node->right); // Recursively count leaves in both subtrees
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int height(struct BinaryTreeNode *node)
{
    if (node == NULL)
    {
        return -1;
    }
    else
    {
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return max(leftHeight, rightHeight) + 1;
    }
}

int depth(struct BinaryTreeNode* root, int val) {
    
    if (root == NULL) {
        return -1;
    }
    if (root->key == val) {
        return 0;
    }
    
    struct BinaryTreeNode* parentNode = parent(root, val);
    
    if (parentNode == NULL) {
        return -1; 
    }


    return 1 + depth(root, parentNode->key);
}

int main()
{
    struct BinaryTreeNode *root = NULL;
    int choice, newval;
    while (1)
    {
    err:
        printf("\n1.Insert\n2.In-order Traversal(Sorting)\n3.Preorder\n4.Post-order\n5.Search\n6.Find min\n7.Find Max\n8.Update\n9.Delete\n10.Find second Max\n11.Find Second Min\n");
        printf("12.Parent\n13.Successor\n14.Predecessor\n15.Count leaf\n16.Height of a tree.\n17. Depth of Node\n");
        printf("\nEnter : ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            printf("\nExited!\n");
            break;
        }
        else if (choice == 1)
        {
            printf("Enter value : ");
            scanf("%d", &newval);
            root = insert(root, newval);
        }
        else if (choice == 2)
        {
            inOrder(root);
        }
        else if (choice == 3)
        {
            preOrder(root);
        }
        else if (choice == 4)
        {
            postOrder(root);
        }
        else if (choice == 5)
        {
            struct BinaryTreeNode *temp;
            printf("Enter value to search : ");
            scanf("%d", &newval);
            temp = search(root, newval);
            if (temp == NULL)
            {
                printf("\nValue not found!\n");
            }
            else
            {
                printf("\nValue %d is found.\n", temp->key);
            }
        }
        else if (choice == 6)
        {
            struct BinaryTreeNode *temp;
            temp = min(root);
            printf("\nThe minimum is : %d\n", temp->key);
        }
        else if (choice == 7)
        {
            struct BinaryTreeNode *temp;
            temp = max(root);
            printf("\nThe maximum is : %d\n", temp->key);
        }
        else if (choice == 8)
        {
            printf("Enter target value to update :");
            int target;
            scanf("%d", &target);
            printf("Enter new value : ");
            scanf("%d", &newval);
            root = update(root, target, newval);
            inOrder(root);
        }
        else if (choice == 9)
        {
            struct BinaryTreeNode *temp;
            printf("Enter value to delete: ");
            scanf("%d", &newval);
            temp = delete (root, newval);
            inOrder(root);
        }
        else if (choice == 10)
        {
            struct BinaryTreeNode *temp;
            temp = secondmax(root);
            printf("\nThe 2nd maximum is : %d\n", temp->key);
        }
        else if (choice == 11)
        {
            struct BinaryTreeNode *temp;
            temp = secondmin(root);
            printf("\nThe 2nd minimum is : %d\n", temp->key);
        }
        else if (choice == 12)
        {
            printf("Enter value of node for parent : ");
            scanf("%d", &newval);
            struct BinaryTreeNode *temp = parent(root, newval);
            printf("Parent is %d\n", temp->key);
        }
        else if (choice == 13)
        {
            printf("Enter value : ");
            scanf("%d", &newval);
            struct BinaryTreeNode *temp = successor(root, newval);
            printf("successor : %d", temp->key);
        }
        else if (choice == 14)
        {
            printf("Enter value : ");
            scanf("%d", &newval);
            struct BinaryTreeNode *temp = predecessor(root, newval);
            printf("predecessor : %d", temp->key);
        }
        else if (choice == 15)
        {
            int leafCount = countLeaves(root);
            printf("\nTotal number of leaves: %d\n", leafCount);
        }
        else if (choice == 16)
        {
            int treeHeight = height(root);
            printf("\nHeight of the tree: %d\n", treeHeight);
        }
        else if (choice == 17) {
            printf("Enter value to find its depth: ");
            scanf("%d", &newval);
            int nodeDepth = depth(root, newval);
            if (nodeDepth == -1) {
                printf("Node with value %d not found.\n", newval);
            } else {
                printf("Depth of node %d: %d\n", newval, nodeDepth);
            }
        }
        else
        {
            printf("\nWrong choice!\n");
            goto err;
        }
    }
}
