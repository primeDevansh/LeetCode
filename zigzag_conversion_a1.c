#include <stdio.h>
#include <stdlib.h>
/*
char* convert(char* s, int numRows) {
    char* result[1000]; //2D array for zig zag ooutput
    char* ret_string = (char*)malloc(1001 * sizeof(char));
    int numColumns = 1000;
    int i, j, k, t;
    for(i = 0; i < numRows; i++) {
        result[i] = (char*)malloc(numColumns * sizeof(char));
    }
    for(i = 0; i < numRows; i++) {
        for(j = 0; j < numColumns; j++) {
            result[i][j] = ';';
        }
    }//';' means ignore the character

    for(i = 0, k = 0; s[k] != '\0'; i++) {
        for(j = 0; (j < numRows) && (s[k] != '\0'); j++) {
            result[j][i] = s[k++];
        }
        if(j == numRows) {
            for(t = j - 2, j = i + 1; (s[k] != '\0') && (t >= 0); t--, j++) {
                result[t][j] = s[k++];
            }
        }
        else
            break;
    }

    for(i = 0, k = 0; i < numRows; i++) {
        for(j = 0; j < 10; j++) {
            if(result[i][j] != ';') {
                printf("%c  ", result[i][j]);
                // ret_string[k++] = result[i][j];
            }
            else {
                printf("  ");
            }
            printf("\n");
        }
    }
    ret_string[k] = '\0';
    return ret_string;
}
*/

/*
char* convert(char* s, int numRows) {
    int offset = 0, i, j, k;
    k = 0;
    int slen = 0;
    char* str = (char*)malloc(1000 * sizeof(char));
    if(numRows >= 2) {
        offset = (numRows * 2) - 2;
    }

    while(s[slen++]);

    for(i = 0; i < numRows; i++) {
        for(j = i; j < slen; j += offset) {
            str[k++] = s[j];
        }
    }
    str[k] = '\0';
    return str;
}
*/

char* convert(char* s, int numRows) {
    char zigzag[1000][1000];
    char* result = (char*)malloc(1000 * sizeof(char));
    int i, j, k;

    for(i = 0; i < numRows; i++) {
        for(j = 0; j < 1000; j++) {
            zigzag[i][j] = ';';
        }
    }

    i = j = k = 0;
    while(s[k]) {
        // if(i)
        //     i++;
        for(; s[k] != '\0' && i < numRows; i++, k++) {
            zigzag[i][j] = s[k];
        }
        if(s[k]) {
            //if s[k] != '\0' means i will have to be equal to numRows
            for(j = j + 1, i = i - 2; s[k] != '\0' && i >= 0; j++, i--) {
                zigzag[i][j] = s[k++];
            }
            j--;
            i = 1;
        }
        else
            break;
    }

    for(i = 0, k = 0; i < numRows; i++) {
        for(j = 0; j < 10; j++) {
            if(zigzag[i][j] != ';') {
                printf(" %c ", zigzag[i][j]);
                result[k++] = zigzag[i][j];
            }
            else
                printf("   ");
        }
        printf("\n");
    }
    result[k] = '\0';
    return result;
}

int main() {
    char *str = (char*)malloc(1000 * sizeof(char));
    int numRows;
    char *ret_str = (char*)malloc(1000 * sizeof(char));

    printf("Enter a string : ");
    scanf(" %s", str);
    printf("Enter number of rows : ");
    scanf(" %d", &numRows);

    ret_str = convert(str, numRows);
    printf("\nString is: %s\n", ret_str);
    return 0;
}