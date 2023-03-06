#include <iostream>
#include<string>
using namespace std;

int n = 0;

void swap(int nums[], int i, int j) {

    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;

}

void printNums(int nums[], int n) {

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

}


void chooseSort(int nums[], int n) {

    //˼·����i = 0λ�ÿ�ʼ��ÿ��ѡ��һ����С��λ�÷���iλ��
    //����i��
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            minIndex = nums[j] < nums[minIndex]?j:minIndex;
        }
        swap(nums, i, minIndex);
    }
   
}

int main() {


    int test[12] = {4,2,7,10,3,9,100,64,77,92,101,50};
    n = sizeof(test) / sizeof(test[0]);

    //����ǰ��ӡ
    printNums(test, n);

    chooseSort(test, n);

    //������ӡ
    printNums(test, n);

    return 0;
}