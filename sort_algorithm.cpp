// 二分查找
int binarySearch(vector<int>& nums, int target) {
    int i = 0;
    int j = nums.size() - 1;

    while (i <= j) {
        int m = i + (j - i) / 2;
        if (nums[m] < target) {
            i = m + 1;
        }
        else if (nums[m] > target) {
            j = m - 1;
        }
        else {
            return m;
        }
    }

    return -1;
}

// 选择排序
void selectionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int k = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        swap(nums[i], nums[k]);
    }
}

// 冒泡排序
void bubbleSort(vector<int>& nums) {
    for (int i = nums.size() - 1; i > 0; i--) {
        bool flag = false;
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}

// 插入排序
void insertionSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        int base = nums[i];
        int j = i - 1;
        
        while (j >= 0 && nums[j] > base) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = base;
    }
}

// 快速排序
int partition(vector<int>& nums, int left, int right) {
    int i = left;
    int j = right;
    int base = nums[left];

    while (i < j) {
        while (i < j && nums[j] > base) {
            j--;
        }
        while (i < j && nums[i] < base) {
            i++;
        }

        swap(nums[i], nums[j]);
    }
    swap(nums[i], nums[left]);
    return i;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int pivot = partition(nums, left, right);
    quickSort(nums, left, pivot - 1);
    quickSort(nums, pivot + 1, right);
}

// 归并排序
void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right) {
        return;
    }
    
    int mid = left + (right - left) / 2;
    
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid right);
}

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> tmp(right - left + 1, 0);
    int i = 0, j = mid + 1, k = 0;
    while (i <= mid && j <= right) {
        if (nums[i] < nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }

    while (i <= mid)
        tmp[k++] = nums[i++];
    while (j <= right)
        tmp[k++] = nums[j++];

    for (int k = 0; k < tmp.size(); k++) {
        nums[left + k] = tmp[k];
    }
}
