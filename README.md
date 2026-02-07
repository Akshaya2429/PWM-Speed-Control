# PWM Speed Control – Command-Based Robot Motion


## 🎯 Challenge Objective

Build a robot that can move in different directions and at different speeds using **PWM (Pulse Width Modulation)**.

This challenge focuses on **speed as an engineering parameter**, not just movement.

### Outcomes

- Understand how speed affects precision and stability.
- Learn how PWM controls motor power.
- Use commands and parameters together in robotic systems.

---

## 📌 Problem Statement

In real robotic systems, controlling direction alone is not enough.

- A robot moving too fast loses control and accuracy.
- A robot moving too slow becomes inefficient.

Your task is to build a robot where:

- Direction is controlled using single-character commands.
- Speed is controlled using PWM values.
- All inputs are provided through the Arduino Serial Monitor.

---

## ⚙️ System Type

- Manual command-based control with variable speed
- **Input:** Serial commands
- **Processing:** Command parsing + PWM logic
- **Output:** Motor speed and direction

---

## 🎮 Command Set

| Command | Action |
|---------|--------|
| F | Move Forward |
| B | Move Backward |
| L | Turn Left |
| R | Turn Right |
| S | Stop |

---

## 🚀 Task – Command-Based Speed & Direction Control

### Objective

Control both robot direction and speed through the Arduino Serial Monitor.

### Requirements

- Respond to direction commands (`F`, `B`, `L`, `R`, `S`)
- Support PWM duty cycles of:
  - 25%
  - 50%
  - 75%
  - 100%



---
