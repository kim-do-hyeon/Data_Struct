#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 100

typedef char TElement;
typedef struct BinaryTreeNode{
    TElement data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
} TNode;

TNode* root;


typedef TNode* Element;

Element data[MAX_QUEUE_SIZE];
int front;
int rear;

void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}

void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }

void enqueue(Element val)
{
    if (is_full())
        error("Queue Full Error");
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    data[rear] = val;
}

Element dequeue()
{
    if (is_empty())
        error("Queue Empty Error");
    front = (front + 1) % MAX_QUEUE_SIZE;
    return data[front];
}

Element peek()
{
    if (is_empty())
        error("Queue Empty Error");
    return data[(front + 1) % MAX_QUEUE_SIZE];
}

void init_tree()
{
    root = NULL;
}
int is_empty_tree() { return root == NULL; }
TNode* get_root(){ return root;}


TNode* create_tree(TElement val, TNode *left, TNode *right)
{
    TNode *n = (TNode*)malloc(sizeof(TNode));
    n -> data = val;
    n -> left = left;
    n -> right = right;
    return n;
}

void preorder(TNode *n)
{
    if(n != NULL)
    {
        printf("[%c] ", n -> data);
        preorder(n -> left);
        preorder(n -> right);
    }
}

void inorder(TNode *n)
{
    if(n != NULL)
    {
        inorder(n -> left);
        printf("[%c] ", n -> data);
        inorder(n -> right);
    }
}

void postorder(TNode *n)
{
    if(n != NULL)
    {
        postorder(n -> left);
        postorder(n -> right);
        printf("[%c] ",n -> data);
    }
}

void levelorder(TNode *root){
    TNode* n;
    if(root == NULL) {
        return;
    }
    init_queue();
    enqueue(root);
    while(!is_empty()){
        n = dequeue();
        if(n != NULL){
            printf("[%c] ", n -> data);
            enqueue(n -> left);
            enqueue(n -> right);
        }
    }
    
}

int main(void)
{
    TNode *b, *c, *d, *e, *f;

    init_tree();
    d = create_tree('D', NULL ,NULL);
    e = create_tree('E', NULL, NULL);
    b = create_tree('B', d, e);
    f = create_tree('F', NULL, NULL);
    c = create_tree('C', f, NULL);
    root = create_tree('A', b, c);

    printf("\n   In-Order : "); inorder(root);
    printf("\n  Pre-Order : "); preorder(root);
    printf("\n Post-Order : "); postorder(root);
    printf("\nLevel-Order : "); levelorder(root);
    printf("\n");
}