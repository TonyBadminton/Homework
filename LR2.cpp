#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
class Vector
{
public:
    Vector(int size);

    inline double calculateNorm();

    inline void inputValues();

    inline void displayValues();

    inline void add(Vector first, Vector second);

    inline void subtract(Vector first, Vector second);

    inline void calculateScalarProduct(Vector first, Vector second);
    inline double calculateAngle(Vector a, Vector b);
    inline bool areParallel(Vector a, Vector b);
    inline void printComparison(Vector a, Vector b);
    inline void multiplyByScalar(Vector vec, double scalar);
    inline double fourth();
    inline void first(Vector a, Vector b);
    inline void second(Vector vec, double scalar);
    inline void third(Vector vec, double scalar);
    inline void elementwiseMultiply(Vector vec, double scalar);

private:
    std::vector<double> values;
    int size;
};

Vector::Vector(int size1) : values(size1), size(size1) {}

inline void Vector::printComparison(Vector a, Vector b) {
    int help = 1;
    bool bRes = false;
    if (a.calculateNorm() > b.calculateNorm()) 
    {
        bRes = true;
        std::cout << "norma(Vector1) > norma(Vector2)" << std::endl;
    }
    if (a.calculateNorm() < b.calculateNorm()) 
    {
        bRes = true;
        std::cout << "norma(Vector1) < norma(Vector2)" << std::endl;
    }
    if (!bRes)
        std::cout << "norma(Vector1) = norma(Vector2)" << std::endl;

    if (help == 0)
    {
        if (areParallel(a, b))
            std::cout << "Vectors are parallel." << std::endl;
        else 
            std::cout << "Vectors are not parallel." << std::endl;
    }
}

inline void Vector::inputValues()
{
    for (int i = 0; i < values.size(); i++)
    {
        std::cin >> values[i] ;
    }
}

inline void Vector::displayValues()
{
    for (const int& c_num : values)
    {
        std::cout << c_num  << " ";
    }
}

inline void Vector::add(Vector a, Vector b)
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = a.values[i] + b.values[i];
        std::cout << values[i] << " ";
    }
    std::cout << "\n";
}

inline void Vector::first(Vector a, Vector b) {
    double dotProduct = 0;
    for (int i = 0; i < values.size(); i++) {
        dotProduct += a.values[i] * b.values[i];
    }
    std::cout << dotProduct << "\n";
}





inline void Vector::second(Vector vec, double scalar) {
    for (int i = 0; i < values.size(); i++) {
        values[i] = vec.values[i] * scalar;
    }
}

inline void Vector::third(Vector vec, double scalar) {
    for (int i = 0; i < values.size(); i++) {
        values[i] = vec.values[i] * scalar;
    }
}

inline double Vector::fourth() {
    double norm = 0;
    for (int i = 0; i < values.size(); i++) {
        norm += pow(values[i], 2);
    }
    norm = sqrt(norm);
    return norm;
}






inline void Vector::elementwiseMultiply(Vector vec, double scalar)
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = vec.values[i] * scalar;
        std::cout << values[i] << " ";
    }
    std::cout << "\n";
}

inline void Vector::subtract(Vector a, Vector b)
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = a.values[i] - b.values[i];
        std::cout << values[i] << " ";
    }
    std::cout << "\n";
}

inline void Vector::calculateScalarProduct(Vector a, Vector b)
{
    double dotProduct = 0;

    for (int i = 0; i < values.size(); i++)
    {
        dotProduct += a.values[i] * b.values[i];
    }

    std::cout << dotProduct << "\n";
}

inline void Vector::multiplyByScalar(Vector vec, double scalar)
{
    for (int i = 0; i < values.size(); i++)
    {
        values[i] = vec.values[i] * scalar;
        std::cout << values[i] << " ";
    }
    std::cout << "\n";
}





inline double Vector::calculateNorm()
{
    double norm = 0;

    for (int i = 0; i < values.size(); i++)
    {
        norm += pow(values[i], 2);
    }

    norm = sqrt(norm);

    return norm;
}


inline double Vector::calculateAngle(Vector a, Vector b) {
    double dotProduct = 0;
    double normA = a.calculateNorm();
    double normB = b.calculateNorm();
    for (int i = 0; i < values.size(); i++) {
        dotProduct += a.values[i] * b.values[i];
    }
    return acos(dotProduct / (normA * normB));
}




inline bool Vector::areParallel(Vector a, Vector b) {
    double angle = calculateAngle(a, b);
    // Пороговый угол для считать их параллельными, можно настраивать
    double threshold = 0.01;
    return angle < threshold;
}

int main()
{
    int size;

    double scalar;

    std::cin >> size;

    Vector vector1(size);
    Vector vector2(size);
    Vector vector3(size);

    vector1.inputValues();
    vector2.inputValues();

    std::cin >> scalar;

    std::cout << "vector1= ";
    vector1.displayValues();
    std::cout << "norma= " << vector1.calculateNorm() << "\n";

    std::cout << "vector2= ";
    vector2.displayValues();
    std::cout << "norma= " << vector2.calculateNorm() << "\n";



    std::cout << "summa= ";
    vector3.add(vector1, vector2);

    std::cout << "raznost= ";
    vector3.subtract(vector1, vector2);

    std::cout << "scalar= ";
    vector3.calculateScalarProduct(vector1, vector2);

    std::cout << "mult chislo * Vector1= ";
    vector3.multiplyByScalar(vector1, scalar);

    std::cout << "mult chislo * Vector2= ";
    vector3.elementwiseMultiply(vector2, scalar);

    vector3.printComparison(vector1, vector2);

    return 0;
}