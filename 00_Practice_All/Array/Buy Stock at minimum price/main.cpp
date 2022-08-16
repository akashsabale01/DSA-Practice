#include <iostream>

using namespace std;

int bestPriceToBuyStock(int input1, int input2[])
{
    // Approach 1 - Prefix sum array
    // int prefixSum[input1];

    // prefixSum[0] = input2[0];

    // int minValue = (prefixSum[0] >= 0) ? 0 : prefixSum[0];
    // for (int i = 1; i < input1; i++)
    // {
    //     prefixSum[i] = input2[i] + prefixSum[i - 1];
    //     if (prefixSum[i] < minValue)
    //         minValue = prefixSum[i];
    // }

    // return minValue;

    // Optimal Approach  - Using Pointer
    int price = 0, min = 0;
    for (int i = 0; i < input1; i++)
    {
        price += input2[i];
        if (price < min)
            min = price;
    }
    return min;
}

int main()
{

    int input1 = 5;
    int input2[] = {-39957, -17136, 35466, 21820, -26711};
    // int input2[] = {-39957, -17136, 1, 2, -26711};

    // int input1 = 9;
    // int input2[] = {-4527, -1579, -38732, -43669, -9287, -48068, -30293, -30867, 18677};
    // int input1 = 3;
    // // int input2[] = {-3, 10, -15};
    // int input2[] = {10, 20, 30};

    int result = bestPriceToBuyStock(input1, input2);

    cout << endl;
    cout << "Result = " << result;
    cout << endl;

    return 0;
}

// https://prepinsta.com/cognizant-genc-elevate/coding-questions/
// Question 1
// You want to buy a particular stock at its lowest price and sell it later at its highest price. Since the stock market is unpredictable, you steal the price plans of a company for this stock for the next N days.
// Find the best price you can get to buy this stock to achieve maximum profit.

// Note: The initial price of the stock is 0.

// Input Specification:
// Input1: N, number of days
// Input2: Array representing change in stock price for the day.

// Output Specification:
// Your function must return the best price to buy the stock at.