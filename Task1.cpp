#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    setlocale(LC_ALL, "RU");
    const int students = 5;
    std::vector<std::string> surnames(students);

    std::cout << "Введите " << students << " фамилий студентов на английском:" << std::endl;
    for (int i = 0; i < students; ++i) {
        std::cout << "Фамилия " << (i + 1) << ": ";
        std::getline(std::cin, surnames[i]);
    }

    // Сортировка фамилий по алфавиту
    std::sort(surnames.begin(), surnames.end());

    std::cout << "\nСфамилии студентов в алфавитном порядке:" << std::endl;
    for (const auto& surname : surnames) {
        std::cout << surname << std::endl;
    }

    return 0;
}