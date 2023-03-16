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
    while(left < size) {       //意味着有孩子节点
        
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


void heapSort(int nums[]) {

    //for (int i = 0; i < n; i++) {
        //一个一个添加形成堆
        //heapInsert(nums,i);
    //}


    for (int i = n - 1; i >= 0; i--) {
        heapify(nums, i, n);
    }

    int size = n;    //定义size为堆的大小
    swap(nums, 0, --size);
    while (size > 0) {
        //堆顶和最后一个元素交换后在变成堆
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

    //排序前打印
    printNums(test, n);
    heapSort(test);

    //排序后打印
    printNums(test, n);

    return 0;
}
