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
