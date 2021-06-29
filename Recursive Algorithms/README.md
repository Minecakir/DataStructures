# Recursive Algorithms
You are asked to implement a program that takes a text file containing the snapshot of a set of objects (called blobs), and compute the number of pixels, center of mass for each blob on the screen. 
A blob pixel on the given file is indicated by a ‘X’ char, and a non-blob pixel is indicated by a space char. 
**A blob is defined to be a set of connected pixels, where a pixel (r, c) is connected only to its 4 neighbors.**
**That is, the pixel (r, c) can be connected to its LEFT neighbor (r, c-1), its RIGHT neighbor (r, c+1), its UP neighbor (r-1, c) and its DOWN neighbor (r+1, c).**
Your job is to find all pixels that make up each blob and also compute the blob’s center of mass, which is defined to be the average of the coordinates making up the blob in the x and y coordinates. 
Consider the following example file: blob1.txt (This file is given to you).

![image](https://user-images.githubusercontent.com/67970973/123843432-90ffea80-d91a-11eb-8481-07b494c0c714.png)

- The first row of the file contains the number of rows (10) and the number of columns (20) in this file. As you can see there are 3 blobs in the file: Two rectangles and a triangle. 
- Your program will first prompt the user for the name of this file. It will then read this file and create a two-dimensional array to store the pixels (either an ‘X’ indicating a pixel belonging to a blob, or a space character indicating that the pixel is empty). 
- You are then asked to implement a recursive algorithm that takes this 2D array and compute the number of pixels and the center of mass for each blob.
- Your program must first print the input matrix on the screen and then print the result. An example output for the above input file is given below. Your output must match our output:

![image](https://user-images.githubusercontent.com/67970973/123843573-bd1b6b80-d91a-11eb-9f56-ab605bfd563a.png)

- As you can see from our output given above, you must first print the input file in a nicely formatted table.
-  Then you must process the input and print statistics for each blob: The blob number, the number of pixels making up the blob, and its center of mass (CoM) in the y and x coordinates, that is, CoM Row and CoM Column.


👨‍💻Click the link below for solution

[main.cpp](https://github.com/Minecakir/DataStructures/blob/main/Lab1/main.cpp)

### Different txt Files and Output Results

![Screenshot_1](https://user-images.githubusercontent.com/67970973/99145670-c99bce00-2681-11eb-9f77-f42b9944ff4d.png)

👨‍💻[Click here to access the txt file used in this solution](https://github.com/Minecakir/DataStructures/blob/main/Recursive%20Algorithms/blobs1.txt)

![Screenshot_2](https://user-images.githubusercontent.com/67970973/99145672-cb659180-2681-11eb-9579-ff1e2cca8c9c.png)

👨‍💻[Click here to access the txt file used in this solution](https://github.com/Minecakir/DataStructures/blob/main/Recursive%20Algorithms/blobs2.txt)

![Screenshot_3](https://user-images.githubusercontent.com/67970973/99145674-cc96be80-2681-11eb-804c-0dd445d91434.png)

👨‍💻[Click here to access the txt file used in this solution](https://github.com/Minecakir/DataStructures/blob/main/Recursive%20Algorithms/blobs3.txt)

![Screenshot_4](https://user-images.githubusercontent.com/67970973/99145675-cef91880-2681-11eb-8978-68055f77a31b.png)

