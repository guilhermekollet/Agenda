#include "Contato.hpp"

Contato::Contato()
{

    _nome = "Unknown";
    _sobrenome = "Unknown";
    _ddd = "Unknown";
    _numero = "Unknown";
    _state = false;

}

Contato::~Contato()
{

}

bool Contato::thereData()
{

    if(_nome != "Unknown" && _ddd != "Unknown" && _numero != "Unknown") _state = true;

return _state;
}

string Contato::getContato()
{

    stringstream ss;
    ss << "Nome: " << _nome << " | Sobrenome: " << _sobrenome << " | DDD: (" << _ddd << ") | Numero: " << _numero;

return ss.str();
}
