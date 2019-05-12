//Creates a tile.
tile::tile(char display, string n, string c, bool pass)
{
  display_char = display;
  name = n;
  color = c;
  passable = pass;
  return;
}



tile_map::tile_map(int rows, int cols)
{
  //Builds map
  m_map = new tile*[rows];
  for(int i = 0; i < rows; ++i)
    m_map[i] = new tile[cols];
  m_cols = cols;
  m_rows = rows;
  return;
}

//Deletes the map.
tile_map::~tile_map()
{
  for(int i = 0; i < m_rows; ++i)
    delete[] m_map[i];
  delete[] m_map;
  return;
}

//Returns private variables

int tile_map::cols()
{
  return m_cols;
}

int tile_map::rows()
{
  return m_rows;
}

//Fills the map with a single tile.
void tile_map::map_fill(tile &tile)
{
  for(int i = 0; i < m_rows; ++i)
  {
    for(int j = 0; j < m_cols; ++j)
    {
      m_map[i][j] = tile;
    }
  }
}

//Changes a selected range of tiles.
void tile_map::tile_range(int row1, int row2, int col1, int col2, tile &tile)
{
  //Swaps the row/column inputs if needed.
  if(col1 > col2)
    std::swap(col1, col2);
  if(row1 > row2)
    std::swap(row1, row2);
  //Invalid coord errors
  if(col2 > m_cols - 1 || col1 < 0)
  {
    cout << "ERROR: INVALID COLUMN NUMBER." << endl;
    return;
  }
  if(row2 > m_rows - 1 || row1 < 0)
  {
    cout << "ERROR: INVALID ROW NUMBER" << endl;
    return;
  }

  //Performs the changes.
  for(int i = col1; i <= col2; ++i)
  {
    for(int j = row1; j <= row2; ++j)
      m_map[j][i] = tile;
  }
  return;
}
//Changes a single tile.
void tile_map::tile_change(int row, int col, tile &tile)
{
  //Invalid coord errors
  if(col > m_cols - 1 || col < 0)
  {
    cout << "ERROR: INVALID COLUMN NUMBER." << endl;
    return;
  }
  if(row > m_rows - 1 || row < 0)
  {
    cout << "ERROR: INVALID ROW NUMBER" << endl;
    return;
  }
  m_map[row][col] = tile;
  return;
}

//Prints out the map without object overlaid.
void tile_map::print(int player_pos[2])
{
  for(int i = 0; i < m_rows; ++i)
  {
    for(int j = 0; j < m_cols; ++j)
    {
      if(i == player_pos[0] && j == player_pos[1])
        std::cout << termcolor::bold << "p" << termcolor::reset;
      else if(m_map[i][j].color == "green")
        std::cout << termcolor::green << m_map[i][j].display_char << termcolor::reset;
      else if(m_map[i][j].color == "black")
        std::cout << m_map[i][j].display_char;
    }
    std::cout << endl;
  }
  return;
}
