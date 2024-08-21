# Game of Life

## Getting Started

Follow these steps to set up and run the `Game of Life` project.

### 1. Clone the Repository

First, clone the repository to your local machine:

```bash
git clone https://github.com/powerpuff-luv/game_of_life.git
cd game_of_life/src
```

### 2. Install Required Libraries

This project requires the ncurses library. Install it using your package manager:

#### On Debian/Ubuntu:

```bash
sudo apt-get update
sudo apt-get install libncurses5-dev libncursesw5-dev
```

#### On CentOS/RHEL/Scientific Linux 6.x/7.x+ and Fedora Linux 21 or older:

```bash
sudo yum install ncurses-devel
```

#### On macOS:

```bash
brew install ncurses
```

### 3. Compile the Game

Compile the "game_of_life.c" file using "gcc":

```bash
gcc -o game_of_life game_of_life.c -lncurses
```

### 4. Run the Game

Now you're ready to run the game, select any initial image from the data directory:

```bash
./game_of_life < data/data1.txt
```

#### stdin:</br>

'a' - speed up</br>
'z' - slow down</br>
'q' - quit the game
