# Fillit

Introduction: Fillit is a project that lets you discover and/or familiarize yourself with a recurring problem in programming: searching for the optimal solution among a huge set of possibilities. In this particular project, you will be charged with creating an algorithm which fits some Tetriminos together into the smallest possible square.
The executable "fillit" takes only one parameter, a file which contains a list of Tetriminos to assemble. This file has a very specific format (see input sample).

## Input Sample

### In the Input file below (all the pieces are correct) I:
* Check for wrong length lines('\n' in an invalid position).
* Check for any invalid characters.
* Count number of '#', should be 4.
* Check for '\n' at the end of piece clock.
* Check each '#' character to see if it's adjacent to another. A valid piece with 4 of '#' characters will either have 6 or 8     adjacencies.

![image](https://user-images.githubusercontent.com/45500862/66710870-c3784700-ed35-11e9-8db0-57094994480b.png)
