import os
from random import randint

generator_file = "graph_generator"
solution_file = "solution"

n_m_i_s = [[5, 8, 1], [100, 110, 1], [10000, 20000, 4], [50000, 100000, 4]]
nms = []
for n, m, i in n_m_i_s:
    while i:
        nms.append([n, m])
        i -= 1

if __name__ == "__main__":
    os.system(f"g++ {generator_file}.cpp -o {generator_file}")
    os.system(f"g++ {solution_file}.cpp -o {solution_file}")
    print("Compiled cpp files")

    for i in range(len(nms)):
        n, m = nms[i]
        maxWeight = 100
        tnum = str(i).zfill(2)
        input_file = f"tests/input/input{tnum}.txt"
        output_file = f"tests/output/output{tnum}.txt"

        random_seed = randint(1, 100000)

        # generate graph
        os.system(f"./{generator_file} {random_seed} {n} {m} {maxWeight} > ./{input_file}")
        # solve
        os.system(f"./{solution_file} < ./{input_file} > ./{output_file}")

        print(f"Generated and solved test #{tnum}")
