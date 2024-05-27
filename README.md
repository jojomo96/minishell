<p align="center">
  <img src="https://github.com/ayogun/42-project-badges/blob/main/badges/minishellm.png?raw=true" alt="minishell"/>
</p>

<p align="center">
  Score: <i>125/100</i><br>
  Finished: <i>27.05.2024</i><br>
  Team: <a href="https://github.com/jojomo96" target="_blank">@jojomo96</a> & <a href="https://github.com/flomero" target="_blank">@flomero</a>
</p>

# minishell
*As beautiful as a shell*

Summary:
> This project is about creating a simple shell. Yes, your own little bash. You will learn a lot about processes and file descriptors.

# Usage
```bash
$ make
$ ./minishell
```

![shell screenshot](/.imgs/shell.png)

# Features
- A Prompt just like Bash with working history
- History is saved during sessions
- Builtin Commands:
  - `echo` (with option -n)
  - `cd` (with relative & absolute path and - and ~)
  - `pwd`
  - `export` (with and without args, supports `+=`)
  - `unset`
  - `env`
  - `exit`
- execution of external Commands using the `$PATH`, as well as relative or absolute Paths
- Redirections: `<`, `>`, `<<` & `>>`
- Logic Operators: `&&`, `||` and parenthesis
- Pipes `|`: The output of each command in the pipeline is connected to the input of the next command via a pipe.
- Expansion:
  - handle env Variables starting with `$`
  - handle `$?`
  - handle wildcard expansion using `*` and `?`
- Support interactive and non-interactive mode
- Signal Handling for <kbd>CRTl+C</kbd>, <kbd>CRTl+D</kbd> & <kbd>CRTl+\\</kbd>

# Debug
- run `make debug` to enable debug prints
- run `make tree` to enable outputting of the AST to dot-format

## Example of AST Visulization

```bash
(echo ok1 && echo ok2) || cd /fail3 && echo ok4 || echo ok5 || echo ok6 | grep ok1 >> out
```

![Ast Visualization](/.imgs/ast.png)