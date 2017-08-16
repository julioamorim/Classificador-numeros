# Rede neural para classificação de números manuscritos
## Dependências
Biblioteca FANN (Fast Artificial Neural Network)
Para a compilação e utilização do programa é necessário ter a biblioteca FANN instalada. Segue abaixo um tutorial de instalação em várias distribuições linux.

Ubuntu/Linux Mint/Debian
<pre>sudo apt-get install libfann{2,-dev}</pre>

Fedora 21-22/Red Hat/CentOS
<pre>su -c "yum install fann fann-devel"</pre>

Fedora 23-24
<pre>sudo dnf install fann fann-devel</pre>

(Opcional) Plotly - Geração de gráficos com python
Para a geração de gráficos é necessário ter um interpretador python com a versão >= 2.7, o programa pip
e a biblioteca plotly, cuja instalação é descrita abaixo.

### Instalação do pip
#### Fedora 21-22/Red Hat/CentOS
Python 2.7: <pre>su -c "yum install python-pip"</pre>
Python 3: <pre>su -c "yum install python3-pip"</pre>
#### Fedora 23-24
Python 2.7: <pre>sudo dnf install python-pip</pre>
Python 3: <pre>sudo dnf install python3-pip</pre>
#### Ubuntu/Linux Mint/Debian
Python 2.7: <pre>sudo apt-get install python-pip</pre>
Python 3: <pre>sudo apt-get install python3-pip</pre>

### Instalação do Plotly
Python 2.7: <pre>sudo pip install plotly</pre>
Python 3: <pre>sudo pip3 install plotly</pre>

## Compilação
<pre>make</pre>

## Treinamento da rede
<pre>./treinamento <i>&lt;n&gt;</i></pre>
Onde <i>n</i> é o número de neurônios da camada escondida da rede.

## Teste
<pre>./teste number_classify.best_h<i>&lt;n&gt;</i>.net</pre>
Onde <i>n</i> é o número de neurônios da camada escondida da rede.
