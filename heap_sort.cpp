#include <iostream>
#include<string>
using namespace std;

int n = 0;

void swap(int nums[], int i, int j) {

    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

//
void heapInsert(int nums[],int index) {

    while (nums[index] > nums[(index - 1) / 2]) {

        swap(nums, index, (index - 1) / 2);
        index = (index - 1) / 2;
    }
}

void heapify(int nums[], int index, int size) {
    int left = 2 * index + 1;
    while(left < size) {       //��ζ���к��ӽڵ�
        
        int largest = left + 1 < size && nums[left + 1] > nums[left] ? left + 1 : left;
        largest = nums[largest] > nums[index] ? largest : index;
        if (largest == index) {
            break;
        }
        swap(nums, largest, index);
        index = largest;
        left = 2 * index + 1;
    }
}


void heapSort(int nums[], int l, int r) {

    //for (int i = 0; i < n; i++) {
        //һ��һ������γɶ�
        //heapInsert(nums,i);
    //}


    for (int i = n - 1; i >= 0; i--) {
        heapify(nums, i, n);
    }

    int size = n;    //����sizeΪ�ѵĴ�С
    swap(nums, 0, --size);
    while (size > 0) {
        //�Ѷ������һ��Ԫ�ؽ������ڱ�ɶ�
        heapify(nums, 0, size);
        swap(nums, 0, --size);
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
    heapSort(test, 0, n - 1);

    //������ӡ
    printNums(test, n);

    return 0;
}