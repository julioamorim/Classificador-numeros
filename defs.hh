#ifndef DEFS_INCLUDED
#define DEFS_INCLUDED

#include <fann.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>


#define SIZE_OUT 10


const unsigned int entradas = 64;
const unsigned int saidas = 10;
const unsigned int camadas = 3;
const float erro_maximo = 0.0f;
const unsigned int max_epocas = 10000;
const unsigned int epocas_entre_impressoes = 100;
const unsigned int epocas_entre_testes = 100;


#endif
