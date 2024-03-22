#include <iostream>
#include <vector>
#include <iomanip>

inline void outputArray(const std::vector<double>& c_vArr)
{
    for (const double& c_dArrayNumber : c_vArr)
        std::cout << std::fixed << std::setprecision(3) << c_dArrayNumber << " ";
    std::cout << std::endl;
}

inline void processingVector(std::vector<double>& vArr, const int c_iTemp)
{
    outputArray(vArr);
    double dSumArithmeticAverage = 0;
    for (double& dArrayNumber : vArr)
        dSumArithmeticAverage += dArrayNumber;
    vArr.push_back(dSumArithmeticAverage);
    vArr.push_back(dSumArithmeticAverage / c_iTemp);
    outputArray(vArr);
    dSumArithmeticAverage = 0;
    for (double& dArrayNumber : vArr)
        dSumArithmeticAverage += dArrayNumber;
    for (double& dArrayNumber : vArr)
        if (dArrayNumber == 0.000)
            dArrayNumber = dSumArithmeticAverage / vArr.size();
    outputArray(vArr);
}


int main()
{
    int iInputStartArrSize = 0;
    std::cin >> iInputStartArrSize;
    std::vector<double> vArr(iInputStartArrSize);
    for (double& dArrayNumber : vArr)
        std::cin >> dArrayNumber;
    std::cout << iInputStartArrSize << std::endl;
    processingVector(vArr, iInputStartArrSize);
    int iChoiceAction = 0;
    std::cin >> iChoiceAction;
    while (iChoiceAction != 0)
    {
        if (iChoiceAction == 1)
        {
            double dNewElement = 0;
            std::cin >> dNewElement;
            vArr.push_back(dNewElement);
            std::cout << "+: " << vArr.size() << std::endl;
        }
        if (iChoiceAction == 2)
            if (!vArr.empty())
            {
                vArr.pop_back();
                std::cout << "-: " << vArr.size() << std::endl;
            }
        processingVector(vArr, vArr.size());
        std::cin >> iChoiceAction;
    }
    return 0;
}
