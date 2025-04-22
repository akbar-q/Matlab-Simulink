# Conversion Table: 0–100% to 0–4096 Scale

This table converts an input value in the range of 0 to 100 (representing a percentage) into a corresponding value in the range 0 to 4096 using the following formula:

Output = (Input ÷ 100) × 4096


| Input | Input ÷ 100 | × 4096 Result | Final Output (Rounded) |
|-------|-------------|---------------|-------------------------|
| 0     | 0.00        | 0.0           | 0                       |
| 10    | 0.10        | 409.6         | 410                     |
| 20    | 0.20        | 819.2         | 819                     |
| 30    | 0.30        | 1228.8        | 1229                    |
| 40    | 0.40        | 1638.4        | 1638                    |
| 50    | 0.50        | 2048.0        | 2048                    |
| 60    | 0.60        | 2457.6        | 2458                    |
| 70    | 0.70        | 2867.2        | 2867                    |
| 80    | 0.80        | 3276.8        | 3277                    |
| 90    | 0.90        | 3686.4        | 3686                    |
| 100   | 1.00        | 4096.0        | 4096                    |

## Notes
- The output is calculated by first dividing the input percentage by 100, then multiplying the result by 4096.
- The final output is rounded to the nearest integer for practical use, such as in digital resolution scaling or analog-to-digital conversion.