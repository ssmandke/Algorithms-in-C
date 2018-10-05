
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<string.h>

#define bool char
#define true 1
#define false 0
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

int a[] = {1,3,5,6,7,8,9};
int b[] = {1,4,6,8,12,14,15,17};

int c[] = {4 , 8 , 9, 12, 13, 15};
int d[] = {3 , 7 , 8, 10, 11};
 
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int p, q, i, j;
    if (nums1Size < nums2Size) {
        p = 0;
        q = nums1Size;
		printf("\r\nCase 1: size1 < size2 => %d  %d => p = %d, q = %d\r\n", nums1Size, nums2Size, p, q);
    } else {
        p = (nums1Size - nums2Size) / 2;        
		q = p + nums2Size;
		printf("\r\nCase 2: size1 > size2 => %d  %d => p = %d, q = %d\r\n", nums1Size, nums2Size, p, q);
    }

    while (p <= q) {
        i = (p + q) / 2;
        j = (nums1Size + nums2Size) / 2 - i;
        if (i < nums1Size && j > 0 && nums1[i] < nums2[j - 1]) {
            p = i + 1;
        } else if (i > 0 && j < nums2Size && nums1[i - 1] > nums2[j]) {
            q = i - 1;
        } else {
            break;
        }
    }

    double left, right;
    if (i == nums1Size) {
        right = nums2[j];
    } else if (j == nums2Size) {
        right = nums1[i];
    } else {
        right = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
    }

    if ((nums1Size + nums2Size) % 2) {
        return right;
    }

    if (i == 0) {
        left = nums2[j - 1];
    } else if (j == 0) {
        left = nums1[i - 1];
    } else {
        left = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];
    }
    return (left + right) / 2;
}

int main()
{
  printf("Median of 2 sorted arrays is %f\r\n\n",findMedianSortedArrays(a, sizeof(a)/sizeof(int), b, sizeof(b)/sizeof(int)));
  printf("Median of 2 sorted arrays is %f\r\n\n",findMedianSortedArrays(c, sizeof(c)/sizeof(int), c, sizeof(d)/sizeof(int)));
  return 0;
}
