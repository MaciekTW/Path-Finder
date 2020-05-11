# Path-Finder
Backtracking algorithm. 


## Description
##### This application uses backtracking to find a path to a harbor for our ship. The algorithm also counts the amount of moves that are needed to reach the destination.  The ship cannot sail on too shallow water, it means it has to avoid the Sea sectors where the water level is too low. The depth of a sector must be at least 5 so the ship could safely sail on it. This minimal depth and also the size of sea map can be easily changed in main file. 

## Text File Format

If we want to find a path to harbor for our ship we need to provide a name of text file **with** .txt extension as a command line argument
The file must include "depth map of the sea" (Depth of each sea sector represent by integer value). The harbor is located always in the lower right corner. And the starting point is located in upper left corner. Default size of the map is 8 x 8

Both the file and application have to be placed in the same folder.

Example form of a text file

``` 
6 6 7 9 7 9 8 3
4 2 5 4 1 9 3 2
4 5 3 4 3 6 7 6
2 1 1 5 4 2 1 8
1 4 9 7 7 7 9 8
7 7 6 4 4 5 1 2
8 5 4 2 6 6 6 9
9 8 6 9 7 2 1 6
```
The example file titled ***sea.txt*** has been included to repository.
