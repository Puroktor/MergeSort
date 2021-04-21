#include <iostream>
#include <algorithm>

using std::cout;
using std::sort;
using std::endl;

int* merge(int *c, int *d, int n) {
    int i = 0, j = 0;
    int* b = new int[n];
    while (i < n / 2 && j < n - n / 2)
    {
        if (*(c + i) < *(d + j))
        {
            *(b + i + j) = *(c + i);
            i++;
        }
        else
        {
            *(b + i + j) = *(d + j);
            j++;
        }
    }
    while (i < n / 2) {
        *(b + i + j) = *(c + i);
        i++;
    }
    while (j < n - n / 2) {
        *(b + i + j) = *(d + j);
        j++;
    }

    delete[] c;
    delete[] d;
    return b;
}

int* mergeSort(int *arr, int n)
{
    if (n == 1)
        return new int[1]{ *arr };

    int *c = mergeSort(arr,n/2);
    int *d = mergeSort(arr+n/2, n - n / 2);

    return merge(c,d,n);
}

bool checkIsCorrect(int *first, int *second, int n)
{
    for (int i = 0; i < n; i++) 
        if (first[i] != second[i]) 
            return false;
        
    return true;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 1e5;
    for (int i = 0; i < 10; i++) {
        int* arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; i++)
            arr[i] = rand();
        int* sorted = mergeSort(arr, n);
        sort(arr, arr + n);

        if (checkIsCorrect(arr, sorted, n))
        {
            cout << "Отсортирован правильно" << endl;
        }
        else
        {
            cout << "-25 баллов"<<endl;
        }

        delete[] arr;
        delete[] sorted;
    }
}