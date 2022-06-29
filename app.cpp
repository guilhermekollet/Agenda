#include "include/Conta.hpp"
#include <iostream>

using namespace std;

bool app()
{
    Conta exe;

    bool loop = true;
    bool loop2 = true;
    
    do
    {
        int value;
        cout << endl;
        cout << "1) Agenda" << endl;
        cout << "2) Sair" << endl;
        cout << endl << "> ";
        cin >> value;

        system("clear||cls");

        switch(value)
        {
            case 1:
                do
                {

                    int value2;
                    cout << endl;
                    cout << "1) Abrir Agenda" << endl;
                    //cout << "2) Nova Agenda" << endl;
                    //cout << "3) Deletar Agenda" << endl;
                    cout << "2) Propriedades" << endl;
                    cout << "3) Sair" << endl;
                    cout << endl << "> ";
                    cin >> value2;

                    system("clear||cls");

                    switch(value2)
                    {
                        case 1:

                            system("clear||cls");

                            exe.loadAgenda("../database/agenda.csv");
                            cout << endl << exe.exibeAgenda() << endl;
                        break;

                        case 2:

                            if(exe.getAgenda() == nullptr)
                            {
                                
                                cout << "Nao ha nenhuma agenda aberta nessa conta ainda." << endl;
                                
                            }
                            else
                            {

                                cout << exe.getAgenda()->getProperties() << endl;

                            }


                        break;

                        case 3:

                            loop = true;
                            loop2 = false;
                        break;

                    }

                }
                while(loop2);

            break;

            case 2:
                exit(0);
                loop = false;
            break;
            
            default:
                break;
        }

    } 
    while(loop);
    




}

int main()
{

    app();

return 0;
}