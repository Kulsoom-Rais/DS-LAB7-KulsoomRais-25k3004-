#include <iostream>
using namespace std;

int comparisons = 0;

void displayPart(int arr[], int left, int right)
{
    for (int i = left; i <= right; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void merge(int arr[], int left, int mid, int right)
{
    int temp[8];
    int i = left, j = mid + 1, k = left;

    cout << "\nLeft subarray: ";
    displayPart(arr, left, mid);

    cout << "Right subarray: ";
    displayPart(arr, mid + 1, right);

    while (i <= mid && j <= right)
    {
        comparisons++;

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

    cout << "Merged subarray: ";
    displayPart(arr, left, right);
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {1299, 499, 2499, 799,
                 499, 1599, 999, 299};
    int n = 8;

    cout << "Original prices: ";
    displayPart(arr, 0, n - 1);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted prices: ";
    displayPart(arr, 0, n - 1);

    cout << "Total element comparisons: "
         << comparisons << endl;

    return 0;
}
