def check_transmission(input_str, output_str):
    """
    Checks if the input string matches the output string.
    
    Args:
        input_str (str): The input binary string
        output_str (str): The output binary string
    
    Returns:
        str: 'OK' if they match, 'ERROR' if they don't
    """
    if input_str == output_str:
        return "OK"
    else:
        return "ERROR"

def main():
    # Read the number of test cases
    T = int(input())
    
    # Process each test case
    for _ in range(T):
        # Read input and output binary strings
        line = input().strip()
        input_str, output_str = line.split()
        
        # Check if the transmission was successful
        result = check_transmission(input_str, output_str)
        
        # Print the result
        print(result)

if __name__ == "__main__":
    main()