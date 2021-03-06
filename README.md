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

First of all, I wrote [this little program](understanding_printf_flags.c) just to understand the subject and printf's flags.

Those are the format identifier's I nedd to recode:

%  | type |
---|------|
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

flag| ? |
----|---|
num	| (number between % and the identifier) minimum field width						|
'-' 	| left justify 																	|
'0' 	| field padded with 0's instead of blanks										|
'.' 	| maximum field width															|
'*' 	| indicates that the maximum or minimum field width will be passed as parameter	|

To be aware:

* flag '0' is ignored when flag '-' is present
* flag '0' results in undefined behavior with '%c', '%s' and '%p'
* flag '.' results in undefined behavior with '%c' and '%p'

(due my researches and empirical tests, 'undefined behavior' means the flags will be ignored, just as the '0' with '-')

## study || further reading

* [variadic functions -intro](https://www.youtube.com/watch?v=FgvrnYScdH8)
* [va-arg](https://www.tutorialspoint.com/c_standard_library/c_macro_va_arg.htm)
* [layout of directories](http://syque.com/cstyle/ch7.1.htm)
* [format specification syntax](https://docs.microsoft.com/pt-br/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=msvc-160)

## tests
   
* [PFT_EXAM](https://github.com/cclaude42/PFT_2019)
* [42TESTERS-PRINTF](https://github.com/Mazoise/42TESTERS-PRINTF)
* [ft_printf_test](https://github.com/cacharle/ft_printf_test)
