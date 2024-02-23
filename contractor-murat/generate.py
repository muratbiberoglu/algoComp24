import os
from random import randint

generator_file = "generator"
solution_file = "solution2"

n_q_i_s = [[10, 50, 3], [50, 1000, 3], [100, 20000, 2], [100, 1000000, 2]]
nms = [[n, m] for n, m, i in n_q_i_s for _ in range(i)]

if __name__ == "__main__":
    os.system(f"g++-13 {generator_file}.cpp -o {generator_file}")
    os.system(f"g++-13 {solution_file}.cpp -o {solution_file}")
    print("Compiled cpp files")

    for i in range(len(nms)):
        n, m = nms[i]
        tnum = str(i).zfill(2)
        input_file = f"tests/input/input{tnum}.txt"
        output_file = f"tests/output/output{tnum}.txt"

        random_seed = randint(1, 100000)

        # generate
        os.system(f"./{generator_file} {random_seed} {n} {m} > ./{input_file}")
        # solve
        os.system(f"./{solution_file} < ./{input_file} > ./{output_file}")

        print(f"Generated and solved test #{tnum}")
