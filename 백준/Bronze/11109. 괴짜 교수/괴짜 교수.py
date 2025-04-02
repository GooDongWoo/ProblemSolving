def should_parallelize(d, n, s, p):
    """
    Determine whether parallelization is beneficial.
    
    Args:
        d (int): Time to develop parallel version
        n (int): Number of times the program will run
        s (int): Serial version execution time
        p (int): Parallel version execution time
        
    Returns:
        str: Decision on whether to parallelize
    """
    # Total time for serial version = n * s
    serial_total_time = n * s
    
    # Total time for parallel version = development time + n * parallel execution time
    parallel_total_time = d + (n * p)
    
    # Compare the total times
    if serial_total_time < parallel_total_time:
        return "do not parallelize"
    elif serial_total_time > parallel_total_time:
        return "parallelize"
    else:
        return "does not matter"

def main():
    # Read the number of test cases
    t = int(input())
    
    # Process each test case
    for _ in range(t):
        # Read and parse the input
        d, n, s, p = map(int, input().split())
        
        # Determine the decision
        decision = should_parallelize(d, n, s, p)
        
        # Print the result
        print(decision)

if __name__ == "__main__":
    main()