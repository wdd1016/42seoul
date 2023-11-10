# CPP Module 08

[CPP Module 08](https://brassy-plate-60f.notion.site/CPP-Module-08-858a2a708ac748f584e094c35c00ef15?pvs=4)

# 핵심 포인트

- Iterator
- 시퀀스 컨테이너(sequence container)
    - std::vector : 가변 길이 배열 (Dynamic contiguous array)
    - std::list : 양방향 연결 구조를 가진 자료형 (Doubly linked list)
    - std::deque (Double ended queue)
- 연관 컨테이너(associative container)
    - 셋(set) 과 멀티셋(multiset)
    - 맵(map) 과 멀티맵(multimap)
- 컨테이너 어댑터(container adapter)

# 정리

- EX00
    
    STL (**Standard Template Library**, [https://cplusplus.com/reference/stl/](https://cplusplus.com/reference/stl/))
    
    Containers
    
    시퀀스 컨테이너(sequence container)
    
    std::vector<int>
    
    std::list<int>
    
    std::deque<int>
    
- EX01
    
    연관 컨테이너(associative container)
    
    ```cpp
    Member function
    
    template <class InputIterator> 
    void insert (InputIterator first, InputIterator last);
    
    Range insert (iteratable container 다 받을 수 있음)
    ```
    
    시간복잡도 (big-O notation) → insert, sorting
    
- EX02
    
    컨테이너 어댑터(adapter container)
    
    std::stack는 아래의 구조로 되어있다. (클러스터 맥기준)
    
    ```cpp
    template <class _Tp, class _Container /*= deque<_Tp>*/>
    class _LIBCPP_TEMPLATE_VIS stack
    {
    	public:
    	    typedef _Container                               container_type;
    	    typedef typename container_type::value_type      value_type;
    	    typedef typename container_type::reference       reference;
    	    typedef typename container_type::const_reference const_reference;
    	    typedef typename container_type::size_type       size_type;
    	    static_assert((is_same<_Tp, value_type>::value), "" );
    	
    	protected:
    	    container_type c;
    	
    	...
    }
    ```
    
    std::stack은 맴버변수로 deque를 가지며, 모든 데이터는 여기에 저장, 수정, 삭제된다.
    
    Deque에는 4가지의 iterator가 존재한다.
