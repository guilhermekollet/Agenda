#include "include/Conta.hpp"
#include <iostream>

using namespace std;

bool app()
{

    Conta exe;
    exe.newAgenda();
    exe.deleteAgenda();
    exe.loadAgenda("../database/agenda.csv");

}

int main()
{

    app();

return 0;
}