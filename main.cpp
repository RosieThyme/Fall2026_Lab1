#include <iostream>


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

    return 0;
}