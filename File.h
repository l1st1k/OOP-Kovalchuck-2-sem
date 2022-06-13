#pragma once
#include <fstream>
#include <iostream>

using namespace std;

class File {
private:
	string file_name;
protected:
	fstream file_stream;
	ifstream file_input;
	ofstream file_output;
public:
	File(string temp = "") { this->file_name = temp; }
	~File() { }
	string get_file_name() { return this->file_name; };
};

template <class T>
class File_bin : public File {
public:
	File_bin() {	}
	File_bin(string path) :File(path) {
		this->file_stream.open(this->get_file_name(), ios::in | ios::out | ios::binary);
		if (!this->file_stream.is_open()) {
			cout << " Файл не открылся! \n ";
			exit(1);
		}
	}
	~File_bin() { this->file_stream.close(); }
	void read_txt(T& obj) { this->file_stream >> obj; }
	void write_bin(T& obj) { this->file_stream << obj; }
	bool eof_bin() { return this->file_stream.eof(); }
};

template <class T>
class File_txt : public File {
public:
	File_txt() {}
	File_txt(string path) : File(path) { }
	bool eof_txt_in() { return  this->file_input.eof(); }
	bool eof_txt_out() { return  this->file_output.eof(); }
	void read_txt(T& obj) { this->file_input >> obj; }
	void write_txt(T& obj) { this->file_output << obj; }
	void open_txt_in();
	void open_txt_out();
	void close_txt_out() { this->file_output.close(); }
	void close_txt_in() { this->file_input.close(); }
	~File_txt() {}
};

template<class T>
inline void File_txt<T>::open_txt_in() {
	this->file_input.open(this->get_file_name(), ios::in);
	if (!file_input.is_open()) {
		cout << "Текстовый файл не открылся для записи!\n" << get_file_name() << endl;
		return;
	}
}

template<class T>
inline void File_txt<T>::open_txt_out() {
	this->file_output.open(this->get_file_name(), ios::out);
	if (!file_output.is_open()) {
		cout << "Текстовый файл не открылся для чтения!\n" << get_file_name() << endl;
		return;
	}
}
