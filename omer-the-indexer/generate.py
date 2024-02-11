import os
from random import randint

number_generator_file = "number_generator"
query_generator_file = "query_generator"
solution_file = "solution"

npq_t = [([5, 2, 10], 1), ([100, 5, 1000], 1), ([100000, 5, 100000], 8)]
npq = []
for [n, p, q], t in npq_t:
    while t:
        npq.append([n, p, q])
        t -= 1

if __name__ == "__main__":
    os.system(f"g++ {number_generator_file}.cpp -o {number_generator_file}")
    os.system(f"g++ {query_generator_file}.cpp -o {query_generator_file}")
    os.system(f"g++ {solution_file}.cpp -o {solution_file}")
    print("Compiled cpp files")

    for t in range(len(npq)):
        n, p, q = npq[t]
        tnum = str(t).zfill(2)
        number_file = f"tests/number/number{tnum}.txt"
        input_file = f"tests/input/input{tnum}.txt"
        output_file = f"tests/output/output{tnum}.txt"

        random_seed = randint(1, 100000)

        # generate numbers
        os.system(f"./{number_generator_file} {random_seed} {n} {p} {q} > ./{number_file}")
        os.system(f"cat ./{number_file} > ./{input_file}")
        # generate queries
        os.system(f"./{query_generator_file} {random_seed} < ./{number_file} >> ./{input_file}")
        # solve
        os.system(f"./{solution_file} < ./{input_file} > ./{output_file}")

        print(f"Generated and solved test #{tnum}")
