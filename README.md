*This project has been created as part of the 42 curriculum by ansimonn@student.42angouleme.fr*

# Content

- [Description](#description)

- [Instructions](#instructions)

- [Ressources](#ressources)

# Description

## Project

There are 2 stacks named a and b.

At the beginning:

- The stack a contains a random number of unique negative and/or positive
integers.

- The stack b is empty.

The goal is to sort the numbers in stack a in ascending order. To achieve this, 
the following operations are available:

- sa (swap a): Swap the first 2 elements at the top of stack a.\
Do nothing if there is only one element or none.

- sb (swap b): Swap the first 2 elements at the top of stack b.\
Do nothing if there is only one element or none.

- ss : sa and sb at the same time.

- pa (push a): Take the first element at the top of b and put it at the top of a.\
Do nothing if b is empty.

- pb (push b): Take the first element at the top of a and put it at the top of b.\
Do nothing if a is empty.

- ra (rotate a): Shift up all elements of stack a by 1.\
The first element becomes the last one.

- rb (rotate b): Shift up all elements of stack b by 1.\
The first element becomes the last one.

- rr : ra and rb at the same time.

- rra (reverse rotate a): Shift down all elements of stack a by 1.\
The last element becomes the first one.

- rrb (reverse rotate b): Shift down all elements of stack b by 1.\
The last element becomes the first one.

- rrr : rra and rrb at the same time.

To reach the 100% completion on the project, the program needs to sort **100 random elements in less than 700
average operations**, and **500 random elements in less than 5500 average operations**.

## Implementation

I used the K-sort algorithm after some researches/discussions with other students because it is a good
compromise between simplicity and efficiency. The sorting process is divided in 2 different steps.

- During the first step, all elements from the a stack are pushed into the b stack in order to put the smallests
elements in the middle of it and the larger ones on the borders. If every element was represented by a line with
a size proportionnal to its value, this would form the shape of a 'K' in the b stack.

- After this, the second step's objective is to push back all elements to the a stack directly in ascending
order. Because stack b is already in a 'K' shape, the next element to push to a at each iteration is
supposed to be near to the top or the bottom of the stack, meaning we can reach it in a few rotations.

This algorithm stays optimised between 10 and 1000 elements in the starting a stack, meaning its perfectly
appropriate to use it in this project.

# Instructions



# Ressources
