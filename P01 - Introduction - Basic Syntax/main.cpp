#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main() {
	//string name = "Budi";
	//int age = 22;
	//double height = 171;

	//cout << "Nama saya " << name << " Umur saya " << age << " dan tinggi saya " << height;

	// MATH OPERATION - untuk angka
	// +
	// -
	// *
	// /
	// n*n
	
	// LOGICAL OPERATION - untuk true/false
	// && - and
	// || - or
	// ^ - xor
	// == - equal
	// > - greater than
	// >= - greater than equal
	// < - less than
	// < - less than than equal
	// != - not equal
	// ! - not

	// CAMEL CASE
	// namaLengkap
	// PASCAL CASE
	// NamaLengkap
	// SNAKE CASE
	// nama_lengkap

	// Naming Variable 
	// 1. Tidak ada simbol kecuali underscore
	// 2. Tidak boleh ada space
	// 3. Tidak boleh sama dengan keyword/function

	// <DATA TYPE> <VARIABLE NAME> = <VALUE>;


	// INPUT 
	// a = int(input())
	string name;
	int age;
	double height;


	cout << "Masukkan nama anda ";
	getline(cin, name);
	cout << "Umur saya adalah " << name << endl;

	cout << "Masukkan umur anda ";
	cin >> age;
	cout << "Umur saya adalah " << (double) age;
	return 0;
}