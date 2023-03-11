# Fract-ol

[fractol notion](https://brassy-plate-60f.notion.site/Fract-ol-50a70976e5914c00a7e773aecbe190ae)

# 핵심 포인트

- [https://42kchoi.tistory.com/229](https://42kchoi.tistory.com/229) **MiniLibX 라이브러리 배워보기**
- **fractal**
- **complex numbers**
- **perror, strerror**
- **math 라이브러리**
- **이벤트(event in programming)**
- ~~parallelisation process~~

# 정리

- **MiniLibX 라이브러리**
    
    [https://love-every-moment.tistory.com/62?category=942026](https://love-every-moment.tistory.com/62?category=942026)
    
    - **참고 사이트**
        
        [https://harm-smits.github.io/42docs/libs/minilibx.html](https://harm-smits.github.io/42docs/libs/minilibx.html)
        
        [https://42kchoi.tistory.com/229](https://42kchoi.tistory.com/229)
        
        [https://velog.io/@chez_bono/solong](https://velog.io/@chez_bono/solong)
        
        [https://yeosong1.github.io/miniRT라이브러리](https://yeosong1.github.io/miniRT%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC)
        
        [https://velog.io/@parksj3205/miniLibX로-윈도우-생성과-간단한-도형-그리기](https://velog.io/@parksj3205/miniLibX%EB%A1%9C-%EC%9C%88%EB%8F%84%EC%9A%B0-%EC%83%9D%EC%84%B1%EA%B3%BC-%EA%B0%84%EB%8B%A8%ED%95%9C-%EB%8F%84%ED%98%95-%EA%B7%B8%EB%A6%AC%EA%B8%B0)
        
        [https://jeonjeunghoon.tistory.com/entry/42서울-MiniLibX-새-창을-생성하자](https://jeonjeunghoon.tistory.com/entry/42%EC%84%9C%EC%9A%B8-MiniLibX-%EC%83%88-%EC%B0%BD%EC%9D%84-%EC%83%9D%EC%84%B1%ED%95%98%EC%9E%90)
        
        [https://jeonjeunghoon.tistory.com/entry/MiniLibX-키를-입력-받아-보자](https://jeonjeunghoon.tistory.com/entry/MiniLibX-%ED%82%A4%EB%A5%BC-%EC%9E%85%EB%A0%A5-%EB%B0%9B%EC%95%84-%EB%B3%B4%EC%9E%90)
        
        [https://topknell.tistory.com/84](https://topknell.tistory.com/84)
        
    - **mlx_init**
        
        ```objectivec
        void *mlx_init()
        {
          mlx_ptr_t	*new_mlx;
          int		bidon;
          int		i;
        
          if ((new_mlx = malloc(sizeof(*new_mlx))) == NULL)
            return ((void *)0);
          new_mlx->win_list = NULL;
          new_mlx->img_list = NULL;
          new_mlx->loop_hook = NULL;
          new_mlx->loop_hook_data = NULL;
          new_mlx->main_loop_active = 0;
        
          new_mlx->appid = [NSApplication sharedApplication];
        
          // super magic trick to detach app from terminal, get menubar & key input events
          for (NSRunningApplication * app in [NSRunningApplication runningApplicationsWithBundleIdentifier:@"com.apple.finder"])
            {
              [app activateWithOptions:NSApplicationActivateIgnoringOtherApps];
              break;
            }
          usleep(100000);
          ProcessSerialNumber psn = { 0, kCurrentProcess };
          (void) TransformProcessType(&psn, kProcessTransformToForegroundApplication);
          usleep(100000);
          [[NSRunningApplication currentApplication] activateWithOptions:NSApplicationActivateIgnoringOtherApps];
        
          // load font
          new_mlx->font = mlx_new_image(new_mlx, (FONT_WIDTH+2)*95, FONT_HEIGHT);
          i = 0;
          while (i < 4*(FONT_WIDTH+2)*95*FONT_HEIGHT)
            {
              new_mlx->font->buffer[i+0] = font_atlas.pixel_data[i+2];
              new_mlx->font->buffer[i+1] = font_atlas.pixel_data[i+1];
              new_mlx->font->buffer[i+2] = font_atlas.pixel_data[i+0];
              ((unsigned char *)new_mlx->font->buffer)[i+3] = 0xFF-font_atlas.pixel_data[i+3];
              i += 4;
            }
        
        #ifdef	STRINGPUTX11
          new_mlx->font->vertexes[2] = FONT_WIDTH/1.4;
          new_mlx->font->vertexes[4] = FONT_WIDTH/1.4;
          new_mlx->font->vertexes[5] = (-FONT_HEIGHT-1)/1.4;
          new_mlx->font->vertexes[7] = (-FONT_HEIGHT-1)/1.4;
        #else
          new_mlx->font->vertexes[2] = FONT_WIDTH;
          new_mlx->font->vertexes[4] = FONT_WIDTH;
          new_mlx->font->vertexes[5] = -FONT_HEIGHT-1;
          new_mlx->font->vertexes[7] = -FONT_HEIGHT-1;
        #endif
        
          return ((void *)new_mlx);
        }
        ```
        
    - **Managing windows**
        - mlx_new_window
        - mlx_clear_window
        - mlx_destroy_window
    - **Drawing inside windows**
        
        Both functions will discard any display outside the window. This makes  mlx_pixel_put slow. Consider using images instead.
        
        - mlx_pixel_put
            
            ```c
            int mlx_pixel_put ( void *mlx_ptr, void *win_ptr, int x, int y, int color );
            ```
            
        - mlx_string_put
            
            ```c
            int mlx_string_put  ( void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string
            );
            ```
            
    - **COLOR MANAGEMENT**
        
        The  color  parameter has an integer type. The displayed color needs to be encoded in this integer, following a defined scheme. All displayable colors can be  split  in  3 basic  colors: red, green and blue. Three associated values, in the 0-255 range, represent how much of each color is mixed up to create the original color. Theses  three values  must  be  set  inside the integer to display the right color. The three least significant bytes of this integer are filled as shown in the picture below:
        
        ```
                   | 0 | R | G | B |   color integer
                   +---+---+---+---+
        ```
        
        While filling the integer, make sure you avoid endian problems.  Remember that the "blue" byte should always be the least significant one.
        Depending on hardware capabilities, the most significant bit can handle transparency.
        Beware, at the opposite of the OpenGL classics, it does not represent opacity.
        
    - **Manipulating images**
        - mlx_new_image
        - mlx_get_data_addr
        - mlx_put_image_to_window
            
            Three identifiers are needed here, for the connection  to the  display,  the  window  to use, and the image (respectively mlx_ptr , win_ptr and img_ptr ). The ( x , y ) coordinates define where the image should be placed  in  the window.
            
        - **mlx_get_color_value**
        - mlx_xpm_to_image
            
            XPM는 X11 Pixmap Graphic입니다.
            
            X Windows 시스템에서 사용하는 비트 맵 이미지, 네트워크로 연결된 클라이언트 서버 컴퓨터를 실행하는 데 사용되는 (GUI); 단색, 회색조 및 컬러 픽스맵 데이터를 지원합니다. pixmap을 C 프로그래밍 언어의 정적 문자 배열로 저장합니다.
            
            XPM 파일은 .XBM 파일을 확장하도록 설계되었습니다. 두 이미지 유형 모두 C 프로그램 소스 코드에 포함될 수 있으며 C 컴파일러를 사용하여 애플리케이션으로 직접 컴파일 될 수 있습니다.
            
        - mlx_png_file_to_image
        - mlx_destroy_image
        
        The four  functions  that  create  images,  **mlx_new_image(), mlx_xpm_to_image(), mlx_xpm_file_to_image()  and  mlx_png_file_to_image()**, will return **NULL if an error occurs**. Otherwise they return a non-null pointer as an image identifier.
        
    - **Handle events**
        - **mlx_loop**
            
            ```objectivec
            void mlx_loop(mlx_ptr_t *mlx_ptr)
            {
              CFRunLoopObserverRef observer;
              CFRunLoopObserverContext ocontext = {.version = 0, .info = mlx_ptr, .retain = NULL, .release = NULL, .copyDescription = NULL};
            
              mlx_ptr->main_loop_active = 1;
            
              observer = CFRunLoopObserverCreate(NULL, kCFRunLoopBeforeTimers, true, 0, do_loop_flush, &ocontext);
              CFRunLoopAddObserver(CFRunLoopGetMain(), observer, kCFRunLoopCommonModes);
            
              //  [[[MlxLoopHookObj alloc] initWithPtr:mlx_ptr] performSelector:@selector(do_loop_hook) withObject:nil afterDelay:0.0];
            
              [NSApp run];
            }
            ```
            
        - mlx_key_hook
        - mlx_mouse_hook
        - mlx_expose_hook
        - mlx_loop_hook
            
            아무 이벤트도 일어나지 않을 경우 인자로 받았던 함수가 호출됩니다.
            
            이벤트 발생 조건 없이 (*funct_ptr)()에 매개변수로 입력된 함수를 무한대로 실행합니다.
            
        
        mlx_key_hook는 key를 누를때마다 이벤트가 일시적으로 발생하지만, mlx_hook는 누르고있는 상태에서 이벤트가 무한히 반복된다.
        
- **사용 함수**
    
    open, close, read, write, printf, malloc, free, perror, strerror, exit
    
    - ****strerror****
        
        [https://modoocode.com/105](https://modoocode.com/105)
        
        오류 메세지 문자열을 가리키는 포인터를 얻어온다. `errnum`
         의 값을 통해 발생하였던 오류에 알맞은 오류 메세지를 가리키는 포인터를 리턴한다. 이 때 리턴되는 포인터는 [문자열 리터럴](https://modoocode.com/33)
        을 가리키고 있기 때문에 그 내용이 바뀔 수 없다. 참고로 [strerror](https://modoocode.com/105)
         에 의해 출력되는 오류 메세지는 현재 사용중인 컴파일러나 플랫폼에 따라 다를 수 있다.
        
    - **perror**
        
        [https://modoocode.com/53](https://modoocode.com/53)
        
        오류 메세지를 출력한다.
        
        전역 변수 `errno` 의 값을 해석하여 이에 해당하는 시스템 오류 메세지를 **표준 오류 출력 스트림(stderr)**에 출력한다. 또한 추가적으로 전달하고자 하는 사용자 정의 메세지를 [str](https://modoocode.com/str) 인자에 담아 출력할 수 도 있다.
        
        `errno` 는 정수형 변수로 이전의 라이브러리 함수에 의해 발생한 오류에 대한 정보를 가지고 있다. 이 때, `errno` 에 값에 따라 [perror](https://modoocode.com/53) 함수에 의해 출력되는 시스템 오류 메세지는 플랫폼이나 컴파일러에 따라 달라질 수 있다.
        
        만일 [str](https://modoocode.com/str) 이 널 포인터가 아니라면 사용자 정의 메세지가 시스템 오류 메세지 이전에 출력된다. 이 때 두 개의 메세지는 ": " 로 구분된다. 그리고 [str](https://modoocode.com/str) 이 널 포인터인지 아닌지에 상관 없이 맨 마지막에는 개행 문자('\n')가 출력된다.
        
        [perror](https://modoocode.com/53) 은 오류가 발생한 바로 다음에 호출되어야 한다. 그렇지 않을 경우 다른 함수들의 호출에 의해 출력 결과가 달라질 수 있다.
        
- **Math 라이브러리**
    
    사용하려고 했지만, 복소수 곱셈같은건 없었다(…)
    
    유일하게 사용한건 double *fabs(double) 함수
    
- **Fractal**
    - **Mandelbrot set**
        
        [https://ko.wikipedia.org/wiki/망델브로_집합](https://ko.wikipedia.org/wiki/%EB%A7%9D%EB%8D%B8%EB%B8%8C%EB%A1%9C_%EC%A7%91%ED%95%A9)
        
        [https://en.wikipedia.org/wiki/Mandelbrot_set](https://en.wikipedia.org/wiki/Mandelbrot_set)
        
        ```c
        for each pixel (Px, Py) on the screen do
            x0 := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.00, 0.47))
            y0 := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1.12, 1.12))
            x := 0.0
            y := 0.0
            iteration := 0
            max_iteration := 1000
            while (x*x + y*y ≤ 2*2 AND iteration < max_iteration) do
                xtemp := x*x - y*y + x0
                y := 2*x*y + y0
                x := xtemp
                iteration := iteration + 1
            
            color := palette[iteration]
            plot(Px, Py, color)
        
        from [https://en.wikipedia.org/wiki/Mandelbrot_set](https://en.wikipedia.org/wiki/Mandelbrot_set)
        ```
        
    - **Julia set**
        
        [https://en.wikipedia.org/wiki/Julia_set](https://en.wikipedia.org/wiki/Julia_set)
        
        [https://ko.wikipedia.org/wiki/쥘리아_집합](https://ko.wikipedia.org/wiki/%EC%A5%98%EB%A6%AC%EC%95%84_%EC%A7%91%ED%95%A9)
        
        ```c
        R = escape radius #  choose R > 0 such that R**n - R >= sqrt(cx**2 + cy**2)
        
        for each pixel (x, y) on the screen, do:
        {
            zx = scaled x coordinate of pixel # (scale to be between -R and R)
            zy = scaled y coordinate of pixel # (scale to be between -R and R)
          
            iteration = 0
            max_iteration = 1000
          
            while (zx * zx + zy * zy < R**2  AND  iteration < max_iteration) 
            {
                xtmp = (zx * zx + zy * zy) ^ (n / 2) * cos(n * atan2(zy, zx)) + cx;
        	    zy = (zx * zx + zy * zy) ^ (n / 2) * sin(n * atan2(zy, zx)) + cy;
        	    zx = xtmp;
            
                iteration = iteration + 1
            } 
            if (iteration == max_iteration)
                return black;
            else
                return iteration;
        }
        
        from https://en.wikipedia.org/wiki/Julia_set
        ```
        
    - **Burning Ship**
        
        [https://en.wikipedia.org/wiki/Burning_Ship_fractal](https://en.wikipedia.org/wiki/Burning_Ship_fractal)
        
        ```c
        for each pixel (x, y) on the screen, do:
            x := scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.5, 1))
            y := scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1, 1))
        
            zx := x // zx represents the real part of z
            zy := y // zy represents the imaginary part of z 
        
            iteration := 0
            max_iteration := 100
          
            while (zx*zx + zy*zy < 4 and iteration < max_iteration) do
                xtemp := zx*zx - zy*zy + x 
                zy := abs(2*zx*zy) + y // abs returns the absolute value
                zx := xtemp
                iteration := iteration + 1
        
            if iteration = max_iteration then // Belongs to the set
                return insideColor
        
            return iteration × color
        
        from https://en.wikipedia.org/wiki/Burning_Ship_fractal
        ```
        
- **의문점과 해결방법**
    1. mlx_loop동안 event가 발생하면, 어디서부터 어디까지 실행될까? 
        - 이벤트 핸들러 함수 1개만 실행된다. 이후 다시 대기상태로 변경된다.
    2. 1점을 그리고 출력할까? 1줄을 그리고 출력할까? 전체를 그리고 출력할까?
        - 전체를 그리고 출력해야 렉이 덜생긴다.
    3. real number (x)는 좌측부터 우측으로 증가하지만, imaginary number (y)는 위부터 아래로 증가한다. 따라서 y는 복소평면과 부호가 반대이다. (무시해도 OK →  단지 모양이 뒤집어질뿐이다.)
    4. 1000픽셀 x 1000픽셀의 용량은 얼마나 될까?
    1000 x 1000 x 4 (byte) = 4,000,000 byte = 4MB
    5. 무한한(이라지만 최대한의) 확장 및 축소를 고려해야한다.
    특히, 축소의 경우 점으로 보일때까지 축소되어야한다.
    6. 메모리 leak에 대해서 고민해보자.
    괜히 mlx_destroy함수를 사용하면 일부만 삭제되고, window나 image포인터(정확히는 구조체)내부에 동적할당되어있는 부분 일부가 남아있게된다.
    따라서, Destroy함수는 사용하지말고, exit()를 사용하여 leak을 방지하도록 하자.
    ~~(mlx를 뜯고 씹고 맛보고 즐길 준비가 되어있으면 mlx 구조체 내부 구조를 들고와서 동적할당되어있지만, free되지 않는 부분에 대해 열심히 free해도 된다….???)~~
- **간단한 절차 정리**
    
    ```c
    struct initiating
    
    mlx_init();
    mlx_new_window();
    mlx_new_image();
    mlx_get_data_addr();
    ft_hook_setup(); ->  mlx_key_hook() && mlx_mouse_hook()
    ft_print_image(); -> 해당함수는 hook_handler함수들에 내에서도 사용된다.
    mlx_loop();
    
    return (0);
    ```
