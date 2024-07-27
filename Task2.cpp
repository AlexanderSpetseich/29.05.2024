#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void fillArray(std::vector<std::vector<int>>& array, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Введите элемент [" << i + 1 << "][" << j + 1 << "]: ";
            std::cin >> array[i][j];
        }
    }
}

std::vector<int> findCommon(const std::vector<int>& a, const std::vector<int>& b) {
    std::vector<int> common;
    std::set_intersection(a.begin(), a.end(), b.begin(), b.end(), std::back_inserter(common));
    return common;
}

std::vector<int> findUnique(const std::vector<int>& a, const std::vector<int>& b) {
    std::set<int> uniqueSet(a.begin(), a.end());
    uniqueSet.insert(b.begin(), b.end());

    std::vector<int> unique(uniqueSet.begin(), uniqueSet.end());
    return unique;
}

std::vector<int> findNegative(const std::vector<int>& input) {
    std::set<int> negativeSet;
    for (int num : input) {
        if (num < 0) {
            negativeSet.insert(num);
        }
    }
    return std::vector<int>(negativeSet.begin(), negativeSet.end());
}

int main() {
    setlocale(LC_ALL, "RU");
    int rowsA, colsA, rowsB, colsB, rowsC, colsC;

    std::cout << "Введите количество строк для массива A: ";
    std::cin >> rowsA;
    std::cout << "Введите количество столбцов для массива A: ";
    std::cin >> colsA;
    std::vector<std::vector<int>> A(rowsA, std::vector<int>(colsA));
    fillArray(A, rowsA, colsA);

    std::cout << "Введите количество строк для массива В: ";
    std::cin >> rowsB;
    std::cout << "Введите количество столбцов для массива В: ";
    std::cin >> colsB;
    std::vector<std::vector<int>> B(rowsB, std::vector<int>(colsB));
    fillArray(B, rowsB, colsB);

    std::cout << "Введите количество строк для массива С: ";
    std::cin >> rowsC;
    std::cout << "Введите количество столбцов для массива С: ";
    std::cin >> colsC;
    std::vector<std::vector<int>> C(rowsC, std::vector<int>(colsC));
    fillArray(C, rowsC, colsC);

    // Создаем одномерные массивы для A, B и C
    std::vector<int> flatA, flatB, flatC;

    for (const auto& row : A) flatA.insert(flatA.end(), row.begin(), row.end());
    for (const auto& row : B) flatB.insert(flatB.end(), row.begin(), row.end());
    for (const auto& row : C) flatC.insert(flatC.end(), row.begin(), row.end());

    // Сортировка массивов для корректной работы set_intersection
    std::sort(flatA.begin(), flatA.end());
    std::sort(flatB.begin(), flatB.end());
    std::sort(flatC.begin(), flatC.end());

    // Найдем общие значения для A, B, C
    std::vector<int> commonAB = findCommon(flatA, flatB);
    std::vector<int> commonABC = findCommon(commonAB, flatC);

    // Найдем уникальные значения для A, B, C
    std::vector<int> uniqueABC = findUnique(flatA, flatB);
    uniqueABC = findUnique(uniqueABC, flatC);

    // Найдем общие значения для A и C
    std::vector<int> commonAC = findCommon(flatA, flatC);

    // Найдем отрицательные значения для A, B, C без повторений
    std::vector<int> allNumbers = flatA;
    allNumbers.insert(allNumbers.end(), flatB.begin(), flatB.end());
    allNumbers.insert(allNumbers.end(), flatC.begin(), flatC.end());
    std::vector<int> negativeNumbers = findNegative(allNumbers);

    // Вывод результатов
    std::cout << "Общие значения для A, B, C: ";
    for (int num : commonABC) std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Уникальные значения для A, B, C: ";
    for (int num : uniqueABC) std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Общие значения для A и C: ";
    for (int num : commonAC) std::cout << num << " ";
    std::cout << std::endl;

    std::cout << "Отрицательные значения для A, B, C без повторений: ";
    for (int num : negativeNumbers) std::cout << num << " ";
    std::cout << std::endl;

    return 0;
}