#include "iter.hpp"

void doubleInt(int &a) { a = a * 2; }
void doubleString(std::string &b) { b = b + b; }

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int lenArr = sizeof(arr) / sizeof(arr[0]);
    iter(arr, lenArr, doubleInt);
    for (int i = 0; i < lenArr; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    std::string brr[] = {"Hello", "World"};
    int lenBrr = sizeof(brr) / sizeof(brr[0]);
    iter(brr, lenBrr, doubleString);
    for (int i = 0; i < lenBrr; i++) {
        std::cout << "brr[" << i << "] = " << brr[i] << std::endl;
    }
    return 0;
}
