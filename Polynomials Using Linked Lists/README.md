<h3 align="center">Polynomials Using Linked Lists</h3> 


### 1 Assignment
In mathematics, a polynomial is an expression constructed from variables (also known as indeterminates) and constants,
using the operations of addition, subtraction, multiplication, and constant non-negative whole number exponents. 
For example, x²-4x+7 is a polynomial, but x²-(4/x)+7x^3/2 is not, because its second term involves division by the variable
x and also because its third term contains an exponent that is not a whole number.

Polynomials are one of the most important concepts in algebra and throughout mathematics and science. They
are used to form polynomial equations, which encode a wide range of problems, from elementary word problems to
complicated problems in the sciences; they are used to define polynomial functions, which appear in settings ranging from
basic chemistry and physics to economics, and are used in calculus and numerical analysis to approximate other functions.
Polynomials are used to construct polynomial rings, one of the most powerful concepts in algebra and algebraic geometry.
In this lab you will implement several functions to create and manipulate polynomials. The terms of the polynomial
will be stored in a singly linked list in decreasing order of the exponent values.

![image](https://user-images.githubusercontent.com/67970973/108620463-6ddd9f80-743d-11eb-89c1-1834c74da131.png)

Figure 1 depicts how P(x)=2.34x^4 − 4x + 5 and −x^5 + 6x^3 + 5.1x^2 − 8x are represented by linked lists. As seen, each
term of the polynomial is represented by a PolyNode struct (defined in PolyNode.h), which consists of a coefficient and
an exponent. While a coefficient can be a real number, the exponent must be a natural number, i.e., an integer. The
terms of the polynomial are stored in decreasing order of their exponents in the linked list.

![image](https://user-images.githubusercontent.com/67970973/108620528-c876fb80-743d-11eb-80fc-33752f5fe618.png)


![image](https://user-images.githubusercontent.com/67970973/108620553-e80e2400-743d-11eb-82b9-0f235a01d8a5.png)

![image](https://user-images.githubusercontent.com/67970973/108620571-007e3e80-743e-11eb-90cf-bd85bd652978.png)

### OUTPUT

![image](https://user-images.githubusercontent.com/67970973/108620612-4cc97e80-743e-11eb-9728-0cfbaf268f5a.png)

![image](https://user-images.githubusercontent.com/67970973/108620624-5fdc4e80-743e-11eb-93e5-83b1507954e6.png)


