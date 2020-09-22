#include "Datagrama.h"
#include <iostream>
#include <string>
using namespace std;


Datagrama::Datagrama(int origem, int destino, int ttl, string dado) :
origem (origem), destino (destino), ttl (ttl), dado (dado)
{
}

Datagrama::~Datagrama()
{
}

