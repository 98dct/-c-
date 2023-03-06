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

    //˼·������l = 0,r = n-1,Ȼ��һֱ�ݹ���֡��ݹ���֡�һֱ��l= r��Ȼ��ϲ�����
    //������˵���ǣ��ݹ���֣��Ӻϲ�����
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

    //����ǰ��ӡ
    printNums(test, n);

    mergeSort(test,0,n-1);

    //������ӡ
    printNums(test, n);

    return 0;
}