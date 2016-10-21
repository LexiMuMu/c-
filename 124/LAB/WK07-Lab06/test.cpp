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
	iD3 mp3Info;
	char temparr2[4];
	int yearSize;
	ifstream fin;
	fin.open("sample.mp3",ios::binary);
	fin.seekg (-128, ios::end);
	for (int i=0;i<3;i++)
	{
		fin >> temparr2[i];
	}
	temparr2[3]='\0';
	if (strcmp(temparr2,"TAG")!=0)
	{
		cout << "There is NO 'TAG' in the file. The program terminates!!" << endl;
	}
	else
	{
		fin.read(reinterpret_cast<char*>(&mp3Info),sizeof(mp3Info));	
	}
	

	yearSize= strlen(mp3Info.year);
	char tempcomment[50];
	for (int i=0;i<yearSize-4;i++)
	{
		tempcomment[i]=mp3Info.year[4+i];
	}
	tempcomment[yearSize-4]='\0';
	strcpy(mp3Info.comment, tempcomment);//correct comment value

	
	for (int i=0; i<4; i++)
	{
		temparr2[i]=mp3Info.year[i];
	}
	temparr2[4]='\0';//copy year out from the mp3Info.year.	



	int tempTrack = mp3Info.trackNum;

	int tempGenre = mp3Info.genre;
	

	cout << mp3Info.title << endl;
	cout << mp3Info.artist << endl;
	cout << mp3Info.album << endl;
	cout << temparr2 << endl;
	cout << mp3Info.comment << endl;
	cout << tempTrack << endl;
	cout << genre[tempGenre] << endl;
	fin.close();
	
}

