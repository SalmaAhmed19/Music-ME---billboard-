#include<iomanip>
#include<iostream>
#include"library.h"
#include<fstream>
#include<string>
using namespace std;

int main(){
 const int CAP=15;
 Song top_hits[CAP];
 int num_songs=0;
 //to collect data 
 if (!collect_all_songs(top_hits, num_songs)) {
    cout << "Unable to collect data.\n";
    return 1;
  }
  
  cout<<"Welcome to this month song billboard "<<endl;
  char response;
  string choice;
  string artist;
  cout<<"You can choose between theses options "<<endl<<endl;
  do{
   cout<<"If you want to display enter display "<<endl<<endl;
   cout<<"If you want to the chart sorted enter sort ."<<endl<<endl;
   cout<<"If you want to filter enter filter "<<endl<<endl;
   cout<<"If you want to remove a song from the list enter remove "<<endl<<endl;
   cout<<"if you want to see the highest ranking for a specific song enter high "<<endl<<endl;
   cout<<"If you want to know the song that stayed the least on chart enter least "<<endl<<endl;
   cout<<"If you want to quit enter quit "<<endl<<endl;
   
   cout<<"What is your choice " ;
   getline(cin,choice);
   
   if(choice=="display"){
     cout<<"\nWeeks on chart      SONG                       Artist                   w1     w2     w3     w4     w5     w6     w7     w8     w9     w10\n";
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
     display_all_songs(top_hits, num_songs);
   
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
     cout<<endl;
    }else if(choice=="sort"){
     cout<<"\nSorted from best to worst ranking "<<endl;
     cout<<"\nWeeks on chart      SONG                       Artist                   w1     w2     w3     w4     w5     w6     w7     w8     w9     w10\n";
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
     

     sort_by_highest_song(top_hits, num_songs);
     display_all_songs(top_hits, num_songs);
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
     cout<<"\nSorting atists alphabetically \n";
     cout<<"\nWeeks on chart      SONG                       Artist                   w1     w2     w3     w4     w5     w6     w7     w8     w9     w10\n";
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
     sort_by_artist(top_hits,num_songs);
     display_all_songs(top_hits, num_songs);
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
     cout<<endl<<endl;

    }else if(choice =="filter"){
     //display_all_songs(top_hits, num_songs);
     cout << "Which artist do you want to see their song ?\t";
     getline(cin,artist);
     display_song_artist(top_hits, num_songs, artist);
     cout<<endl<<endl;

     cout << "Lowest ranking each of these songs reached is  "<<endl;
     cout<<"\nArtist                     SONG                     Worst Ranking         \n";
     cout<<"-------------------------------------------------------------------------------\n";
     for (int i=0;i<num_songs;i++){
       cout<<left<<setw(27)<<top_hits[i].artist<<setw(25)<<top_hits[i].title<<setw(25)<<worst_ranking_per_song(top_hits[i]) << endl;
      }
     cout<<endl;
    }else if(choice=="remove"){
     string remove_title;
     cout<<"Which song do you want to remove ";
     getline(cin,remove_title);
     //call function
     cout<<"\nWeeks on chart      SONG                       Artist                   w1     w2     w3     w4     w5     w6     w7     w8     w9     w10\n";
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
     remove_song(top_hits,num_songs , remove_title);
     display_all_songs(top_hits, num_songs);
     cout<<"----------------------------------------------------------------------------------------------------------------------------------------------\n";
     cout<<endl<<endl;

    }else if(choice=="high"){
      string high_rank;
      cout<<"Which song do you want to see it's highest ranking ";
      getline(cin,high_rank);
      //for (int i=0;i<num_songs;i++){
      // highest_rank_per_song(top_hits[i]) ;
     //  cout<< endl;
      //}
     highest_rank_per_song(top_hits,num_songs,high_rank);
      //display_all_songs(top_hits, num_songs);
      cout<<endl<<endl;
    }else if(choice=="least"){
      least_weeks_on_chart(top_hits,num_songs);
      cout<<endl ;
    }

  }while(choice!="quit");
  cout<<"Thank you ";
}

