#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class scanner {
	
	public :
		
		void get_input(string line);
		bool LETTER (char in);
		bool SYMBOL (char input_SY);
		bool DIGIT (char input_DI);
		bool SPACE (char input_SP);
		bool ERROR_SYMBOL (char n);
	
};
enum states { start, incomment, innum, inid, inassign, done , error };
states state = start; 

string WORDS[] = { "if","then","else","end","repeat","until","read","write" };
bool scanner :: SPACE (char input_SP) {
    
    return (input_SP == ' ') ;

}

bool scanner :: ERROR_SYMBOL (char n) {
	return (n == '%' || n=='$' || n== '#' || n == '!' || n == '@' || n== '^' || n == '&' || n == '_' || n == '|' 
	|| n== '?' || n == '.' || n == ',' || n == ']' || n == '[' || n== '~' || n == '`'  );
}
void scanner :: get_input(string line)
{
	scanner T ;
	int i = 0;
	bool flag = 0;
	string mytoken;
	while (state != done) {
		switch (state) {
		case start:
			if (T.SPACE(line[i])) {
				i++;
				if (i == line.length()) state = done;
				else state = start;
			}
			else if (T.DIGIT(line[i])) {
				state = innum;
			}
			else if (T.LETTER(line[i])) {
				state = inid;
			}
			else if (line[i] == ':') {
				state = inassign;
			}
			else if (line[i] == '{') {
				i++;
				state = incomment;
			}
			else if (T.SYMBOL(line[i])) {
				cout << line[i] << " : special symbol" << endl ;
				i++;
				if (i == line.length()) state = done;
				else state = start;
			}
			else if (T.ERROR_SYMBOL(line[i])){
				state = error ;
			}
			else state = done;
			break;

		case incomment:
			if (state == incomment) {
				while (line[i] != '}') {
					i++;
					if (i == line.length()) state = done;
					
				}
				i++;
				if (i == line.length()) state = done;
				else state = start;
			}
			break;

		case innum:
			while (T.DIGIT(line[i])) {
				mytoken += line[i];
				i++;
			}
			cout <<mytoken << " : number" << endl;
			mytoken = "";
			if (i == line.length()) state = done;
			else state = start;
			break;

		case inid:
			while (T.LETTER(line[i])) {
				
				if (line[i] == '\n'){
					break ;
				}
				mytoken += line[i];
				i++;
			}
			for (int ii = 0; ii < 8; ii++)
			{
				if (WORDS[ii] == mytoken) flag = 1;
			}
			if (flag) cout  << mytoken << " : resrved word " << endl;
			else cout << mytoken << " : identifier" << endl;
			mytoken = "";
			flag = 0;
			if (i == line.length()) state = done;
			else state = start;
			break;
				

		case inassign:
			if (line[i] == ':') {
				i ++;
				if (line[i] == '=') {
					cout << ":=" << " : special symbol" << endl;
					state = start;
					i++;
				}
			}
			else {
				if (i == line.length()) state = done;
				else state = start;
			}
			break;
		case done:
			break;
			
		case error : 
			if (T.ERROR_SYMBOL(line[i])){
				cout <<line[i] << " : error" << endl ;
				i++;
				state = start ;
			}
			
		}
	}
}
bool scanner :: SYMBOL (char input_SY) {
    
    return (input_SY == '*' || input_SY == '-'|| input_SY == '+'|| input_SY == '='|| input_SY == '/'|| input_SY == '<'|| input_SY == '>'|| input_SY == ';'|| input_SY == '('|| input_SY == ')' );
}


bool scanner :: LETTER (char in) {
    return (in == 'A' || in == 'B' || in == 'C' || in == 'D'|| in == 'E'|| in == 'F'|| in == 'G'|| in == 'H'|| in == 'I'|| in == 'J' ||
    in == 'K'|| in == 'L'|| in == 'M'|| in == 'N'|| in == 'O'|| in == 'P'|| in == 'Q'|| in == 'R'|| in == 'S'|| in == 'T'|| in == 'U'|| in == 'V'|| 
    in == 'W'|| in == 'X'|| in == 'Y'|| in == 'Z'|| in == 'a'|| in == 'b'|| in == 'c'|| in == 'd'|| in == 'e'|| in == 'f'|| in == 'g'|| in == 'h'|| 
    in == 'i'|| in == 'j'|| in == 'k'|| in == 'l'|| in == 'm'|| in == 'n'|| in == 'o'|| in == 'p'|| in == 'q'|| in == 'r'|| in == 's'|| in == 't'||
    in == 'u'|| in == 'v'|| in == 'w'|| in == 'x'|| in == 'y'|| in =='z' );
    
    
}

bool scanner :: DIGIT (char input_DI ) {
    return (input_DI == '0' || input_DI == '1' || input_DI == '2' || input_DI == '3'|| input_DI == '4'|| input_DI == '5'|| input_DI == '6'|| input_DI == '7'|| input_DI == '8'|| input_DI == '9' );

}


int main() {
	
	scanner temp ;
	ifstream f;
	string L, TXT;
	string space = " " ;
	f.open("tiny_sample_code.txt");
	while (!f.eof()) {
		getline(f, L);
		TXT += L;
		TXT+= space ;
	}
	freopen("parser_input.txt", "w", stdout);
	temp.get_input(TXT); 
	fclose(stdout);

	return 0;
}



