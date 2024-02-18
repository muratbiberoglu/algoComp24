import os
from random import randint

generator_file = "generator"
solution_file = "solution"

t_n_p_r_b_s = [[20, 100, 1000, 5, 5, 5], [20, 100, 2000, 5, 5, 5]]
tnprbs = []
for t, n, p, r, b, i in t_n_p_r_b_s:
    while i:
        tnprbs.append([t, n, p, r, b])
        i -= 1

if __name__ == "__main__":
    os.system(f"g++ {generator_file}.cpp -o {generator_file}")
    os.system(f"g++ {solution_file}.cpp -o {solution_file}")
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
