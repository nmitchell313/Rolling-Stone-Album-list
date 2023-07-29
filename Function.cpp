#include "Function.h"

void WriteHeader()
{
    cout << "// Program written by Nicholas Mitchell" << endl;
    cout << "// Email: nmitchell11@cnm.edu" << endl;
    cout << "// File name: MitchellP8" << endl;
    cout << "----------------------------------------" << endl;
}

void WriteIntro()
{
    cout << "\nWelcome to the Data Finder Program!" << endl;
    cout << "This program will analyze Rolling Stone's Top 500 Albums list to"
        << "\n determine the artist with the most appearances in the list,\n"
        << "the year that had the most appearances on the list, and which genre\n"
        << "had the most appearances on the list." << endl;
    cout << "Let's get started." << endl;
}

vector<Album> readDataFromFile(const string& filename)
{
    vector<Album> albums;
    ifstream inputFile(filename);

    if (!inputFile) {
        cout << "Error: Unable to open the file." << endl;
        return albums;
    }

    string line;
    getline(inputFile, line); // Skip the header line

    while (getline(inputFile, line)) {
        istringstream iss(line);
        string data;
        Album album;

        getline(iss, data, ',');
        album.number = stoi(data);

        getline(iss, data, ',');
        album.year = stoi(data);

        getline(iss, album.name, ',');

        getline(iss, album.artist, ',');

        getline(iss, album.genre, ',');

        getline(iss, album.subgenre);

        albums.push_back(album);
    }
    inputFile.close();
    return albums;
}

string findArtistWithMostAppearances(const vector<Album>& albums)
{
    map<string, int> artistAppearances;

    for (const Album& album : albums) {
        artistAppearances[album.artist]++;
    }

    string artistWithMostAppearances;
    int maxAppearances = 0;

    for (const auto& pair : artistAppearances) {
        if (pair.second > maxAppearances) {
            maxAppearances = pair.second;
            artistWithMostAppearances = pair.first;
        }
    }

    return artistWithMostAppearances;
}

vector<int> findYearsWithMostAppearances(const vector<Album>& albums)
{
    map<int, int> yearAppearances;

    for (const Album& album : albums) {
        yearAppearances[album.year]++;
    }

    vector<int> yearsWithMostAppearances;
    int maxAppearances = 0;

    for (const auto& pair : yearAppearances) {
        if (pair.second > maxAppearances) {
            maxAppearances = pair.second;
            yearsWithMostAppearances.clear();
            yearsWithMostAppearances.push_back(pair.first);
        }
        else if (pair.second == maxAppearances) {
            yearsWithMostAppearances.push_back(pair.first);
        }
    }

    return yearsWithMostAppearances;
}

string findGenreWithMostAppearances(const vector<Album>& albums)
{
    map<string, int> genreAppearances;

    for (const Album& album : albums) {
        genreAppearances[album.genre]++;
    }

    string genreWithMostAppearances;
    int maxAppearances = 0;

    for (const auto& pair : genreAppearances) {
        if (pair.second > maxAppearances) {
            maxAppearances = pair.second;
            genreWithMostAppearances = pair.first;
        }
    }

    return genreWithMostAppearances;
}

void GoodBye()
{
    cout << "----------------------------------------------------\n" << endl;
    cout << "\nThanks for using my Data Finder Program! Good-bye!" << endl;
    cout << "------------------------------------------------------" << endl;
}
