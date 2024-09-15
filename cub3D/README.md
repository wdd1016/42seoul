# Cub3D

- cloned from https://github.com/42Seoulcowork/Cub3D_202308
- [cub3D notion](https://brassy-plate-60f.notion.site/Cub3D-d329444dda0840df8a04a117c3f0f2b3)

# 핵심 포인트

- Parse → hook set → rendering (DDA algorithm) → texture handling → mlx_loop (\_hook)

# 정리

- Allowed Function
  open, close, read, write, printf, malloc, free, perror, strerror, exit
  All functions of the math library (-lm man man 3 math)
  All functions of the MinilibX
- Raycasting
  [https://yechoi.tistory.com/16](https://yechoi.tistory.com/16)
  [https://github.com/365kim/raycasting_tutorial](https://github.com/365kim/raycasting_tutorial)
- Bonus
  텍스쳐 구하기 [https://github.com/fsandel/cub3D](https://github.com/fsandel/cub3D)
  벽 충돌 시스템 (기본적으로 완성)
  미니맵
  마우스로 회전
  열고 닫을 수 있는 문
  움직이는 스프라이트
- 느낀점
  파싱테스트는 꼼꼼하게!! (.cubb 같은거 실행 잘되면 안됨)
  Makefile의 -O2옵션 (최적화)는 하면 정말 좋다.
  25줄 + 줄당 글자수 제한 너무 빡빡하다.
  mlx_hook의 옵션을 활용하면 연속된 키의 입력을 받을 수 있다.
  gnl로 받은 line은 꼭 free 해주어야 한다.
  스프라이트랑 미니맵은 vertical line을 그린뒤에 위에다가 출력해도 괜찮다.

# 자료
