#include <iostream>
#include<string>
using namespace std;

int n = 0;

void swap(int nums[], int i, int j) {

    nums[i] = nums[i] ^ nums[j];
    nums[j] = nums[i] ^ nums[j];
    nums[i] = nums[i] ^ nums[j];

}

void insertSort(int nums[], int n) {


    //˼·��0-0����,0-1����0-2����.....
    //0-i����
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0 && nums[j] > nums[j + 1]; j--) {
            swap(nums, j, j + 1);
        }
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

    //����ǰ��ӡ
    printNums(test, n);

    insertSort(test, n);

    //������ӡ
    printNums(test, n);

    return 0;
}