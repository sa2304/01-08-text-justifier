I wrote this text formatter as an exercise 1.8 from Alfred V. Aho "Data Structures and Algorithms" book. 

As recommended in "1.6 Good Programming Practice" I wrote a tool that could also be chained with other command line tools.

Program formats text paragraph to specific width with text alignment to left, right, center or justify.

### Usage
```shell
a.out $width l|r|j|c $filename
```

### Examples
```shell
# line width 80, align left   
a.out 80 l input.txt
# line width 30, justify
a.out 30 j input.txt
# Read stdin, line width 40, left align by default
cat input.txt | a.out 40
```

### Author
Anton Schmidt <schmidt.ajax@yandex.ru>, 2023