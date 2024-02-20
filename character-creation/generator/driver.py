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
    ("01", 10, 5, 10, 3),
    ("02", 20, 200, 100, 50),
    ("03", 50, 20000, 30000, 5000),
    ("04", 100, 400, 800, 200),
    ("05", 200, 16000, 14000, 1000),
    ("06", 500, 200000, 500000, 150000),
    ("07", 1000, 20, 30, 5),
    ("08", 2000, 800000, 800000, 200000),
    ("09", 5000, 550, 850, 250),
    ("10", 10000, 100000, 200000, 50000),
    ("11", 20000, 500000, 10000, 200000),
    ("12", 50000, 800000, 200000, 500000),
    ("13", 100000, 10000, 2000, 5000),
    ("14", 200000, 200000, 400000, 10000),
    ("15", 500000, 2000, 4000, 1000),
    ("16", 1000000, 240000, 360000, 40000)
]


if __name__ == "__main__":
    os.system(f"g++ {number_generator_file}.cpp -o {number_generator_file}")
    os.system(f"g++ {solution_file}.cpp -o {solution_file}")
    print("Compiled cpp files")

    for question_test in range(len(params)):
        question_number, n, a, d, p = params[question_test]

        # generate numbers
        os.system(f"./{number_generator_file} {question_number} {n} {a} {d} {p}")
        # solve
        os.system(f"./{solution_file} {question_number}")

        print(f"Generated and solved test #{question_number}")