#include <iostream>
#include<string>
using namespace std;

int n = 0;

void swap(int nums[], int i, int j) {

    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}


void merge(int nums[], int l, int m, int r) {

    int temp[20];
    int i = 0;
    int p1 = l;
    int p2 = m + 1;
    while(p1 <= m && p2 <= r) {
        if (nums[p1] < nums[p2]) {
            temp[i++] = nums[p1++];
        }
        else {
            temp[i++] = nums[p2++];
        }
    }

    while (p1 <= m) {
        temp[i++] = nums[p1++];
    }
    while (p2 <= r) {
        temp[i++] = nums[p2++];
    }

    for (int j = 0; j < (r - l + 1); j++) {
        nums[l + j] = temp[j];
    }

}

void mergeSort(int nums[],int l,int r) {

    //思路：定义l = 0,r = n-1,然后一直递归二分、递归二分、一直到l= r，然后合并排序，
    //总体来说就是，递归二分，加合并排序
    if (l == r) {
        return;
    }

    int m = l + (r - l) / 2;
    mergeSort(nums,l, m);
    mergeSort(nums, m + 1, r);
    merge(nums, l, m, r);

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

    mergeSort(test,0,n-1);

    //排序后打印
    printNums(test, n);

    return 0;
}