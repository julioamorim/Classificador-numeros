#include <fann.h>

int main()
{
    const unsigned int entradas = 64;
    const unsigned int saidas = 10;
    const unsigned int camadas = 3;
    const unsigned int neuronios_escondidos = 55;
    const float erro_maximo = 0.0f;
    const unsigned int max_epocas = 50000;
    const unsigned int epocas_entre_impressoes = 100;

    struct fann *rede = fann_create_standard(camadas, entradas,
            neuronios_escondidos,saidas);

    fann_set_activation_function_hidden(rede, FANN_SIGMOID);
    fann_set_activation_function_output(rede, FANN_SIGMOID);

    fann_set_training_algorithm(rede, FANN_TRAIN_INCREMENTAL);
    fann_set_learning_rate(rede, 0.05f);

    fann_train_on_file(rede, "input/treinamento/optdigits2.tra", max_epocas,
            epocas_entre_impressoes, erro_maximo);

    fann_save(rede, "number_classify.net");

    fann_destroy(rede);

    return 0;
}
