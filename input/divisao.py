from random import shuffle

data = ''
with open('teste/optdigits.tes', 'r') as file:
    data = file.read()

line = data.split("\n")[:-1]
shuffle(line)

teste = open('teste/teste.tes', 'w')
validacao = open('validacao/validacao.tes', 'w')

metade = len(line)

for i in range(0, len(line)//2):
	teste.write(line[i] + '\n')

for i in range(len(line)//2, len(line)):
	validacao.write(line[i] + '\n')