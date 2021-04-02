global ft_strcmp

section .text
ft_strcmp:                          ; int ft_strcmp(const char *s1, const char *s2);
    xor rdx, rdx                    ; Обнуление ~~сроков~~ rdx
    mov al, byte [rdi]              ; Сохраняем символ в буферик
    cmp al, 0                       ; Если \0, строка пустая
    je  .exit                       ; Уёбываем
.loop:                              ; Начинаем циклик
    cmp al, byte [rsi + rdx]        ; Если символы двух строк не равны
    jne .exit                       ; Ебашим к выходу
    cmp al, 0                       ; Если дошли до конца строки
    je .exit                        ; Валим на выход
    inc rdx                         ; Плюс 1 ~~срок~~ к счётчику
    mov al, byte [rdi + rdx]        ; Сохраняем в буфер следующий символ
    jmp .loop                       ; И начинаем цикл сначала
.exit:                              ; Начало конца
    movzx rcx, byte [rsi + rdx]     ; Переносим в буфер символ второй строки
    sub rax, rcx                    ; Вычитаем с символом первой строки
    ret                             ; И возвращаем их разницу