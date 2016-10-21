
/************************************************
* Filename: mp3.cpp                             *
* Name: Yanhong Ben								*
* Time: Mon 8:30-10:30 17.106					*
* Lab No: 6										*
* File Description: binary I/O 					*
* Date Last Modified: 23/04/2015                *
*************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct iD3
{
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[29];
	char trackNum;
	char genre;
};

char genre[126][128] = {"Blues", "Classic Rock", "Country","Dance", "Disco", "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal","New Age", "Oldies", "Other", "Pop", "R&B", "Rap", "Reggae","Rock","Techno", "Industrial", "Alternative","Ska", "Death Metal","Pranks", "Soundtrack", "Euro-Techno","Ambient", "Trip-Hop","Vocal", "Jazz+Funk", "Fusion", "Trance","Classical","Instrumental", "Acid", "House","Game", "Sound Clip","Gospel", "Noise", "AlternRock","Bass","Soul", "Punk", "Space","Meditative", "Instrumental Pop","Instrumental Rock", "Ethnic", "Gothic", "Darkwave", "Techno-Industrial", "Electronic","Pop-Folk", "Eurodance", "Dream","Southern Rock", "Comedy", "Cult", "Gangsta", "Top 40", "Christian Rap", "Pop/Funk", "Jungle", "Native American", "Cabaret", "New Wave", "Psychadelic", "Rave", "Showtunes", "Trailer", "Lo-Fi","Tribal", "Acid Punk", "Acid Jazz", "Polka", "Retro", "Musical","Rock & Roll", "Hard Rock", "Folk", "Folk-Rock", "National Folk",
"Swing", "Fast Fusion", "Bebop", "Latin", "Revival", "Celtic","Bluegrass", "Avantgarde", "Gothic Rock", "Progressive Rock","Psychedelic Rock", "Symphonic Rock", "Slow Rock", "Big Band","Chorus","Easy Listening", "Acoustic", "Humour", "Speech","Chanson", "Opera", "Chamber Music", "Sonata", "Symphony", "Booty Bass", "Primus", "Porn Groove", "Satire", "Slow Jam", "Club","Tango", "Samba", "Folklore","Ballad", "Power Ballad", "Rhythmic Soul", "Freestyle", "Duet", "Punk Rock", "Drum Solo","Acapella","Euro-House", "Dance Hall"};


int main()
{
	
	char filename[20];
	int filsNameSize = 0;
	char temparr[5];
	char temparr2[5];
	char tempcomment[29];
	int tempTrack = 0;
	int tempGenre = 0;
	int yearSize;
	
	iD3 mp3Info;

	cout << "Enter filename:" << endl;

	cin.getline(filename, 20, '\n');
	filsNameSize = strlen(filename);

	for (int i = 0; i < 5; i++)
	{
		temparr[i] = filename[filsNameSize-4+i];	
	}
	
	if (strcmp(temparr, ".mp3") != 0)
	{
		cout << "extension should be '.mp3'. The program terminates!!" << endl;
		return 0;
	}   //check if filename is ends with .mp3 extension.	
	else 
	{	
		ifstream fin;
		fin.open(filename, ios::binary);
		fin.seekg(-128, fin.end);  //read the 128th from buttom 
		for (int i = 0; i < 3; i++)
		{
			fin >> temparr2[i];
		}
		temparr2[3] = '\0';
		if (strcmp(temparr2,"TAG")!=0)
		{
			cout << "There is NO 'TAG' in the file. The program terminates!!" << endl;
			return 0;
		}  //Seek for TAG to check if tag information is valid in the mp3 file.
		else
		{
			cout << "File is OK and has valid ID3v1.1 tag." << endl;
			fin.read(reinterpret_cast<char*>(&mp3Info), sizeof(mp3Info));
		}  //read struct data from the mp3 file.
	

		yearSize = strlen(mp3Info.year);
		
		for (int i = 0; i < (yearSize - 4); i++)
		{
			tempcomment[i] = mp3Info.year[4+i];
		}
		tempcomment[yearSize-4] = '\0';
		strcpy(mp3Info.comment, tempcomment);   //correct comment value
	
	
		for (int i = 0; i < 4; i++)
		{
			temparr2[i] = mp3Info.year[i];
		}
		temparr2[4] = '\0';   //copy year out from the mp3Info.year.	


		tempTrack = mp3Info.trackNum;   //convert trackNum

		tempGenre = mp3Info.genre;   //convert genre
	
		cout << "Title: " << mp3Info.title << endl;
		cout << "Artist: " << mp3Info.artist << endl;
		cout << "Album: " << mp3Info.album << endl;
		cout << "Year: " << temparr2 << endl;
		cout << "Genre: " << genre[tempGenre] << endl;
		cout << "Comment: " << mp3Info.comment << endl;
		cout << "Track Number: " << tempTrack << endl;  //display the info of struct data

		fin.close();
	}
	
	//change comment and outfile
	char revise;
	ofstream fout;
	fout.open(filename, ios::binary|ios::in|ios::out);
	
	if (!fout.good())
	{
		cout << "open file failed." << endl;	
	}
	cout << "Do you wish to update the comment field (Y/N) ?" << endl;
	cin >> revise;
	
	//update comment
	if (revise == 'Y' or revise == 'y'  )
	{	
		char comment[29];
		cout << "Comment: " ;
		cin.ignore();
		cin.getline(comment, 29,'\n');
		strcpy(mp3Info.comment, comment);
		fout.seekp(-31, ios::end); 
		fout.write(reinterpret_cast<char*>(&mp3Info.comment), sizeof(mp3Info.comment)); 
		cout << "Title: " << mp3Info.title << endl;
		cout << "Artist: " << mp3Info.artist << endl;
		cout << "Album: " << mp3Info.album << endl;
		cout << "Year: " << temparr2 << endl;
		cout << "Genre: " << genre[tempGenre] << endl;
		cout << "Comment: " << mp3Info.comment << endl;
		cout << "Track Number: " << tempTrack << endl; 
	}
	else if (revise == 'N' or revise == 'n')
	{
		cout << "Thank you. Goodbye." << endl;
	}
	else
		cout << "Invalid input. The program teminates." << endl; 

	fout.close();
}
