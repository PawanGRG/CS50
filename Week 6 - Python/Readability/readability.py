def main():
    text = input("Text:")
    letter_count, word_count, sentence_count = count(text)

    avg_letter = letter_count / word_count * 100.0
    avg_sentence = sentence_count / word_count * 100.0

    index = (0.0588 * avg_letter) - (0.296 * avg_sentence) - 15.8

    grade_level = round(index)

    if grade_level <= 1:
        print("Before Grade 1")
    elif grade_level >= 16:
        print("Grade 16+")
    else:
        print("Grade", grade_level)


def count(text):
    letters = 0
    spaces = 0
    punctuations = 0

    for char in text:
        if char.isalpha():
            letters += 1
        elif char == " ":
            spaces += 1
        elif char == "." or char == "!" or char == "?":
            punctuations += 1

    return letters, spaces + 1, punctuations


if __name__ == "__main__":
    main()
