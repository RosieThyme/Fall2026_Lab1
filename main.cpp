#include <iostream>
#include <limits>
#include <utility>

template <typename T>
T templateInput()
{
    T tInput;
    bool validInput = false;
    while (!validInput)
    {
        std::cin >> tInput;
        if (std::cin.fail())
        {
            std::cout << "enter in a numeric value:" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            validInput = true;
        }
    }
    return tInput;
}

int count = 0;

void recFuncBack(int arr[], int Val)
{
    if (Val < 0) return;
    std::cout << arr[Val] << " ";
    recFuncBack(arr, Val - 1);
    ++count;
}

void sortArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIdx = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        std::swap(arr[minIdx], arr[i]);
    }
}

int main()
{
    const int MAX_SIZE = 10;
    int signals[MAX_SIZE];
    int Num;
    int maxVal, maxIndex;

    std::cout << "Enter number of signals that will be input" << std::endl;
    Num = templateInput<int>();

    for (int i = 0; i < Num; ++i)
    {
        std::cout << "Enter signal: " << std::endl;
        signals[i] = templateInput<int>();
    }

    maxVal = signals[0];
    maxIndex = 0;
    for (int i = 1; i < Num; ++i)
    {
        if (signals[i] > maxVal)
        {
            maxVal = signals[i];
            maxIndex = i;
        }
    }
    std::cout << "Strongest signal: " << maxVal << " at index " << maxIndex << std::endl;

    std::cout << "Forward path (start to strongest)" << std::endl;
    for (int i = 0; i < Num; ++i)
    {
        std::cout << signals[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Return path (backtracking):" << std::endl;
    recFuncBack(signals, Num - 1);
    std::cout << std::endl << "Recursive calls made: " << count << std::endl;

    int sortedSignals[MAX_SIZE];
    for (int i = 0; i < Num; ++i)
        sortedSignals[i] = signals[i];

    sortArray(sortedSignals, Num);

    std::cout << "Sorted ascending: " << std::endl;
    for (int i = 0; i < Num; ++i)
        std::cout << sortedSignals[i] << " ";
    std::cout << std::endl;

    count = 0;
    std::cout << "Sorted descending (via recursion): " << std::endl;
    recFuncBack(sortedSignals, Num - 1);
    std::cout << std::endl << "Recursive calls made: " << count << std::endl;

    return 0;
}