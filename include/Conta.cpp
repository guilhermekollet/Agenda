#include "Conta.hpp"

Conta::Conta()
{

    agenda = nullptr;

}

Conta::~Conta()
{

    if(agenda != nullptr) delete agenda;
    agenda = nullptr;

}

bool Conta::newAgenda()
{

    if(agenda == nullptr)
    {

        agenda = new Agenda();
        cout << "Agenda " << agenda->getNome() << " Criada!" << endl;

    return true;
    }

return false;
}

bool Conta::deleteAgenda()
{

    if(agenda != nullptr)
    {

        delete agenda;
        cout << "Agenda " << agenda->getNome() << " Apagada!" << endl;

    return true;
    }

return false;
}

bool Conta::loadAgenda(string url)
{

    if(url != "")
    {
        ifstream read(url);
        string auxStream;
        stringstream stream;


        do
        {

            getline(read, auxStream, ',');
            cout << auxStream << endl;
            if(auxStream == "true") cout << "Há uma agenda!" << endl;
            stream << auxStream;

        } while (read.good());
        cout << stream.str() << endl;
        read.close();

    return(stream.str() != "");
    }

return false;
}