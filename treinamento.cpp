#include <fann.h>

int main()
{
    const unsigned int entradas = 64;
    const unsigned int saidas = 10;
    const unsigned int camadas = 3;
    const unsigned int neuronios_escondidos = 30;
    const float erro_maximo = 0.000001f;
    const unsigned int max_epocas = 5000;
    const unsigned int epocas_entre_testes = 100;

    struct fann *ann = fann_create_standard(camadas, entradas,
            neuronios_escondidos,saidas);

    fann_set_activation_function_hidden(ann, FANN_SIGMOID);
    fann_set_activation_function_output(ann, FANN_SIGMOID);

    fann_train_on_file(ann, "input/treinamento/optdigits2.tra", max_epocas,
            epocas_entre_testes, erro_maximo);

    fann_save(ann, "number_classify.net");

    fann_destroy(ann);

    return 0;
}
