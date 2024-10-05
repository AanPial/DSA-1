#include <stdio.h>
#include <stdlib.h>
#define MAX 100
struct node
{
    int data;
    struct node *next;
};
struct node *createNewnode(int v)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = v;
    temp->next = NULL;
    return temp;
}
void addEdge(struct node *adj[], int x, int y)
{
    // only for directed
    struct node *temp;
    temp = createNewnode(y);
    temp->next = adj[x];
    adj[x] = temp;

    // if it is undirected then add this part
    temp = createNewnode(x);
    temp->next = adj[y];
    adj[y] = temp;
}
void bfs(struct node *adj[], int vertices, int source, int color[], int distance[], int parent[])
{
    int queue[MAX];
    int front = 0, rear = 0;
    queue[rear] = source;
    rear++;
    color[source] = 1;

    while (front != rear)
    {
        int cur = queue[front];
        struct node *temp = adj[cur];
        printf("%d ", cur);
        while (temp != NULL)
        {
            int neighbor = temp->data;
            if (color[neighbor] == 0)
            {
                color[neighbor] = 1;
                parent[neighbor] = cur;
                distance[neighbor] = distance[cur] + 1;
                queue[rear] = neighbor;
                rear++;
            }
            temp = temp->next;
        }
        front++;
    }
}
int main()
{
    int vertices;
    printf("Enter no of vertices : ");
    scanf("%d", &vertices);
    struct node *adj[vertices];
    for (int i = 0; i < vertices; i++)
    {
        adj[i] = NULL;
    }

    int choice, x, y;
    while (1)
    {
    err:
        printf("\nMenu : \n1.Add edge[between vertex]\n2.BFS traversal\nEnter: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            printf("\nExited!\n");
            break;
        }
        else if (choice == 1)
        {
            printf("Enter 1st vertex : ");
            scanf("%d", &x);
            printf("Enter 2nd vertex : ");
            scanf("%d", &y);
            if(x>=vertices || y>=vertices)
            {
                goto err;
            }
            addEdge(adj, x, y);
        }
        else if (choice == 2)
        {
            int color[vertices], distance[vertices], parent[vertices];
            for (int i = 0; i < vertices; i++)
            {
                color[i] = 0;
                distance[i] = 0;
                parent[i] = -1;
            }
            printf("Enter source for BFS : ");
            int source;
            scanf("%d", &source);
            if(source>=vertices)
            {
                goto err;
            }
            bfs(adj, vertices, source, color, distance, parent);
            printf("\nMinimum Distance from 0 to 4 : %d\n",distance[4]);
            printf("\nParent of 4 : %d\n",parent[4]);
        }
        else
        {
            goto err;
        }
    }
}