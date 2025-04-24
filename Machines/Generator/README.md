# 3-Phase AC Generator Model (Speed-Based Load Input from Hardware Measurements)

This Simulink model replicates the behavior of a 3-phase synchronous generator supplying power to a resistive load, where the input conditions (such as prime mover speed) are based on **real hardware measurements**. The generator model incorporates a field voltage input and is tested under varying speed conditions, while the **load resistance remains constant**.

## Hardware Setup Summary

In the physical test bench:

- A **shunt DC motor** acts as the **prime mover**, driving a 3-phase synchronous generator.
- The DC motor speed is varied by adjusting its input **voltage**, thereby controlling the mechanical input to the generator.
- A **purely resistive load (R)** is connected to the generator output and kept **constant** throughout the experiment.
- Real-time values for **speed**, **voltage**, and **current** were measured across various operating conditions.

These measured values were then used to drive the simulation model below.

## Simulation Objective

This Simulink model simulates:

- How varying the prime mover speed affects generator output (voltage and current).
- The generated power at a constant resistive load.
- Measurement and visualization of:
  - Output RMS voltage and current
  - Prime mover mechanical input (power & speed)
  - Generated active power

## Model Overview

The model is organized into three main sections:
1. **Main Generator and Load Configuration** (top panel)
2. **Generator Input/Output Measurements** (bottom-left panel)
3. **Power Analysis at the Load** (bottom-center panel)

![3-Phase AC Generator Model](./a2755dc7-b8c4-465f-b5fa-9bbf18fff657.png)

### Key Components:
- **Synchronous Machine (pu)**: Represents the 3-phase AC generator.
- **Field Voltage Input**: Set to 48V.
- **Prime Mover Speed**: Provided from measured hardware input.
- **Breaker and 3-Phase RLC Load**: Models switching and load connection.
- **RMS Blocks**: For voltage and current measurement.
- **Power Calculation and Visualization Blocks**: Display power data and graphs.

## Visualization

- **Scope Blocks**: Track dynamic behavior.
- **XY Graph**: Plots relationships between input speed and power output.
- **Numerical Displays**: Show instantaneous electrical parameters.

---

## File Structure

- Main Simulink model file.
- Siganls
    - PrimeMoverSignal

---

## Notes

- Field voltage is fixed for all experiments at **48V**.
- Only **speed was varied** during data collection, while **resistive load remained constant**.
- All simulation behavior is driven by **actual measured inputs**, increasing real-world accuracy.

---

## Applications

- Educational demonstration of synchronous generator behavior under variable-speed driving.
- Real-world validation of simulation models with measured input conditions.
- Analysis of AC generator output with respect to mechanical input variation.

---

## License

This project is shared for academic and demonstration purposes only.