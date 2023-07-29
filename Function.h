#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>

using namespace std;

struct Album {
    int number;
    int year;
    string name;
    string artist;
    string genre;
    string subgenre;
};

void WriteHeader();

void WriteIntro();

vector<Album> readDataFromFile(const string& filename);

string findArtistWithMostAppearances(const vector<Album>& albums);

vector<int> findYearsWithMostAppearances(const vector<Album>& albums);

string findGenreWithMostAppearances(const vector<Album>& albums);

void GoodBye();

#endif // !FUNCTION_H

