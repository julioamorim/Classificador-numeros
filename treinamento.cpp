/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Executa o treinamento da rede neural, dado o número de neurônios          *
 * escondidos como parâmetro                                                 *
 * --------------------------------------------------------------------------*/


#include "defs.hh"
#include "validacao.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    ofstream output;
    ostringstream convert, best;
        
    unsigned int neuronios_escondidos;
    unsigned int cont = 0;
    float melhor_erro = 1.0f;

    if (argc > 1)
        neuronios_escondidos = atoi(argv[1]);
    else {
        cout << "ERRO: Informe no argumento do programa quantos neurônios escondidos existirão!" << endl;
        return 0;
    }
    
    
    convert << "./estatisticas/hidden_" << neuronios_escondidos << ".txt";
    best    << "./melhores/number_classify.best_h" << neuronios_escondidos << ".net";
    
    string file(convert.str());
    cout << "Resultados salvos em: " << file << endl;
    
    output.open(file.c_str());

    struct fann *rede = fann_create_standard(camadas, entradas,
            neuronios_escondidos,saidas);

    fann_set_activation_function_hidden(rede, FANN_SIGMOID);
    fann_set_activation_function_output(rede, FANN_SIGMOID);        

    fann_set_training_algorithm(rede, FANN_TRAIN_INCREMENTAL);      //define o tipo da rede ~backpropagation
    fann_set_learning_rate(rede, 0.05f);                             //ajusta a taxa de aprendizagem


    struct fann_train_data * train = fann_read_train_from_file("input/treinamento/optdigits2.tra");
    struct fann_train_data * validation = fann_read_train_from_file("input/validacao/validacao.convertida.tes");

    while(cont < max_epocas){      
        fann_shuffle_train_data(train);   //randomiza os dados de treinamento
        fann_train_on_data(rede, train, epocas_entre_testes, 0, erro_maximo);
   
        float erro = fann_test_data(rede, validation);
        if(erro < melhor_erro){
            fann_save(rede, best.str().c_str());
            melhor_erro = erro;
        }

        cont+= epocas_entre_testes;
        cout << cont << " Épocas. MSE: " << erro << ". Taxa de erro: " 
            << (validacao(rede)*100.) << "% " << endl;
        output << cont << "," << erro << endl;
    }

    output.close();
    fann_destroy(rede);

    return 0;
}
