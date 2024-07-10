#include<iostream>
#include<fstream>
#include<array>

#define SQUARE_SIZE 100
#define N_POINTS 10000

int main()
{
  std::cout << "This code solves temperature diffusion\n";
  std::cout << "-> 1m X 1m\n";
  std::cout << "-> Central difference scheme for space\n";
  std::cout << "-> Eulerian scheme for time\n";

  std::array<int, N_POINTS> T;
  std::fill(T.begin(), T.end(), 300);
  std::fill(T.begin(), T.begin() + SQUARE_SIZE, 400);

  const char* filename = "T.csv";
  std::ofstream output;
  output.open(filename);
  if(!output)
  {
    std::cerr << "Error opening file: " << filename << std::endl;
  }

  output << "x, y, T" << std::endl;
  for( auto it = T.begin(); it != T.end(); it++ )
  {
    int index = std::distance(T.begin(), it);
    int x = index / 100;
    int y = index % 100;
    output << x << ", " << y << ", " << *it << std::endl;
  }
  output.close();


}