tile_map::tile_map(int cols, int rows)
{
  //Builds map
  m_map = new char*[rows];
  for(int i = 0; i < rows; ++i)
    m_map[i] = new char[cols];
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

//Fills the map with a single tile.
void tile_map::map_fill(char tile)
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
void tile_map::tile_range(int col1, int col2, int row1, int row2, char tile)
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
void tile_map::tile_change(int col, int row, char tile)
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
void tile_map::print()
{
  for(int i = 0; i < m_rows; ++i)
  {
    for(int j = 0; j < m_cols; ++j)
    {
      bool output = 0;
      char tile = m_map[i][j];
      if(tile == 'T' || tile == 'g')
      {
        std::cout << termcolor::green << tile << termcolor::reset;
        output = 1;
      }
      if(!output)
        std::cout << tile;
    }
    std::cout << endl;
  }
  return;
}
