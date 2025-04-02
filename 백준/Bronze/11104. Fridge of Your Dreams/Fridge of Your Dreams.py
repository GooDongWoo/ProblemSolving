def binary_to_decimal(binary_string):
    """
    Convert a 24-bit binary string to its decimal representation.
    
    Args:
        binary_string (str): A 24-bit binary string
        
    Returns:
        int: The decimal representation of the binary string
    """
    return int(binary_string, 2)

def main():
    # Read the number of test cases
    n = int(input())
    
    # Process each test case
    for _ in range(n):
        binary_string = input().strip()
        
        # Convert binary to decimal
        decimal_value = binary_to_decimal(binary_string)
        
        # Print the decimal value without leading zeros
        print(decimal_value)

if __name__ == "__main__":
    main()