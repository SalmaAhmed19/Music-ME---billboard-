#include<iostream>
#include<iomanip>
using namespace std;

struct Song{
  string title;
  string artist;
  int weeks_on_chart;
  int worst;
  int highest;
  int weeks[15]; 
};

void collect_one_song(istream& input, Song& s);
void display_one_song(Song s);

bool collect_all_songs(Song arr[],int& n);
void display_all_songs(const Song arr[], int n);
void sort_by_highest_song(Song arr[],int n);
void sort_by_artist(Song arr[],int n );


void display_song_artist(const Song arr[], int n, string artist);
int worst_ranking_per_song(const Song one_song);

int remove_song(Song arr[],int &num_song ,string remove_title);

void highest_rank_per_song(const Song arr[],int num_song,string one_song);
void least_weeks_on_chart(const Song arr[],int num_song);