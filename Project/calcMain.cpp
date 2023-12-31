#include <iostream>
#include <climits>  // for LONG_MAX and LONG_MIN

using namespace std;

extern "C" long int divide(long int num1, long int num2);
extern "C" long int modulo(long int num1, long int num2);
extern "C" long int power(long int num1, long int num2);

int main()
{
    long int a, b;
    long int result;
    char operation;

    cout << "Calculator:" << endl;

    while (1) {
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;
        cout << "Operation (+ - * / % ^) or b to calculate BMI: ";
        cin >> operation;

        switch (operation) {
        case '+':
            __asm {
                mov eax, a
                add eax, b
                jc overflow         // check for overflow
                mov result, eax
                jmp end_add
                overflow :
                mov eax, LONG_MAX
                    mov result, eax
                    end_add :
                ;
            };
            break;
        case '-':
            __asm {
                mov eax, a
                sub eax, b
                jnc underflow       // check for underflow
                mov result, eax
                jmp end_sub
                underflow :
                mov eax, LONG_MIN
                    mov result, eax
                    end_sub :
                ;
            };
            break;
        case '*':
            __asm {
                mov eax, a
                imul eax, b
                jo mul_overflow     // check for overflow
                mov result, eax
                jmp end_mul
                mul_overflow :
                mov eax, LONG_MAX
                    mov result, eax
                    end_mul :
                ;
            };
            break;
        case 'b':
            __asm {
                mov eax, a

                mov ebx, b
                imul ebx, ebx

                xor edx, edx
                div ebx

                mov result, eax
            };
            break;
        case '/':
            if (b == 0) {
                cout << "Cannot divide by zero!" << endl;
                return 1;
            }
            result = divide(a, b);
            break;
        case '%':
            if (b == 0) {
                cout << "Cannot divide by zero!" << endl;
                return 1;
            }
            result = modulo(a, b);
            break;
        case '^':
            if (b < 0) {
                cout << "Cannot raise to a negative power!" << endl;
                return 1;
            }
            result = power(a, b);
            break;
        default:
            cout << "Unknown operation!" << endl;
            return 1;
        }
        if (operation == 'b')   cout << "Weight " << a << " kg, "<< b << " m, your BMI is " << result << endl;
        else cout << a << " " << operation << " " << b << " = " << result << endl;
        cout << endl;
    }

    return 0;
}
