/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main(){
  Simple_window win {Point{100,100},1000,800,"Window"}; //ablak 800x1000

  int x_size = win.x_max();
  int y_size = win.y_max();
  int x_grid = 100;
  int y_grid = 100;
  Lines grid;

  for (int x = x_grid; x < x_size-100; x += x_grid)
    grid.add(Point{x,0},Point{x,y_size});

  for (int y = y_grid; y < y_size; y += y_grid)
    grid.add(Point{0,y},Point{x_size-200,y});

  Vector_ref<Rectangle> re;
  for (int i = 0;i < 8; ++i)
  {
      re.push_back(new Rectangle{Point{i*100,i*100},100,100});
      re[re.size()-1].set_fill_color(Color::red);
      win.attach(re[re.size()-1]);
    }

  Image twitch0 {Point{0,600},"twitch200.jpeg"};
  Image twitch1 {Point{300,0},"twitch200.jpeg"};
  Image twitch2 {Point{500,200},"twitch200.jpeg"};

  Image twitch100 {Point{0,0},"twitch100.jpg"};


  win.attach(twitch0);
  win.attach(twitch1);
  win.attach(twitch2);
  win.attach(grid);
  win.attach(twitch100);
  win.wait_for_button();

  int x = 0;
  int y = 0;
  int dx = 0;
  int dy = 0;
  while (true) {
    x = randint(7);
    y = randint(7);
    dx = 100*x - twitch100.point(0).x;
    dy = 100*y - twitch100.point(0).y;
    twitch100.move(dx,dy);

    win.wait_for_button();
  }

  return 0;
}
