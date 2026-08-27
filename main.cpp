#include <iostream>
#include <limits>
#include <utility>

template <typename T>
T templateInput()
{
    T tInput;
    bool validInput = false;
    //as long as the user has not entered a valid input
    while (!validInput)
    {
        //input validation for the number
        std::cin >> tInput;
        //if the user does not enter a number, prompt the user to enter the correct information
        if (std::cin.fail())
        {
            std::cout<< "enter in a numeric value:"<< std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
        //if the user enters the correct information exit the loop
        else
        {
            validInput = true;
        }
    }
    //return user input
    return tInput;
}
int count = 0;

void recFuncBack(int arr[],int Val)
{
    //base case, checks to see if the Value is negative
    if (Val < 0) return;
    //recursive case that prints out the values and increases the count by one
    std::cout<<arr[Val]<<" ";
    recFuncBack(arr,Val-1);
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
    //variables for input
    const int MAX_SIZE = 10;
    int signals[MAX_SIZE];
    int Num;
    int maxVal;
    int maxIndex = 0;

    //prompt the user for input for the appropriate size of the signal array
    std::cout<<"Enter number of signals that will be input"<<std::endl;
    Num = templateInput<int>();
    //
    for (int i = 0; i < Num; ++i)
    {
        std::cout<<"Enter signal: "<<std::endl;
        signals[i] = templateInput<int>();
    }
    //Look for the strongest signal in the Array
    maxVal = signals[0];
    for (int i = 1; i < Num; ++i)
    {
        if (signals[i] > maxVal)
        {
            maxVal = signals[i];
            maxIndex = i;
        }
    }
    //prints out the strongest signal in the array
    std::cout<<"Strongest signal: "<<maxVal<<" at index "<<maxIndex<<std::endl;
    // sort into a separate array
    int sortedSignals[MAX_SIZE];
    for (int i = 0; i < Num; ++i)
        sortedSignals[i] = signals[i];
    sortArray(sortedSignals, Num);
    //prints out the array from the start of the array to the strongest signal
    std::cout<<"Forward path (start to strongest)"<<std::endl;
    for (int i = 0; i < Num; ++i)
    {
        std::cout<<sortedSignals[i]<<" ";
    }
    std::cout<<std::endl;
    //prints out the path from the strongest signal to the start
    std::cout<<"Return path (backtracking):"<<std::endl;
    recFuncBack(sortedSignals,Num-1);
    std::cout<<std::endl<<"Recursive calls made: "<<count<<std::endl;
    return 0;
}
