#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

void streammode() {
	ifstream fin;
	ofstream fout;

	fin.open("f.txt");

	map<char, int> m;
	m['a'] = 0;
	m['b'] = 0;
	m['c'] = 0;
	m['d'] = 0;
	m['e'] = 0;
	m['f'] = 0;

	if (fin) {
		while (!fin.eof()) {
			char symb;
			fin >> symb;
			if (m.find(symb) != m.end()) {
				m[symb]++;
			}
		}
	}
	else cout << "file not found" << endl;
	fout.open("g.txt",ios::app);
	if (fout) {
		fout << "streammode" << endl;
		for (char s = 'a'; s <= 'f'; s++) {
			fout << s << " " << m[s] << endl;
		}
	}
}
void filemode() {
	FILE* in;
	FILE* out;

	in = fopen("f.txt", "rt");
	map<char, int> m;
	m['a'] = 0;
	m['b'] = 0;
	m['c'] = 0;
	m['d'] = 0;
	m['e'] = 0;
	m['f'] = 0;

	if (in) {
		while (!feof(in)) {
			char symb;
			fread(&symb, 1, 1, in);
			if (m.find(symb) != m.end()) {
				m[symb]++;
			}
		}
		fclose(in);
	}
	else cout << "file not found" << endl;
	out = fopen("g.txt", "at");
	if (out) {
		fprintf(out, "filemode\n");
		for (char s = 'a'; s <= 'f'; s++) {
			int count = m[s];
			fprintf(out, "%c %d \n", s, count);
		}
		fclose(out);
	}
}
int main()
{
	streammode();
	filemode();
	return 0;
}