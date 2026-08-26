#include <iostream>
int recursiveFunctionBackward(int arr[],int Val);
int count = 0;

void recFuncBack(int arr[],int Val) {
    if (Val < 0) return;

    std::cout<<arr[Val]<<" ";
    recFuncBack(arr,Val-1);
    ++count;
}

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
    std::cout<<"Forward path (start to strongest)"<<std::endl;

    for (int i = 0; i < Num; ++i) {
        std::cout<<signals[i]<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Return path (backtracking):"<<std::endl;
    recFuncBack(signals,Num-1);
    std::cout<<std::endl<<"Recursive calls made: "<<count<<std::endl;
    return 0;
}

