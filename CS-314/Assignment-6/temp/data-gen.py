import time
import random


with open('data.txt', 'w+') as f:
	for i in range(10000000):
		f.write('{0:.6f}\n'.format(random.uniform(1.0, 2.0)))

print('done');
