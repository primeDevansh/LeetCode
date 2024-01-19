#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int* numsUnique = (int*)malloc(numsSize * sizeof(int));
    int elements_removed = 0;
    int i, j, k = 0;

    for(i = 0; i < numsSize; i++, k++) {
        numsUnique[k] = nums[i];
        for(j = i + 1; j < numsSize; j++) {
            if(numsUnique[k] == nums[j])
                continue;
            else
                break;
        }
        i = j - 1;
    }
    for(i = 0; i < k; i++) {
        nums[i] = numsUnique[i];
    }
    return k;
}

int addElements(int* nums) {
    int numsSize;
    printf("Enter Number of Elements You Want to Enter: ");
    scanf(" %d", &numsSize);
    printf("Enter elements in non-decreasing sorted order: - \n");
    for(int i = 0; i < numsSize; i++) {
        scanf(" %d", &nums[i]);
    }
    return numsSize;
}

void displayElements(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d\t", arr[i]);
    }
}

int main() {
    const int numsSizeMax = 50;
    int* nums = (int*)malloc(numsSizeMax * sizeof(int));

    int numsSize = addElements(nums);
    int numsSizeUnique = removeDuplicates(nums, numsSize);
    printf("Unique Array Is: - \n");
    displayElements(nums, numsSizeUnique);
    printf("\n");
    return 0;
}