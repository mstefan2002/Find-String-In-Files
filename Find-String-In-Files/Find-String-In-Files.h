#pragma once
#include <string>
#include <string.h>
#include <iostream>
#include <sys/stat.h>
#include "dirent.h"
#include <fstream>

using namespace std;

class Folder
{
private:
	string folderName;
	DIR *dir;
	bool isCaseSensitive;
	bool searchInSubFolders;
public:
	Folder(bool searchInSubFolders);
	~Folder();
	bool open(string folderName);
	void searchInFiles(string findThisString);
	void setCaseSensitive(bool cs);
};
void Clear();
void toLowerCase(string &str);
bool isFile(const char *path);
bool isDir(const char* path);