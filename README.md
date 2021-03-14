# DAA_Assignment
Guting paper implementation
## Problem statement
There are N rectangles. Each rectangle consists of 4 points in the 2D coordinate system as  (X1,Y1) , (X2,Y2), (X3,Y3), (X4,Y4).

Compute the measure and contour of the given set of iso rectangles

## Constraints
-1e16 ≤ (Xi, Yi) <= 1e16

## Input
### Input is given from textfile input.txt in the following format:
N

X11 Y11 X12 Y12 X13 Y13 X14 Y14

.

.

.

XN1 YN1 XN2 YN2 XN3 YN3 XN4 YN4





## Output
M denotes the number of edges
each edge is represented as (X1,Y1) to (X2,Y2) with string type after the corrdinates

type == "Yes" or "No"

Yes means it is part of contour

No means it is not part of contour

### output is given in textfile output.txt in the following format:
M
X11 Y11 X12 Y12 X13 Y13 X14 Y14 type1

.

.

.

XM1 YM1 XM2 YM2 XM3 YM3 XM4 YM4 typeM





