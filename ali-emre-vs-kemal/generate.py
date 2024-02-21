import os
from random import randint

generator_file = "generator"
solution_file = "solution"

MAX_ROOK = 6
MAX_BISHOP = 6

# t_n_p_s = [[20, 100, 2500, 2], [20, 100, 3000, 3], [20, 100, 4000, 3], [20, 100, 4500, 2]]
t_n_p_s = [[5, 500, 90000, 2], [5, 500, 100000, 3], [5, 500, 102000, 3], [5, 500, 105000, 2]]
tnprbs = []
for t, n, p, i in t_n_p_s:
    while i:
        tnprbs.append([t, n, p, randint(1, MAX_ROOK), randint(1, MAX_BISHOP)])
        print(tnprbs[-1])
        i -= 1

if __name__ == "__main__":
    os.system(f"g++-13 {generator_file}.cpp -o {generator_file}")
    os.system(f"g++-13 {solution_file}.cpp -o {solution_file}")
    print("Compiled cpp files")

    for i in range(len(tnprbs)):
        t, n, p, r, b = tnprbs[i]
        tnum = str(i).zfill(2)
        input_file = f"tests/input/input{tnum}.txt"
        output_file = f"tests/output/output{tnum}.txt"

        random_seed = randint(1, 100000)

        # generate
        os.system(f"./{generator_file} {random_seed} {t} {n} {p} {r} {b} > ./{input_file}")
        os.system(f"./{solution_file} < ./{input_file} > ./{output_file}")

        print(f"Generated and solved test #{tnum}")
