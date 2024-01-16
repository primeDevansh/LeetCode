#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* retArray = (int*)malloc(2 * sizeof(int));
    for(int i = 0; i < numsSize; i++) {
        for(int j = i + 1; j < numsSize; j++) {
            if((nums[i] + nums[j]) == target) {
                retArray[0] = i;
                retArray[1] = j;
                *returnSize = 2;
                return retArray;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}

int main() {
    int numsSize, target;
    int* returnSize = (int*)malloc(sizeof(int));
    int* result = (int*)malloc(2 * sizeof(int));
    int* nums = (int*)malloc(20 * sizeof(int));

    printf("Enter size of array : ");
    scanf(" %d", &numsSize);
    printf("Enter array elements : \n");

    for(int i = 0; i < numsSize; i++) {
        printf("Enter element %d of %d : ", i+1, numsSize);
        scanf(" %d", &nums[i]);
    }

    printf("Enter target : ");
    scanf(" %d", &target);

    result = twoSum(nums, numsSize, target, returnSize);

    if (*returnSize > 0) {
        for(int i = 0; i < *returnSize; i++) {
            printf("%d\t", result[i]);
        }
    } else {
        printf("No solution found.");
    }

    printf("\n");
    return 0;
}