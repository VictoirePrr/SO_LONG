# So_Long Project - README

## About
The **So_Long** project is a simple 2D game developed as part of your 42 School curriculum. It revolves around a player navigating a character across a map, collecting items, and avoiding enemies or obstacles to reach a specific goal.

## Requirements
- **Graphics Library**: MinilibX
- **OS**: macOS or Linux (with appropriate MinilibX library installed)
- **Compiling**: Using `make`

## Installation
1. **Clone the repository**:
    ```bash
    git clone https://github.com/VictoirePrr/SO_LONG.git
    cd so_long
    ```

2. **Make the project**:
    ```bash
    make
    ```

3. After compiling, the game will be ready to play with the executable `so_long`.

## How to Play

1. **Start the game**:
    In the terminal, run the game with the command:
    ```bash
    ./so_long map_file.ber
    ```
    The `map_file.ber` is a `.ber` file that contains the layout of your game world.

2. **Game Controls**:
    - **W**: Move up
    - **A**: Move left
    - **S**: Move down
    - **D**: Move right
    - **Arrow Keys**: You can also use the arrow keys to move the player in the respective directions (up, down, left, right).
    - **ESC**: Exit the game

3. **Objective**:
    The goal is to navigate through the maze, collect items (such as keys or coins), and reach the exit. Be cautious of obstacles and enemies that may be scattered around the map.

4. **Map Layout**:
    - **P**: Player's starting position
    - **C**: Collectible item (e.g., a coin)
    - **E**: Exit
    - **1**: Wall (impassable)
    - **0**: Free space (walkable)

## Notes
- The game ends once the player reaches the exit (`E`) after collecting all required items (usually the collectibles represented by `C`).
- The player cannot pass through walls (`1`).
- The map must be carefully designed, ensuring that there is a valid path to the exit.
