# ♟️ Arduino Chess Timer + Custom Board + 3D-Printed Pieces

This project combines electronics, CAD, and digital fabrication to create a fully custom **chess set with a built-in timer**! It includes a **3D-printed case for an Arduino-powered timer**, **laser-cut chessboard**, and a complete set of **3D-printed chess pieces**.

---

## 🧠 Features

- ✅ Arduino Uno-based **digital chess timer**
- ✅ Custom-designed and **3D-printed enclosure**
- ✅ Full set of **chess pieces**, designed and printed in PLA
- ✅ **Laser-cut chessboard** made from wood or acrylic
- ✅ Diagonal vent slits for cooling
- ✅ Minimalist, clean internal layout

---

## 🛠️ Project Components

### Electronics

- Arduino Uno (or Nano)
- 0.96" OLED Display (SSD1306 I2C)
- 2x Momentary Push Buttons
- Jumper Wires (M–F)
- Power via USB or battery

### Mechanical

- `case.STL` — Timer enclosure
- `chess_pieces/` — Full STL set: pawn, rook, bishop, knight, queen, king
- `chessboard.dxf` — Laser-cuttable board layout (standard 8×8 grid)
- Optional: Screws or adhesive for Arduino mounting

---

## 🖨️ 3D Print Settings

| Component     | Material | Infill  | Layer Height | Supports |
|---------------|----------|---------|--------------|----------|
| Case & Lid     | PLA      | 20–30%  | 0.2 mm       | No       |
| Chess Pieces   | PLA      | 10–15%  | 0.1–0.2 mm   | Yes (for overhangs) |

---

## 🔪 Laser Cut Settings

- Material: 1/8" or 1/4" wood / acrylic
- File: `chessboard.dxf`
- Suggested Layer: Vector Cut for squares and border
- Optional: Etch grid labels (A–H, 1–8)
