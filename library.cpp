#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include<limits.h>
#include "library.h"
using namespace std;


//to collect my data from input.dat
void collect_one_song(istream& input, Song& s){
 //cout << "One collected." << endl;
 input>>s.weeks_on_chart;
 input.ignore();
 getline(input,s.title,',');//to get song name
 getline(input,s.artist,',');//to get artist
 
 //to get ranks when weeks increase 
  s.worst = -9999;
 for(int i=0;i<s.weeks_on_chart;i++){
   input>>s.weeks[i]; 
   input.ignore();
    if (s.worst < s.weeks[i]) {
      s.worst = s.weeks[i];
    }
    
  }
  
  //cout<<"weeks "<<s.weeks[i]<<endl;
}

//to display 
void display_one_song(const Song s) {
 // cout << "One displayed." << endl;
  cout << left << setw(20) <<s.weeks_on_chart<<setw(27) <<s.title << setw(25) << s.artist;
  for (int i=0;i<s.weeks_on_chart;i++){
   cout << setw(7) << s.weeks[i];
  }
}

bool collect_all_songs(Song arr[], int& n) {
  ifstream file_input("input.dat");
  if (!file_input.is_open()) {
    cout << "Can't open the file.\n";
    return false;
  }  
  string credit;
  getline(file_input, credit);
  cout << credit <<endl;
  

 for (n = 0; !file_input.eof(); n++) {
   collect_one_song(file_input, arr[n]);
  }
  file_input.close();
  return true;
} 
void display_all_songs(const Song arr[], int n){
  for(int j=0;j<n;j++){
	 display_one_song(arr[j]);
    cout<<endl;
  }
}
void sort_by_highest_song(Song arr[],int n) {
  for (int j = 1; j < n; j++) {
    for (int i = j; i > 0 && arr[i - 1].worst > arr[i].worst; i--) {
      swap(arr[i - 1], arr[i]);
    }
  }  
}
void sort_by_artist(Song arr[], int n) {
  for (int j = 1; j < n; j++) {
    for (int i = j; i > 0 && arr[i - 1].artist> arr[i].artist; i--) {
      swap(arr[i - 1], arr[i]);
    }
  }  
}
void display_song_artist(const Song arr[], int n, string artist){
  for (int j = 0; j < n; j++) {
    if (arr[j].artist== artist) {
      cout << setw(30) << arr[j].title + ", " + arr[j].artist;
      for (int i = 0; i < arr[j].weeks_on_chart; i ++) {
        cout << setw(4) << arr[j].weeks[i];
      }
      cout << endl;
    } 
  } 
}
int worst_ranking_per_song(const Song one_song){
 int worst_ranking_per_song=0;
 for (int i=0;i<one_song.weeks_on_chart;i++){
   if(worst_ranking_per_song<one_song.weeks[i]){
     worst_ranking_per_song=one_song.weeks[i];
    }
 }
  return worst_ranking_per_song;
}

int remove_song(Song arr[],int &num_song,string remove_title ){
 int index_to_remove;
  for(int i=0;i<num_song;i++){
    if(arr[i].title==remove_title){
      index_to_remove=i;
      break;

    }else if(arr[i].title!=remove_title){
      i++;
    }
  }
 if(index_to_remove>=0&&index_to_remove<num_song){
   for(int j=index_to_remove;j<num_song-1;j++){
     arr[j]=arr[j+1];
   }
   num_song--;
  }
 return 0;
}


int best_rank(Song s) {
 int highest_per_song=INT_MAX;
 for (int i=0;i<s.weeks_on_chart;i++){
   if(highest_per_song>s.weeks[i]){
     highest_per_song=s.weeks[i];

    }
  }  
  return highest_per_song;
}

void highest_rank_per_song(const Song arr[],int num_song,string one_song){
 int highest_per_song=INT_MAX;
 int index_high=0;
 cout<<one_song;
 for(int i=0;i<num_song;i++){
   //cout<<"For Loop ";
   if(arr[i].title==one_song){
     index_high=i;
     //cout<<endl;
     //cout<<index_high;
     //cout<<endl;
     break;
    } 
  }
 cout<<" is by "<<arr[index_high].artist;
 cout<<" and this song highest ranking is "<<best_rank(arr[index_high])<<endl;
}

void least_weeks_on_chart(const Song arr[],int num_song){
  int smallest=60;
  int smallest_index = -1; 
  for(int i=0;i<num_song;i++){
    if(arr[i].weeks_on_chart<smallest){
     smallest=arr[i].weeks_on_chart;
      smallest_index = i;
    }
    
  }
  
  cout<<"The song that stayed the least amount of weeks is "<<arr[smallest_index].title<<" by "<<arr[smallest_index].artist<<" and it stayed "<< smallest <<" week(s) "<<endl;
}

 
 




 














