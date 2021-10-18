# Ted the Buider

## Problem Statement

You are Ted Mosby the architect, and creator of all the buildings in a particular block in New York city.
 One day you were eating sandwiches with your best friend Barney, when he asked; 
 
 > "Hey Ted, have you ever wondered what is the total volume of buildings you created in that block?".
 
 Luckily you have recently completed a mathematics and programming course on coursera.

 So, you replied to him, 

 > "Yeah Barney, I will tell you the answer when next time we meet for eating sandwiches".
 
 Then you went straight to your apartment opened your laptop and here you are coding it.
 
Assume, each building in the block is a perfect cuboid with no spaces present between them.
 The block is of length L and width W and each building has the same length of LB and width WB.
 You have the blueprint of the block in which height of each building is given in terms of number of floors(each floor is of 15 ft height).
 calculate the volume of the entire blocks in **meter cube**.

_**Note:** 1 meter = 3.280839895 ft_
 
## Input

- first line of input will contain four integers `L`, `W`, `LB` and `WB` the dimensions of block and a building respectively.(take input in same order)
- the rest of the lines will contain the height of each building **in terms of number of floors in them**.
 
## Output

- [the ceil value](https://en.wikipedia.org/wiki/Floor_and_ceiling_functions) of calculated volume of block.

_**Hint:** the volume may be a large number, choose the datatype wisely_

## Constraints

- `L` is a _multiple_ of `LB`
- `W` is a _multiple_ of `WB`
- 50 &le; LB, WB &le; 150
- 100 &le; L, W &le; 1650
- 1 &le; h &le; 100