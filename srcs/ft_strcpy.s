global ft_strcpy

section .text
ft_strcpy:                      ; char *ft_strcpy(char *dst, char* src);
    mov rax, rdi                ; Сразу вернём dst после ret
    xor rdx, rdx                ; Зануляем нахуй счётчик rdx
    mov cl, byte [rsi]          ; Пихаем в буфер cl первый символ src
    cmp cl, 0                   ; Сравниваем с нулём
    je  .exit                   ; И сразу валим, если строка пустая
.loop:                          ; Начинаем цикл
    mov byte [rax + rdx], cl    ; Из буфера запихиваем символ в dst[rdx]
    inc rdx                     ; Увеличиваем счётчик rdx на один
    mov cl, byte [rsi + rdx]    ; Пихаем в буфер новый символ src[rdx]
    cmp cl, 0                   ; Сравниваем с нулём
    jne .loop                   ; Уходим из цикла, если это был конец строки
.exit:                          ; Начинаем финалочку
    mov byte [rax + rdx], 0     ; Зануляем последний байт, чтобы был конец строки
    ret                         ; И хуярим куда подальше
