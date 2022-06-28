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

};

#endif