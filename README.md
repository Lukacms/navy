# PSU-navy

# Description:
This is a 1st year Epitech project which consist in discovering and using signals to make a battleship between two terminals. <br>
The language used is C, and this program is in 2 times. <br> <br>
The first take a map in parameter : <br>
```
$> ./navy map1
```
You should see in your terminal this output:
```
my_pid: [nbr]
waiting for enemy connection...
```
You can then start the second program, which take 2 arguments: the enemy's PID (given by the first program), and a map like the first : <br>
```
$> ./navy [nbr] map2
```
# Returns:
* If the file given as parameter contain errors, the program return `84`. <br>
A correct file should look like this (4 boats, each with a different size from 2 to 5, and the starting as well as the endings points to place to boat):
```
2:C1:C2
3:D4:F4
4:B5:B8
5:D7:H7
```
* When the game is finished, the program either return `0` in case of victory, or `1` in case of defeat.<br>

## Game:
This program intend to be like a game a battleship, hence the maps for the player and the enemy are upated after each turn and dissplayed in the output.<br>
E.g: end of turn 1 for player 2:
```
waiting for enemy's attack...
A2: missed

attack: B12
wrong position
attack: B5
B5: hit

my positions:
 |A B C D E F G H
-+---------------
1|. 5 5 5 5 5 . 3
2|o . . . . . . 3
3|. . . . . . . 3
4|. . 2 2 . . . .
5|. . . . . . . .
6|. . . . 4 4 4 4
7|. . . . . . . .
8|. . . . . . . .

enemy's positions:
 |A B C D E F G H
-+---------------
1|. . . . . . . .
2|. . . . . . . .
3|. . . . . . . .
4|. . . . . . . .
5|. x . . . . . .
6|. . . . . . . .
7|. . . . . . . .
8|. . . . . . . .

waiting for enemy's attack...
```
* the `x` on the map represent when the attack has hit either the enemy's map or the player's map
* the `o` is when the attack has missed
* The attack needs to be valid: a letter between `A` and `H`, folloowed by a digit between `1` and `8`

# How to use to project
A Makefile is used to compile the code, and it use the following rules:

| Command          | Result                                          |
| ---------------- | ----------------------------------------------- |
| `make`           | Builds a ```navy``` executable.          |
| `make tests_run` | Runs unit tests.                                |
| `make clean`     | Cleans build dumps, keeping the executable.     |
| `make fclean`    | Removes all of the files created by the build.  |
| `make re`        | Calls `make fclean` and then `make`.            |
