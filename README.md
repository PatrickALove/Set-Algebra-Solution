# Set-Algebra-Solution
This program deals with sets of integers.  The integers have the values from 0 to 255.  A number can only appear in a set once although the same number can appear in multiple sets.  There will be four sets identified by the uppercase letters A, B, C and D.  The first four lines of input to the program will be an unordered list of numbers, each separated by a space.  The first line represents set A, the second line is set B, the third line is set C and the fourth is set D.  There can be anywhere from 1 to 255 numbers in a set.  The last number on each line of input is -1 to indicate the end of the line.  Note that -1 is not a member of the set.  
After the first four lines of input defining the sets, there will be a statement defining operations to be done on the sets.  There are two possible operations:

Operation	Operator	Definition
union	&	The union of two sets is a set containing all the members of both sets with duplicates removed.
intersection	^	The intersection of two sets is a set containing only those members that appear in both sets.

If set A is 1 5 3 22 and set B is 22 4 3 2, then A&B is 1 2 3 4 5 22 and A^B is 3 22.

The two operators can be combined for form expressions involving multiple sets.  The operators for union and intersection have the same precedence and are always interpreted from left to right.  If set A is 1 5 3 22, set B is 22 4 3 2 and set C is 1 9 3 then A^B&C is 1 3 9 22.

The program must interpret the set expression and display the results.  Input is from the file set.txt    If a number appears more than once in a set, any duplicates must be removed.  The values in the resulting set may be displayed in any order.  If the resulting set is empty, the program should display NULL.  The equation may use each of the sets A, B, C or D, once, multiple times or not at all.

Sample input from set.txt

40	223	163	230	22	100	-1
223	22	255	6	73	-1
1	62	113	223	-1
62	113	160	22	-1
B&C&A^D

Sample output

22 62 113
