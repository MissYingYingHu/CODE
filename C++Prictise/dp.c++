#include <iostream>
#include <vector>
#include <algorithm>

int uniquepath(int m,int n)
{
  if(m < 1 || n < 1)
  {
    return 0;
  }
  std::vector<std::vector<int> > path_sum(m,std::vector<int>(n,0));
  int i = 0;
  for(i = 0;i < n;++i)
  {
    path_sum[0][i] = 1;
  }
  for(i = 0;i < m;++i)
  {
    path_sum[i][0] = 1;
  }
  int j = 0;
  for(i = 1;i < m;++i)
  {
    for(j = 1;j < n;++j)
    {
      path_sum[i][j] = path_sum[i][j - 1] + path_sum[i - 1][j];
    }
  }
  return path_sum[m - 1][n - 1];
}

int min_path_sum(std::vector<std::vector<int> > &grid)
{
  if(grid.empty())
  {
    return 0;
  }
  int m = grid.size();
  int n = grid[0].size();
  std::vector<std::vector<int> > min_sum(m,std::vector<int>(n,0));
  min_sum[0][0] = grid[0][0];
  int i = 0;
  for(i = 0;i < n;++i)
  {
    min_sum[0][i] = min_sum[i - 1][0] + grid[0][i];
  }
  for(i = 0;i < m;++i)
  {
    min_sum[i][0] = min_sum[i - 1][0] + min_sum[i][0];
  }
  for(i = 1;i < m;++i)
  {
    int j = 0;
    for(j = 1;j < n;++j)
    {
      min_sum[i][j] = std::min(min_sum[i - 1][j],min_sum[i][j - 1] + grid[i][j]);
    }
  }
  return min_sum[m - 1][n - 1];

}


bool ispal(std::string s,int i,int j)
{
  while(i < j)
  {
    if(s[i] != s[j])
    {
      return false;
    }
    --j;
    ++i;
  }
  return true;
}

std::vector<std::vector<bool> > ispal(std::string s)
{
  int n = s.size();
  std::vector<std::vector<bool> >is_pal(s.size(),std::vector<bool>(s.size(),0));
  for(int i = n - 1;i >= 0;--i)
    {
      for(int j = 1;j < n;j++)
      {
        if(j == i)
        {
          is_pal[i][j] = true;
        }
        else if(j == i+ 1)
        {
          is_pal[i][j] = (s[i] == s[j]);
        }
        else
        {
          is_pal[i][j] = ((s[i] == s[j]) && is_pal[i + 1][j - 1]);
        }
      }
    }
  return is_pal;
}

int mincut(std::string s)
{
  if(s.empty())
  {
    return 0;
  }
  int n = s.size();
  std::vector<int> cut(n+1,0);
  int i = 0;
  for(i = 0;i <= n;++i)
  {
    cut[i] = i - 1;
  }
  for(i = 1;i <= n;++i)
  {
    int j = 0;
    for(j = 0;j < i;++j)
    {
      if(ispal(s,j,i - 1))
      {
        cut[i] = std::min(cut[i] + 1,cut[i]);
      }
    }
  }
  return cut[n];
}
int main()
{
  std::cout<<uniquepath(2,3)<<std::endl;
  return 0;
}
