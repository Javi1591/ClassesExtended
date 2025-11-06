# NumDays, TimeOff, and Personnel Report (Chapter 14)

A C++ console program that models employee work hours, vacation, and sick leave using object-oriented programming concepts. This project demonstrates **class composition**, **operator overloading**, and **data validation** through the `NumDays` and `TimeOff` classes.

## Overview
- The `NumDays` class stores hours worked and converts them to days (8 hours = 1 day).  
- The `TimeOff` class stores employee information (name and ID) along with several `NumDays` objects to track:
  - Maximum and used sick leave
  - Maximum and used vacation time
  - Maximum and used unpaid time
- The program prompts the user for employee details, calculates available leave based on months worked, and displays a formatted personnel report.

## Core Logic
- `NumDays` Class:
  - Stores `hours` and provides methods to convert to days (`getDays()`).
  - Overloads operators `+`, `-`, prefix/postfix `++`, and prefix/postfix `--` to modify or combine hour values.
- `TimeOff` Class:
  - Contains `NumDays` objects for all time categories.
  - Uses input validation to ensure vacation hours never exceed **240.0 hours** (company policy).
  - Includes a helper function `calcMaxFromMonths(int months)` that:
    - Grants **12 hours of vacation** and **8 hours of sick leave per month** worked.
    - Caps vacation hours at 240.0.
- Main program:
  - Prompts for employee name, ID, and months worked.
  - Creates a `TimeOff` object and calculates maximum leave values.
  - Displays the results in a formatted summary using `setprecision(2)` and `fixed`.

## Input Validation
- Negative month values are corrected to zero.
- Vacation hours are capped at 240.0 (maximum accrual limit).
- Employee information is read safely using `getline()` and validated for proper data types.

## Build & Run
- Visual Studio (Windows): open the solution or create a Console App and add the source file, then **Build → Run**.
- g++ (CLI):
  ```bash
  g++ -std=c++11 -O2 -o TimeOffReport nazarioCPP214.cpp
  ./TimeOffReport
