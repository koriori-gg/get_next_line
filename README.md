<h1 align="center">
	📖 get_next_line
</h1>
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/koriori-gg/get_next_line?color=blue">
	<img alt="GitHub language count" src="https://img.shields.io/github/languages/count/koriori-gg/get_next_line?color=yellow">
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/koriori-gg/get_next_line">
</p>
<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
</h3>


## 💡 About the project
This project is about reading a line on fd.
## 🛠️ Usage
### Requirements
The function is written in C language and thus needs the gcc compiler and some standard C libraries to run.

### Instructions
#### 1.clone
```
git clone git@github.com:koriori-gg/ft_printf.git
```
#### 2. Using it in your code
To use the function in your code, simply include its header:
```
#include "/include/ft_printf.h"
```
and, when compiling your code, add "libftprintf.a":
```
gcc -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c 
./a.out
```
