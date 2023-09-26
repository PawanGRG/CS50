# Week 1 - C
The first week of CS50  introduced the fundamentals of the C programming language, covering concepts such as variables,
data types, conditionals, loops, and functions.  Lectures, assignments, and problem-solving exercises equipped me with 
essential coding skills and a problem-solving mindset.  Week 1 established a strong foundation for my understanding of 
computer science and programming principles, laying the groundwork for subsequent weeks. I completed various assignments
set by CS50 and are displayed above.
## Cash
In this assignment, I had to implement a program that prompts the user for the number of cents that a customer is owed and then 
prints the smallest number of coins with which that change can be made. An example of the code being ran is:
```
$ ./cash
Change owed: 41
4
```
From this assignment, I learnt:
- **User Input Handling**: I gained experience in prompting the user for input and handling it appropriately. In this case, I used `get_int` to retrieve the number of cents from the user and how to ensure that negative inputs are handled by prompting the user again.
- **Mathematical Operations**: I used mathematical operations to determine the number of coins needed. For example, to calculate the number of quarters, I divided cents by 25, and for dimes, I divided by 10.
- **Return Values**: I understood the importance of returning values explicitly from functions using the return statement. Each of the calculate functions is expected to return the number of coins of a specific denomination


## Credit
In this assignment, I had to implement a program that prompts the user for a credit card number and report whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. To determine if the credit card number prompted by the user is valid, an algorithm called the Luhn's algorithm is utilised. An example of the code being ran is:
```
$ ./credit
Number: 4003600000000014
VISA
```

```
$ ./credit
Number: 6176292929
INVALID
```
From this assignment, the key concepts I learnt: 
- **Algorithms**: I successfully implemented the Luhn's algorithm to verfiy the validitiy of the credit card number inputted by the user. This was done by performing checksum of the credit card number.
- **Conditional Statements**: I got more confident in utilising conditional statments such as `if`, `else if` and `else`. I successfully implemented them in the program to determine the type of credit card (AMEX, MASTERCARD, VISA, or INVALID) based on the input credit card number and its validity.
- **Debugging**: While the previous assignments in week 1 presented relatively straightforward debugging scenarios, this assignment introduced a higher level of complexity, resulting in more intricate bugs. To address these challenges, I employed debugging techniques such as utilising the `printf` function to display variable values, meticulously breaking down the problem into smaller, manageable components, and systematically solving them. This method proved effective in resolving the intricate bugs encountered during the assignment.
- **Functions**: I created a function that checks whether the first one or two digits of a long integer first match a specified integer `check`. This was needed as a part of determining if the credit card number was either AMEX, MASTERCARD or VISA. 


## Mario Less
In this assignment, I was tasked to recreate the pyramid towards the end of World 1-1 in Nintendo’s Super Mario Brothers game, using hashes (#) for the bricks. This program allows the user to decide how tall the pyramid should be by first prompting them for a positive integer between 1 and 8. If the user doesn’t input a positive integer between 1 and 8, when prompted, the program re-prompts the user until they cooperate. 
For example the code would run like this:
```
 $ ./mario_less
Height: 4
   #
  ##
 ###
####
```
From this assignment the key lessons I learnt was:
- **For Loops**: I learnt how to declare `for` loops and how to utilise it in correctly to achieve the wanted outcome. The `for` loops control the iteration for both rows and columns of the pyramid.
- **Nested Loops**: I learnt that `for` loops can be nested in another `for` loop, this was to handle the spaces and hash symbols for each row of the pyramid.


## Mario More
This assignment was similar to the one of Mario Less where I was tasked to recreate the pyramid towards the end of World 1-1 in Nintendo’s Super Mario Brothers game, using hashes (#) for the bricks. However this time, I was tasked to create 2 pyramids, mirroring each other in effect. The user is prompted for a positive integer between 1 and 8 to determine the height of the pyramid, and if the user doesn’t input a positive integer between 1 and 8, when prompted, the program re-prompts the user until they cooperate. An example of the code would be this:
```
$ ./mario_more
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########
```
From this assignment I learnt:
- **Algorithmic Thinking**:  I designed an efficient algorithm for creating the pyramid pattern, considering the arrangement of spaces and hash symbols on each row. I also recognised and leveraged repeating patterns and relationships between spaces and hash symbols to construct the pyramid accurately.
- **Debugging**: I encountered and addressed coding issues and errors by breaking down the problem into smaller, manageable components, and systematically solving them. This method proved effective in resolving the intricate bugs encountered during the assignment.


## Population
In this assignment, I implemented a program that calculates the number of years required for the population to grow from the start size to the end size. The program prompts the user for a start size and an end size, making sure the user enters a starting size greater than or equal to 9 and if the user enters a number less than 9, the user is re-prompted. Additonally, the program ensures the user enters the end size that is greater than or equal to the starting population size, if the requirements are not met then the user will be re-prompted again. Example of the code being ran is this:
```
$ ./population
Start size: -5
Start size: 3
Start size: 9
End size: 5
End size: 18
Years: 8
```
From this assignment I learnt:
- **While Loops**:  I proficiently utilised while loops to repetitively prompt the user for input until valid values were provided. Furthermore, I employed a while loop to calculate the number of years necessary to reach the target population size.
- **User Input Handling**: I employed the get_int function to solicit user input while ensuring the input adhered to specific constraints. This included prompting the user for both the starting and ending population sizes and verifying that the input values met the required criteria.
