#include <stdio.h>
#include <stdlib.h>

typedef struct Tnode{
    int key;
    struct Tnode* left, * right;
} TNode;

int cnt = 0;


//================================================================
#define MAX_QUEUE_SIZE 100
typedef TNode* Element;
 
Element data[MAX_QUEUE_SIZE];
int front, rear;
 
void error(char str[]) {
    printf("%s\n", str);
    exit(1);
}

void init_queue() { front = rear = 0; ; }
int is_empty() { return front == rear; }
int is_full() { return front == (rear + 1) % MAX_QUEUE_SIZE; }
int size() { return(rear - front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; }
 
void enqueue(Element val) {
    if (is_full())
        error("큐 포화 에러");
    rear = (rear + 1) % MAX_QUEUE_SIZE;
    data[rear] = val;
}
Element dequeue() {
    if (is_empty())
        error("큐 공백 에러");
    front = (front + 1) % MAX_QUEUE_SIZE;
    return data[front];
}
Element peek() {
    if (is_empty())
        error("큐 공백 에러");
    return data[(front + 1) % MAX_QUEUE_SIZE];
}
 
void levelorder(TNode *root) {
    TNode* n;
    if(root == NULL){
        return;
    }
    init_queue();
    enqueue(root);
    while (!is_empty()) {
        n = dequeue();
        if (n != NULL) {
            printf("[%d] ", n->key);
            enqueue(n->left);
            enqueue(n->right);
        }
    }
}


// NEWNODE
TNode* newNode(int item){
    TNode * temp = (TNode*)malloc(sizeof(TNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// INORDER
//void levelorder(TNode* root){
//    if(root != NULL)
//    {
//        levelorder(root->left);
//        printf("[%d] ", root->key);
//        levelorder(root->right);
//    }
//}

// INSERT
TNode * insert_node_AVL(TNode* root, int key)
{
    if(root == NULL){
        return newNode(key);
    }
    if(key < root->key){
        root->left = insert_node_AVL(root->left, key);
    }
    else if(key > root->key){
        root->right = insert_node_AVL(root->right, key);
    }
    return root;
}

// CALC HEIGHT
int calc_height(TNode* n){
    int height_left, height_right;
    if (n == NULL)
    {
        return 0;
    }
    height_left = calc_height(n->left);
    height_right = calc_height(n->right);
    if(height_left > height_right)
    {
        return height_left + 1;
    }
    else{
        return height_right + 1;
    } 
}

// Calculate Node Length
int count_node(TNode *n) {
    if (n == NULL){
        return 0;
    }
    return count_node(n->left) + count_node(n->right) + 1;
}
 
// Calculate Leaf Node Length
int count_leaf(TNode *n) {
    if (n == NULL)
    {
        return 0;
    }
    if (n->left == NULL && n->right == NULL)
    {
        return 1;
    }
    else
    {
        return count_leaf(n->left) + count_leaf(n->right);
    }
}

// MAIN
void main()
{
    TNode* root;
    root = newNode(30); printf("\nAVL(30): "); levelorder(root);
    root = insert_node_AVL(root, 40); printf("\nAVL(40): "); levelorder(root);
    root = insert_node_AVL(root, 100); printf("\nAVL(100): "); levelorder(root);
    root = insert_node_AVL(root, 20); printf("\nAVL(20): "); levelorder(root);
    root = insert_node_AVL(root, 10); printf("\nAVL(10): "); levelorder(root);
    root = insert_node_AVL(root, 60); printf("\nAVL(60): "); levelorder(root);
    root = insert_node_AVL(root, 70); printf("\nAVL(70): "); levelorder(root);
    root = insert_node_AVL(root, 120); printf("\nAVL(120): "); levelorder(root);
    root = insert_node_AVL(root, 110); printf("\nAVL(110): "); levelorder(root);


	printf("\n노드의 개수 = %d\n", count_node(root));
	printf("단말의 개수 = %d\n", count_leaf(root));
	printf("트리의 높이 = %d\n", calc_height(root));

}