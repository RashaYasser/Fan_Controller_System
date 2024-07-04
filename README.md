# Temperature-Controlled Fan Controller System

This project aims to design a temperature-controlled fan using an ATmega32 microcontroller, where the fan automatically turns ON or OFF based on the temperature. The ATmega32 operates at a frequency of 1MHz. The system utilizes an LM35 temperature sensor to provide continuous analog output corresponding to the sensed temperature. This analog signal is then converted to a digital value by the ADC, and based on the calculated temperature, the fan speed is adjusted accordingly.

## System Components

### Hardware Components
- **Microcontroller**: ATmega32 (1MHz)
- **Temperature Sensor**: LM35
- **LCD**: 2x16 LCD
- **DC Motor**: Fan control
- **ADC**: Analog-to-digital converter
- **PWM**: Pulse-width modulation for motor speed control

### Pin Configuration
- **LCD Control Pins**:
  - RS: PD0
  - RW: Ground
  - E: PD2
- **LCD Data Bus**: All PORTC pins
- **Temperature Sensor**: Connected to ADC channel 2

## System Functionality

### Temperature Monitoring and Fan Control
1. **Temperature Sensing**: The LM35 sensor outputs an analog signal proportional to the temperature.
2. **Analog to Digital Conversion**: The ADC converts the analog signal to a digital value.
3. **Temperature Calculation**: The microcontroller calculates the temperature based on the digital value.
4. **Display Temperature**: The temperature is displayed on the LCD.
5. **Control Fan Speed**: Based on the temperature:
   - < 30°C: Turn off the fan.
   - ≥ 30°C: Turn on the fan at 25% speed.
   - ≥ 60°C: Turn on the fan at 50% speed.
   - ≥ 90°C: Turn on the fan at 75% speed.
   - ≥ 120°C: Turn on the fan at 100% speed.

### Display
The LCD continuously displays the current temperature and fan state.

### PWM Control
- **PWM Signal**: Generated from Timer0 to control the DC Motor speed.
- **Frequency**: 500Hz to control the DC Motor speed with a non-inverting mode and prescaler of F_CPU/8.
