- read an fdf map using get next line and store all points in an array of arrays of ints
- for every index in children arrays raise x by one unit
- for every index in the parent array raise y by one unit
- set z to the int value of every index
- do whatever rotations wanted to all points
- put all the points on the plane
- bresenham each point with y = m where m is a constant to the point next to it x = x+1
- bresenham each point with x = m where m is a constant to the point next to it y = y+1
- connect dots

  - loop through the array, record the biggest Y and the biggest X
  - look in the range 0 to X and 0 to Y
  - loop through all points and connect those who have the same X
  - loop through all points and connect those who have the same Y

- add an x sorted array of points
