#include <iostream>
#include "second_task.h"

int main()
{
    A test(1, 2);
    A test1(3, 3);
    B testB(1, 2);

    //Сравнение между A
    std::cout << (test <= test1) << (test >= test1) << (test == test1) << (test != test1) << '\n';

    //Сравнение между A и B
    std::cout << (test >= testB) << (test <= testB) << (test != testB) << (test == testB) << '\n';

    std::cout << "All tests passed successfully!" << '\n';

    return 0;
}
