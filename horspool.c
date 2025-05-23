#include <stdio.h>
#include <string.h>

#define max 256

void createshifttable(char pattern[], int pl, int st[]) {
    for (int i = 0; i < max; i++) {
        st[i] = pl;
    }
    for (int i = 0; i < pl - 1; i++) {
        st[(unsigned char)pattern[i]] = pl - 1 - i;
    }
}

int horspool(char text[], char pattern[]) {
    int tl = strlen(text);
    int pl = strlen(pattern);  // ✅ Corrected this line
    int st[max];
    createshifttable(pattern, pl, st);

    int i = pl - 1;

    while (i < tl) {  // ✅ Fixed loop condition
        int k = 0;
        while (k < pl && pattern[pl - 1 - k] == text[i - k]) {
            k++;
        }
        if (k == pl) {
            return i - pl + 1;  // ✅ Correct match index
        } else {
            i += st[(unsigned char)text[i]];
        }
    }
    return -1;
}

int main() {
    char text[] = "abracadabra";
    char pattern[] = "cad";

    int position = horspool(text, pattern);

    if (position != -1)
        printf("Pattern found at position %d\n", position);
    else
        printf("Pattern not found.\n");

    return 0;
}
