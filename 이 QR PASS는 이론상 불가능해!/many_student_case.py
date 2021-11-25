N = 10
M = 10
Q = 10001

with open('many_student_case.in', 'w') as f:
    f.write("{} {}\n".format(N, M))
    for i in range(N):
        for j in range(M):
            if i == 0 and j == 0:
                f.write("2")
            elif i == 9 and j == 9:
                f.write("2")
            elif j % 2 == 0:
                f.write("0")
            elif j % 4 == 1 and i == 9:
                f.write("0")
            elif j % 4 == 3 and i == 0:
                f.write("0")
            else:
                f.write("1")
        f.write("\n")

    f.write("{}\n".format(Q))

    for i in range(Q-1):
        f.write("{} 1558 0\n".format(20200000 + i))
    f.write("{} 1612 1\n".format(20200000))