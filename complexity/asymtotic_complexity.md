# Asymptotic complexity

Used for analyzing the running time and/or the space usage of programs as function of input size.
The asymptotic behaviour of a function `f(n)` refers to the behaviour (growth) of the function as `n` gets large. This means that for a large `n` the function `f(n) = c1 * n + d1` is always asymptotically better than a function say `g(n) = c2 * n^2 + d2`. This however may not be the case for small values of `n` if the values of `c2` and `d2` are much smaller than respectively `c1` and `d1`.

## Big O notation(big omega, big theta)

In order to check which algorithm is better it is not enough to measure the time. There are several reasons for that - different machines will record different time and furthermore for fast algorithms speed measurements may not be precise enough. Instead we look at the number of simple operations the computer has to perform.

### Formal definitions

* Big O  
  ![equation](https://latex.codecogs.com/gif.latex?%5Csmall%20O%28g%28n%29%29%20%3D%20%5C%7Bf%28n%29%20%7C%20%5C%20%5Cexists%20c%20%3E%200%2C%20%5Cexists%20%5C%20n_0%3A%20%5Cforall%20n%20%5Cgeq%20n_0%2C%20%5C%200%20%5Cleq%20f%28n%29%20%5Cleq%20c%20%5Ccdot%20g%28n%29%5C%7D)
* Big Omega  
  ![equation](https://latex.codecogs.com/gif.latex?%5Csmall%20%5COmega%28g%28n%29%29%20%3D%20%5C%7Bf%28n%29%20%7C%20%5C%20%5Cexists%20c%20%3E%200%2C%20%5Cexists%20%5C%20n_0%3A%20%5Cforall%20n%20%5Cgeq%20n_0%2C%20%5C%200%20%5Cleq%20c%20%5Ccdot%20g%28n%29%20%5Cleq%20f%28n%29%5C%7D)
* Big Theta  
  ![equation](https://latex.codecogs.com/gif.latex?%5Csmall%20%5CTheta%28g%28n%29%29%20%3D%20%5C%7Bf%28n%29%20%7C%20%5C%20%5Cexists%20c1%2Cc2%20%3E%200%2C%20%5Cexists%20%5C%20n_0%3A%20%5Cforall%20n%20%5Cgeq%20n_0%2C%20%5C%200%20%5Cleq%20c1%20%5Ccdot%20g%28n%29%20%5Cleq%20f%28n%29%20%5Cleq%20c2%20%5Ccdot%20f%28n%29%20%5C%7D)

Said otherwise big-O gives an upper bound of the complexity in the worst case that is the maximum number of operations that might be performed.
In the table below are listed classes of functions that you can encounter.

Big O notation| order of growth
:---: | :---:
O(1)|constant
O(log n)|logarithmic
O(n)|linear
O(n log n)|"n log n"
O(n^2)|quadratic
O(n^3)|cubic
O(n^c)|polynomial
O(c^n)|exponential

![Big-O](big-O.jpg)
![Big-O-ComplexityChart](big-O-complexity-chart.jpg)

## Useful resources

* [Big O notation](http://web.mit.edu/16.070/www/lecture/big_o.pdf)
* [Big O cheat sheet](https://www.bigocheatsheet.com/)
