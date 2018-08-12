# scanner-using-c-
my code takes input from a file and print it on a file,
i used function (get line ) that take a line from file and push it to string variable 
called TXT and passing it to a class's function get_input .
i made a class scanner having  6 functions 
5 of them boolien functions , their function is :

1- SYMBOL : return true if the passing char is symbol 
2- LETTER : return true if the passing char is alphabet Letter
3- DIGIT : return true if the passing char is Digit
4- SPACE : return true if the passing char is space
5- ERROR_SYMBOL : return true if the passing char is 
symbol that is not allowed in the code

the last function is get_input that it is attribute is TXT (the code)

the function main role is to test a single char's type if it is 
letter or digit or special char or error or space 
by passing the char to switch case 

if it is comment , the incomment state is executed and 
program skips it 
if it is digit , innum state is executed and program checks 
if the next char is also digit or something else and print digit .
if it is special char ,inassign state is executed and program prints it
if it is error symbol , program prints error
if it is char , program checks if it is reserved word or 
an id then inid state is executed .
