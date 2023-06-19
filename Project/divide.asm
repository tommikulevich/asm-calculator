; Divide function (divide.asm)

.386P
.model flat
public _divide

.code
_divide proc near
    push   ebp
    mov    ebp,esp
    xor    edx, edx             ; clear edx before div
    mov    eax, [ebp+8]         ; first argument
    idiv   dword ptr [ebp+12]   ; second argument
    pop    ebp
    ret
_divide endp
end