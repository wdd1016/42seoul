# CPP Module 07

[CPP Module 07](https://brassy-plate-60f.notion.site/CPP-Module-07-10a27bd866be43718f1e78f0ad32bbb3?pvs=4)

# 핵심 포인트

- Template
- Class Template ( + Template specialization)
- Function Template
- Functor (Function Object)
- Non-type template arguments

# 정리


- EX00
    
    템플릿을 cpp 파일과 header 파일로 나누어서 만든뒤, 메인에 header 파일만 추가했을때 생기는 문제점
    [CPP Module 07 notion 에서 확인](https://brassy-plate-60f.notion.site/CPP-Module-07-10a27bd866be43718f1e78f0ad32bbb3?pvs=4)
    
    해결방안은 만든 cpp파일을 include(…)  혹은 헤더파일에 다 구현하기 or tpp file
    [CPP Module 07 notion 에서 확인](https://brassy-plate-60f.notion.site/CPP-Module-07-10a27bd866be43718f1e78f0ad32bbb3?pvs=4)
    
- EX01
    
    Functor (Function Object)의 사용
    
    iterator (반복자)의 역활을 하여, 하나씩 접근하여 함수를 진행해야 함.
    
- EX02
    
    Array만들기
    
    operator[] → 함수에서 const의 사용 : 함수 뒤에 const를 붙이면 반환형이 const여도 괜찮고, 그렇지 않은 경우 const 데이터를 받지 못하는 오류 발생!
    
    ~Array() → delete[]
    
