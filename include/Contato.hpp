#ifndef _CONTATO_HPP
#define _CONTATO_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Contato
{

    private:
    string _nome;
    string _sobrenome;
    string _ddd;
    string _numero;
    bool _state;

    public:
    Contato();
    ~Contato();
    bool thereData();
    string getContato();
    string getNome();
    string getSobrenome();
    string getDDD();
    string getNumero();
    bool setNome(string nome);
    bool setSobrenome(string sobrenome);
    bool setDDD(string ddd);
    bool setNumero(string numero);

};

#endif