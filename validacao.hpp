#include "defs.hh"


using std::ifstream;

float bin_to_float(float * out_real, float * out_nn){
    float sum = 0;
    for(int i = 0; i < SIZE_OUT; i++)
        sum+=(out_real[i] - out_nn[i])*(out_real[i] - out_nn[i]);
    return sum/SIZE_OUT;
}

float validacao(struct fann * rede) {
    float entradas[64], saida_real[10];
    int linhas, n_entradas, n_saidas;
    ifstream arq("input/validacao/validacao.convertida.tes");
    arq >> linhas >> n_entradas >> n_saidas;
    
    float erro_quadrado_medio =0;

    for(int k = 0; k < linhas; k++){
        for(int i = 0; i < n_entradas; i++)
            arq >> entradas[i];
        for(int i = 0; i < n_saidas; i++)
            arq >> saida_real[i];

        float * saidas = fann_run(rede, entradas);              //calcula as saídas da rede para validação
      
        erro_quadrado_medio+=bin_to_float(saida_real, saidas);
        
    }
    return erro_quadrado_medio/linhas;
}
