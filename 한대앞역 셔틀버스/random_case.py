import random

TIME_MIN = 6 * 3600
TIME_MAX = 22 * 3600 + 59 * 60 + 59

for i in range(0, 10):
    N = 20000
    M = 20000
    T1 = [random.randint(TIME_MIN, TIME_MAX) for _ in range(N)]
    T2 = [random.randint(TIME_MIN, TIME_MAX) for _ in range(M)]

    T1.sort()
    T2.sort()

    with open('random_case{}.in'.format(i), 'w') as f:
        f.write("{}\n".format(N))

        for T in T1:
            f.write("{} {} {} {}\n".format(T // 3600, T % 3600 // 60, T % 60, random.randint(0, 100)))

        f.write("{}\n".format(M))

        for T in T2:
            f.write("{} {} {} {}\n".format(T // 3600, T % 3600 // 60, T % 60, random.randint(0, 100)))