import os
from random import randint

# Get the directory of the current script
script_directory = os.path.dirname(os.path.abspath(__file__))

# Change the working directory to the script directory
os.chdir(script_directory)

number_generator_file = "generator"
solution_file = "solver"


params = [
    # min_dim, max_dim, num_edge_min, num_edge_max, num_test
    # 10
    (3, 6, 5, 10, 2),
    (4, 9, 8, 15, 3),
    (7, 15, 15, 25, 4),
    # 100
    (8, 16, 20, 30, 5),
    (10, 20, 20, 40, 8),
    (12, 25, 30, 40, 15),
    # 1000
    (30, 100, 100, 200, 10),
    (50, 150, 150, 300, 15),
    (100, 200, 200, 400, 25),
    # 10000
    (70, 150, 300, 500, 25),
    (100, 200, 400, 600, 40),
    (200, 400, 600, 1200, 50),
    # 100000
    (300, 500, 1000, 2000, 70),
    (400, 600, 1500, 2500, 100),
    (800, 1600, 2500, 4000, 150),
]


if __name__ == "__main__":
    os.system(f"g++ {number_generator_file}.cpp -o {number_generator_file}")
    os.system(f"g++ {solution_file}.cpp -o {solution_file}")
    print("Compiled cpp files")

    for question_test in range(len(params)):
        min_dim, max_dim, num_edge_min, num_edge_max, num_test = params[question_test]
        tnum = str(question_test).zfill(2)
        input_file = f"tests/input/input{tnum}.txt"
        output_file = f"tests/output/output{tnum}.txt"

        random_seed = randint(1, 100000)

        # generate numbers
        os.system(f"./{number_generator_file} {random_seed} {min_dim} {max_dim} {num_edge_min} {num_edge_max} {num_test} > ./{input_file}")
        # solve
        os.system(f"./{solution_file} < ./{input_file} > ./{output_file}")

        print(f"Generated and solved test #{tnum}")