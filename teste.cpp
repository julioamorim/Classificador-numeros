#include <iostream>
#include <fstream>
#include <cstdio>
#include <climits>
#include <fann.h>

using namespace std;

int main(){
    struct fann *ann = fann_create_from_file("number_classify.net");

    float entradas[64], saida_real[10];
    ifstream arq("input/teste/optdigits2.tes");
    int linhas, n_entradas, n_saidas;
    arq >> linhas >> n_entradas >> n_saidas;

    for(int k = 0; k < 10; k++){
        for(int i = 0; i < n_entradas; i++)
            arq >> entradas[i];
        for(int i = 0; i < n_saidas; i++)
            arq >> saida_real[i];

        float * saidas = fann_run(ann, entradas);
        cout << "Posicao\tSaída:\tValor real:\n";
        for(int i = 0; i < n_saidas; i++){
            cout << i << '\t' << saidas[i] << '\t' << saida_real[i] << '\n';
        }
    }
    fann_destroy(ann);
    return 0;
}
