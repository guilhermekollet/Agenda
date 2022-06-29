#include "Contato.hpp"

Contato::Contato()
{

    _nome = "";
    _sobrenome = "";
    _ddd = "";
    _numero = "";
    _state = false;

}

Contato::~Contato()
{

}

bool Contato::thereData()
{

    if(_nome != "" && _ddd != "" && _numero != "") _state = true;

return _state;
}

string Contato::getContato()
{

    stringstream ss;
    ss << "Nome: " << _nome << " | Sobrenome: " << _sobrenome << " | DDD: (" << _ddd << ") | Numero: " << _numero;

return ss.str();
}

string Contato::getNome()
{

return _nome;    
}

string Contato::getNumero()
{

return _numero;
}

string Contato::getSobrenome()
{

return _sobrenome;
}

string Contato::getDDD()
{

return _ddd;
}

bool Contato::setNome(string nome)
{

    if(nome != "")
    {

        _nome = nome;

    return true;
    }

return false;
}

bool Contato::setSobrenome(string sobrenome)
{

    if(sobrenome != "")
    {

        _sobrenome = sobrenome;

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

bool Contato::setNumero(string numero)
{

    if(numero != "")
    {

        _numero = numero;

    return true;
    }

return false;
}