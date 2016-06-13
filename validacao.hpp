#include <fstream>
#include <fann.h>

using std::ifstream;

float bin_to_float(float * vetor, int tamanho){
    int max = 0;
    for(int i = 1; i < tamanho; i++){
        if(vetor[i] > vetor[max])
            max = i;
    }
    return float(max);
}

float validacao(struct fann * rede) {
    float entradas[64], saida_real[10];
    int linhas, n_entradas, n_saidas;
    ifstream arq("input/teste/optdigits2.tes");
    arq >> linhas >> n_entradas >> n_saidas;

    int erros =0, acertos = 0;
    for(int k = 0; k < linhas; k++){
        for(int i = 0; i < n_entradas; i++)
            arq >> entradas[i];
        for(int i = 0; i < n_saidas; i++)
            arq >> saida_real[i];

        float * saidas = fann_run(rede, entradas);
        float fsaida=bin_to_float(saidas,n_saidas),  freal = bin_to_float(saida_real, n_saidas);
        if(fsaida == freal)
            acertos++;
        else
            erros++;
    }
    return float(acertos)/linhas;
}
