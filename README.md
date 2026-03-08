# Memory STEM Toy – MindSpark

MindSpark is an interactive educational toy designed to improve
memory, pattern recognition, and logical thinking in children
through an engaging game-based learning system.

The toy uses LEDs, buttons, sound feedback, and an LCD display
to create pattern recognition challenges where players must
repeat LED sequences correctly to progress through levels.

---

## Features

- Interactive memory pattern game
- Multi-level difficulty progression
- Visual and audio feedback
- Score and level tracking
- Real-time game information display

---

## Hardware Components

- Arduino Nano / ESP32
- 4 Push Buttons
- 4 Colored LEDs
- Piezo Buzzer
- 20x4 LCD Display
- Breadboard
- Resistors
- USB Power Supply

---

## How It Works

1. The system generates a random LED pattern.
2. LEDs flash with buzzer sound to show the sequence.
3. The player repeats the pattern using buttons.
4. The system checks the input.
5. If correct → Level increases.
6. If incorrect → Game over.

---

## Hardware Architecture

The Arduino microcontroller controls all input and output devices.

Inputs:
- Push buttons
- Potentiometer (mode selection)

Outputs:
- LEDs
- Buzzer
- LCD display

---

## Software Architecture

The software runs a continuous game loop with these modules:

- Hardware initialization
- Pattern generation
- Pattern display
- Player input detection
- Response verification
- Level progression system

---

## Simulation

Tinkercad simulation link:

[Insert your Tinkercad link here]

---

## Future Improvements

- Multiple game modes
- Mobile app connectivity
- Wireless communication using ESP32
- AI-based adaptive difficulty

---

## Educational Value

This project helps develop:

- Pattern recognition
- Short-term memory
- Logical thinking
- STEM learning engagement

---

## Authors

Team MindSpark (Vishwarupa, Haripriya, Arya, Shravani)
STEM Educational Toy Development Project
