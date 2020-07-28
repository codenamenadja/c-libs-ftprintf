## MAKE TARGETS

    - USE MAKE command to build project. this projects depends to additionals lib
    - run test script with below command
        - ``gcc test.c ft_printf.a addtionals/ft_additionals.a``


### stdarg.h

- desc

    함수는 가변적인 수와 타입의 아규먼트로 실행될 수 있다.
    
    **va_list**라는 타입과 3가지 매크로를 stdarg.h에 정의하는데, 그는 해당 가변적인 매개변수, 즉 해당 함수가 알 수 없는 그들을 파악하는데 도움을 준다.  
    
    > 호출되는 함수는 반드시 va_list라는 타입을 선언하여야 하는데 그들은 3가지 매크로에서 사용된다.

- type

- macros

    - ``va_start()``
    
        ```c
        void va_start(va_list ap, last);
        ```
        
        ``ap``를 초기화 한다. 그는 va_arg, va_end에 의해 사용될 수 있기 떄문에, 따라서, 그들은 먼저 호출되어야 한다.
        
        ``last``아규먼트는 변수 아규먼트 리스트 이전의 마지막 아규먼트이다.  그는, 호출하는 함수가 타입을 아는 마지막 아규먼트이다.  
        왜냐하면 이 아규먼트의 주소는 va_start에서 사용될 수 있기 때문에, 레지스터 변수로 록은 함수로, 혹은 배열 타입으로 선언되서는 안된다.


    - ``va_arg()``
    
        ```c
        type va_arg(va_list ap, type);
        ```

        va_arg매크로는 호출의 타입과 값이 있는 다음 아규먼트를 가진 표현으로 확장된다.  
        
        - ``ap``아규먼트는 ``va_start()``콜에서 초기화 된 것이어야 한다.
        - 각 호출은 ``ap``를 수정하여, 다음 콜이 다음 아규먼트를 리턴하도록 한다.
        - ``type``아규먼트는, 타입 이름이 명세되어 있으며, 따라서, 해당 타입의 포인터가 들어오며 type에 ``*``연산자를 붙이는 것만으로 얻을 수 있다.
        - va_start매크로 실행의 첫 va_arg매크로 호출은 ``last``다음의 매개변수를 리턴한다.
        - RETURNS
            - 성공적인 호출들은 남은 매개변수들의 값을 리턴한다.
            - 만약 더 이상 전달 매개변수가 남아있지 않거나, type이 해당 다음 매개변수와 타입호환이 되지 않는다면, 랜덤 에러들이 발생할 것이다.
        - 만약 ``ap``가 ``va_arg(ap, type)``을 사용하는 함수로 전달 된다면, 해당 함수가 리턴한 후에 ap의 값은 undefined된다.

    - ``va_end()``
    
        ```c
        void va_end(va_list ap);
        ```
        
         각 ``va_start()``콜에 대한 각 호출은, 동일 함수 내에서, va_end()와 호환하는 함수를 호출하는 걸로 매치되어야한다. ``va_end(ap)``이후에 ``ap``는 undefined된다.
        복수의 리스트를 순회하는, 각 va_start(), va_end()들이 가능하다. va_end는 매크로거나 함수이다.

    - ``va_copy()``
    
        ```c
        void va_copy(va_list dest, va_list src);
        ```
        
        이 매크러는 이전에 초기화된 아규먼트 리스트인 src를 dest로 복사한다.  이 행동은 va_start()가 dest로 같은 마지막 아규먼트와 적용된 것과 같으며, 현재 상태의 src에 도달하는데 사용된 동일 수의 va_arg()콜들이 따라온다.  
        명백한 실행은 va_list가 스택프레임에 대한 포인터로 하게 한다. 그러한 조건안에서, 아래와 같은 할당을 대체할 것은 없다.  
        ```c
        va_list aq = ap;
        ```
        
        불행히도, 거기엔 포인터들의 배열의 길이를 1로 만드는 시스템이 있으며, 거기엔 아래와 같은 것이 필요하다.
        
        ```c
        va_list aq;
        *aq = *ap;
        ```
        
        마지막으로 아규먼트들이 레지스터로 전달된 시스템들에서, va_start()를 통해 메모리를 할당하고, 아규먼트들을 거기 저장하고, 또한 어떤 아규먼트가 다음인지에 대한 가리킴이 필수적이며, 그리하여 va_arg()는 리스트를 순회 할 수 있다.  
        이제 va_end()는 할당된 메모리를 다시 해제할 수 있다.  
        이 상황을 수용하기 위해서, va_copy가 추가되었으며, 위의 할당문은 아래와 같이 대체될 수 있다.
        ```c
        va_list aq;
        va_copy(aq, ap);
        ...
        va_end(aq);
        ```
        
        각 va_copy()콜은 그와 상통하는 va_end()콜이 같은 함수내에서 매치 되야 한다.  
        일부 시스템들은 va_copy()가 아니라 ``__va_copy()``를 사용하기도 한다.
