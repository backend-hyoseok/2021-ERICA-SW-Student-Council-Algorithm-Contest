N = 100
M = 100
Q = 100000

with open('large_case.in', 'w') as f:
    f.write("{} {}\n".format(N, M))
    
    for i in range(N):
        for j in range(M):
            if i == 0 and j == 0:
                f.write("2")
            elif i == 0 and j == 99:
                f.write("2")
            elif j % 2 == 0:
                f.write("0")
            elif j % 4 == 1 and i == 99:
                f.write("0")
            elif j % 4 == 3 and i == 0:
                f.write("0")
            else:
                f.write("1")
        f.write("\n")

    f.write("{}\n".format(Q))
    
    for i in range(Q):
        f.write("20200000 0900 {}\n".format(i % 2))