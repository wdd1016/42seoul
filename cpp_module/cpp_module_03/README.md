# CPP Module 03

[CPP Module 03](https://brassy-plate-60f.notion.site/CPP-Module-03-aff9c62d1863498b82011312578efea5?pvs=4)

# 핵심 포인트

- Inheritance

# 정리

- EX00
    
    Base class generate
    
- EX01, EX02
    
    Inheritance
    
    Derived class
    
    Overriding
    
- EX03
    
    Diamond Polymorphism ([https://caniro.tistory.com/135](https://caniro.tistory.com/135))
    
    Virtual Base Class
    
    2개이상의 상속을 받을 경우, 중복된 상속은 두개의 값을 모두 갖고있기에 사용할 수 없는 상태가 된다.
    
    Virtual base classes are always created before non-virtual base classes. This ensures all bases are created before their derived classes.
    
    Virtual Base Class를 상속받는경우에, 해당 base class의 데이터는 1개만 존재하기때문에 ScavTrap::_attackDamege은 FragTrap::_attackDamege이자 ClapTrap::_attackDamege로써 30의 데이터를 갖고있다 (ClapTrap : 0 → ScavTrap : (0 → 20) → FragTrap : (20 → 30)
    
    상속받은 함수는 데이터를 사용할때 해당 함수가 있는 클래스를 기준으로 데이터를 받는다.
    
    (Diamond에 attack이 있으면 Diamond::_name, attack이 없으면 ScavTrap::attack이 발동되므로 ScavTrap::_name이자 virtual base class member variable에 있는 ClapTrap::_name을 쓴다.) 
    