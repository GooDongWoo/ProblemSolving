def check_pangram(sentence):
    """
    Check if a sentence is a pangram and return missing letters if not.
    
    Args:
        sentence (str): The sentence to check
        
    Returns:
        tuple: (is_pangram, missing_letters)
            - is_pangram (bool): True if the sentence is a pangram, False otherwise
            - missing_letters (str): String of missing letters in alphabetical order
    """
    # Convert to lowercase and create a set of used letters
    used_letters = set()
    
    for char in sentence.lower():
        if 'a' <= char <= 'z':
            used_letters.add(char)
    
    # Create set of all lowercase English letters
    all_letters = set('abcdefghijklmnopqrstuvwxyz')
    
    # Find missing letters
    missing = all_letters - used_letters
    
    # Check if it's a pangram
    is_pangram = len(missing) == 0
    
    # Return the result
    if is_pangram:
        return True, ""
    else:
        # Sort missing letters alphabetically
        return False, ''.join(sorted(missing))

def main():
    # Read the number of sentences
    n = int(input())
    
    # Process each sentence
    for _ in range(n):
        sentence = input()
        
        # Check if it's a pangram
        is_pangram, missing_letters = check_pangram(sentence)
        
        # Print the result
        if is_pangram:
            print("pangram")
        else:
            print(f"missing {missing_letters}")

if __name__ == "__main__":
    main()