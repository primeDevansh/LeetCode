#include <stdio.h>
#include <stdlib.h>

char* convert(char* s, int numRows) {
    int i, j, k, l, s_len = 0;
    int OFFSET;
    int* offset = (int*)malloc(2 * sizeof(int));

    while(s[s_len++]);
    char* result = (char*)malloc((s_len + 2) * sizeof(char));

    OFFSET = (numRows * 2) - 2;
    offset[0] = OFFSET;
    offset[1] = 0;

    for(i = 0, k = 0; i < numRows; i++) {
        for(j = i, l = 0; j < s_len; k++) {
            result[k] = s[j];
            if(numRows == 1 || OFFSET == 0)
                j++;
            else if(i == 0 || i == (numRows - 1))
                j += OFFSET;
            else {
                if(l == 0) {
                    offset[0] -= 2;
                    if(offset[0] == 0)
                        offset[0] = 1;
                    j += offset[0];
                    l = 1;
                }
                else {
                    offset[1] += 2;
                    j += offset[1];
                    l = 0;
                }
            }
        }
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
/*
char* convert(char* s, int numRows) {
    char zigzag[1000][1000];
    char* result = (char*)malloc(1000 * sizeof(char));
    int i, j, k, l;

    for(i = 0; i < numRows; i++) {
        for(j = 0; j < 1000; j++) {
            zigzag[i][j] = ';';
        }
    }

    i = j = k = 0;
    while(s[k]) {
        if(numRows == 1) {
            for(i = 0, j = 0; s[k] != '\0'; j++, k++)
                zresult[k] = s[k];
            break;
        }
        else
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
        for(l = 0; l < j; l++) {
            if(zigzag[i][l] != ';') {
                result[k++] = zigzag[i][l];
            }
        }
    }
    result[k] = '\0';
    return result;
}
*/
/*
char* convert(char* s, int numRows) {
    char* zigzag[1000];
    char* result = (char*)malloc(1000 * sizeof(char));
    int i, j, k, l;

    for(i = 0; i < numRows; i++) {
        zigzag[i] = (char*)malloc(1000 * sizeof(char));
    }

    for(i = 0; i < numRows; i++) {
        for(j = 0; j < 1000; j++)
            zigzag[i][j] = ';';
    }

    i = 0;
    j = 0;
    k = 0;

    while(s[k]) {
        if(numRows == 1) {
            for(i = 0, j = 0; s[k] != '\0'; j++, k++)
                zigzag[i][j] = s[k];
            break;
        }
        else
            for(; s[k] != '\0' && i < numRows; i++, k++) {
                zigzag[i][j] = s[k];
            }
        if(s[k]) {
            for(j = j + 1, i = i - 2; s[k] != '\0' && i >= 0; j++, i--)
                zigzag[i][j] = s[k++];
            j--;
            i = 1;
        }
        else
            break;
    }

    for(i = 0, k = 0; i < numRows; i++)
        for(l = 0; l < j; l++)
            if(zigzag[i][l] != ';')
                result[k++] = zigzag[i][l];
    result[k] = '\0';
    return result;
}
*/