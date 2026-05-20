//
// Created by Ábrahám Dávid on 2026. 05. 20..
//

void merge(int *nums1, int nums1Size, int m, int *nums2, int nums2Size, int n) {
    int *ptr = &nums1[m + n - 1];

    int *p1 = &nums1[m - 1];
    int *p2 = &nums2[n - 1];

    while (p2 >= nums2) {
        if (p1 >= nums1 && *p1 > *p2) {
            *ptr-- = *p1--;
        } else {
            *ptr-- = *p2--;
        }
    }
}

