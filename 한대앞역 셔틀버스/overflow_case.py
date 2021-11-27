T = 6 * 3600

N = 20000
M = 20000

with open('overflow_case.in', 'w') as f:
    f.write("{}\n".format(N))
    for _ in range(N):
        f.write("{} {} {} {}\n".format(T // 3600, T % 3600 // 60, T % 60, 100))
        T += 1
    
    f.write("{}\n".format(M))
    for _ in range(M):
        f.write("{} {} {} {}\n".format(T // 3600, T % 3600 // 60, T % 60, 0))
        T += 1