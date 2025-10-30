# Pipex  
Re-implementation of Unix pipelines and redirections (e.g., `cmd1 | cmd2 > file`) in C at 42 Roma Luiss.

## What it does  
- Parses commands and their arguments from command line.  
- Establishes pipes between child processes.  
- Handles redirections (`>`, `>>`, `<`).  
- Properly handles multiple commands chained.  
- Ensures correct exit statuses and handles errors gracefully.

## Why it matters  
This project forces deep understanding of:  
- inter-process communication (`pipe`, `fork`, `dup2`)  
- input/output redirection internals  
- error checking and process exit statuses  
- memory management in a multi-process context  

## Tech stack  
C, Unix APIs, Makefile, Git

## Status  
✅ Completed  
Score: **100%**  
