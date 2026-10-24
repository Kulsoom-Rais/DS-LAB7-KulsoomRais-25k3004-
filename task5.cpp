#include <iostream>
using namespace std;

int comparisons = 0;
int partitionCount = 0;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int partition(int arr[], int low, int high, int n)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    partitionCount++;

    cout << "\nPivot: " << pivot
         << ", boundaries: [" << low
         << ", " << high << "]" << endl;

    while (true)
    {
        while (i <= high)
        {
            comparisons++;

            if (arr[i] > pivot)
                break;

            i++;
        }

        while (j > low)
        {
            comparisons++;

            if (arr[j] <= pivot)
                break;

            j--;
        }

        if (i >= j)
            break;

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }

    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    cout << "Array after partition: ";
    display(arr, n);

    return j;
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
    int arr[] = {55, 25, 75, 15, 65, 35, 45};
    int n = 7;

    cout << "Original array: ";
    display(arr, n);

    quickSort(arr, 0, n - 1, n);

    cout << "\nSorted array: ";
    display(arr, n);

    cout << "Total element comparisons: "
         << comparisons << endl;

    cout << "Total partition operations: "
         << partitionCount << endl;

    return 0;
}
