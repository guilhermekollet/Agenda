#include "Agenda.hpp"

Agenda::Agenda(string nome)
{

    _nome = nome;

}

Agenda::~Agenda()
{

}

string Agenda::getNome()
{

return _nome;
}

string Agenda::getLista()
{

    stringstream ss;
    
    for(int i = 0; i < _Lista.size(); i++)
    {

        ss << _Lista.at(i).getContato() << endl;

    }

return ss.str();
}