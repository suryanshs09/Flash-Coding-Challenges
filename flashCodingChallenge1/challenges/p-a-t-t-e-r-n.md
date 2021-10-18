# p-a-t-t-e-r-n

## Problem Statement

You need to create a diamond-shaped layered pattern as the output of this challenge.
 Each layer of the pattern will conatin **lower case english alphabets** starting with a in the outermost layer then b in the layer within and so on.
 The alphabets in a single row are seperated by a specific string named `fillChar`.

_**Note:** there are spaces before each row starts and no spaces after row is completed in the pattern._

## Input

- The first line of input contains a single integer `n` denoting the size of the pattern. For example, if n=5, then pattern will contain alphabets from a to e.
- the second line will contain the string `fillChar`.

## Output

- the desired pattern.
 
## Constraints

- 1 &le; `n` &le; 26
- 1 &le; \| `fillChar` \| &le; 5
- every character ch ∈ `fillChar` is such that, ch ∉ \{\[a-z\], \[A-Z\] and \[0-9\]\}
- all pattern charachters \(that are not part of fillChar\) ∈ \[a-z\]
