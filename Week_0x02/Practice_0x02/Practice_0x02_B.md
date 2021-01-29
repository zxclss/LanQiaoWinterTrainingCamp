# Practice_0x02

## B - 3-B

### Problem:

There are ${N}$ integers ${a_1,a_2,...,a_N}$ not less than ${1}$. The values of ${a_1,a_2,...,a_N }$are not known, but it is known that ${a_1×a_2×...×a_N=P}$.

Find the maximum possible greatest common divisor of ${a_1,a_2,...,a_N}$.

### Constraints

- ${1≤N≤10^{12}}$
- ${1≤P≤10^{12}}$

### Input

Input is given from Standard Input in the following format:

```
N P
```

### Output

Print the answer.

### Sample Input 1

```
3 24
```

### Sample Output 1

```
2
```

The greatest common divisor would be ${2}$ when, for example, ${a1=2,a2=6}$ and ${a3=2}$.

-----------



### Sample Input 2

```
5 1
```

### Sample Output 2

```
1
```

As ${a_i}$ are positive integers, the only possible case is ${a_1=a_2=a_3=a_4=a_5=1}$.

----------------



### Sample Input 3

```
1 111
```

### Sample Output 3

```
111
```

---------------



### Sample Input 4

```
4 972439611840
```

### Sample Output 4

```
206
```



[OJ地址](https://atcoder.jp/contests/caddi2018/tasks/caddi2018_a?lang=en)