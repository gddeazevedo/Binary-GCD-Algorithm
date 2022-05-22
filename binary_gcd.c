#include <stdio.h>


int binary_gcd(unsigned int a, unsigned int b);

int main() {
    printf("%d\n", binary_gcd(11, 66));
    return 0;
}

int binary_gcd(unsigned int a, unsigned int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    if (a == b) return a;

    // a and b are even
    if (~a & 1 && ~b & 1) {
        return binary_gcd(a >> 1, b >> 1) << 1;
    }

    // a is even and b is odd
    if (~a & 1) {
        return binary_gcd(a >> 1, b);
    }

    // a is odd and b is even
    if (~b & 1) {
        return binary_gcd(a, b >> 1);
    }

    // both are odd
    if (a >= b) {
        return binary_gcd((a - b) >> 1, b);
    }

    // a <= b
    return binary_gcd(a, (b - a) >> 1);
}