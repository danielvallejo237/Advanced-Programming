#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
using namespace std ;
int main(){
 std :: multiset <int > G , B ;//for storing tree(can have multiple same values)
 std :: multiset <int> :: iterator fit ,it ;
//for storing winners of battle
 vector < int > storeG , storeB ;
int n , i  ,  j , k , x , y ,battles , ng ,nb;
 scanf("%d",&n);
 while ( n-- ){
          
        G.clear ()  ; B.clear() ;//clearing trees after every case
         storeB.clear() ; storeG.clear() ;//clearing stores
scanf("%d %d %d" , &battles ,&ng ,&nb);
   //populating tress of both Green and Blue army
       for ( i = 0 ; i < ng ; i++)
       {
             scanf("%d",&x);
             G.insert ( x );
       }
       for ( i = 0 ; i < nb; i++)
       {
             scanf("%d",&x);
             B.insert ( x );
       }
      
   //while both army has soldiers,continue battle
      while ( G.size() > 0 && B.size() > 0)
      {   
             storeG.clear() ; storeB.clear() ;
             
             for ( i = 0 ; i < battles ; i++)
              {
                    it = G.end() ; it -- ;//pointing to last element(highest)
                    fit = B.end() ; fit-- ;
//if green man wins
                    if ( *it > *fit)
                    {
                          G.erase(it); B.erase(fit);
                          storeG.push_back ( *it - *fit);
                    }
                    else if ( *it < *fit)//if blue wins
                    {
                          G.erase(it); B.erase(fit);
                          storeB.push_back ( *fit - *it);
                    }
                    else//if both are same 
                        {   
                            G.erase(it); B.erase(fit);
                        }
if (G.size() == 0 || B.size() == 0)
                    break ;
              }
              //insert all winners to respective side 
              for ( int z = 0 ; z < storeB.size() ; z++)
                        B.insert( storeB [z] );
              for ( int z = 0 ; z < storeG.size() ; z++)
                     G.insert ( storeG [z] );
            
      }
if ( G.size() == 0 && B.size() == 0)
      {
           printf("green and blue died\n");
      }
      else if (G.size() > 0)
      { 
          printf("green wins\n");
            it = G.end() ;
          do {
              it --;
              printf("%d\n",*it);
          }
          while ( it != G.begin());
}
      else if (B.size() > 0)
      {
          printf("blue wins\n");
          it = B.end() ;
          do {
              it --;
              printf("%d\n",*it);
          }
          while ( it != B.begin());
          
      }
      if (n)
      printf("\n");
  }
    return 0;
}