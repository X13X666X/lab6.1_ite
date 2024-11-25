#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void CreateRandomArray(int* arr, int size, int start, int end) {
    for (int i = 0; i < size; i++) {
        arr[i] = start + rand() % (end - start + 1);
    }
}

void PrintArray(int* arr, int size) {
    cout << "[ ";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << ", ";
    }
    cout << " ]" << endl;
}

int CountCriteriaElements(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] % 2 != 0) {
            count++;
        }
    }
    return count;
}

int SumCriteriaElements(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] % 2 != 0) {
            sum += arr[i];
        }
    }
    return sum;
}

void ReplaceCriteriaElementsWithZero(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] % 2 != 0) {
            arr[i] = 0;
        }
    }
}

int main() {
    srand((unsigned)time(0));
    const int size = 23;
    const int rangeStart = -25, rangeEnd = 80;
    int arr[size];

    CreateRandomArray(arr, size, rangeStart, rangeEnd);

    cout << "Original array:" << endl;
    PrintArray(arr, size);

    int count = CountCriteriaElements(arr, size);
    int sum = SumCriteriaElements(arr, size);
    ReplaceCriteriaElementsWithZero(arr, size);

    cout << "Count of positive odd elements: " << count << endl;
    cout << "Sum of positive odd elements: " << sum << endl;

    cout << "Modified array:" << endl;
    PrintArray(arr, size);

    return 0;
}