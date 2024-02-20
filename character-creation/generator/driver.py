import os
from random import shuffle

# Get the directory of the current script
script_directory = os.path.dirname(os.path.abspath(__file__))

# Change the working directory to the script directory
os.chdir(script_directory)

number_generator_file = "generator"
solution_file = "solver"


params = [
    # n, llc, ulc, llm, ulm
    # 0
    (5, 3, 8, 1, 10),
    # 1
    (10, 8, 16, 5, 20),
    (20, 15, 30, 10, 40),
    (50, 30, 60, 20, 80),
    # 2
    (100, 60, 120, 40, 160),
    (200, 120, 240, 80, 320),
    (500, 300, 600, 200, 800),
    # 3
    (1000, 600, 1200, 400, 1600),
    (2000, 1200, 2400, 800, 3200),
    (5000, 3000, 6000, 2000, 8000),
    # 4
    (10000, 6000, 12000, 4000, 16000),
    (20000, 12000, 24000, 8000, 32000),
    (50000, 30000, 60000, 20000, 80000),
    # 5
    (100000, 60000, 120000, 40000, 160000),
    (200000, 120000, 240000, 80000, 320000),
    (500000, 300000, 600000, 200000, 800000),
    #
    (1000000, 300000, 600000, 200000, 800000)
]

if __name__ == "__main__":
    os.system(f"g++ {number_generator_file}.cpp -o {number_generator_file}")
    os.system(f"g++ {solution_file}.cpp -o {solution_file}")
    print("Compiled cpp files")

    shuffle(params)

    for question_test in range(len(params)):
        n, llc, ulc, llm, ulm = params[question_test]
        tnum = str(question_test).zfill(2)
        input_file = f"tests/input{tnum}.txt"
        output_file = f"tests/output{tnum}.txt"

        # generate numbers
        print(f"Generating test #{question_test}")
        os.system(f"./{number_generator_file} {n} {llc} {ulc} {llm} {ulm} > ./{input_file}")
                
        # solve
        print(f"Solving test #{question_test}")
        os.system(f"./{solution_file} < ./{input_file} > ./{output_file}")

        print(f"Generated and solved test #{tnum}")