// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int size, int value) {
    int count = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if ((arr[i] + arr[j]) == value)
                count += 1;
    return count;
}
int countPairs2(int* arr, int size, int value) {
    int count = 0;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > value)
            continue;
        for (int j = size - 1; j > i; j--) {
            if (arr[j] > value)
                continue;
            if ((arr[i] + arr[j]) == value)
                count += 1;
        }
    }
    return count;
}
int cbinsearch(int* arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) {
            count++;
            int left = mid - 1;
            int right = mid + 1;
            while (left >= 0 && arr[left] == value) {
                count++;
                left--;
            }
            while (right < size && arr[right] == value) {
                count++;
                right++;
            }
            return count;
        }
        if (arr[mid] < value) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int second = value - arr[i];
        count += cbinsearch(&arr[i + 1], len - i - 1, second);
    }
    return count;
}
