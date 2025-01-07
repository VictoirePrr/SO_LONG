## The so_long algorithm !

## Overview

The so_long project is a grid-based game implemented using the MiniLibX library. The player navigates through a map, collecting items and reaching an exit, while ensuring the map adheres to specific rules.

## File Structure and Responsibilities

### so_long.c

#### Purpose:

Main entry point of the program, orchestrating initialization and the game loop.

#### Key Functions:

```c
check_argv(char *argv):

- Validates if the provided map filename ends with .ber.

- Returns 0 if the filename is valid, 1 otherwise.
```

```c
main(int argc, char **argv):

- Entry point for the program.

- Ensures the proper number of arguments and validates the map.

- Handles initialization (window, images, map parsing) and starts the game loop using MiniLibX.
```

-----------------

### check_items.c

#### Purpose:

Ensures the map contains valid elements and adheres to gameplay rules.

#### Key Functions:

```c
err_items(t_matrix *matrix):

- Checks if all characters in the map are valid (C, P, E, 0, 1).

- Returns 0 if valid, 1 otherwise.
```

```c
err_items_count(t_matrix *matrix):

Ensures the map contains exactly:

- One player (P),

- One exit (E),

- At least one collectible (C).

- Returns 0 if valid, 1 otherwise.
```

```c
parsing_map(t_matrix *matrix):

Verifies the map against multiple rules:

- Valid items,

- Correct rectangle shape,

- Proper wall enclosure,

- Player accessibility using flood-fill.

- Returns 0 if all checks pass, 1 otherwise.
```

-----------------

### check_map.c

#### Purpose:

Validates the map's structure and boundary conditions.

#### Key Functions:

```c
check_rectangle(t_matrix *matrix):

- Ensures all rows have the same length.

- Returns 0 if the map is rectangular, 1 otherwise.
```

```c
check_first_last_rows(char *row):

- Validates if a row (first or last) is entirely walls (1).

- Returns 0 if valid, 1 otherwise.
```

```c
check_walls(t_matrix *matrix):

- Ensures all rows are enclosed by walls on the edges.

- Returns 0 if valid, 1 otherwise.
```

-----------------

### fill_map.c

#### Purpose:

Handles reading and storing the map from the file into memory.

#### Key Functions:

```c
fill_the_matrix(const char *file, t_matrix *matrix):

- Reads the map line by line and stores it in the matrix structure.

- Handles memory allocation and errors during reading.
```

```c
read_map(const char *file, t_matrix *matrix):

- Opens the map file, calculates the number of rows, and allocates memory for the matrix.

- Calls fill_the_matrix to populate the matrix.

- Returns the populated map or NULL on failure.
```

-----------------

### flood_fill.c

#### Purpose:

Implements a flood-fill algorithm to validate map accessibility.

#### Key Functions:

```c
flood_fill(t_matrix *matrix, int x, int y):

- Recursively traverses the map from the player's starting position (P).

- Marks traversable tiles as visited (X).
```

```c
check_player_access(t_matrix *matrix):

- Initiates the flood-fill from the player's position.

- Validates that all items (C) and the exit (E) are reachable.
```

```c
final_check(t_matrix *matrix):

- Confirms that all required elements are marked as reachable (X).

- Returns 0 if valid, 1 otherwise.
```

-----------------

### utils.c

Purpose:

Provides utility functions for error handling and memory management.

#### Key Functions:

```c
print_error(void):

- Outputs "Error" to the standard output.
```

```c
free_all(char **matrix):

- Frees all allocated memory for the map matrix.
```

```c
dup_temp(const char *s1):

- Creates a duplicate of the string, excluding newline characters.

- Returns the newly allocated string.
```

-----------------

### closing_utils.c

#### Purpose:

Manages resource cleanup and closing operations.

#### Key Functions:

```c
handling_close(t_data *data):

- Frees all allocated resources (sprites, map, MiniLibX components).

- Outputs a closing message and exits the program.
```

```c
free_sprites(t_data *data):

- Frees all loaded sprite images used in the game.
```

```c
handling_key(int key):

- Handles key press events.

- Exits the program if the ESC key is pressed.
```

-----------------

### init_game.c

#### Purpose:

Initializes the game's graphical components.

#### Key Functions:

```c
initialize_window(t_data *data, t_matrix *matrix):

- Sets up the MiniLibX window with dimensions based on the map size.
```

```c
put_xpm_to_data(void *xvar, char *xpm, t_img *img):

- Loads an XPM image file into the program.

- Returns the initialized image structure.
```

```c
initialize_img(t_data *data, t_img *img):

- Loads all necessary images for the game (player, walls, floor, items, exit).
```

-----------------

### start_game.c

#### Purpose:

- Draws the map and initializes the game loop.

#### Key Functions:

```c
put_img_to_window(t_data *data, t_img img, int vtl, int htl):

- Places an image at the specified coordinates in the window.
```

```c
handle_img(t_data *data, int vtl, int htl):

- Determines which image to display based on the map's tile content.
```

```c
start_game(t_data *data):

- Iterates over the map and renders the initial game state in the window.

- Map Symbols:

C: Collectible item.

P: Player start position.

E: Exit.

0: Empty space.

1: Wall.

- Image Dimensions:

XPM_WIDTH: Width of each image tile.

XPM_HEIGHT: Height of each image tile.
```

-----------------

## Glossary

Matrix: 2D array representing the game map.

Flood-fill Algorithm: Recursive method to check tile accessibility.

MiniLibX: A lightweight library for graphical programming in C.


## Conclusion

The so_long project combines validation, memory management, and graphical rendering to create a robust, rule-compliant game. Each module contributes to a cohesive pipeline, ensuring the map is valid and playable while adhering to the project requirements.
