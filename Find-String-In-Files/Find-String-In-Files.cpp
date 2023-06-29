#include "pch.h"
#include "Find-String-In-Files.h"

string pathFolder;
bool foundString;
int main()
{
	Clear();
	if (!pathFolder.empty())
		cout << "We are searching in the folder " << pathFolder;
	else
	{
		cout << "Folder location: \n";
		getline(cin, pathFolder);
	}

	char YesOrNo;
	cout << "\nSearch in subfolders as well? (y/n): ";
	cin >> YesOrNo;
	cin.get();
	YesOrNo = tolower(YesOrNo);


	Folder folder(YesOrNo == 'y');
	while (!folder.open(pathFolder))
	{

		cout << "The folder " << pathFolder << " was not found, please try again.\n";
		cout << "Folder location: \n";
		getline(cin, pathFolder);
	}
	
	cout << "\nCase sensitive? (y/n): ";
	cin >> YesOrNo;
	cin.get();
	YesOrNo = tolower(YesOrNo);
	folder.setCaseSensitive(YesOrNo == 'y');

	string findThisString;
	cout << "\nText to search for: \n";
	getline(cin, findThisString);

	foundString = false;
	folder.searchInFiles(findThisString);
	if (!foundString)
		cout << "\n\nThe text was not found.";

	cout << "\n\n\nReload the program? (y/n): ";
	cin >> YesOrNo;
	YesOrNo = tolower(YesOrNo);
	if (YesOrNo == 'n')
		return 1;

	cout << "\nSame path? (y/n): ";
	cin >> YesOrNo;
	YesOrNo = tolower(YesOrNo);

	cin.get();
	if (YesOrNo == 'n')
		pathFolder = "";

	return main();
}
Folder::Folder(bool searchInSubFolders)
{
	this->searchInSubFolders = searchInSubFolders;
}
Folder::~Folder()
{
	if (this->dir != NULL)
		closedir(this->dir);
}
bool Folder::open(string folderName)
{
	this->folderName = folderName;
	this->dir = opendir(folderName.c_str());
	if (this->dir == NULL)
		return false;
	return true;
}
void Folder::setCaseSensitive(bool cs)
{
	this->isCaseSensitive = cs;
}
void Folder::searchInFiles(string findThisString)
{
	if (!this->isCaseSensitive)
		toLowerCase(findThisString);

	dirent *file;
	string pathFile,lineFromFile;
	char fileName[261];
	const char* findThisStringC = findThisString.c_str();
	while ((file = readdir(this->dir)) != NULL)
	{
		strcpy_s(fileName, sizeof(fileName), file->d_name);
		if (strcmp(fileName, ".") == 0 || strcmp(fileName, "..") == 0)
			continue;

		pathFile = this->folderName + "\\" + fileName;
		const char* pathFileC = pathFile.c_str();
		if (isDir(pathFileC))
		{
			if (!this->searchInSubFolders)
				continue;

			Folder subFolder(true);
			if (subFolder.open(pathFile))
				subFolder.searchInFiles(findThisString);
			continue;
		}
		if (!isFile(pathFileC))
			continue;

		ifstream f(pathFileC);
		if (f.fail())
		{
			cout << "Unable to open the file " << pathFile << endl;
			f.close();
			continue;
		}
		int lineId = 0;
		while (!f.eof())
		{
			lineId++;
			getline(f, lineFromFile);
			if (!this->isCaseSensitive)
				toLowerCase(lineFromFile);
			if (strstr(lineFromFile.c_str(), findThisStringC) == NULL)
				continue;

			cout << "Found the text (line " << lineId << ") in the file " << pathFile << endl;
			foundString = true;
			break;
		}
		f.close(); 
	}
}
void Clear()
{
	system("cls");
}
void toLowerCase(string &str)
{
	for (char& c : str)
		c = tolower(c);
}
bool isFile(const char *path)
{
	struct stat path_stat;
	stat(path, &path_stat);
	return S_ISREG(path_stat.st_mode);
}
bool isDir(const char* path)
{
	struct stat path_stat;
	stat(path, &path_stat);
	return S_ISDIR(path_stat.st_mode);
}
