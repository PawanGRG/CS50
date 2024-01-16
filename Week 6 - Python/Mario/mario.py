import cs50

def main():
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                break
        except ValueError:
            print("Invalid input. Please enter a whole number.")
    i = height - 1
    for j in range(1,height+1,1):
        empty = " "
        print(empty * (i),end='')
        i -= 1
        char ="#"
        print(char * j, end='  ')
        print(char * j)


if __name__ == "__main__":
    main()