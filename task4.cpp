#include <iostream>
using namespace std;

int partitionCount = 0;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high, int n)
{
    int pivot = arr[high];
    int i = low - 1;

    partitionCount++;

    cout << "\nPivot: " << pivot
         << ", boundaries: [" << low
         << ", " << high << "]" << endl;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    cout << "Array after partition: ";
    display(arr, n);

    return i + 1;
}

void quickSort(int arr[], int low, int high, int n)
{
    if (low < high)
    {
        int pi = partition(arr, low, high, n);

        quickSort(arr, low, pi - 1, n);
        quickSort(arr, pi + 1, high, n);
    }
}

int main()
{
    int arr[] = {40, 20, 70, 10, 60, 30, 50};
    int n = 7;

    cout << "Original array: ";
    display(arr, n);

    quickSort(arr, 0, n - 1, n);

    cout << "\nSorted array: ";
    display(arr, n);

    cout << "Total partition operations: "
         << partitionCount << endl;

    return 0;
}
