import os
import time
import numpy as np
import csv


def compile(f, o, std='c++14'):
    cmd = 'g++ {0}.cpp -lm -O{1} -std={2} -o bin/{0}'.format(f, o, std)
    print(cmd)
    os.system(cmd)


def measure(writer, f, label, x, cnt=10):
    x = int(x)
    print(f, x)
    t = []
    for i in range(cnt):
        # time.sleep(1)
        res = os.popen('./bin/{} {}'.format(f, x)).read()
        t.append(list(map(int, res.split())))
    t = np.asarray(t)
    print(t)
    avg = t.mean(0)
    print(avg)
    covar = t.std(0)/avg
    print(covar)
    for i in range(t.shape[1]):
        writer.writerow([f, x, label[i]]+list(t[:, i]))
    return t


def test_all(o):
    with open('raw_O{}.csv'.format(o), 'w') as f:
        writer = csv.writer(f)
        writer.writerow(['program', 'x', 'task']+list(map(lambda x: 'T'+str(x+1), range(10))))
        compile('vector', o)
        # compile('vector_reserve')
        compile('array', o)
        for i in [1e6, 3e6, 1e7, 3e7, 1e8]:
            measure(writer, 'vector', ['push', 'set', 'access'], i)
            # measure(writer, 'vector_reserve', ['push', 'set', 'access'], i)
            measure(writer, 'array', ['set1', 'access1', 'set2', 'access2'], i)

        compile('vector_insert', o)
        for i in [1e4, 3e4, 5e4, 1e5]:
            measure(writer, 'vector_insert', ['insert', 'erase'], i)


os.makedirs('bin', exist_ok=True)
test_all(0)
test_all(2)
