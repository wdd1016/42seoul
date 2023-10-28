# CPP Module 04

[CPP Module 04](https://brassy-plate-60f.notion.site/CPP-Module-04-cbdbbb9f549747b69228b48936a2ee8c?pvs=4)

# 핵심 포인트

- Subtype polymorphism, abstract classes, interfaces

# 정리

- EX00
    
    Virtual Function
    
    Virtual Function Table (Array of Function pointers)
    
    Dynamic binding vs Static binding
    
- EX01
    
    Virtual Destructor
    
    Member variable (pointer) → Dynamic allocation (new, delete)
    
    Deep copy vs Shallow copy
    
- EX02
    
    pure virtual function
    
    Abstract Class
    
- EX03
    
    Interface
    
    polymorphism practice
    
    C++98에는 인터페이스가 존재하지 않습니다(심지어 C++20에도 존재하지 않습니다). 하지만 순수한 추상 클래스는 일반적으로 인터페이스라고 부릅니다. 따라서 이번 마지막 연습에서는 이 모듈을 구현하기 위해 인터페이스를 구현해 보겠습니다.
    
    다음 AMateria 클래스의 정의를 완성하고 필요한 멤버 함수를 구현합니다.
    
    ```cpp
    class AMateria
    {
    	protected:
    	[...]
    
    	public:
    		AMateria(std::string const & type);
    	[...]
    		std::string const & getType() const; //Returns the materia type
    		virtual AMateria* clone() const = 0;
    		virtual void use(ICharacter& target);
    };
    ```
    
    Materias 콘크리트 클래스 Ice와 Cure를 구현합니다. 소문자로 된 이름을 사용하여(Ice의 경우 "ice", Cure의 경우 "cure") 유형을 설정합니다. 물론 그 멤버 함수인 clone()은 같은 유형의 새 인스턴스를 반환합니다(즉, 얼음 재료를 복제하면 새 얼음 재료를 얻게 됩니다).
    
    The use(ICharacter&) member function will display:
    • Ice: "* shoots an ice bolt at <name> "
    • Cure: " heals <name>’s wounds *"
    <name> 은 파라미터로 전달된 캐릭터의 이름입니다. 꺾쇠 괄호(< 및 >)를 인쇄하지 마십시오.
    
    Materia를 다른곳에 할당하는 동안 유형을 복사하는 것은 의미가 없습니다.
    
    다음 인터페이스를 구현하는 구체적인 Character 클래스를 작성합니다:
    
    ```cpp
    class ICharacter
    {
    	public:
    		virtual ~ICharacter() {}
    		virtual std::string const & getName() const = 0;
    		virtual void equip(AMateria* m) = 0;
    		virtual void unequip(int idx) = 0;
    		virtual void use(int idx, ICharacter& target) = 0;
    };
    ```
    
    캐릭터의 인벤토리 슬롯은 4개이며, 이는 최대 4개의 재료를 의미합니다.
    생성 시 인벤토리는 비어 있습니다. 처음 발견한 빈 슬롯에 마테리아를 장착합니다. 즉, 슬롯 0부터 슬롯 3까지 순서대로 장착합니다. 인벤토리가 가득 찬 상태에서 재료를 추가하거나 존재하지 않는 재료를 사용/장비 해제하려고 하면 아무 작업도 하지 마세요(하지만 버그는 금지되어 있습니다). unequip() 멤버 함수는 마테리아를 삭제하지 않아야 합니다!
    
    캐릭터가 바닥에 남긴 마테리아를 원하는 대로 처리하세요.
    unequip() 등을 호출하기 전에 주소를 저장하되, 메모리 누수를 방지해야 한다는 점을 잊지 마세요.
    
    use(int, ICharacter&) 멤버 함수는 슬롯[idx]에 있는 마테리아를 사용해야 하며, 대상 파라미터를 AMateria::use 함수에 전달해야 합니다.
    
    캐릭터의 인벤토리는 모든 유형의 마테리아를 지원할 수 있습니다.
    
    캐릭터에 해당 이름을 파라미터로 사용하는 생성자가 있어야 합니다. 캐릭터의 복사(복사 생성자 또는 복사 할당 연산자 사용)는 반드시 Deep해야 합니다.
    복사하는 동안 캐릭터의 재료는 새 재료가 인벤토리에 추가되기 전에 삭제해야 합니다. 물론 캐릭터가 파괴되면 재료도 삭제해야 합니다.
    
    다음 인터페이스를 구현할 구체적인 클래스 MateriaSource를 작성합니다:
    
    ```cpp
    class IMateriaSource
    {
    	public:
    		virtual ~IMateriaSource() {}
    		virtual void learnMateria(AMateria*) = 0;
    		virtual AMateria* createMateria(std::string const & type) = 0;
    };
    ```
    
    - learnMateria(AMateria*)
    파라미터로 전달된 마테리아를 복사하여 나중에 복제할 수 있도록 메모리에 저장합니다. 캐릭터와 마찬가지로 MateriaSource는 최대 4개의 마테리아를 알 수 있습니다. 반드시 고유할 필요는 없습니다.
    - createMateria(std::string const &)
    새 마테리아를 반환합니다. 이는 이전에 MateriaSource가 학습한 마테리아의 복사본으로, 파라미터로 전달된 유형과 동일한 유형입니다. 유형을 알 수 없으면 0을 리턴합니다.
    
    간단히 말해, 마테리아소스는 필요할 때 생성할 수 있는 마테리아의 '템플릿'을 학습할 수 있어야 합니다. 그러면 유형을 식별하는 문자열만 사용하여 새로운 머티리얼을 생성할 수 있습니다.
