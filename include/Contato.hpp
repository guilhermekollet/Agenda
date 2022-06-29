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
    string _name;
    string _lastName;
    string _ddd;
    string _number;
    bool _state;

    public:
    Contato();
    Contato(string name, string lastName, string ddd, string number);
    ~Contato();
    bool thereData();
    string getContato();
    string getName();
    string getLastName();
    string getDDD();
    string getNumber();
    bool setNome(string name);
    bool setSobrenome(string lastName);
    bool setDDD(string ddd);
    bool setNumero(string number);

};

#endif