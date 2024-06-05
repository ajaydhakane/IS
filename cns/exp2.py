import itertools
import string

def brute_force_attack(target_password):
    characters = string.ascii_lowercase  # 'abcdefghijklmnopqrstuvwxyz'
    max_length = 4  # Limiting to four characters

    for length in range(1, max_length + 1):
        for attempt in itertools.product(characters, repeat=length):
            attempt_password = ''.join(attempt)
            print(f"Trying password: {attempt_password}")
            if attempt_password == target_password:
                print(f"Password found: {attempt_password}")
                return

    print("Password not found within the specified length limit.")

# Example usage
target_password = "test"
brute_force_attack(target_password)
