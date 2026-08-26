#include <iostream>
int recursiveFunctionForward(int arr[],int max);
int recursiveFunctionBackward(int arr[],int Val);
int count = 0;


int main() {
    const int MAX_SIZE = 10;
    int signals[MAX_SIZE];
    int Num;
    int maxVal, maxIndex;

    std::cout<<"Enter number of signals that will be input"<<std::endl;
    std::cin>>Num;

    for (int i = 0; i < Num; ++i) {
        std::cout<<"Enter signal: "<<std::endl;
        std::cin>>signals[i];
    }

    maxVal = signals[0];
    for (int i = 1; i < Num; ++i) {
        if (signals[i] > maxVal) {
            maxVal = signals[i];
            maxIndex = i;
        }
    }
    std::cout<<"Strongest signal: "<<maxVal<<" at index "<<maxIndex<<std::endl;

    //just to see outputs and check
      for (int i = 0; i < Num; ++i) {
          std::cout<<signals[i]<<" ";
      }

    //this is what the code should do
    for (int i = (Num); i >= 0; --i) {
        if (i <= maxIndex) {
            std::cout<<signals[i]<<" ";
        }
    }
    std::cout<<std::endl;
    recursiveFunctionBackward(signals,maxIndex);
    std::cout<<std::endl;
    std::cout<<"Cont #: "<<count<<std::endl;

    return 0;
}

//recusive function for backtracking
int recursiveFunctionForward(int arr[],int max)
{
    //recursive case
    //if (n <= 0)
    if (max >= 0)
    {
        recursiveFunctionForward(arr,max-1);
        std::cout<<arr[max]<<" ";
        count++;
    }
    //base case
    return count;
}
int recursiveFunctionBackward(int arr[],int Val)
{
    //base case
    //if (n <= 0)
    if (Val == 0)
    {
        return count;
    }
    //recursive case
    recursiveFunctionBackward(arr,Val-1);
    std::cout<<arr[Val]<<" ";
    count++;

}
