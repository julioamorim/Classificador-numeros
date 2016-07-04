/* ***************************************************************************
 * @Autores:     Rafael Hengen Ribeiro, Regis Thiago Feyh, Ricardo Parizotto *
 * @Matrículas:  1311100016,            1311100012,        1311100007        *
 * @E-mails:     rafaelhr.ribeiro@gmail.com, registhiagofeyh@gmail.com       *
 *               ricardo.dparizotto@gmail.com                                *
 * --------------------------------------------------------------------------*
 * Executa o teste de uma rede neural dado o arquivo .net como parâmetro     *
 * --------------------------------------------------------------------------*/


#include "defs.hh"


using namespace std;

float bin_to_float(float * vetor, int tamanho){
    int max = 0;
    for(int i = 1; i < tamanho; i++){
        if(vetor[i] > vetor[max])
            max = i;
    }
    return float(max);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "ERRO: Informe no argumento o caminho da rede!" << endl;
        return 0;
    }

    struct fann *ann = fann_create_from_file(argv[1]);

    float entradas[64], saida_real[10];
    ifstream arq("input/teste/teste.convertido.tes");
    int linhas, n_entradas, n_saidas;
    arq >> linhas >> n_entradas >> n_saidas;

    int erros =0, acertos = 0;
    for(int k = 0; k < linhas; k++){
        for(int i = 0; i < n_entradas; i++)
            arq >> entradas[i];
        for(int i = 0; i < n_saidas; i++)
            arq >> saida_real[i];

        float * saidas = fann_run(ann, entradas);
        cout << "Posicao\tSaída:\tValor real:\n";
        for(int i = 0; i < n_saidas; i++){
            cout << i << '\t' << saidas[i] << '\t' << saida_real[i] << '\n';
        }
        float fsaida=bin_to_float(saidas,n_saidas),  freal = bin_to_float(saida_real, n_saidas);
        cout << "Saída: " << fsaida << "\tValor real: " << freal << ' ' << ((fsaida != freal) ? " ERROU!" : "") << '\n';
        if(fsaida == freal)
            acertos++;
        else
            erros++;
    }
    cout << "Erros: " << erros << "/" << linhas << '\n';
    cout << "Taxa de acerto: " <<  float(acertos)/linhas*100 << "% \n";
    fann_destroy(ann);
    return 0;
}
