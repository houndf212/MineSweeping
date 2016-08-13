#include "boardgen.h"
#include <algorithm>

void BoardGen::Gen(Matrix *m, int n)
{
    //第一步，所有设置为 unknow
    cleanRealMatrix(m);

    //第二步，选取随机mine
    vector<MatrixIter> vec = randPos(m, n);

    // 第三步，计算number
    calNum(m, vec);
}

void BoardGen::cleanRealMatrix(Matrix *m)
{
    for (MatrixIter it=m->begin(), end=m->end(); it!=end; ++it)
    {
        *it = Status::Blank;
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

vector<MatrixIter> BoardGen::randPos(Matrix *m, int n)
{
    int allsize = m->row_size()*m->col_size();
    vector<int> vecIndex = randRang(n, allsize);
    vector<MatrixIter> ret;
    ret.reserve(vecIndex.size());
    for (size_t i=0; i<vecIndex.size(); ++i)
    {
        MatrixIter iter(m, vecIndex[i]);
        *iter = Status::Flagged;
        ret.push_back(iter);
    }
    return ret;
}

void BoardGen::calNum(Matrix *m, const vector<MatrixIter> &vec)
{
    for (size_t i=0; i<vec.size(); ++i)
    {
        Pos p = vec.at(i).toPos();
        assert(m->get(p) == Status::Flagged);
        addone(m, p.row-1, p.col-1);
        addone(m, p.row-1, p.col);
        addone(m, p.row-1, p.col+1);
        addone(m, p.row, p.col-1);
        addone(m, p.row, p.col+1);
        addone(m, p.row+1, p.col-1);
        addone(m, p.row+1, p.col);
        addone(m, p.row+1, p.col+1);
    }
}

void BoardGen::addone(Matrix *m, int row, int col)
{
    Pos p(row, col);

    if (!m->isInMatrix(p))
        return;

    Status s = m->get(p);
    if (s==Status::Flagged)
        return;

    if (s==Status::Blank)
    { m->set(p, Status::Number1); }
    else
    {
        int v = int(m->get(p));
        m->set(p, Status(++v));
    }
}


