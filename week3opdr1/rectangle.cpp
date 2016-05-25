// example:
// definition of the functions of a rectangle object

#include "rectangle.hpp"

rectangle::rectangle( window & w, const vector & start, const vector & end ):
   drawable( w, start, end - start ),
   end( end ),
   start(start),
   left(   w, vector( start.x, start.y ), vector( start.x, end.y   ) ),
   right(  w, vector( end.x,   start.y ), vector( end.x,   end.y   ) ),
   top(    w, vector( start.x, start.y ), vector( end.x,   start.y ) ),
   bottom( w, vector( start.x, end.y   ), vector( end.x,   end.y   ) )
{}

void rectangle::draw(){
   left.draw();
   right.draw();
   top.draw();
   bottom.draw();
}
void rectangle ::draw_full(){
  
    for(int i =0; i+start.x<=end.x;i++){
         for(int j = 0; (j+start.y)<=(end.y);j++){
     w.draw(vector ((start.x+i),(start.y+j)));
        
        }
    }}
  

