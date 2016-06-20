#!/usr/bin/env python3

fw = open('validacao/validacao.convertida.tes','w')

fw.write('899 64 10\n') # 3823 linhas, 64 entradas, 10 saídas (0-10, formato FANN)

f = open('validacao/validacao.tes')

for line in f:
    item = line[:-1].split(',')
    for k in range(64): # Para cada entrada
        fw.write(item[k] + ' ') # Muda o separador de ',' pra ' '
    n = int(item[64])
    fw.write('\n')
    for i in range(10):
        if i == n:
            fw.write('1 ')
        else:
            fw.write('0 ')
    fw.write('\n')


