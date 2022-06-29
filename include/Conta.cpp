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
        cout << "Agenda " << agenda->getNomeAgenda() << " Criada!" << endl;

    return true;
    }

return false;
}

bool Conta::deleteAgenda()
{

    if(agenda != nullptr)
    {

        delete agenda;
        cout << "Agenda " << agenda->getNomeAgenda() << " Apagada!" << endl;

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

        string nomeAgenda;
        int qtdContatos;

        do
        {

            getline(read, auxStream, ',');
            
            if(auxStream == "true")
            {

                getline(read, nomeAgenda, ',');
                getline(read, auxStream, ',');
                qtdContatos = stoi(auxStream);
                getline(read, auxStream, '\r');
                stream << qtdContatos << "," << auxStream;

            }
            else return false;
            

        } while (read.good());

        agenda = new Agenda(nomeAgenda);
        agenda->newContactFromCSV(stream.str());

        read.close();

    return(stream.str() != "");
    }

return false;
}

string Conta::exibeAgenda()
{

return agenda->getLista();
}