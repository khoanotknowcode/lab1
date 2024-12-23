// Put your C program here
#include <stdio.h>
#include <stdint.h>
#include <string.h>

int32_t is_two_byte_char(char c) {
    return (c & 11100000 == 11000000) ? 1 : 0;
}

int main() {
    unsigned char str[128];

    printf("Enter your input: ");
    fgets(str,sizeof(str),stdin);
    printf("\n");

    uint32_t dec = 0;

    if ((str[0] & 0b11111000) == 0b11110000) {
        if (str[0] != 0 && str[1] != 0 && str[2] != 0 && str[3] != 0)
            dec = (str[0] & 0x7)<<18 | (str[1] & 0x3F)<<12 | (str[2] & 0x3F)<<6 | (str[3] & 0x3F);
    } else if ((str[0] & 0b11110000) == 0b11100000) {
        if (str[0] != 0 && str[1] != 0 && str[2] != 0)
            dec = (str[0] & 0xF)<<12 | (str[1] & 0x3F)<<6 | (str[2] & 0x3F);
    } else if ((str[0] & 0b11100000) == 0b11000000) {
        if (str[0] != 0 && str[1] != 0)
            dec = (str[0] & 0x1F)<<6 | (str[1] & 0x3F);
    } else {
        dec = str[0];
    }
    
    printf("Input character : %s\n", str);
    printf("Codepoint of the character is %d\n", dec);
}