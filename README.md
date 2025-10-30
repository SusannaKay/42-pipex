# Pipex
Reimplementation of basic shell piping (`cmd1 | cmd2`) using low-level UNIX system calls in C.  
42 Roma Luiss project.

---

## 🧩 Project Goal

Recreate the behavior of the following shell command:

```bash
< infile cmd1 | cmd2 > outfile
```

The program must:
1. Read from `infile`
2. Run `cmd1`
3. Pipe the output of `cmd1` into `cmd2`
4. Write the final result into `outfile`

All of this must be done manually using `fork`, `pipe`, `dup2`, and `execve`, without relying on the shell.

This project is the **mandatory part only**:
- exactly 2 commands
- a single pipe
- standard input redirection and output redirection
- no here_doc, no multiple chained commands

---

## ⚙️ How It Works

### 1. Argument parsing
The program expects exactly 4 arguments:
```txt
./pipex infile "cmd1 args..." "cmd2 args..." outfile
```

It will:
- open `infile` for reading
- open/create `outfile` for writing
- split each command string into an argv-style array using `ft_split`
- resolve each command's executable path using `$PATH`

### 2. Creating the pipe and processes
The parent process:
1. Creates a pipe `fd[2]`
   - `fd[0]` = read end  
   - `fd[1]` = write end  
2. Forks twice:
   - first child runs `cmd1`
   - second child runs `cmd2`

### 3. First child (cmd1)
- Redirects `infile` → `STDIN` using `dup2(infile_fd, STDIN_FILENO)`
- Redirects `STDOUT` → pipe write end using `dup2(fd[1], STDOUT_FILENO)`
- Closes unused fds
- Calls `execve()` with the resolved command path

Result: `cmd1` reads from the file and writes into the pipe.

### 4. Second child (cmd2)
- Redirects pipe read end → `STDIN` using `dup2(fd[0], STDIN_FILENO)`
- Redirects `STDOUT` → `outfile` using `dup2(outfile_fd, STDOUT_FILENO)`
- Closes unused fds
- Calls `execve()` with the resolved command path

Result: `cmd2` reads what `cmd1` produced, and writes final output to the file.

### 5. Parent
- Closes all file descriptors
- Waits for both children with `waitpid()`
- Returns the final exit status

---

## 🔄 Execution Flow (visual)

```txt
          fork() child 1                 fork() child 2
        +--------------+               +----------------+
infile →|    cmd1      | --pipe--> ---->|      cmd2      | → outfile
        +--------------+               +----------------+

- child 1:
    stdin  = infile
    stdout = pipe write end

- child 2:
    stdin  = pipe read end
    stdout = outfile
```

In terms of file descriptors:

```txt
infile_fd  -> dup2(..., STDIN_FILENO)  in first child
fd[1]      -> dup2(..., STDOUT_FILENO) in first child

fd[0]      -> dup2(..., STDIN_FILENO)  in second child
outfile_fd -> dup2(..., STDOUT_FILENO) in second child
```

---

## 🔍 Command path resolution

To execute a command like `ls -l`, the program:
1. Extracts the `PATH` environment variable
2. Splits it into directories (e.g. `/bin`, `/usr/bin`, …)
3. Joins each directory with the command name (`/bin/ls`, `/usr/bin/ls`, …)
4. Uses `access(path, X_OK)` to find the first executable match
5. Calls `execve()` with that full path

If the command cannot be found or executed, an error message is printed and the child exits.

---

## 🧰 Allowed operations / syscalls used

- `open`, `close`
- `pipe`
- `fork`
- `dup2`
- `execve`
- `waitpid`
- `access`
- string/memory utilities from a custom `libft`

No higher-level helpers from the shell are allowed.

---

## 🧼 Error handling

The program handles:
- missing files / permission errors
- invalid commands
- failures in `fork`, `pipe`, `dup2`, `execve`, etc.
- freeing allocated memory for command argument arrays before exiting the child

If something fails, it reports the error using `perror()` or a custom error print, and exits with a non-zero status.

---

## 📦 Tech Stack

- C (POSIX)
- manual file descriptor management
- process control and IPC (inter-process communication)
- custom `libft` for string handling, split, etc.
- Makefile

---

## ✅ Status

- Mandatory part completed  
- Final evaluation: **100%**
