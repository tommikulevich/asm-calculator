; Modulo function (modulo.asm)

.386P
.model flat
public _modulo

.code
_modulo proc near
    push   ebp
    mov    ebp,esp
    xor    edx, edx             ; clear edx before div
    mov    eax,[ebp+8]          ; first argument
    idiv   dword ptr [ebp+12]   ; second argument
    mov    eax, edx             ; return remainder
    pop    ebp
    ret
_modulo endp
end