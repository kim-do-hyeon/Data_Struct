# 이진탐색트리
탐색작업을 효율적으로 하기 위한 자료구조
<img width="524" alt="Pasted Graphic" src="https://user-images.githubusercontent.com/21982942/167353223-6047f8c5-94df-4507-bae0-4d6716015a54.png">

레코드 record / 필드  field / 테이블 table / 키 key / 주요키 primary key

- 모든 노드는 유일한 키를 갖는다.
- 왼쪽 서브 트리 키들은 루트 키보다 작다.
- 오른쪽 서브 트리의 키들은 루트의 키보다 크다.
- 왼쪽과 오른쪽 서브 트리도 이진탐색트리다.

<img width="644" alt="Pasted Graphic 1" src="https://user-images.githubusercontent.com/21982942/167353255-232fc17f-4618-4a3d-955e-9d8bcd3769c9.png">

- key(왼쪽 서브 트리) <= key(루트 노드) <= key(오른쪽 서브 트리)
- 이진탐색을 중위순회하면 오름차순으로 정렬된 값을 얻을 수 있다.

<img width="644" alt="Pasted Graphic 2" src="https://user-images.githubusercontent.com/21982942/167353611-2c1fee28-732f-4058-801e-d163243bf8b2.png">

- 기본 연산은 이진트리와 동일하다.

# 탐색연산
- 비교한 결과가 같으면 탐색이 성공적으로 끝난다.
- 키 값이 루트보다 작으면 -> 왼쪽 자신을 기준으로 다시 탐색
- 키 값이 루트보다 크면 -> 오른쪽 자식을 기준으로 다시 탐색

<img width="530" alt="image" src="https://user-images.githubusercontent.com/21982942/167364152-7d3d6840-56bf-4de7-93f4-fc13bc142022.png">


```
# Logical #

function search(root, key)

if root = NULL
    then return NULL;
if key = KEY(root)
    then return root;
    else if key < KEY(root)
        then return serach(LEFT(root), key);
        else
            return search(RIGHT(root), key);
```

### 순환적인 구현
```C
# Logical C #

TNode* search(TNode *n, int key)
{
    if(n == NULL)   return NULL;
    else if(key == n -> data)   return n;
    else if(key < n -> data)    return search(n -> left, key);
    else    return search(n -> right, key);
}
```
```Python
# Logical Python #

def find(self, val):
        if (self.findNode(self.root, val) is False):
            return False
        else:
            return True
```

### 반복적인 구현
```C
# Logical C #

TNode* search_iter(TNode *n, int key)
{
    while(n != NULL)
    {
        if(key == n -> data)    return n;
        else if(key < n-> data)     n = node -> left;
        else    n = node -> right;
    }
    return NULL;
}
```
```Python
# Logical Python #
def findNode(self, currentNode, val):
        if (currentNode is None):
            return False
        elif (val == currentNode.val):
            return currentNode
        elif (val < currentNode.val):
            return self.findNode(currentNode.leftChild, val)
        else:
            return self.findNode(currentNode.rightChild, val)
```

# 삽입연산
- 먼저 탐색을 수행하며, 탐색에 실패한 위치가 바로 새로운 노드를 삽입하는 위치이다.

<img width="530" alt="image" src="https://user-images.githubusercontent.com/21982942/167364119-dd210de6-e5d7-4c4c-a72a-5520c735d4a3.png">

```
# Logical #

function insert(root, n)

if KEY(n) = kEY(root)
    then return;
else if KEY(n) < KEY(root) then
    if LEFT(root) = NULL
        then LEFT(root) <- n;
        else insert(LEFT(root), n);
else
    if RIGHT(root) = NULL
        then RIGHT(root) <- n;
        else insert(RIGHT(root), n);
```

```C
# Logical C #

void insert(TNode *r, TNode *n)
{
    if(n -> data == r ->data) return;
    else if(n -> data < r -> data)
    {
        if(r -> left == NULL)
        {
            r -> left = n;
        }
        else
        {
            insert(r -> left, n);
        }
    }
    else
    {
        if(r -> right == NULL)
        {
            r -> right = n;
        }
        else
        {
            insert(r -> right, n);
        }
    }
}
```
```Python
# Logical Python #

def insert(self, val):
        if (self.root is None):
            self.setRoot(val)
        else:
            self.insertNode(self.root, val)

def insertNode(self, currentNode, val):
    if (val <= currentNode.val):
        if (currentNode.leftChild):
            self.insertNode(currentNode.leftChild, val)
        else:
            currentNode.leftChild = Node(val)
    elif (val > currentNode.val):
        if (currentNode.rightChild):
            self.insertNode(currentNode.rightChild, val)
        else:
            currentNode.rightChild = Node(val)
```

# 삭제연산
- 이진탐색트리에서의 삭제 연산은 복잡하다.
<br>
- 노드 삭제의 3가지 경우
> 삭제하려는 노드가 단말 노드일 경우 <br>
> 삭제하려는 노드가 하나의 왼쪽이나 오론쪽 서브 트리중 하나만 가지고 있는 경우<br>
> 삭제하려는 노드가 두개의 서브 트리 모두 가지고 있는 경우<br>

## 케이스 1 : 단말 노드의 삭제
- 단말 노드의 부모 노드를 찾아서 연결을 끊으면 된다.
<img width="526" alt="image" src="https://user-images.githubusercontent.com/21982942/167577913-00b73f91-8c28-4481-a0b2-7418070aa871.png">

```
# Logical #
if((node -> left == NULL && node -> right == NULL)){
    if(parent == NULL) root = NULL;
    else {
        if(parent -> left == node)
            parent -> left = NULL;
        else parent -> right = NULL;
    }
}
```

## 케이스 2 : 자식이 하나인 노드 삭제
- 노드는 삭제하고 서브 트리는 부모 노드에 붙여준다.
<img width="526" alt="image" src="https://user-images.githubusercontent.com/21982942/167578213-5a851dca-2ec6-4d82-90e8-431f178a76de.png">

```
# Logical #
if(node -> left == NULL || node -> right == NULL){
    child = (node -> left != NULL) ? node -> left : node -> right;
    if(node == root) root = child;
    else{
        if(parent -> left == node)
            parent -> left = child;
        else parent -> right = child;
    }
}
```

## 케이스 3 : 두 개의 자식을 가진 노드 삭제
- 가장 비슷한 값을 가진 노드를 삭제 노드 위치로 가져온다.
- 후계 노드의 선택
<img width="651" alt="image" src="https://user-images.githubusercontent.com/21982942/167578679-a24fdb52-76aa-4d13-8d59-27311b65d576.png">

```
if((node -> left == NULL) && node -> right == NULL){
    case 1
}
else if((node -> left == NULL && node -> right == NULL)){
    case 2
}
else{
    succp = node ;
    succ = node -> right;
    while(succ -> left != NULL){
        succp = succ;
        succ = succ -> left;
    }
    if(succp -> left == succ){
        succp -> left = succ -> right;
    }
    else succp -> right = succ -> right;

    node -> data = succ -> data;
    node = succ;
}
```

# 이진 탐색 트리의 성능
- 이진 탐색 트리에서의 탐색, 삽입, 삭제 연산의 시간 복잡도는 트리의 높이를 h라고 했을때, h와 비례한다.

> 최선의 경우
- 이진 트리가 균형적으로 생성되어 있는 경우
- 시간복잡도 : O(logn)

> 최악의 경우
- 경사이진트리 : h = n;
- 시간복잡도 : O(n)
