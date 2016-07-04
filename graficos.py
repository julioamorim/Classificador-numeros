#!/usr/bin/env python3

import plotly
from plotly.graph_objs import Scatter, Layout
from sys import argv, exit

fname = ""
try:
    fname = argv[1]
except:
    print("Digite o nome do arquivo de dados")
    exit(0)

f = open(fname)

epocas = []
mse = []

for line in f:
    s = line[:-1].split(',')
    epocas.append(int(s[0]))
    mse.append(float(s[1]))

plotly.offline.plot({"data":[Scatter(x=epocas, y=mse)],"layout":Layout(title="Aprendizagem: " + fname)})
