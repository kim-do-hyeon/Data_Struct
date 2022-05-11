# 이진트리의 기본 순회
- 3가지 기본적인 순회방법
![image](https://user-images.githubusercontent.com/21982942/167869702-6a0f05b4-13cb-454b-8e45-0eac998c64f8.png)

> 전위순회 (preorder traversal)
- 루트 노드 -> 왼쪽 노드 -> 오른쪽 노드
> 중위순회 (inorder traversal)
- 왼쪽 노드 -> 루트 노드 -> 오른쪽 노드
> 후위순회 (postorder traversal)
- 왼쪽 노드 -> 오른쪽 노드 -> 루트 노드

![image](https://user-images.githubusercontent.com/21982942/167869752-91d86f2f-93ca-4000-9cc3-d9dae702f048.png)

> 전체 트리나 서브트리나 구조는 동일하다
- 순환 호출을 이용한다.

> 레벨순회 (levelorder traversal)
- 이전 순회는 '스택'을 사용한다.
- 큐를 이용해 구현한다.

```
# Logical #
level_order()

initialize queue;
if(root == NULL) then return;
enqueue(root);
while isEmpty(queue) ≠ TRUE do
    x ← dequeue(queue);
    if( x≠NULL) then
        print DATA(x);
        enqueue(LEFT(x));
        enqueue(RIGHT(x));
```

# traversal.c README
![image](https://user-images.githubusercontent.com/21982942/167870035-60259dd7-08a2-41ee-8dc6-fb9d90ba29fc.png)

다음과 같은 트리가 있을때, 중위순회와 전위순회, 후위순회, 레벨 순회의 결과를 나타낸다.

![image](https://user-images.githubusercontent.com/21982942/167870470-a8ae5394-3adb-49da-b483-1708c985455f.png)