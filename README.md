# push_swap
Dual stack machine emulator with quicksort algorithm.<br />
You have 2 stacks named a and b.<br />
At the beginning:
- The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.<br />
- The stack b is empty.<br />
The goal is to sort in ascending order numbers into stack a. To do so the programm has the
following operations:<br />
- sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.<br />
- sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.<br />
- ss : sa and sb at the same time.<br />
- pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.<br />
- pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.<br />
- ra (rotate a): Shift up all elements of stack a by 1.<br />
The first element becomes the last one.<br />
- rb (rotate b): Shift up all elements of stack b by 1.<br />
The first element becomes the last one.<br />
- rr : ra and rb at the same time.<br />
- rra (reverse rotate a): Shift down all elements of stack a by 1.<br />
The last element becomes the first one.<br />
- rrb (reverse rotate b): Shift down all elements of stack b by 1.<br />
The last element becomes the first one.<br />
- rrr : rra and rrb at the same time.<br />

The program tries to find the smallest list of instructions possible to sort the stack
a, the smallest number being at the top
