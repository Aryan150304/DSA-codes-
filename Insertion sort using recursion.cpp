// insertion sort does not compare element by element it compares directly and inserts directly
#include <iostream>
using namespace std;

void sortarr(int *arr, int n)
{
    if (n == 1 || n == 0)
    {
        return;
    }
    sortarr(arr, n - 1);
    int temp = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > temp)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = temp;
}
int main()
{
    int arr[5] = {10, 9, 8, 7, 0};
    sortarr(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
