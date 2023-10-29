# CPP Module 06

[CPP Module 06](https://brassy-plate-60f.notion.site/CPP-Module-06-63ad1fb109404f699880f0d248715d8f?pvs=4)

# 핵심 포인트

- Static 완벽 가이드 :  [https://kukuta.tistory.com/434](https://kukuta.tistory.com/434)
- Implicit Casting
- Explicit Casting
- Static cast ([https://en.cppreference.com/w/cpp/language/static_cast](https://en.cppreference.com/w/cpp/language/static_cast))
- Const cast ([https://en.cppreference.com/w/cpp/language/const_cast](https://en.cppreference.com/w/cpp/language/const_cast))
- Dynamic cast ([https://en.cppreference.com/w/cpp/language/const_cast](https://en.cppreference.com/w/cpp/language/const_cast))
- Reinterpret cast ([https://en.cppreference.com/w/cpp/language/reinterpret_cast](https://en.cppreference.com/w/cpp/language/reinterpret_cast))
- [https://marmelo12.tistory.com/291](https://marmelo12.tistory.com/291)

# 정리

- EX00
    
    Static class (c++은 없지만, 비슷하게 구현)
    
    **DBL_MAX, FLT_MAX, DBL_MIN, FLT_MIN**
    
    오버플로우(**DBL_MAX, FLT_MAX**) 처리, **DBL_MIN, FLT_MIN**이 문제
    
- EX01
    
    Reinterpret cast
    
    uintptr_t
    
- EX02
    
    Dynamic cast ([https://www.ibm.com/docs/ko/i/7.5?topic=expressions-dynamic-cast-operator-c-only](https://www.ibm.com/docs/ko/i/7.5?topic=expressions-dynamic-cast-operator-c-only))
    
    `T` 가 포인터이고 `dynamic_cast` 연산자가 실패하면 연산자는 `T`유형의 널 포인터를 리턴합니다. `T` 가 참조이고 `dynamic_cast` 연산자가 실패하는 경우 연산자는 `std::bad_cast`예외를 발생시킵니다. 표준 라이브러리 헤더 `<typeinfo>`에서 이 클래스를 찾을 수 있습니다.
    
