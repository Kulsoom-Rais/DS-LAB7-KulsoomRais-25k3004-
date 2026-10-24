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

    int totalPasses = 0;
    int temp = maxValue;

    while (temp > 0)
    {
        totalPasses++;
        temp /= 10;
    }

    int exp = 1;

    for (int pass = 1; pass <= totalPasses; pass++)
    {
        countingSort(arr, n, exp);

        cout << "After digit pass " << pass << ": ";
        display(arr, n);

        exp *= 10;
    }

    return totalPasses;
}

int main()
{
    int arr[] = {94, 802, 7, 1234, 56, 321, 405, 18};
    int n = 8;

    cout << "Original tracking IDs: ";
    display(arr, n);

    int passes = radixSort(arr, n);

    cout << "\nFinal sorted tracking IDs: ";
    display(arr, n);

    cout << "Total number of passes: "
         << passes << endl;

    return 0;
}
