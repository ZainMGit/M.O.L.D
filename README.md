# M.O.L.D (Moisture Optimization and Level Detection)


M.O.L.D is a simple Arduino-based dehumidifier controller. The project monitors room humidity and automatically activates a fan when the air is too damp. It also checks the water level in the collection tray and warns the user when it is full.

## Features

- **Humidity Sensing**: Uses a DHT11 sensor to read temperature and relative humidity.
- **Automatic Fan Control**: Turns a fan on or off whenever humidity crosses a certain thresholds 
- **Water Level Detection**: A float switch lights the red LED when the water tray is full.
- **Status Display**: A 16x2 I²C LCD shows current temperature and humidity.
- **Circuit Design**: KiCad schematic and PCB files are provided in the `M.O.L.D Circuit Diagram (KiCad)` directory, along with a PDF export.

## Hardware Connections
If using the Arduino Uno R4 microcontroller:  
| Component        | Arduino Pin |
|------------------|-------------|
| DHT11            | D2          |
| Fan              | D3          |
| Green LED        | D4          |
| Float Switch     | D7          |
| Red LED          | D8          |
| LCD (I²C)       | A4 (SDA) / A5 (SCL) |


See the schematic PDF (`M.O.L.D Circuit Diagram.pdf`) for the full wiring diagram.

## Building and Uploading

1. Install the `DHT11` and `LCD_I2C` libraries through the Arduino Library Manager.
2. Open `M.O.L.D.ino` in the Arduino IDE.
3. Compile and upload the sketch.

