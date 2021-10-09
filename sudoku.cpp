#include <bits/stdc++.h>
#define ll long long

using namespace std;

//Решаем судоку, перебирая разичные варианты снизу
vector<int> GetCandidates(vector<vector<int>> S, int n){
  set<int> Candidates = {1,2,3,4,5,6,7,8,9};
  for (ll i=0; i<9; i++) { Candidates.erase(S[n/9][i]); }
  for (ll i=0; i<9; i++) { Candidates.erase(S[i][n%9]); }
  int sq1 = (n / 9) / 3;
  int sq2 = (n % 9) / 3;
  for (ll i=sq1*3; i<(sq1+1)*3; i++) for (ll j=sq2*3; j<(sq2+1)*3; j++) Candidates.erase(S[i][j]);
  vector<int> Cand;
  set<int> :: iterator it = Candidates.begin();
  while (it != Candidates.end()) {Cand.push_back(*it); it++;}
  return Cand;
}

pair<vector<vector<int>>,bool> SudokuSolutionDown(vector<vector<int>> Sud, int r){
//Находим возможных кандидатов на эту клетку и перебираем. Если находим, что вариантов в оставшейся клетке нет, то возвращаемся к предидущему шагу
    vector<vector<int>> S = Sud;
    if (r > 80)
    {
    pair<vector<vector<int>>,bool> FullGrid;
    FullGrid.first=S;
    FullGrid.second=1;
    return FullGrid;
    }
    //Заполняем все клетки, которые заполняются однозначно
    int FilledCells;
    for (int i=0; i<81; i++)
    {
    FilledCells = 0;
    for (int j=0; j<81; j++) if (S[j/9][j%9] == 0)
    {
        vector<int> Candidates = GetCandidates(S,j);
        if (Candidates.size() == 1)
            {
            S[j/9][j%9] = Candidates[0];
            FilledCells++;
            }
    }
    if (FilledCells == 0) {break;}
    }
    if (S[r/9][r%9] != 0)
        {
        return SudokuSolutionDown(S,r+1);
        }
    vector<int> Candidates = GetCandidates(S,r);
    if (Candidates.size() == 0)
    {
    pair<vector<vector<int>>,bool> FailedGrid;
    FailedGrid.first=S;
    FailedGrid.second=0;
    return FailedGrid;
    } else
    {
    int p=0;
    while (p != Candidates.size())
    {
        S[r/9][r%9] = Candidates[p];
        pair<vector<vector<int>>,bool> TryGrid;
        TryGrid = SudokuSolutionDown(S,r+1);
        if (TryGrid.second == 1) {return TryGrid;} else {p++;}
    }
    pair<vector<vector<int>>,bool> WrongGrid;
    WrongGrid.first=S;
    WrongGrid.second = 0;
    return WrongGrid;
    }
}

pair<vector<vector<int>>,bool> SudokuSolutionTop(vector<vector<int>> Sud, int r){
//Находим возможных кандидатов на эту клетку и перебираем. Если находим, что вариантов в оставшейся клетке нет, то возвращаемся к предидущему шагу
    vector<vector<int>> S = Sud;
    if (r > 80)
    {
    pair<vector<vector<int>>,bool> FullGrid;
    FullGrid.first=S;
    FullGrid.second=1;
    return FullGrid;
    }
    //Заполняем все клетки, которые заполняются однозначно
    int FilledCells;
    for (int i=0; i<81; i++)
    {
    FilledCells = 0;
    for (int j=0; j<81; j++) if (S[j/9][j%9] == 0)
    {
        vector<int> Candidates = GetCandidates(S,j);
        if (Candidates.size() == 1)
            {
            S[j/9][j%9] = Candidates[0];
            FilledCells++;
            }
    }
    if (FilledCells == 0) {break;}
    }
    if (S[r/9][r%9] != 0)
        {
        return SudokuSolutionTop(S,r+1);
        }
    vector<int> Candidates = GetCandidates(S,r);
    if (Candidates.size() == 0)
    {
    pair<vector<vector<int>>,bool> FailedGrid;
    FailedGrid.first=S;
    FailedGrid.second=0;
    return FailedGrid;
    } else
    {
    int p=Candidates.size()-1;
    while (p != -1)
    {
        S[r/9][r%9] = Candidates[p];
        pair<vector<vector<int>>,bool> TryGrid;
        TryGrid = SudokuSolutionTop(S,r+1);
        if (TryGrid.second == 1) {return TryGrid;} else {p--;}
    }
    pair<vector<vector<int>>,bool> WrongGrid;
    WrongGrid.first=S;
    WrongGrid.second = 0;
    return WrongGrid;
    }
}

vector<vector<int>> SolutionDown(vector<vector<int>> Puzzle)
{
    pair<vector<vector<int>>,bool> Ans;
    Ans = SudokuSolutionDown(Puzzle,0);
    return Ans.first;
}

vector<vector<int>> SolutionTop(vector<vector<int>> Puzzle)
{
    pair<vector<vector<int>>,bool> Ans;
    Ans = SudokuSolutionTop (Puzzle,0);
    return Ans.first;
}

int main()
{
    vector<vector<int>> Sudoku;
    //Enter your sudoku
    Sudoku = {
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}};

    vector<vector<int>> SudokuTop  =  SolutionTop ( Sudoku );
    vector<vector<int>> SudokuDown = SolutionDown ( Sudoku );
    //cout << endl;
    cout << endl;
    for (ll i=0; i<9; i++) {
    for (ll j=0; j<9; j++) {cout << Sudoku[i][j] << " ";} cout << endl;}
    cout << "Sudoku Solution Top:" << endl;
    for (ll i=0; i<9; i++) {
    for (ll j=0; j<9; j++) {cout << SudokuTop [i][j] << " ";} cout << endl;}
    cout << "Sudoku Solution Down:" << endl;
    for (ll i=0; i<9; i++) {
    for (ll j=0; j<9; j++) {cout << SudokuDown[i][j] << " ";} cout << endl;}
    return 0;
}
