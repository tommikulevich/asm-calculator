; Power function (power.asm)

.386P
.model flat
public _power

.code
_power proc near
    push   ebp
    mov    ebp,esp
    mov    ecx,[ebp+12]     ; second argument (exponent)
    mov    eax,[ebp+8]      ; first argument (base)
    mov    ebx,eax          ; copy of base
    dec    ecx              ; decrement exponent by 1
    jz     endpower         ; if exponent is 0, end
power_loop:
    imul   eax,ebx
    loop   power_loop
endpower:
    pop    ebp
    ret
_power endp
end