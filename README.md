# Geometry Dodge

**Geometry Dodge** is a simple and engaging 2D game where the objective is to dodge various geometric objects to achieve the highest score possible. Developed as part of a C++ course in my Computer Science studies, this project leverages the Raylib library for graphics rendering.

## About

In **Geometry Dodge**, the player controls a character that must avoid colliding with random geometric shapes. The longer you avoid the obstacles, the higher your score will be. As the game progresses, the difficulty increases, challenging the player to react faster and more strategically. When you collide with an object, it's game over, but you can press any key to restart the game.

This game is built using C++ and the Raylib library, a simple and easy-to-use game development library for creating 2D games. The project was created as part of my computer science course.

The game logic and structure are based on the template provided by [tupini07/raylib-cpp-cmake-template](https://github.com/tupini07/raylib-cpp-cmake-template/tree/main).

The sprites of the character are from a template provided on itch.io: https://gibbongl.itch.io/8-directional-gameboy-character-template.

## Gameplay

- The player controls a character that moves on the screen.
- Various geometric objects (e.g., squares, circles) bounce random from the top of the screen.
- The goal is to avoid these objects and survive for as long as possible to achieve a high score.
- The longer you survive, the more challenging the game becomes.
- When you get hit by an object, the game ends. You can press any key to restart the game.

## Controls

- **W**: Move up
- **A**: Move left
- **S**: Move down
- **D**: Move right
- **R**: Press to restart the game after a game over

## Installation

1. **Clone the repository**:

   ```bash
   git clone https://github.com/AuriomTex/CPP_Project.git
   cd CPP_Project
   ```

2. **Run the Game**:

   ```bash
   cd build
   ./CPP_Project.exe
   ```
