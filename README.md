# ft_printf
 recode printf :astonished:

* [Introduction](#introduction)
* [Step by step](#step)
* [Study resources](#study)
* [Testing](#tests) 

## introduction  

The versatility of the printf function in C represents a great exercise in programming for us. This [project](https://github.com/paulahemsi/ft_printf/blob/main/en.subject.pdf) is of moderate difficulty. It will enable you to discover variadic functions in C.
The key to a successful ft_printf is a well-structured and good extensible code.

## step by step

First of all, I wrote [this little program](https://github.com/paulahemsi/ft_printf/blob/main/understanding_printf_flags.pdf) just to understand the subject and printf's flags.

Those are the format identifier's I nedd to recode:

%c | character				|
%s | string					|
%p | pointer				|
%d | decimal signed integer	|
%i | integer				|
%u | unsigned integer		|
%x | hex integer (lowercase)|
%X | hex integer (uppercase)|
%% | just the %				|

And those are the flags:

num	| (number between % and the identifier) minimum field width						|
- 	| left justify 																	|
0 	| field padded with 0's instead of blanks										|
. 	| maximum field width															|
* 	| indicates that the maximum or minimum field width will be passed as parameter	|

To be aware:

* flag '0' is ignored when flag '-' is present
* flag '0' results in undefined behavior with '%c', '%s' and '%p'
* flag '.' results in undefined behavior with '%c' and '%p'

(due my researches and empirical tests, 'undefined behavior' means the flags will be ignored, just as the '0' with '-')

## study || further reading

* [variadic functions -intro](https://www.youtube.com/watch?v=FgvrnYScdH8)


## tests
   
* [PFT_EXAM](https://github.com/cclaude42/PFT_2019)
* [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
* [ft_printf_test](https://github.com/cacharle/ft_printf_test)
