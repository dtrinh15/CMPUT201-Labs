
#### hase-ki Lab5 Feedback


#### Part 1:

	Makefile  -  1.00/1.00

	check_nesting - detects correct nesting  -  1.00/1.00

	check_nesting - detects incorrect nesting  -  1.00/1.00
	- ./check_nesting throws error for input '({({)}})'. Should output 'Parentheses are not nested properly' to stdout.
	- ./check_nesting throws error for input '){}}'. Should output 'Parentheses are not nested properly' to stdout.
	- ./check_nesting throws error for input '{({)}{}}'. Should output 'Parentheses are not nested properly' to stdout.
	- ./check_nesting throws error for input '{{((()))}'. Should output 'Parentheses are not nested properly' to stdout.
	- ./check_nesting throws error for input '{}(){}('. Should output 'Parentheses are not nested properly' to stdout.

	check_nesting - ignores extra characters  -  1.00/1.00

	check_nesting - handles buffer overflows  -  1.00/1.00
	- ./check_nesting has incorrect output for input '((((((((((()))))))))))'. Should output 'Stack overflow' to stderr.
	- ./check_nesting throws error for input '(((((((((())))))))))'. Should output 'Parentheses are nested properly' to stdout.

#### Total:

	Total for assignment:  -  5.00/5.00

Grader: Kushol
