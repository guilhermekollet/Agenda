#include "Agenda.hpp"

Agenda::Agenda(string nome)
{

    _nome = nome;

}

Agenda::~Agenda()
{

}

string Agenda::getNomeAgenda()
{

return _nome;
}

int Agenda::getSizeAgenda()
{

return _Lista.size();
}

string Agenda::getLista()
{

    stringstream ss;
    
    for(int i = 0; i < _Lista.size(); i++)
    {

        if(_Lista.at(i).getNome() == "")
        {

            ss << _Lista.at(i).getSobrenome() << " | +" << _Lista.at(i).getDDD() << _Lista.at(i).getNumero() << endl;
        
        }
        else if(_Lista.at(i).getNome() == "" && _Lista.at(i).getSobrenome() == "")
        {

            ss << "+" << _Lista.at(i).getDDD() << _Lista.at(i).getNumero() << endl;
        
        }
        else if(_Lista.at(i).getNome() != "" && _Lista.at(i).getSobrenome() == "")
        {

            ss << _Lista.at(i).getNome() << " | +" << _Lista.at(i).getDDD() << _Lista.at(i).getNumero() << endl;
        
        }
        else
        {

            ss << _Lista.at(i).getNome() << " " << _Lista.at(i).getSobrenome()  << " | +" << _Lista.at(i).getDDD() << _Lista.at(i).getNumero() << endl;

        }

    }

return ss.str();
}

bool Agenda::newContactFromCSV(string csv)
{

    if(csv != "")
    {
        
        stringstream buffer(csv);
        string auxStream;

        getline(buffer, auxStream, ',');
        
        int qtd = stoi(auxStream);

        do
        {

            for(int i = 0; i < qtd; i++)
            {
                Contato *c = new Contato();
                
                getline(buffer, auxStream, ':');
                c->setNome(auxStream);

                getline(buffer, auxStream, ':');
                c->setSobrenome(auxStream);

                getline(buffer, auxStream, ':');
                c->setDDD(auxStream);

                getline(buffer, auxStream, ',');
                c->setNumero(auxStream);

                addContact(*c);
                delete c;
            }

        }
        while(buffer.good());

    }

return false;
}

bool Agenda::addContact(Contato &contato)
{

    if(contato.getNumero() != "")
    {

        _Lista.push_back(contato);

    return true;
    }

}