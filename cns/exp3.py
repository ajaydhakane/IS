import string

def caesar_decrypt(ciphertext, shift):
    decrypted_text = ""
    for char in ciphertext:
        if char in string.ascii_lowercase:
            decrypted_text += chr((ord(char) - shift - 97) % 26 + 97)
        elif char in string.ascii_uppercase:
            decrypted_text += chr((ord(char) - shift - 65) % 26 + 65)
        else:
            decrypted_text += char
    return decrypted_text

def frequency_analysis(ciphertext):
    frequency = {}
    for char in string.ascii_lowercase:
        frequency[char] = 0

    for char in ciphertext.lower():
        if char in string.ascii_lowercase:
            frequency[char] += 1

    most_common_letter = max(frequency, key=frequency.get)
    return most_common_letter

def cryptanalysis_attack(ciphertext):
    most_common_in_english = 'e'
    most_common_in_ciphertext = frequency_analysis(ciphertext)
    
    shift = (ord(most_common_in_ciphertext) - ord(most_common_in_english)) % 26

    decrypted_text = caesar_decrypt(ciphertext, shift)
    return decrypted_text, shift

# Example usage
ciphertext = "Gur dhvpx oebja sbk whzcf bire gur ynml qbt."
decrypted_text, shift = cryptanalysis_attack(ciphertext)
print(f"Decrypted Text: {decrypted_text}")
print(f"Detected Shift: {shift}")
