#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 1000

typedef struct {
    int digits[MAX_DIGITS];
    int sign;
    int length;
} BigInt;

void init_bigint(BigInt *num) {
    for(int i = 0; i < MAX_DIGITS; i++) num->digits[i] = 0;
    num->sign = 1;
    num->length = 1;
}

void string_to_bigint(BigInt *num, const char *str) {
    init_bigint(num);
    int start = 0, len = strlen(str);
    
    if(str[0] == '-') { num->sign = -1; start = 1; }
    else if(str[0] == '+') { num->sign = 1; start = 1; }
    
    num->length = len - start;
    for(int i = 0; i < num->length; i++) {
        num->digits[i] = str[len - 1 - i] - '0';
    }
}

void print_bigint(const BigInt *num) {
    if(num->sign == -1) printf("-");
    for(int i = num->length - 1; i >= 0; i--) {
        printf("%d", num->digits[i]);
    }
}

int compare_bigint(const BigInt *a, const BigInt *b) {
    if(a->length > b->length) return 1;
    if(a->length < b->length) return -1;
    for(int i = a->length - 1; i >= 0; i--) {
        if(a->digits[i] > b->digits[i]) return 1;
        if(a->digits[i] < b->digits[i]) return -1;
    }
    return 0;
}

int is_zero(const BigInt *num) {
    return (num->length == 1 && num->digits[0] == 0);
}

void add_bigint(BigInt *result, const BigInt *a, const BigInt *b) {
    init_bigint(result);
    if(a->sign != b->sign) {
        BigInt temp_b = *b;
        temp_b.sign = -temp_b.sign;
        subtract_bigint(result, a, &temp_b);
        return;
    }
    
    result->sign = a->sign;
    int carry = 0, max_len = (a->length > b->length) ? a->length : b->length;
    
    for(int i = 0; i < max_len || carry; i++) {
        int sum = carry;
        if(i < a->length) sum += a->digits[i];
        if(i < b->length) sum += b->digits[i];
        result->digits[i] = sum % 10;
        carry = sum / 10;
        result->length = i + 1;
    }
}

void subtract_bigint(BigInt *result, const BigInt *a, const BigInt *b) {
    init_bigint(result);
    if(a->sign != b->sign) {
        BigInt temp_b = *b;
        temp_b.sign = -temp_b.sign;
        add_bigint(result, a, &temp_b);
        return;
    }
    
    int cmp = compare_bigint(a, b);
    if(cmp == 0) { init_bigint(result); return; }
    
    const BigInt *larger, *smaller;
    if(cmp > 0) { larger = a; smaller = b; result->sign = a->sign; } 
    else { larger = b; smaller = a; result->sign = -a->sign; }
    
    int borrow = 0;
    for(int i = 0; i < larger->length; i++) {
        int diff = larger->digits[i] - borrow;
        if(i < smaller->length) diff -= smaller->digits[i];
        if(diff < 0) { diff += 10; borrow = 1; } 
        else { borrow = 0; }
        result->digits[i] = diff;
        result->length = i + 1;
    }
    
    while(result->length > 1 && result->digits[result->length - 1] == 0) {
        result->length--;
    }
}

void multiply_bigint(BigInt *result, const BigInt *a, const BigInt *b) {
    init_bigint(result);
    result->sign = a->sign * b->sign;
    
    for(int i = 0; i < a->length; i++) {
        int carry = 0;
        for(int j = 0; j < b->length || carry; j++) {
            int product = result->digits[i + j] + a->digits[i] * 
                         (j < b->length ? b->digits[j] : 0) + carry;
            result->digits[i + j] = product % 10;
            carry = product / 10;
            if(i + j + 1 > result->length) result->length = i + j + 1;
        }
    }
}

void divide_bigint(BigInt *quotient, BigInt *remainder, const BigInt *a, const BigInt *b) {
    init_bigint(quotient);
    init_bigint(remainder);
    
    if(is_zero(b)) {
        printf("Erro: Divisão por zero!\n");
        return;
    }
    
    quotient->sign = a->sign * b->sign;
    remainder->sign = 1;
    
    BigInt temp_a = *a, temp_b = *b;
    temp_a.sign = temp_b.sign = 1;
    
    for(int i = temp_a.length - 1; i >= 0; i--) {
        for(int j = remainder->length; j > 0; j--) {
            remainder->digits[j] = remainder->digits[j - 1];
        }
        remainder->digits[0] = temp_a.digits[i];
        remainder->length++;
        
        while(remainder->length > 1 && remainder->digits[remainder->length - 1] == 0) {
            remainder->length--;
        }
        
        int count = 0;
        while(compare_bigint(remainder, &temp_b) >= 0) {
            BigInt temp;
            subtract_bigint(&temp, remainder, &temp_b);
            *remainder = temp;
            count++;
        }
        quotient->digits[i] = count;
    }
    
    quotient->length = temp_a.length;
    while(quotient->length > 1 && quotient->digits[quotient->length - 1] == 0) {
        quotient->length--;
    }
}

void gcd_bigint(BigInt *result, const BigInt *a, const BigInt *b) {
    BigInt x = *a, y = *b;
    x.sign = y.sign = 1;
    
    if(is_zero(&x)) { *result = y; return; }
    
    while(!is_zero(&y)) {
        BigInt temp, rem;
        divide_bigint(&temp, &rem, &x, &y);
        x = y;
        y = rem;
    }
    *result = x;
}

int main() {
    BigInt a, b, result, rem;
    int op;
    char input[1000];
    
    printf("=== CALCULADORA BIG INT ===\n");
    
    while(1) {
        printf("\n1-Soma  2-Sub  3-Mult  4-Div  5-Mod  6-MDC  0-Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();
        
        if(op == 0) break;
        if(op < 1 || op > 6) { printf("Opcao invalida!\n"); continue; }
        
        printf("Numero 1: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        string_to_bigint(&a, input);
        
        printf("Numero 2: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        string_to_bigint(&b, input);
        
        printf("Resultado: ");
        print_bigint(&a);
        
        switch(op) {
            case 1: 
                add_bigint(&result, &a, &b);
                printf(" + ");
                break;
            case 2:
                subtract_bigint(&result, &a, &b);
                printf(" - ");
                break;
            case 3:
                multiply_bigint(&result, &a, &b);
                printf(" * ");
                break;
            case 4:
                if(is_zero(&b)) { printf("Div por zero!\n"); continue; }
                divide_bigint(&result, &rem, &a, &b);
                printf(" / ");
                break;
            case 5:
                if(is_zero(&b)) { printf("Div por zero!\n"); continue; }
                divide_bigint(&result, &rem, &a, &b);
                result = rem;
                printf(" %% ");
                break;
            case 6:
                gcd_bigint(&result, &a, &b);
                printf(" MDC ");
                break;
        }
        
        print_bigint(&b);
        printf(" = ");
        print_bigint(&result);
        printf("\n");
    }
    
    printf("Ate mais!\n");
    return 0;
}
