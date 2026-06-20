import random

N = random.randint(1, 12)

edges = []

for v in range(2, N + 1):
    p = random.randint(1, v - 1)
    edges.append((p, v))

# 頂点番号をシャッフル
labels = list(range(1, N + 1))
random.shuffle(labels)
 
def relabel(x):
    return labels[x - 1]

edges = [(relabel(u), relabel(v)) for u, v in edges]

# 辺順もシャッフル
random.shuffle(edges)

print(N)
for u, v in edges:
    print(u, v)
