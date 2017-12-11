#include "third_party/catch.hpp"

#include <vector>

using namespace std;

/**
 * Problem:
 * Implement the "paint fill" function that one might see on many image editing
 * programs. That is, given a screen (represented by a two-dimensional array of
 * colors), a point, and a new color, fill in the surrounding area until the
 * color changes from the original color.
 */

void fill(vector<vector<int>>& image, int oldColor, int newColor, int r,
          int c) {
  int R = image.size();
  int C = image[0].size();
  if (r >= 0 && r < R && c >= 0 && c < C && image[r][c] == oldColor) {
    image[r][c] = newColor;
    fill(image, oldColor, newColor, r, c - 1);
    fill(image, oldColor, newColor, r, c + 1);
    fill(image, oldColor, newColor, r - 1, c);
    fill(image, oldColor, newColor, r + 1, c);
  }
}

void paintFill(vector<vector<int>>& image, int r, int c, int color) {
  fill(image, image[r][c], color, r, c);
}

TEST_CASE("ch9.7 paint fill") {
  vector<vector<int>> image = {
      {1, 4, 4, 4}, {1, 1, 4, 4}, {1, 1, 4, 4}, {4, 1, 4, 1}};
  vector<vector<int>> expected = {
      {2, 4, 4, 4}, {2, 2, 4, 4}, {2, 2, 4, 4}, {4, 2, 4, 1}};

  paintFill(image, 0, 0, 2);

  REQUIRE(image == expected);
}