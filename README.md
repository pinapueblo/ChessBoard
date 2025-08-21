# ♟️ Arduino Chess/Checkers Timer + Custom Board + 3D-Printed Pieces

---

## 📌 Overview
This project combines CAD design, 3D printing, and Arduino programming to create a **custom chess set with an integrated timer**.  
The goal is to design and manufacture a **playable chessboard** with fully 3D-printed pieces and a **self-built chess timer**, housed in a custom case, powered by an Arduino and OLED display.

This project showcases:
- 🧩 CAD modeling (board, pieces, timer case)
- 🖨️ 3D printing and manufacturing
- ⚡ Arduino hardware integration (OLED, buttons, LEDs)
- 💻 Embedded programming for timing logic
- 🎮 A polished, playable final product

---

## 🏗️ Components

### 1. **3D-Printed Chessboard**
- Designed in CAD with integrated slots for electronics
- Board manufactured with a balance of durability and aesthetics
- Smooth finish for consistent gameplay

### 2. **3D-Printed Chess Pieces**
- Custom CAD designs for all 32 chess pieces and all 24 checkers pieces
- Printed for consistency in weight and balance
- Optional: weighted bases for stability

### 3. **Custom Chess Timer**
- CAD-designed enclosure with clean cutouts for OLED screen and buttons
- Two tactile push buttons (Start / Pause & Reset)
- Integrated Arduino logic for countdown tracking

### 4. **Electronics**
- **Arduino Uno/Nano** as controller  
- **0.96" OLED display** for timer output  
- **Tactile push buttons** for player inputs  
- **LED indicators** (optional, for visual cues)  
- Powered via USB or battery pack  

---

## ⚙️ Features
- Dual timer functionality (one per player)  
- Start/stop per button press  
- Adjustable initial time (configurable in code)  
- Visual feedback via OLED + LEDs  
- Portable and lightweight design  

---

## 🖼️ CAD & Manufacturing
- CAD files for:
  - Chessboard  
  - Chess pieces  
  - Timer enclosure (with embossed top)  
- Designed with print tolerances in mind (0.2–0.3 mm clearance for OLED & button fit)  
- Printed with PLA (can be adapted to other materials)  

---

## 🧑‍💻 Code
Arduino code handles:
- Button inputs (debounced)  
- Countdown timer logic  
- Pause/resume functions  
- OLED rendering of both player clocks  

All code lives in the [`/arduino`](./arduino) folder.  

---

## 🚀 Future Improvements
- Add buzzer for time warnings  
- Magnetic base or weighted pieces  
- Backlit board squares for modern look  
- Bluetooth/USB logging of moves & time  

---

## 📷 Gallery
(*Add photos of board, pieces, timer once printed and assembled*)  

---

## 🔧 How to Build
1. Print the provided CAD files  
2. Assemble chessboard & pieces  
3. Print timer enclosure  
4. Wire Arduino with OLED + buttons (see wiring diagram in `/docs`)  
5. Upload Arduino code  
6. Play chess with your custom set 🎉  

---

## 📜 License
MIT License – free to use, modify, and share.  

---
