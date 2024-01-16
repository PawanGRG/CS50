def main():
    while True:
        try:
            num = int(input("Number: "))
            if num > 0:
                break
        except ValueError:
            print("Invalid input. Please enter a number.")

    num_str = str(num)  # Convert the number to a string
    is_valid, count = checksum(num)

    if is_valid:
        if count == 15 and (num_str.startswith('34') or num_str.startswith('37')):
            print("AMEX")
        elif count == 16 and num_str.startswith(('51', '52', '53', '54', '55')):
            print("MASTERCARD")
        elif (count == 13 or count == 16) and num_str.startswith('4'):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")

def checksum(number):
    sum = 0
    count = 0
    number = str(number)
    reverse_number = number[::-1]

    for i, digit in enumerate(reverse_number):
        if (i + 1) % 2 == 0:
            double_digit = int(digit) * 2
            sum += double_digit // 10 + double_digit % 10
        else:
            sum += int(digit)

        count += 1

    return sum % 10 == 0, count

if __name__ == "__main__":
    main()
