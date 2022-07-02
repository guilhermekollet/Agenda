#include "Conta.hpp"

Conta::Conta()
{

    agenda = nullptr;

}

Conta::~Conta()
{

    if(agenda != nullptr) delete agenda;
    
    for(int i=0; i < _lista.size(); i++)
    {
        delete &_lista.at(i);
    }

}

Agenda *Conta::getAgenda()
{

return agenda;
}

bool Conta::newAgenda()
{

    if(agenda == nullptr)
    {

        agenda = new Agenda();
        cout << "Agenda " << agenda->getAgendaName() << " Criada!" << endl;
        _lista.push_back(*agenda);

    return true;
    }

return false;
}

bool Conta::deleteAgenda()
{

    if(agenda != nullptr)
    {

        delete agenda;
        cout << "Agenda " << agenda->getAgendaName() << " Apagada!" << endl;

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
        _lista.push_back(*agenda);
        agenda->getAgendaFromCSV(stream.str());

        read.close();

    return(stream.str() != "");
    }

return false;
}

string Conta::exibeAgenda()
{

return agenda->getLista();
}

string Conta::exibeAgendas()
{

    stringstream ss;
    for(int i=0; i < _lista.size(); i++)
    {

        ss << _lista.at(i).getProperties() << endl;

    }

return ss.str();
}