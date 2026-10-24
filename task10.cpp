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
    {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    cout << "Frequency count: ";
    display(count, 10);

    
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    cout << "Cumulative count: ";
    display(count, 10);

    
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    cout << "Output array: ";
    display(output, n);

    
    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    cout << "Array after copying back: ";
    display(arr, n);

    delete[] output;
}

int radixSort(int arr[], int n)
{
    int maxValue = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > maxValue)
            maxValue = arr[i];
    }

    
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
        cout << "\n PASS "
             << pass << " \n";

        cout << "Original array: ";
        display(arr, n);

        cout << "Digit position: " << exp << endl;

        countingSort(arr, n, exp);

        exp *= 10;
    }

    return totalPasses;
}

int main()
{
    int accessionNumbers[] = {
        7314, 314, 731, 34, 3147,
        147, 47, 7314, 4, 314
    };

    int n = sizeof(accessionNumbers) /
            sizeof(accessionNumbers[0]);

    cout << "Original accession numbers: ";
    display(accessionNumbers, n);

    int passes = radixSort(accessionNumbers, n);

    cout << "\nFinal sorted accession numbers: ";
    display(accessionNumbers, n);

    cout << "Maximum digit passes required: "
         << passes << endl;

    return 0;
}
