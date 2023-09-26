# Week 1 - C
The first week of CS50  introduced the fundamentals of the C programming language, covering concepts such as variables,
data types, conditionals, loops, and functions.  Lectures, assignments, and problem-solving exercises equipped me with 
essential coding skills and a problem-solving mindset.  Week 1 established a strong foundation for my understanding of 
computer science and programming principles, laying the groundwork for subsequent weeks. I completed various assignments
set by CS50 and are displayed above.
## Cash
In this assignment, I had to implement a program that prompts the user for the number of cents that a customer is owed and then 
prints the smallest number of coins with which that change can be made. From this assignment, I learnt:
- **User Input Handling**: I gained experience in prompting the user for input and handling it appropriately. In this case, I used `get_int` to retrieve the number of cents from the user and how to ensure that negative inputs are handled by prompting the user again.
- **Mathematical Operations**: I used mathematical operations to determine the number of coins needed. For example, to calculate the number of quarters, I divided cents by 25, and for dimes, I divided by 10.
- **Return Values**: I understood the importance of returning values explicitly from functions using the return statement. Each of the calculate functions is expected to return the number of coins of a specific denomination


## Credit
In this assignment, I had to implement a program that prompts the user for a credit card number and report whether it is a valid American Express, MasterCard, or Visa card number, per the definitions of each’s format herein. To determine if the credit card number prompted by the user is valid, an algorithm called the Luhn's algorithm is utilised. From this assignment, the key concepts I learnt: 
- **Algorithms**: I successfully implemented the Luhn's algorithm to verfiy the validitiy of the credit card number inputted by the user. This was done by performing checksum of the credit card number.
- **Conditional Statements**: I got more confident in utilising conditional statments such as `if`, `else if` and `else`. I successfully implemented them in the program to determine the type of credit card (AMEX, MASTERCARD, VISA, or INVALID) based on the input credit card number and its validity.
- **Debugging**: While the previous assignments in week 1 presented relatively straightforward debugging scenarios, this assignment introduced a higher level of complexity, resulting in more intricate bugs. To address these challenges, I employed debugging techniques such as utilising the `printf` function to display variable values, meticulously breaking down the problem into smaller, manageable components, and systematically solving them. This method proved effective in resolving the intricate bugs encountered during the assignment. 


## Mario Less
In this assignment, I was tasked to recreate the pyramid towards the end of World 1-1 in Nintendo’s Super Mario Brothers game, using hashes (#) for the bricks. This program allows the user to decide how tall the pyramid should be by first prompting them for a positive integer between 1 and 8. If the user doesn’t input a positive integer between 1 and 8, when prompted, the program re-prompts the user until they cooperate. 
For example the code would run like this:
```
 $ ./mario.c
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
This assignment was similar to the one of Mario Less
