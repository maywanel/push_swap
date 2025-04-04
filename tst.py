import subprocess
import random
import signal
import sys

def generate_numbers(count):
    numbers = random.sample(range(-1000, 1001), count)  # Ensure unique numbers
    return numbers

def execute_push_swap(count):
    numbers = generate_numbers(count)
    numbers_str = ' '.join(map(str, numbers))
    cmd = f"./push_swap \"{numbers_str}\" | wc -l"
    result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
    return numbers, int(result.stdout.strip())

def main():
    count = int(input("Enter the number of random numbers: "))
    results = []
    
    def signal_handler(sig, frame):
        print("\nStopping...\n")
        if results:
            max_case = max(results, key=lambda x: x[1])
            print(f"Min: {min(results, key=lambda x: x[1])[1]}")
            print(f"Max: {max_case[1]}")
            avg = sum(result[1] for result in results) / len(results)
            print(f"Avg: {avg:.2f}")
            print(f"Max Case: {max_case[0]}")
        sys.exit(0)
    
    signal.signal(signal.SIGINT, signal_handler)
    
    while True:
        numbers, moves = execute_push_swap(count)
        results.append((numbers, moves))
        print(f"Numbers: {numbers}\nMoves: {moves}\n")

if __name__ == "__main__":
    main()
