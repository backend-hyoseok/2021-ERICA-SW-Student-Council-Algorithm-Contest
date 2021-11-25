import random

N = 100
M = 100

A = [[0 for _ in range(M)] for _ in range(N)]

Q = 100000

count = 0
while count < 100:
    x = random.randint(0, 99)
    y = random.randint(0, 99)

    if A[x][y] == 0:
        open_count = 0
        if x > 1 and A[x-1][y] == 0:
            open_count += 1
        if x < N - 1 and A[x+1][y] == 0:
            open_count += 1
        if y > 1 and A[x][y-1] == 0:
            open_count += 1
        if y < M - 1 and A[x][y+1] == 0:
            open_count += 1

        if open_count == 4:
            A[x][y] = 2
            count += 1

Q_list = [[random.randint(20200000, 20200999), random.randint(900, 2200), random.randint(0, 99)] for _ in range(Q)]

Q_list.sort(key=lambda q: q[1])

with open('random_case.in', 'w') as f:
    f.write("{} {}\n".format(N, M))
    
    for i in range(N):
        for j in range(M):
            f.write("{}".format(A[i][j]))
        f.write("\n")

    f.write("{}\n".format(Q))

    for q in Q_list:
        f.write("{} {:0>4} {}\n".format(q[0], q[1], q[2]))

