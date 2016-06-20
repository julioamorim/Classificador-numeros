#include <fann.h>
#include <iostream>
#include "validacao.hpp"

using namespace std;

int main()
{
    const unsigned int entradas = 64;
    const unsigned int saidas = 10;
    const unsigned int camadas = 3;
    const unsigned int neuronios_escondidos = 55;
    const float erro_maximo = 0.0f;
    const unsigned int max_epocas = 20000;
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
            fann_save(rede, "number_classify.best.net");
            melhor_erro = erro;
        }

        cont+= epocas_entre_testes;
        cout << cont << " Épocas. Erro: " << erro << endl;
    }

    fann_destroy(rede);

    return 0;
}
