import os
from random import randint

query_generator_file = "input-generator"
solution_file = "solution"

if __name__ == "__main__":
    os.system(f"g++ {query_generator_file}.cpp -o {query_generator_file}")
    os.system(f"g++ {solution_file}.cpp -o {solution_file}")
    print("Compiled cpp files")

    for t in range(22, 24):
        tnum = str(t).zfill(2)

        input_file = f"tests/input/input{tnum}.txt"
        output_file = f"tests/output/output{tnum}.txt"

        # solve
        os.system(f"./{solution_file} < ./{input_file} > ./{output_file}")

        print(f"Generated and solved test #{tnum}")