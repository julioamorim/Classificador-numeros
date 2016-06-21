#include <fann.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "validacao.hpp"

using namespace std;

int main(int argc, char *argv[])
{
        
    unsigned int neuronios_escondidos;
    if (argc > 1)
        neuronios_escondidos = atoi(argv[1]);
    else {
        cout << "ERRO: Informe no argumento do programa quantos neurônios escondidos existirão!" << endl;
        return 0;
    }

    cout << "Neurônios escondidos: " << neuronios_escondidos << endl;
    
    ofstream output;
    ostringstream convert, best;
    
    convert << "./estatisticas/hidden_" << neuronios_escondidos << ".txt";
    best    << "./melhores/number_classify.best_h" << neuronios_escondidos << ".net";
    
    string file(convert.str());
    cout << "Resultados salvos em: " << file << endl;
    
    output.open(file.c_str());

    const unsigned int entradas = 64;
    const unsigned int saidas = 10;
    const unsigned int camadas = 3;
    const float erro_maximo = 0.0f;
    const unsigned int max_epocas = 50000;
    const unsigned int epocas_entre_impressoes = 100;
    const unsigned int epocas_entre_testes = 100;

    unsigned int cont = 0;
    float melhor_erro = 1.0f;

    struct fann *rede = fann_create_standard(camadas, entradas,
            neuronios_escondidos,saidas);

    fann_set_activation_function_hidden(rede, FANN_SIGMOID);
    fann_set_activation_function_output(rede, FANN_SIGMOID);

    fann_set_training_algorithm(rede, FANN_TRAIN_INCREMENTAL);
    fann_set_learning_rate(rede, 0.05f);


    while(cont < max_epocas){
        fann_train_on_file(rede, "input/treinamento/optdigits2.tra", epocas_entre_testes,
            epocas_entre_impressoes, erro_maximo);

        float erro = validacao(rede);
        if(erro < melhor_erro){
            fann_save(rede, best.str().c_str());
            melhor_erro = erro;
        }

        cont+= epocas_entre_testes;
        cout << cont << " Épocas. Erro: " << erro << endl;
        output << cont << "," << erro << endl;
    }

    output.close();
    fann_destroy(rede);

    return 0;
}
