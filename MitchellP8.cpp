/*
    filename: MitchellP8.cpp
    programmer: Nicholas Mitchell
    email: nmitchell11@cnm.edu
*/
#include "Function.h"

int main()
{
    const string filename = "Top_500_albumlist.txt";
    vector<Album> albums = readDataFromFile(filename);

    if (albums.empty()) {
        return 1;
    }

    string artistWithMostAppearances = findArtistWithMostAppearances(albums);
    vector<int> yearsWithMostAppearances = findYearsWithMostAppearances(albums);
    string genreWithMostAppearances = findGenreWithMostAppearances(albums);

    // Displaying the results
    cout << "Data Analysis Results:" << endl;
    cout << "======================" << endl;
    cout << "1. Artist with the most appearances: " << artistWithMostAppearances << endl;
    cout << "2. Year(s) with the most album appearances: ";
    for (int year : yearsWithMostAppearances) {
        cout << year << " ";
    }
    cout << endl;
    cout << "3. Genre with the most album appearances: " << genreWithMostAppearances << endl;

    return 0;
}

