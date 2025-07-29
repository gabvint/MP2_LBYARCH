<h1 align = "center"> <b> LBYARCH MP2 </b> </h1>
<h4 align = "center"> A kernel in C program and x86-64 assembly language that performs a dot product between vector A and vector B </h4>
<p align = "center"> <i> by Gabrielle Tongol & Royce Vergara </i> </p>

## 1. Comparative Execution Time & Performance Analysis

This section presents the **average execution time (in seconds)** for both the **C** and **x86-64 Assembly** implementations of the dot product kernel, measured over 20 runs.

| Vector Size (Elements)   | C Average Time (sec) | x86-64 ASM Average Time (sec)  |
|--------------------------|----------------------|--------------------------------|
| 2^20 (1,048,576)         | *0.004450*           | *0.001200*                     |
| 2^24 (16,777,216)        | *0.072050*           | *0.022350*                     |
| 2^28 (268,435,456)       | *0.977800*           | *0.279800*                     |

**Analysis:**  
The x86-64 assembly version of the kernel has a faster average time than the C version for all test cases.

---

## 2. Screenshot: C Program Output



---

## 3. Screenshot: x86-64 Assembly Program Output


---

## 4. Short Video


---
