global ft_strlen

section .text
ft_strlen:                  ; size_t ft_stren(char *str);
    xor rax, rax            ; Зануляем сразу же к хуям счётчик, который и вернётся
    cmp byte [rdi], 0       ; Сравниваем первый символ str с нулём
    je  .exit               ; Уёбываем, если это ноль сразу и вернём в итоге 0
.loop:                      ; Начинаем циклик
    inc rax                 ; Увеличиваем счётчик (всё равно не конец строки)
    cmp byte [rdi+rax], 0   ; Сравниваем str[rax] с нулём, чтобы выйти если что
    jne .loop               ; И валим если конец строки
.exit:                      ; Финальчек превет
    ret                     ; И ебашь
