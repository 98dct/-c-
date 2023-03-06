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

    int less = l - 1;  //<����߽�
    int more = r;      //>���ұ߽�

    while (l < more) {     //l��ʾ��ǰλ��

        if (nums[l] < nums[r]) {

            //<�����ƣ�������ǰλ�ú�С������һ��λ�ã���ǰλ��++
            less++;
            swap(nums,l,less);
            l++;
        }
        else if (nums[l] > nums[r]) {
            //>�����ƣ�������ǰλ�úʹ�����ǰһ��λ�ã���ǰλ�ò���
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

    //˼·����patition�ֳ�<������������>��
    //Ȼ��ݹ�С��������������ֱ��l==r
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

    //����ǰ��ӡ
    printNums(test, n);

    quickSort(test, 0, n - 1);

    //������ӡ
    printNums(test, n);

    return 0;
}