#include "main.h"

/**
 * get_line - Read a line of input from a file stream.
 *
 * @lineptr: Pointer to the buffer where the line will be stored.
 * @n: Pointer to the size of the buffer. Will be updated if more space is needed.
 * @stream: The file stream to read from.
 *
 * Return: Number of characters read, including the newline character.
 *         -1 on failure or end-of-file.
 */

ssize_t get_line(char **lineptr, size_t *n, FILE *stream)
{
	static char *buffer;
	static size_t bufsize = 0, bufpos = 0, i;
	ssize_t chars_read = 0, bytes_read = 0;
	int line_end = 0;
	char *newbuf;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	if (*lineptr != NULL)
	{
		free(*lineptr);
		*lineptr = NULL;
	}

	bufsize = INITIAL_BUFSIZE;
	bufpos = 0;
	buffer = (char *)malloc(bufsize);

	if (buffer == NULL)
		return (-1);

	if (*lineptr != NULL)
{
    free(*lineptr);
    free(buffer);
    *lineptr = NULL;
}

	while (!line_end)
	{
		if (bufpos + CHUNK_SIZE >= bufsize)
		{
			bufsize += CHUNK_SIZE;
			newbuf = (char *)malloc(bufsize);

			if (newbuf == NULL)
			{
				free(buffer);
				buffer = NULL;
				return (-1);
			}

			_memcpy(newbuf, buffer, bufpos);
			free(buffer);
			buffer = NULL;
			buffer = newbuf;
		}

		bytes_read = read(fileno(stream), buffer + bufpos, bufsize - bufpos);

	if (bytes_read == 0)
	{
		if (chars_read == 0)
		{
			free(buffer);
			buffer = NULL;
			return (-1);
		}
		line_end = 1;
	}
	else if (bytes_read < 0)
	{
		free(buffer);
		return (-1);
	}
	else
	{
		chars_read += bytes_read;
		bufpos += bytes_read;

		for (i = (size_t)(bufpos - bytes_read); i < bufpos; i++)
		{
			if (buffer[i] == '\n')
			{
				line_end = 1;
				break;
			}
		}
	}
	}

	buffer[bufpos] = '\0';
	*lineptr = buffer;

	return (chars_read);
}
