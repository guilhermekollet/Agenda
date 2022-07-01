#ifndef _CONTA_HPP
#define _CONTA_HPP

#include "Contato.hpp"
#include "Agenda.hpp"
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

class Conta
{

    private:
    Agenda *agenda;
    vector<Agenda> _lista;

    public:
    Conta();
    ~Conta();

    Agenda *getAgenda();

    bool newAgenda();
    bool deleteAgenda();
    bool loadAgenda(string url);
    string exibeAgenda();

};

#endif