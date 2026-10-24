#include <iostream>
using namespace std;

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int getMax(int arr[], int n)
{
    int maximum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maximum)
        {
            maximum = arr[i];
        }
    }

    return maximum;
}

void countingSort(int arr[], int n, int exp, int pass)
{
    int count[10] = {0};
    int* output = new int[n];

    
    for (int i = 0; i < n; i++)
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    cout << "\n Pass " << pass << " " << endl;

    cout << "Frequency count: ";
    displayArray(count, 10);

    
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    cout << "Cumulative count: ";
    displayArray(count, 10);

    
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;

        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    cout << "Output array: ";
    displayArray(output, n);

    
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    cout << "Array copied back: ";
    displayArray(arr, n);

    delete[] output;
}

void radixSort(int arr[], int n)
{
    int maximum = getMax(arr, n);
    int pass = 1;

    
    for (int exp = 1; maximum / exp > 0; exp *= 10)
    {
        countingSort(arr, n, exp, pass);
        pass++;
    }

    cout << "\nTotal digit passes: " << pass - 1 << endl;
}

int main()
{
    int arr[] = {
        4721, 305, 472, 89, 3005, 721,
        1000, 305, 9999, 42, 870, 100
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    displayArray(arr, n);

    radixSort(arr, n);

    cout << "\nFinal sorted array: ";
    displayArray(arr, n);

    return 0;
}
