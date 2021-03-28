/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) {return 1;}

double slope(double x) {return x/2;}

double square(double x) {return x*x;}

double sloping_cos(double x) {return cos(x)+slope(x);}

int main(){

  constexpr int xmax = 600;
  constexpr int ymax = 600;

  constexpr int x_kozep = xmax/2;
  constexpr int y_kozep = ymax/2;
  Point origo {x_kozep,y_kozep};

  constexpr int r_min = -10;
  constexpr int r_max = 11;

  constexpr int n_points = 400;

  constexpr int x_scale = 20;
  constexpr int y_scale = 20;

  constexpr int xlength = xmax-200;
  constexpr int ylength = ymax-200;

  Axis x {Axis::x,Point{100,y_kozep},xlength,xlength/x_scale,"1 == 20 pixels"};
  Axis y {Axis::y,Point{x_kozep,500},ylength,ylength/y_scale,"1 == 20 pixels"};
  x.set_color(Color::red);
  y.set_color(Color::red);

  Simple_window win {Point{100,100},xmax,ymax," Function Graphs"}; // 600x600 Ablak

  Function f1 {one,r_min,r_max,origo,n_points,x_scale,y_scale};
  win.attach(f1);

  win.wait_for_button();
  Function f2 {slope,r_min,r_max,origo,n_points,x_scale,y_scale};
  Text t1 {Point{100,375},"x/2"};
  win.attach(f2);
  win.attach(t1);

  Function f3 {square,r_min,r_max,origo,n_points,x_scale,y_scale};
  win.attach(f3);

  Function f4 {cos,r_min,r_max,origo,n_points,x_scale,y_scale};
  f4.set_color(Color::blue);
  win.attach(f4);

  Function f5 {sloping_cos,r_min,r_max,origo,n_points,x_scale,y_scale};
  win.attach(f5);

  win.attach(x);
  win.attach(y);


  win.wait_for_button();

}
