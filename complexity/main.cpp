# include <iostream>

// Example for a function with constant complexity O(1)
void print(int* arr, int n)
{
    std::cout << (arr[0] + arr[1]) * (arr[0] - arr[1]) << std::endl;
}


// Example for a function with linear complexity O(n)
void sum(int* arr, int n)
{
    int sum = 0;
    int counter2 = 0;
    for(int i=0; i<n; ++i)
    {  
        sum += arr[i];
        counter2++;
    }
    std::cout << sum << std::endl;
}

// Example for a function with quadratic complexity O(n^2) - Bubble sort
void sort(int* arr, int n)
{
    for(int i=0; i<n - 1; ++i)
    {  
        for(int j=0; j<n - i -1; j++)
        {  
            if(arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for(int i = 0; i<n; i++)
    {  
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Example for a function with logarithmic complexity O(logn)
void rec(int* arr, int n)
{
    if(n <= 1)
    {
        std::cout << arr[0];
    }

    rec(arr, n/2);
}

// Example for a function with quadratic memory M(n^2)
void memory(int* arr, int n)
{
    int* arr2 = new int[n^2];
    int* arr3 = new int[100*n];

    for(int i=0;i<n;i++)
    {
        arr2[i] = arr[i];
    }

    delete[] arr2;
    delete[] arr3;
}

int main()
{
    int arr[3] = {1,3,2};
    sum(arr, 3);
    sort(arr, 3);

    return 0;

}