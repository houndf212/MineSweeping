#include "boardgen.h"
#include <ctime>
#include <algorithm>

void BoardGen::Gen(Board &b)
{
    //第一步，所有设置为 unknow
    cleanRealMatrix(b);

    //第二步，选取随机mine
    vector<Pos> vec = randPos(b);

    // 第三步，计算number
    calNum(b, vec);
}

void BoardGen::cleanRealMatrix(Board &b)
{
    for (int row=0; row<b.RowSize(); ++row)
    {
        for (int col=0; col<b.ColSize(); ++col)
        {
            b.setPos_r(Pos(row, col), PosStatus::Blank);
        }
    }
}

vector<int> BoardGen::randRang(int s, int n)
{
    assert(n>0);
    assert(0<=s && s<n);

    //先用 std 简单解决
    vector<int> vec(n, 0);
    for (int i=0; i<n; ++i)
        vec[i] = i;

    std::srand(time(0));
    std::random_shuffle(vec.begin(), vec.end());
    vec.resize(s);
    return vec;
}

vector<Pos> BoardGen::transIndex(const vector<int> &vec, int rowlen)
{
    vector<Pos> ret;
    for (int i=0; i<vec.size(); ++i)
    {
        int v = vec.at(i);
        int row = v / rowlen;
        int col = v % rowlen;
        ret.push_back(Pos(row, col));
    }
    return ret;
}

vector<Pos> BoardGen::randPos(Board &b)
{
    int allsize = b.RowSize()*b.ColSize();
    vector<int> vecIndex = randRang(b.MineNum(), allsize);
    vector<Pos> vec = transIndex(vecIndex, b.ColSize());
    for (int i=0; i<vec.size(); ++i)
    {
        b.setPos_r(vec.at(i), PosStatus::Mine);
    }
    return vec;
}

void BoardGen::calNum(Board &b, const vector<Pos> &vec)
{
    auto addone = [&b](int row, int col)
    {
      Pos p(row, col);

      if (!b.isInBoard(p))
          return;

      PosStatus s = b.getPos_r(p);
      if (s==PosStatus::Mine)
          return;

      if (s==PosStatus::Blank)
      { b.setPos_r(p, PosStatus::Number1); }
      else
      {
          int v = int(b.getPos_r(p));
          ++v;
          b.setPos_r(p, PosStatus(v));
      }
    };

    for (int i=0; i<vec.size(); ++i)
    {
        Pos p = vec.at(i);
        assert(b.getPos_r(p) == PosStatus::Mine);
        addone(p.row-1, p.col-1);
        addone(p.row-1, p.col);
        addone(p.row-1, p.col+1);
        addone(p.row, p.col-1);
        addone(p.row, p.col+1);
        addone(p.row+1, p.col-1);
        addone(p.row+1, p.col);
        addone(p.row+1, p.col+1);
    }
}


