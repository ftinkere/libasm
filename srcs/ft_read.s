global ft_read

extern __errno_location

section .text
ft_read:
    mov rax, 0
    syscall
    cmp rax, 0
    jl .errex
    ret
.errex:
    mov rcx, rax
    call __errno_location WRT ..plt
    neg rcx
    mov [rax], rcx
    mov rax, -1
    ret