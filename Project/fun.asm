title The fun Subroutine    (fun.asm)

; This subroutine links to Visual C++ 6.0.

.386P
.model flat
public _fun

.code
_fun proc near   ; w = 20*z^2 - 100*y + x
    push   ebp
    mov    ebp,esp
    push   ecx
    push   ebx

    mov    eax, 20				; 
    mul    sdword PTR[ebp+16]	; third argument
    mul    sdword PTR[ebp+16]	; 
    mov    ecx, eax				;

    mov    eax, 100				; 
    mul    sdword PTR[ebp+12]	; second argument
    mov    ebx, eax
	mov    eax, ecx
	sub    eax, ebx

    add    eax, [ebp+8]			; first argument
	
	pop	   ebx
    pop    ecx 
    pop    ebp
    ret                   
_fun endp
end

