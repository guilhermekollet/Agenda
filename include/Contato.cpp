#include "Contato.hpp"

Contato::Contato()
{

    _name = "";
    _lastName = "";
    _ddd = "";
    _number = "";
    _state = false;

}

Contato::Contato(string name, string lastName, string ddd, string number)
{

    _name = name;
    _lastName= lastName;
    _ddd = ddd;
    _number = number;
    _state = true;

}

Contato::~Contato()
{

}

bool Contato::thereData()
{

    if(_name != "" && _ddd != "" && _number != "") _state = true;

return _state;
}

string Contato::getContato()
{

    stringstream ss;
    ss << "Nome: " << _name << " | Sobrenome: " << _lastName << " | DDD: (" << _ddd << ") | Numero: " << _number;

return ss.str();
}

string Contato::getName()
{

return _name;    
}

string Contato::getNumber()
{

return _number;
}

string Contato::getLastName()
{

return _lastName;
}

string Contato::getDDD()
{

return _ddd;
}

bool Contato::setNome(string nome)
{

    if(nome != "")
    {

        _name = nome;

    return true;
    }

return false;
}

bool Contato::setSobrenome(string lastName)
{

    if(lastName != "")
    {

        _lastName = lastName;

    return true;
    }

return false;
}

bool Contato::setDDD(string ddd)
{

    if(ddd != "")
    {

        _ddd = ddd;

    return true;
    }

return false;
}

bool Contato::setNumero(string number)
{

    if(number != "")
    {

        _number = number;

    return true;
    }

return false;
}