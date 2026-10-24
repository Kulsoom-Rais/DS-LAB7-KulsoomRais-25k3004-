#include <iostream>
using namespace std;

int mergeCount = 0;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int left, int mid, int right, int n)
{
    int temp[8];
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    mergeCount++;

    cout << "After merge " << mergeCount << ": ";
    display(arr, n);
}

void mergeSort(int arr[], int left, int right, int n)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, n);
        mergeSort(arr, mid + 1, right, n);

        merge(arr, left, mid, right, n);
    }
}

int main()
{
    int arr[] = {78, 45, 92, 63, 45, 88, 51, 70};
    int n = 8;

    cout << "Original array: ";
    display(arr, n);

    mergeSort(arr, 0, n - 1, n);

    cout << "\nSorted marks: ";
    display(arr, n);

    cout << "Total merge operations: "
         << mergeCount << endl;

    return 0;
}
