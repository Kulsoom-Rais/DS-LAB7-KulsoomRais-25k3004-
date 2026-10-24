#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void countingSort(int arr[], int n, int exp)
{
    int* output = new int[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
}

int radixSort(int arr[], int n)
{
    int maxValue = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > maxValue)
            maxValue = arr[i];

    int passes = 0;

    while (maxValue > 0)
    {
        passes++;
        maxValue /= 10;
    }

    int exp = 1;

    for (int pass = 1; pass <= passes; pass++)
    {
        countingSort(arr, n, exp);

        cout << "After pass " << pass << ": ";
        display(arr, n);

        exp *= 10;
    }

    return passes;
}

int main()
{
    int arr[] = {91, 8, 1024, 56, 305, 7, 120};
    int n = 7;

    cout << "Original array: ";
    display(arr, n);

    int passes = radixSort(arr, n);

    cout << "\nSorted array: ";
    display(arr, n);

    cout << "Total passes: " << passes << endl;

    return 0;
}
