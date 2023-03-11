# Ft_printf

[printf notion](https://brassy-plate-60f.notion.site/Ft_printf-e9cbad12ba2044b997c0da07a7f33ae1)

# 핵심 포인트

- `va_list` : 각 가변 인자의 `시작 주소`를 가리킬 `포인터`입니다. 모양은 멋있게 생겼지만 내부적으로는 `char *` 혹은 자체적인 특수한 포인터로 정의되어 있는 녀석입니다.
- `va_start` : `va_list`로 만들어진 포인터에게 가변인자 중 첫 번째 인자의 주소를 가르쳐주는 중요한 매크로입니다.
- `va_arg` : 특정 가변인자를 가리키고 있는 `va_list`의 내장 값을 다음 가변인자로 이동시켜 주는 매크로입니다. va_list의 `주소는 수정되지않으며`, 단지 `구조체 내부 값이 수정`됩니다.

# 정리

- ft_printf의 형식태그  `%[flag][width][.precision]서식지정자`
    
    `[인수크기]`도 있지만 사용하지 않는다.
    
- `flag`  : ft_printf에서는 ‘-’, ‘0’, ‘#’, ‘ ‘, ‘+’의 5가지 이용
    
    `‘-’` : 좌측 정렬하여 출력, Ft_printf에서는 `모든 서식지정자`에 적용
    
    `‘0’` : `d, i, u, x, X` 에서 사용가능
    
          Space대신 0 출력
    
          `‘-’ flag 혹은 .precision`이 있으면 무시 
    
     `‘#’` : `x, X` 에서 사용가능, `0x` or `0X` 숫자앞에 출력 (단, 값이 0일때는 제외)
    
     `‘ ‘` : `d, i, u` 에서 사용가능, `‘+’`있거나 값이 `음수`이면 무시
    
          출력하는 수 앞에 space 추가하여 출력
    
     `‘+’` : `d, i` 에서 사용가능, 값이 `양수`이면 숫자 앞에 + 추가하여 출력
    
- `width` : 출력 되는 최소 문자 수를 제어하는 음수가 아닌 10진법 정수
    
    `‘-’` flag 유무에 따라 출력 방향이 결정되며, `‘0’`옵션에 따라 `space`나 `0`을 출력함
    
- `precision` : `정밀도` .(점)과 10진수 숫자 문자열이 차례로 연결되어 있음.
    
    정밀도가 비어있으면, 0(영)으로 처리하고  음수는 무시 ([https://bit.ly/3FHgaIn](https://bit.ly/3FHgaIn))
    
    `d, o, i, u, x 또는 X 변환`에 대해 표시되는 `최소` 자리 수, `s 변환`의 문자열에서는 인쇄되는 `최대` 바이트 수를 나타내며 `c 변환`에서는 적용되지 않음
    
    `precision`의 자리수를 계산할때는 인자의 `수, 문자`만 계산하고 부호나 space는 무시함 
    
- 서식 지정자 : Ft_printf에서는 `cspdiuxX%` 이용
    
    `c : char`  `s : string`  `p : address(or hexademical size_t)` 
    
    `d, i : int`  `u : unsigned int`  `x : hexademical 소문자` `X: hexademical 대문자`
    
- 주의사항
    
    ```c
    char *str == 0 일 경우에는 str = "(null)"로 변경하여 출력
    precision == 0 && va_arg(va_list, int) == 0 일 경우에는 숫자 출력하지 않음
    ```
