Useful Linux commands:
_____________________

Use cd -r ~/CompSci ~/h-drive to copy all of the files from CompSci into my h-drive
can use Tab to autocomplete
	pressing Tab twice will show all possible autofill options for what's typed so far

pwd - Shows the current absolute path to the used directory
cd - set the directory to the stated relative directory
	cd - : this will send you back to the last directory you accessed in the terminal
	cd .. : this will take you to the directory which your current directory exists inside
ls - displays all directories in the current  directory
	-F - shows a little more detail about the file
		/ after the name - this is a directory
		@ - this is a link
		* - this is an executable file
	-s - displays the size of files and directories alongside the name

	-S - sorts the files and directories by size

mv [old] [new]- Should move the first stated directory to the second or renames it
cp [old] [new]- Copies the contents of thew current directory
rm [path]- Deletes the specified file/directory
mkdir [path]- Makes a new directory in the current directory with the specified name
rmdir - Deletes the specified directory in the current directory
less - Used to read the contents of a text file one page (screen) at a time
man -  used to display the user manual of any terminal command
wc [filename] - prints the number of lines, words and characters in the specified file
	-l - prints just the lines
	-m - prints just the number of characters
	-w - prints just the number of words
cat **[files] - prints the contents of every file named after the cat command
sort [file] - by default, it sorts the contents of the file alphabetically
	-n - sorts the file's contents numerically
head [file] - prints the first line from the specified file
	-n [num] - prints the first n number of lines from the file
tail [file] - prints the last line from the specified file
	-n [num] - prints the last  n number of lines from the file
cut [file] - cuts out and prints certain sections of each line in a file
	Usually expects the delimiter to be a Tab
	-d [character] - sets the delimiter to be the new character set
	-f [fieldNum] - specifies the index of the field which we want to extract
		*KEEP IN MIND THAT THE FIRST FIELD IS 1*
grep [thing] [filename] - finds all occurences of the thing in the specified file

_______________________
Useful Linux wildcards:
_______________________

* - represents 0+ characters
? - represents 1 unknown character only
> [filename] - redirects the command's output to the specified file instead of printing it to the screen - overwrites existing file
>> [filename] - appends the command's output to the specified file instead of printing to the screen
| (also called a pipe) - output of the command of the left is to be used as an input to the command on the right
____________________
Useful Nano commands
____________________

M - means alt key on the keyboard
	E.g M-6 means that you sohudl hold the Alt key and the 6 key7 simultaneously to copy
