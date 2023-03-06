#include <iostream>
#include<string>
using namespace std;

int n = 0;

void swap(int nums[],int i,int j){

    nums[i] = nums[i] ^ nums[j];
    nums[j] = nums[i] ^ nums[j];
    nums[i] = nums[i] ^ nums[j];

}

void bubbleSort(int nums[],int n) {
    

    //思路：每一轮选出最大值，放在数组最右边
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (nums[j] > nums[j+1]) {
                swap(nums, j, j+1);
            }
        }
    }
}

void printNums(int nums[],int n) {

    
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    cout << endl;

}


int main() {

    
    int test[12] = {4,2,7,10,3,9,100,64,77,92,101,50};
    n = sizeof(test) / sizeof(test[0]);

    //排序前打印
    printNums(test, n);

    bubbleSort(test,n);

    //排序后打印
    printNums(test, n);

    return 0;
}