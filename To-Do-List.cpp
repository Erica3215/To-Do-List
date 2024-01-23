// To-Do-List.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

   

void showTasks(const std::vector<std::string>& tasks)
{
    setlocale(LC_ALL, "Russian");
    std::cout << "Список Дел :" << std::endl;
    for (int i = 0; i < tasks.size(); ++i)
    {
        std::cout << i + 1 << ". " << tasks[i] << std::endl;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    std::vector<std::string> tasks;
    std::string task;
    char choice;

    // Load existing tasks from file
    std::ifstream inputFile("tasks.txt");
    while (getline(inputFile, task))
    {
        tasks.push_back(task);
    }
    inputFile.close();

    do
    {
        std::cout << "А - Добавить задачу" << std::endl;
        std::cout << "П - Просмотр Задач" << std::endl;
        std::cout << "У - Уйти" << std::endl;
        std::cout << "Что вы хотите сделать: ";
        std::cin >> choice;

        switch (choice)
        {
        case 'А':
        case 'а':
            std::cout << "Введите задачу:";
            std::cin.ignore(); // Clears the input buffer
            getline(std::cin, task);
            tasks.push_back(task);
            break;
        case 'П':
        case 'п':
            showTasks(tasks);
            break;
        }
    } while (choice != 'У' && choice != 'У');

    // Save tasks to file
    std::ofstream outputFile("tasks.txt");
    for (const auto& t : tasks)
    {
        outputFile << t << std::endl;
    }
    outputFile.close();

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
