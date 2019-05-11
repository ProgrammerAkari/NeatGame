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

tile_map::~tile_map()
{
  for(int i = 0; i < m_rows; ++i)
    delete[] m_map[i];
  delete m_map;
  return;
}

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

void tile_map::map_print()
{
  for(int i = 0; i < m_rows; ++i)
  {
    for(int j = 0; j < m_cols; ++j)
    {
      std::cout << m_map[i][j];
    }
    std::cout << endl;
  }
  return;
}
