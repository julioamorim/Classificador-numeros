from sys import argv


label = []
data = []
print(argv[1])
file = open(argv[1]).read()
lines = file.split('\n')

for line in lines:
	s = line.split(',')
	if len(s) == 2:
		label.append(s[0])
		data.append(float(s[1]))

print(label)
print(data)
