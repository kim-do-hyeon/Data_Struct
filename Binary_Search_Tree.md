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
