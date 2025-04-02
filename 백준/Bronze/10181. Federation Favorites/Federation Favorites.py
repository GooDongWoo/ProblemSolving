def is_perfect(n):
    """
    Determines if a number is perfect and returns its divisors if it is.
    A perfect number equals the sum of its positive divisors less than itself.
    """
    if n <= 1:
        return False, []
    
    # Find all divisors less than n
    divisors = []
    for i in range(1, int(n**0.5) + 1):
        if n % i == 0:
            divisors.append(i)
            # Add the pair divisor if it's not n itself
            if i != n // i and n // i != n:
                divisors.append(n // i)
    
    # Sort divisors for proper output format
    divisors.sort()
    
    # Check if sum of divisors equals n
    return sum(divisors) == n, divisors

def main():
    """Process input according to the problem specification."""
    while True:
        n = int(input())
        if n == -1:
            break
            
        perfect, divisors = is_perfect(n)
        
        if perfect:
            # Format output as "n = 1 + 2 + ..."
            output = f"{n} = " + " + ".join(map(str, divisors))
            print(output)
        else:
            print(f"{n} is NOT perfect.")

if __name__ == "__main__":
    main()