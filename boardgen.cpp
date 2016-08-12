#include "boardgen.h"

#include <algorithm>

void BoardGen::Gen(Board &b)
{
    //第一步，所有设置为 unknow
    cleanRealMatrix(b);

    //第二步，选取随机mine
    vector<MatrixIter> vec = randPos(b);

    // 第三步，计算number
    calNum(b, vec);
}

void BoardGen::cleanRealMatrix(Board &b)
{
    StatusMatrix& m = b.real_matrix;
    for (auto it = m.begin(); it!=m.end(); ++it)
    {
        *it = PosStatus::Blank;
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

    std::random_shuffle(vec.begin(), vec.end());
    vec.resize(s);
    return vec;
}

vector<MatrixIter> BoardGen::randPos(Board &b)
{
    int allsize = b.RowSize()*b.ColSize();
    vector<int> vecIndex = randRang(b.MineNum(), allsize);
    vector<MatrixIter> ret;
    ret.reserve(vecIndex.size());
    for (int i=0; i<vecIndex.size(); ++i)
    {
        MatrixIter iter(&b.real_matrix, vecIndex[i]);
        *iter = PosStatus::Mine;
        ret.push_back(iter);
    }
    return ret;
}

void BoardGen::calNum(Board &b, const vector<MatrixIter> &vec)
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
        Pos p = vec.at(i).toPos();
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


