# get_next_line

## 📖 About

`get_next_line` is a function that reads a line from a file descriptor. This project introduced the concept of static variables in C and improved my understanding of file I/O operations, memory management, and buffer handling.

## 🔑 Key Features

- Read text lines from any file descriptor (files, standard input, etc.)
- Handle multiple file descriptors simultaneously (bonus part)
- Process text efficiently regardless of buffer size
- Clean memory management with no leaks
- Robust error handling

## 📋 Function Prototype

```c
char *get_next_line(int fd);
```

**Parameters:**
- `fd`: The file descriptor to read from

**Return Values:**
- The next line from the file descriptor (including the newline character if present)
- `NULL` if there's nothing more to read or if an error occurred

## 🚀 Implementation Details

### Core Mechanism

The function works by:
1. Reading chunks of data from the file descriptor into a buffer
2. Accumulating these chunks until a newline character is found
3. Returning the complete line and storing any leftover data for the next call
4. Using static variables to maintain state between function calls

### Files Structure

- **get_next_line.c**: Main function implementation
- **get_next_line_utils.c**: Helper functions for string manipulation
- **get_next_line.h**: Function prototypes and necessary includes
- **Bonus versions**: Extended functionality to handle multiple file descriptors

## ⚙️ Usage

### Compilation

```bash
# Compile with the standard buffer size (defined in the code)
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c

# Compile with a custom buffer size
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

### Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    // Reading from a file
    fd = open("example.txt", O_RDONLY);
    if (fd == -1)
        return (1);

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);

    // Reading from standard input
    printf("\nEnter text (Ctrl+D to end):\n");
    while ((line = get_next_line(0)))
    {
        printf("Line read: %s", line);
        free(line);
    }

    return (0);
}
```

## 🧪 Testing

The function was thoroughly tested against:
- Various buffer sizes (1, 42, 9999, etc.)
- Different line lengths (empty, short, very long)
- Multiple file descriptors
- Binary files
- Standard input
- Edge cases (empty files, no newline at EOF)

## 🔧 Technical Challenges

- **Buffer Management**: Efficiently handling data regardless of buffer size
- **Memory Allocation**: Ensuring proper memory allocation and preventing leaks
- **Static Variables**: Using static variables correctly to maintain state
- **Edge Cases**: Handling file ending without newline character
- **Multiple FD Handling**: Managing different file descriptors without mixing content (bonus)

## 💭 Reflections

This project taught me the importance of:
- Careful memory management in C
- Efficient buffer handling
- Static variables for preserving state
- Clean code organization
- Edge case handling in file operations

## 📝 Note

For detailed project requirements, please see [get_next_line.md](get_next_line.md).

---

*This project is part of the 42 School Common Core curriculum.*
