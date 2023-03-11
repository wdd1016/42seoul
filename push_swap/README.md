# Push_swap

[push_swap notion](https://www.notion.so/Push_swap-4b0373720b754ac7a48e1c878a87fbda)

# 핵심 포인트

- **스택 (자료구조)**
- **큐, 덱(double-ended queue)**
- **정렬**
- [push_swap 가이드 (Quick sort)](https://www.notion.so/push_swap-c15e62229b9541d78fadec4d6aae8b50)

# 정리

- 스택
    - 스택의 구조
        
        **스택**(stack)은 제한적으로 접근할 수 있는 나열 구조이다.
        
        스택은 한 쪽 끝에서만 자료를 넣거나 뺄 수 있는 선형 구조(LIFO - Last In First Out)으로 되어 있다.
        
        나중에 넣은 값이 먼저 나오는 [LIFO](https://ko.wikipedia.org/wiki/LIFO)구조다.
        
        | 연산 | 기능 |
        | --- | --- |
        | init() | 스택을 초기화 |
        | create() | 스택을 생성 |
        | is_empty(s) | 스택이 비어있는지 검사 |
        | is_full(s) | 스택이 가득 찼는지 검사 |
        | push(e) | 스택의 맨 위에 요소 e 추가 |
        | pop(s) | 스택의 맨 위 요소를 삭제 |
        | peek(s) | 스택의 맨 위 요소를 삭제하지 않고 반환 |
        
        | 연산 | 기능 |
        | --- | --- |
        | top() | 스택 맨 위에 있는 데이터 값 반환 |
        | push() | 스택에 데이터 삽입 |
        | pop() | 스택에서 데이터 삭제하여 반환 |
        | isempty() | 스택에 원소가 없으면 'True', 있으면 'False' 값 반환 |
        | isfull() | 스택에 원소가 없으면 'False', 있으면 'True' 값 반환 |
        
        [https://ko.wikipedia.org/wiki/스택](https://ko.wikipedia.org/wiki/%EC%8A%A4%ED%83%9D)
        
        [https://code-lab1.tistory.com/5](https://code-lab1.tistory.com/5)
        
        [https://roi-data.com/entry/자료구조-4-스택Stack이란-연산-구현방법](https://roi-data.com/entry/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-4-%EC%8A%A4%ED%83%9DStack%EC%9D%B4%EB%9E%80-%EC%97%B0%EC%82%B0-%EA%B5%AC%ED%98%84%EB%B0%A9%EB%B2%95)
        
    - 스택의 구현
        - 1. 스택의 **정적** 구현 : 1차원 ****배열**** 사용
            1. **스택의 생성**
            top : 가장 최근에 입력되었던 자료를 가리키는 변수
            stack[0] ... stack[top] : 먼저 들어온 순으로 저장
            공백 상태 : top = -1
            
            ```c
            // 1차원 배열의 사용
            
            # define MAX_STACK_SIZE 100
            int stack[MAX_STACK_SIZE];
            
            /* top의 초기 값은 스택이 비어있을 때 -1 이다. */
            int top = -1;
            ```
            
            1. **스택의 삽입 (Push)**
            
            ```c
            void push(int item)
            {
                if (top >= MAX_STACK_SIZE - 1) {
                	stack_full();
                    return;
                }
                	stack[++top] = item;
                    // top ++; stack[top] = item;
            }
            
            // push(x)
            
            if is_full(S)
            	then error "overflow"
                	else top <- top + 1
                	     data[top] <- x
            ```
            
            1. **스택의 삭제 (Pop)**
            
            ```c
            int pop() {
                if (top == -1)
                	return stack_empty();
                // int x; x = stack[top]; top--; return x;
                return stack[top--];
            }
            
            // pop()
            
            if is_empty()
                then error "underflow"
                else e <- data[top]
                	 top <- top-1
                     return e
            ```
            
            1. **스택의 검사 ( isempty / isfull )**
            
            ```c
            // 스택이 비어있는지 검사하는 함수
            int isempty()
            { if (top < 0)
                return(1);
              else
                return(0);
            }
            
            // 스택이 가득 차 있는지 검사하는 함수
            int isfull()
            { if (top >= MAX_STACK_SIZE -1 )
                return(1);
              else
                return(0);
            }
            ```
            
        - 2. 스택의 ****동적**** 구현 ********: ****연결 리스트**** 사용
            1. **스택의 생성**
            
            ```c
            // 요소의 타입
            typedef int element;
            
            typedef struct StackNode {
                // 노드의 타입
                element item;
                struct StackNode *link;
            } StackNode; // 연결된 스택 관련 데이터
            
            typedef struct {
                StackNode *top;
            } LinkedStackType;
            ```
            
            1. **스택의 삽입**
            
            ```c
            void push(LinkedStackType *s,int data)
            {
            		StackNode *temp = (StackNode *)malloc(sizeof(StackNode)); 
            		// 동적노드 생성
            		temp->item = data; // 새로운 노드에 입력할 값 복사
            		temp->link = s->top; // 새로운 노드가 기존의 top 노드를 가르키도록 함
            		s->top = temp; // temp 노드가 top 노드로 선언
            }
            ```
            
            1. **스택의 삭제**
            
            ```c
            // 삭제 함수
            element pop(LinkedStackType *s)
            {
                if( is_empty(s) ) {
                    fprintf(stderr, "스택이 비어있음\n");
                    exit(1);
                }
                else{
                	StackNode *temp = s->top;
                    int item = temp->item;
                    s->top = s->top->link;
                    free(temp);
                    return item;
                }
            }
            ```
            
        
        [https://roi-data.com/entry/자료구조-4-스택Stack이란-연산-구현방법](https://roi-data.com/entry/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B0-4-%EC%8A%A4%ED%83%9DStack%EC%9D%B4%EB%9E%80-%EC%97%B0%EC%82%B0-%EA%B5%AC%ED%98%84%EB%B0%A9%EB%B2%95)
        
        [https://taco99.tistory.com/8](https://taco99.tistory.com/8)
        
- 큐, 덱(double-ended queue) → 사용하기로 결정
    - 덱의 구조
        
        덱(deque)은 double-ended queue의 줄임말로써 후단(rear)으로만 데이터를 삽입했던 기존 선형 큐, 원형 큐와 달리 큐의 **전단(front)와 후단(rear)에서 모두 삽입과 삭제가 가능한 큐입니다.**
        
        덱의 연산에서 주의할 점은 데이터를 삽입 연산 시 front는 감소하고 rear는 증가하며 삭제 연산 시 front는 증가하고 rear는 감소하는 점입니다.
        
        ‘덱’ 으로 발음하는 이유는 '디큐' 로 발음할 경우 큐의 dequeue연산과 그 발음이 같아져서 이 둘을 구분하기 어렵기 때문이다.
        
        - 덱에 사용되는 Abstract Data Type
            
            create() ::= 덱을 생성한다.
            
            init(dq) ::= 덱을 초기화한다.
            
            is_empty(dq) ::=   덱이 공백상태인지를 검사한다.
            
            is_full(dq) ::= 덱이 포화상태인지를 검사한다.
            
            add_front(dq, e) ::= 덱의 앞에 요소를 추가한다.
            
            add_rear(dq, e) ::= 덱의 뒤에 요소를 추가한다.
            
            delete_front(dq) ::= 덱의 앞에 있는 요소를 반환한 다음 삭제한다.
            
            delete_rear(dq) ::= 덱의 뒤에 있는 요소를 반환한 다음 삭제한다.
            
            get_front(q) ::= 덱의 앞에서 삭제하지 않고 앞에 있는 요소를 반환한다.
            
            get_rear(q) ::= 덱의 뒤에서 삭제하지 않고 뒤에 있는 요소를 반환한다.
            
    - 덱의 구현
        
        ```c
        typedef int element;
        
        // 덱 큐 타입
        typedef struct {
        	element  data[MAX_QUEUE_SIZE];
        	int  front, rear;
        } DequeType;
        
        // 오류 함수
        void error(char *message)
        {
        	fprintf(stderr, "%s\n", message);
        	exit(1);
        }
        
        // 덱 초기화 
        void init_deque(DequeType *q)
        {
        	q->front = q->rear =  0;
        }
        
        // 공백 상태 검출 함수
        int is_empty(DequeType *q)
        {
        	return (  q->front == q->rear );
        }
        
        // 포화 상태 검출 함수
        int is_full(DequeType *q)
        {
        	return (( q->rear  + 1) % MAX_QUEUE_SIZE == q->front);
        }
        
        // 덱 큐 출력 함수
        void deque_print(DequeType *q)
        {
        	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
        	if (!is_empty(q)) {
        		int i = q->front; // i에 현재 q의 front값을 넣어주고
        		do {
        			i = (i + 1) % (MAX_QUEUE_SIZE); // i의 자리를 1증가
        			printf("%d | ", q->data[i]); // 증가한 i 자리에 해당하는 data값을 출력
        		} while ( i != q->rear); 
        	}
        	printf("\n");
        }
        
        // rear쪽 삽입 함수
        void add_rear(DequeType *q, element item)
        {
        	if (is_full(q))
        		error("큐가 포화상태입니다");
        	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; // rear값 1 증가
        	q->data[ q->rear ] = item;
        }
        
        // rear쪽 삭제 함수
        element delete_rear(DequeType *q)
        {
        	int prev = q->rear;
        	if (is_empty(q))
        		error("큐가 공백상태입니다");
        	q->rear =  (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; // rear값 1감소
        	return q->data[prev];
        }
        
        // rear쪽 반환
        element get_rear(DequeType *q)
        {
        	if (is_empty(q))
        		error("큐가 공백상태입니다");
        	return q->data[ q->rear ];
        }
        
        // front쪽 삽입 함수
        void add_front(DequeType *q, element val)
        {
        	if (is_full(q))
        		error("큐가 포화상태입니다");
        	q->data[ q->front ] = val;
        	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE; // front값 1감소
        }
        
        // front쪽 삭제 함수
        element delete_front(DequeType *q)
        {
        	if (is_empty(q))
        		error("큐가 공백상태입니다");
        	q->front =  (q->front + 1) % MAX_QUEUE_SIZE  ; // front값 1 증가
        	return q->data[ q->front ];
        }
        
        // front쪽 반환
        element get_front(DequeType *q)
        {
        	if (is_empty(q))
        		error("큐가 공백상태입니다");
        	return q->data[ (q->front + 1) % MAX_QUEUE_SIZE ];
        }
        ```
        
    
    [https://yjg-lab.tistory.com/116](https://yjg-lab.tistory.com/116)
    
- 명령어
    
    `sa` : swap a - 스택 a의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 a가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
    
    `sb` : swap b - 스택 b의 top에 위치한 두 개의 원소의 순서를 맞바꿉니다. 스택 b가 비어있거나 원소가 1개만 있을 때는 아무 동작도 하지 않습니다.
    
    `ss` - sa와 sb를 동시에 수행합니다.
    
    `pa` : push a - 스택 b의 top에 위치한 원소 한 개를 스택 a의 top으로 옮깁니다. 스택 b가 비어있을 경우에는 아무 동작도 하지 않습니다.
    
    `pb` : push b - 스택 a의 top에 위치한 원소 한 개를 스택 b의 top으로 옮깁니다. 스택 a가 비어있을 경우에는 아무 동작도 하지 않습니다.
    
    `ra` : rotate a - 스택 a의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
    
    `rb` : rotate b - 스택 b의 원소를 한 칸씩 위로 옮깁니다. 스택의 첫 번째 원소는 맨 마지막 원소가 됩니다.
    
    `rr` : ra와 rb를 동시에 수행합니다.
    
    `rra` : reverse rotate a - 스택 a의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
    
    `rrb` : reverse rotate b - 스택 b의 원소를 한 칸씩 아래로 옮깁니다. 스택의 마지막 원소는 맨 첫 번째 원소가 됩니다.
    
    `rrr` : rra와 rrb를 동시에 수행합니다.
    
    [명령어 필기 정리](https://www.notion.so/2c65712844974b84a09b2880c91cb13c)
    
- 퀵 정렬
    
    [https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html](https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html)
    
    ```c
    # include <stdio.h>
    # define MAX_SIZE 9
    # define SWAP(x, y, temp) ( (temp)=(x), (x)=(y), (y)=(temp) )
    
    // 1. 피벗을 기준으로 2개의 부분 리스트로 나눈다.
    // 2. 피벗보다 작은 값은 모두 왼쪽 부분 리스트로, 큰 값은 오른쪽 부분 리스트로 옮긴다.
    /* 2개의 비균등 배열 list[left...pivot-1]와 list[pivot+1...right]의 합병 과정 */
    /* (실제로 숫자들이 정렬되는 과정) */
    int partition(int list[], int left, int right){
      int pivot, temp;
      int low, high;
    
      low = left;
      high = right + 1;
      pivot = list[left]; // 정렬할 리스트의 가장 왼쪽 데이터를 피벗으로 선택(임의의 값을 피벗으로 선택)
    
      /* low와 high가 교차할 때까지 반복(low<high) */
      do{
        /* list[low]가 피벗보다 작으면 계속 low를 증가 */
        do {
          low++; // low는 left+1 에서 시작
        } while (low<=right && list[low]<pivot);
    
        /* list[high]가 피벗보다 크면 계속 high를 감소 */
        do {
          high--; //high는 right 에서 시작
        } while (high>=left && list[high]>pivot);
    
        // 만약 low와 high가 교차하지 않았으면 list[low]를 list[high] 교환
        if(low<high){
          SWAP(list[low], list[high], temp);
        }
      } while (low<high);
    
      // low와 high가 교차했으면 반복문을 빠져나와 list[left]와 list[high]를 교환
      SWAP(list[left], list[high], temp);
    
      // 피벗의 위치인 high를 반환
      return high;
    }
    
    // 퀵 정렬
    void quick_sort(int list[], int left, int right){
    
      /* 정렬할 범위가 2개 이상의 데이터이면(리스트의 크기가 0이나 1이 아니면) */
      if(left<right){
        // partition 함수를 호출하여 피벗을 기준으로 리스트를 비균등 분할 -분할(Divide)
        int q = partition(list, left, right); // q: 피벗의 위치
    
        // 피벗은 제외한 2개의 부분 리스트를 대상으로 순환 호출
        quick_sort(list, left, q-1); // (left ~ 피벗 바로 앞) 앞쪽 부분 리스트 정렬 -정복(Conquer)
        quick_sort(list, q+1, right); // (피벗 바로 뒤 ~ right) 뒤쪽 부분 리스트 정렬 -정복(Conquer)
      }
    
    }
    
    void main(){
      int i;
      int n = MAX_SIZE;
      int list[n] = {5, 3, 8, 4, 9, 1, 6, 2, 7};
    
      // 퀵 정렬 수행(left: 배열의 시작 = 0, right: 배열의 끝 = 8)
      quick_sort(list, 0, n-1);
    
      // 정렬 결과 출력
      for(i=0; i<n; i++){
        printf("%d\n", list[i]);
      }
    }
    https://gmlwjd9405.github.io/2018/05/10/algorithm-quick-sort.html
    ```

- 최적화, 문제점
    
    [좌표압축](https://r4bb1t.tistory.com/46)을 통한 항상 이론상 최적에 가까운 최적화 도입
    (Tim sort → Binery search → index로 이루어진 0 ~ size-1의 값을 가진 배열 생성)
    
    추가적인 스택(명령어를 실행할 최소(min), 최대(max)값(좌표압축을 통해 항상 max - min + 1 ==갯수 이다), 해당 구간이 존재하는 Deque(location))을 push 하고 pop하면서 정렬을 진행
    
    5개 이하의 경우 따로 최적화 (3개는 2번, 5개는 12번 이하여야함)
    
    피벗을 2개를 사용하여 quick 정렬을 진행하므로, 3개이하로 남았을때는 hardsort라는 과정을 도입하여 최적화 진행 ([해당 내용 필기](https://www.notion.so/Quick-sort-algorithm-Hard-sort-6eaa7c0ed7144e6fadb5ed1b74f71fa6))
    
    [B 스택(Deque)를 정렬할때 주의할 점은, rra와 rrb를 진행하기전에 Big Number 뭉치를 먼저 정렬을 끝내야한다는 점이다.](https://www.notion.so/push_swap-c15e62229b9541d78fadec4d6aae8b50) (rra, rrb를 진행하면 가장먼저 정렬해야할 Big Number 뭉치가 Middle과 고정값 사이에 갇히게 된다. [해당 내용 필기](https://www.notion.so/Quick-sort-algorithm-Hard-sort-6eaa7c0ed7144e6fadb5ed1b74f71fa6)) → 재귀함수로 구현하였다.
    
    RR과 RRR을 사용할수있는 경우를 찾아 최적화를 진행하였다. → Middle값에서 PB(PA)를 진행하고 RB(RA)를 이어가야할때,  다음스택 숫자를 보고 RA(RB)를 진행해야하면, RR을 사용하였고, rra와 rrb를 비교하여 적절한 RRR을 사용하였다.
    
    보너스에서는 좌표압축부분을 제외하였고(다만 중복방지를 위해 정렬은 1번 진행하였다), command에 출력부분삭제, gnl을 이용한 표준입력(0)받기를 사용하였다.
    
    기존 원형덱에서는 front == rear일때 비어있다고 표현하였는데, 나는 rear == -1일때를 비어있다고 표현하면서, front == rear일때는 1개가 존재한다고 사용하였다.
    
- Tim sort
    
    [https://www.geeksforgeeks.org/timsort/](https://www.geeksforgeeks.org/timsort/)
    
    삽입정렬 + 합병정렬
    
    [https://d2.naver.com/helloworld/0315536](https://d2.naver.com/helloworld/0315536)
    
- Visualizer, Tester
    
    https://github.com/o-reo/push_swap_visualizer
    
    https://github.com/laisarena/push_swap_tester
    
    https://github.com/minckim42/push_swap_tester
    
    https://github.com/louisabricot/push_swap_tester
    
    https://github.com/ksnow-be/push_swap_checker
    