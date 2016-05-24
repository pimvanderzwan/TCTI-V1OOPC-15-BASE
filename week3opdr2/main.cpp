#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"
int main(){
   window w( vector( 128, 64 ),1  );
    wall k (w,vector(0,0),vector(127,63),2);
     line top( w, vector(   0,  0 ), vector( 127,  0 ) );
   line right( w, vector( 127,  0 ), vector( 127, 63 ) );
   line bottom( w, vector(   0, 63 ), vector( 127, 63 ) );
   line left( w, vector(   0,  0 ), vector(   0, 63 )  );
   ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );
   
   drawable * objects[] = { &b,&k , &top, &left, &right, &bottom};

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
   wait_ms( 18);
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other, objects );
         } 
      }
   }
}
