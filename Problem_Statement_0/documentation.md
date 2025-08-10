# 📝 Calcualator PS0

A simple CLI calculator.

---

## Problem Understanding
**What the problem is asking:**<br>
The ps0 was to build a simple CLI calculator, which can perform operations like simple arithmetic as well as trignometric and exponential operations.<br>

**Key concepts involved:** <br>
I used cin>>, vectors, to take input and binary search to calculate square root.

**My approach:**<br>
I used cin >> number >> op >> number to take input from 1+2 and then pushed numbers into one vector and operators into another vector. Using these both vectors, I then performed calculations one by one from LEFT TO RIGHT. I didn't implement BODMAS.

---

##  Conceptual Learning

### **New Concepts I Discovered**
- **[Concept Name]:** I learned how '>>' breaks the input according to their types. i learned how to erase certain elements from vectors and got to revise binary search once more for the square root.

### **How I Applied These Concepts**
I used '>>' to easily seperate numbers from operators for later use and I used vectors to keep track of what numbers were with which operator. Binary search was way faster than linear search for finding square root.

### **Real-World Connections**
A simple command-line calculator may sound basic, but it required concepts like parsing input(the hardest part for me)and performing operations. This project got us to think about different mathematical algorithms for different operations.


<h1 style="color:red;">HOW TO USE THIS CALCULATOR?</h1>

After the prompt '>' is printed, for basic operation like +-/*^ you can write it like "1+2/3-4^5=". Can input as many spaces as you want and as many operations in one prompt as yu want. Operations witll be performed from left to right No bodmass. For functions like square root input 'sqrt 25', no equals to required but at least one space between sqrt and number in required. See **testing.jpeg** file for test screenshots.