// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int res = 0;
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if ((arr[i] + arr[j]) == value)
                res += 1;
    return res;
}
int countPairs2(int* arr, int len, int value) {
    int res = 0;
    for (int i = 0; i < len - 1; i++) {
        if (arr[i] > value)
            continue;
        for (int j = len - 1; j > i; j--) {
            if (arr[j] > value)
                continue;
            if ((arr[i] + arr[j]) == value)
                res += 1;
        }
    }
    return res;
}
int countPairs3(int* arr, int size, int value) {
    int res = 0;
    for (int i = 0; i < size - 1; i++) {
        int left = i, right = size;
        while ((right - left) > 1) {
            int mid = (left + right) / 2;
            if (arr[mid] + arr[i] == value) {
                res++;
                int top = mid + 1;
                while (arr[top] + arr[i] == value && top < right) {
                    res++;
                    top++;
                }
            }
            if (arr[mid] + arr[i] > value)
                right = mid;
            if (arr[mid] + arr[i] < value)
                left = mid;
        }
    }
    return res;
}
