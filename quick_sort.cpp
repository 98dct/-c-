#include <iostream>
#include<string>
using namespace std;

int n = 0;

void swap(int nums[], int i, int j) {

    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

pair<int,int> patition(int nums[],int l,int r) {

    int less = l - 1;  //<区左边界
    int more = r;      //>区右边界

    while (l < more) {     //l表示当前位置

        if (nums[l] < nums[r]) {

            //<区右移，交换当前位置和小于区下一个位置，当前位置++
            less++;
            swap(nums,l,less);
            l++;
        }
        else if (nums[l] > nums[r]) {
            //>区左移，交换当前位置和大于区前一个位置，当前位置不变
            more--;
            swap(nums, l, more);
        }
        else {
            l++;
        }
    }
    swap(nums, more, r);
    return {less+1,more};
}




void quickSort(int nums[], int l, int r) {

    //思路：先patition分成<区、等于区、>区
    //然后递归小于区，大于区，直至l==r
    if (l < r) {

        swap(nums, l+rand() % (r-l+1), r);
        pair<int,int> p = patition(nums, l, r);
        quickSort(nums, l, p.first - 1);
        quickSort(nums, p.second + 1, r);
    }
}

void printNums(int nums[], int n) {

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}


int main() {


    int test[12] = { 4,2,7,10,3,9,100,64,77,92,101,50 };
    n = sizeof(test) / sizeof(test[0]);

    //排序前打印
    printNums(test, n);

    quickSort(test, 0, n - 1);

    //排序后打印
    printNums(test, n);

    return 0;
}