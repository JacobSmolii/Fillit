# Fillit

Introduction: Fillit is a project that lets you discover and/or familiarize yourself with a recurring problem in programming: searching for the optimal solution among a huge set of possibilities. In this particular project, you will be charged with creating an algorithm which fits some Tetriminos together into the smallest possible square.
The executable "fillit" takes only one parameter, a file which contains a list of Tetriminos to assemble. This file has a very specific format (see input sample).

## Solution

#### In the Input file below (all pieces are correct) I:
* Check for wrong length lines('\n' in an invalid position).
* Check for any invalid characters.
* Count number of '#', should be 4.
* Check for '\n' at the end of piece clock.
* Check each '#' character to see if it's adjacent to another. A valid piece with 4 of '#' characters will either have 6 or 8     adjacencies.

![image](https://user-images.githubusercontent.com/45500862/66710870-c3784700-ed35-11e9-8db0-57094994480b.png)

<hr>
The next step I create the linked list with `add_list()` function where I find, cut each piece with 4 of '#' and stored them into the struct and I make sure that the piece is shifted to the top left of the map.
<hr>
The solver works using recursive backtracking. If the piese doesn't overlap any other pieces it places it on the map and then tries to call `solve()` function on all of the other pieces. If they all fit with the current piece in place then it succeeds. If not it moves the current piece and tries to solve the rest of the pieces with the current piece in it's new place. If it's moved all the pieces and still can't make them fit on the current map then it exits the solver, makes a larger map, and then tries to solve again.
