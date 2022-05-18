#include <stdio.h>
#include <stdlib.h>
 
typedef int TElement;
 
typedef struct BinaryTreeNode {
    TElement     data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} TNode;
TNode* root;
 
void init_tree() { root = NULL; }
int is_empty_tree() { return root == NULL; }
TNode* get_root() { return root; }
 
TNode* create_tree(TElement val, TNode* l, TNode* r)
{
    TNode* n = (TNode*)malloc(sizeof(TNode));
    n->data = val;
    n->left = l;
    n->right = r;
    return n;
}

void Preorder(TNode *n) {
    if (n != NULL) {
        printf("[%d] ", n->data);
        Preorder(n->left);
        Preorder(n->right);
    }
}
void inorder(TNode *n) {
    if (n != NULL) {
        inorder(n->left);
        printf("[%d] ", n->data);
        inorder(n->right);
    }
}
void Postorder(TNode *n) {
    if (n != NULL) {
        Postorder(n->left);
        Postorder(n->right);
        printf("[%d] ", n->data);
    }
}
 
// 기본 제공 코드
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
            printf("[%d] ", n->data);
            enqueue(n->left);
            enqueue(n->right);
        }
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
 
// Calculate Tree Height
int Tree_Heigth(TNode *n) {
    int height_left, height_right;
    if (n == NULL)
    {
        return 0;
    }
    height_left = Tree_Heigth(n->left);
    height_right = Tree_Heigth(n->right);
    if(height_left > height_right)
    {
        return height_left + 1;
    }
    else{
        return height_right + 1;
    }
}
 
TNode* search(TNode *n, int key) {
    if (n == NULL) return NULL;
    else if (key == n->data) return n;
    else if (key < n->data) return search(n->left, key);
    else return search(n->right, key);
}
 
void search_Binary_Serach_Tree(int key) {
    TNode* n = search(root, key);
    if (n != NULL)
    {
        printf("[탐색 연산] : 성공 [%d] = 0x%x\n", n->data, n);
    }
    else
    {
        printf("[탐색 연산] : 실패: No %d!\n", key);
    }
}

int insert(TNode* r, TNode* n) {
    if (n->data == r->data)
    {
        return 0;
    }
    else if (n->data < r->data)
    {
        if (r->left == NULL)
        {
            r->left = n;
        }
        else
        {
            insert(r->left, n);
        }
    }
    else {
        if (r->right == NULL)
        {
            r->right = n;
        }
        else 
        {
            insert(r->right, n);
        }
    }
    return 1;
}
 
void insert_Binary_Serach_Tree(int key) {
    TNode* n = create_tree(key, NULL, NULL);
    if (is_empty_tree())
    {
        root = n;
    }
    else if (insert(root, n) == 0)
    {
        free(n);
    }
}

void find_max_value(TNode *node)
{
    int temp = 0;
    TNode* n;
    if(root == NULL){
        return;
    }
    init_queue();
    enqueue(root);
    while (!is_empty()) {
        n = dequeue();
        if (n != NULL) {
            if(n->data > temp)
            {
                temp = n->data;
            }
            enqueue(n->left);
            enqueue(n->right);
        }
    }
    printf("%d\n", temp);
}

void delete_node (TNode *parent, TNode *node) {
    TNode *child, *succ, *succp;
    /*
    단말노드의 부모노드를 찾아서 연결을 끊으면 된다.
    */
    if ((node->left == NULL && node->right == NULL)) { // case 1 : 단말 노드 삭제
        if (parent == NULL) root = NULL;
        else {
            if (parent->left == node)
                parent->left = NULL;
            else parent->right = NULL;
        }
    }
    /*
    노드는 삭제하고 서브 트리는 부모 노드에 붙여줌
    */
    else if (node->left == NULL || node->right == NULL) { // case 2 : 자식이 하나인 노드 삭제
        child = (node->left != NULL) ? node->left : node->right;
        if (node == root) root = child;
        else {
            if (parent->left == node)
                parent->left = child;
            else parent->right = child;
        }
    }
    /*
    가장 비슷한 값을 가진 노드를 삭제 노드 위치로 가져옴
    후계 노드의 선택
    */
    else { // case 3 두개의 자식을 가진 노드 삭제
        succp = node;
        succ = node->right;
        while (succ->left != NULL) {
            succp = succ;
            succ = succ->left;
        }
        if (succp->left == succ)
            succp->left = succ->right;
        else succp->right = succ->right;
        
        node->data = succ->data;
        node = succ;
    }
    // free(succ);
}
 
void delete_Binary_Serach_Tree(int key) {
    TNode *parent = NULL;
    TNode *node = root;
    
    if (node == NULL) return;
    while (node != NULL && node->data != key) {
        parent = node;
        node = (key < node->data) ? node->left : node->right;
    }
    if (node == NULL)
        printf("키가 없습니다.\n");
    else delete_node (parent, node);
}
 
int main()
{
    init_tree();
    printf("[삽입 연산] : 35 18  7 26  3 68 22 30 99");
    insert_Binary_Serach_Tree(35);
    insert_Binary_Serach_Tree(18);
    insert_Binary_Serach_Tree(7);
    insert_Binary_Serach_Tree(26);
    insert_Binary_Serach_Tree(12);
    insert_Binary_Serach_Tree(3);
    insert_Binary_Serach_Tree(68);
    insert_Binary_Serach_Tree(22);
    insert_Binary_Serach_Tree(30);
    insert_Binary_Serach_Tree(99);
    
    printf("\n   In-Order : "); inorder(root);
    printf("\n  Pre-Order : "); Preorder(root);
    printf("\n Post-Order : "); Postorder(root);
    printf("\nLevel-Order : ");  levelorder(root);
    
    printf("\n 노드의 개수 = %d\n", count_node(root));
    printf(" 단말의 개수 = %d\n", count_leaf(root));
    printf(" 트리의 높이 = %d\n", Tree_Heigth(root));
    
    search_Binary_Serach_Tree(26);
    search_Binary_Serach_Tree(25);
    
    printf("\noriginal bintree: LevelOrder: "); levelorder(root);                                                              
    delete_Binary_Serach_Tree(3);
    printf("\ncase1: < 3> 삭제: LevelOrder: "); levelorder(root);
    delete_Binary_Serach_Tree(68);
    printf("\ncase2: <68> 삭제: LevelOrder: "); levelorder(root);
    delete_Binary_Serach_Tree(18);
    printf("\ncase3: <18> 삭제: LevelOrder: "); levelorder(root);
    delete_Binary_Serach_Tree(35);
    printf("\ncase3: <35> root: LevelOrder: "); levelorder(root);
    
    printf("\n 노드의 개수 = %d\n", count_node(root));
    printf(" 단말의 개수 = %d\n", count_leaf(root));
    printf(" 트리의 높이 = %d\n", Tree_Heigth(root));
    printf(" 삽입된 배열 중 가장 큰 값 = ");
    find_max_value(root);
    return 0;
}