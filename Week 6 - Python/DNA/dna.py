import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        return

    dna_data = {}

    with open(sys.argv[1], newline="") as database_file:
        csvreader = csv.reader(database_file)
        STR = next(csvreader)

        for row in csvreader:
            name = row[0]
            str_counts = {}
            for i in range(1, len(STR)):
                str_name = STR[i]
                str_count = int(row[i])
                str_counts[str_name] = str_count
            dna_data[name] = str_counts

    with open(sys.argv[2], "r") as seq_file:
        dna_sequence = seq_file.read()

    longest_str_runs = {}

    for str_name in STR[1:]:
        longest_run = longest_match(dna_sequence, str_name)
        longest_str_runs[str_name] = longest_run

    for name in dna_data:
        is_match = True

        for str_name in longest_str_runs:
            if longest_str_runs[str_name] != dna_data[name][str_name]:
                is_match = False
                break
        if is_match:
            print(name)
            return

    print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
