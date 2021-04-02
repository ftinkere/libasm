global ft_strdup

extern malloc
extern ft_strlen
extern ft_strcpy

section .text
ft_strdup:
    push rdi
    call ft_strlen WRT ..plt
    mov rdi, rax
    inc rdi
    call malloc WRT ..plt
    cmp rax, 0
    je .exit
    mov rdi, rax
    pop rsi
    call ft_strcpy WRT ..plt
.exit:
    ret