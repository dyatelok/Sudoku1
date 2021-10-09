#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll pepepoop;

//Меняем местами 2 ряда
vector<vector<int>> Swap_rows(vector<vector<int>> S, int n1, int n2){
vector<vector<int>> Sudoku = S;
for (ll i=0; i<9; i++) swap(Sudoku[n1][i],Sudoku[n2][i]);
return Sudoku;
}

//Меняем местами 2 столбца
vector<vector<int>> Swap_columns(vector<vector<int>> S, int n1, int n2){
vector<vector<int>> Sudoku = S;
for (ll i=0; i<9; i++) swap(Sudoku[i][n1],Sudoku[i][n2]);
return Sudoku;
}

//Меняем местами группу по 3 строки
vector<vector<int>> Swap_3rows(vector<vector<int>> S, int n1, int n2){
vector<vector<int>> Sudoku = S;
Sudoku=Swap_rows(Sudoku,n1*3+0,n2*3+0);
Sudoku=Swap_rows(Sudoku,n1*3+1,n2*3+1);
Sudoku=Swap_rows(Sudoku,n1*3+2,n2*3+2);
return Sudoku;
}

//Меняем местами группу по 3 столбца
vector<vector<int>> Swap_3columns(vector<vector<int>> S, int n1, int n2){
vector<vector<int>> Sudoku = S;
Sudoku=Swap_columns(Sudoku,n1*3+0,n2*3+0);
Sudoku=Swap_columns(Sudoku,n1*3+1,n2*3+1);
Sudoku=Swap_columns(Sudoku,n1*3+2,n2*3+2);
return Sudoku;
}

//Перегиб поля относительно диагонали
vector<vector<int>> Transposition(vector<vector<int>> S){
vector<vector<int>> Sudoku = S;
for (ll i=0;   i<8; i++) for (ll j=1+i; j<9; j++) swap(Sudoku[i][j],Sudoku[j][i]);
return Sudoku;
}

//Превращаем поле по первичному квадрату и маске, наложенной на него
vector<vector<int>> Field(vector<vector<int>> Sudoku, vector<vector<bool>> T){
vector<vector<int>> ReturnField;
ReturnField.resize(9);
for (int i=0; i<9; i++) ReturnField[i].resize(9);
for (int i=0; i<9; i++) for (int j=0; j<9; j++) ReturnField[i][j]=0;

for (ll i=0; i<9; i++)
for (ll j=0; j<9; j++)
{
  if (T[i][j] == 0) { ReturnField[i][j] = Sudoku[i][j]; }
}
return ReturnField;
}

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

//Проверка на то, решаемое ли судок по данным судоку начальному квадрату
bool IsSolvable(vector<vector<int>> Sudoku){
//Провера, решаемо ли судоку единственным способом
return (SolutionDown(Sudoku) == SolutionTop(Sudoku));
//return 0;
}

//Генерация поля
pair<vector<vector<int>>,vector<vector<int>>> Generate_Field(){
pair<vector<vector<int>>,vector<vector<int>>> S;
vector<vector<int>> Sudoku;
Sudoku.resize(9);
for (ll i=0; i<9; i++) Sudoku[i].resize(9);
//Заполняем первичную табличку
Sudoku[0]={1,2,3,4,5,6,7,8,9};
Sudoku[1]={4,5,6,7,8,9,1,2,3};
Sudoku[2]={7,8,9,1,2,3,4,5,6};
Sudoku[3]={2,3,4,5,6,7,8,9,1};
Sudoku[4]={5,6,7,8,9,1,2,3,4};
Sudoku[5]={8,9,1,2,3,4,5,6,7};
Sudoku[6]={3,4,5,6,7,8,9,1,2};
Sudoku[7]={6,7,8,9,1,2,3,4,5};
Sudoku[8]={9,1,2,3,4,5,6,7,8};

int r1,r2,r3;
//Перемешиваем нашу таблицу для генерации решенного судоку
for (ll i=0; i<100; i++){
r1 = rand()%3;
r2 = rand()%3;
r3 = rand()%3;
Sudoku=Swap_rows(Sudoku,3*r1+r2,3*r1+r3);
r1 = rand()%3;
r2 = rand()%3;
r3 = rand()%3;
Sudoku=Swap_columns(Sudoku,3*r1+r2,3*r1+r3);
r1 = rand()%3;
r2 = rand()%3;
Sudoku=Swap_3rows(Sudoku,r1,r2);
r1 = rand()%3;
r2 = rand()%3;
Sudoku=Swap_3columns(Sudoku,r1,r2);
r1 = rand()%2;
if (r1) {Sudoku=Transposition(Sudoku);}
}

S.first = Sudoku;
S.second = Sudoku;
//Генерация задачки
vector<vector<bool>> K,T;
K.resize(9);  T.resize(9);
for (ll i=0; i<9; i++) { K[i].resize(9); T[i].resize(9); }
for (ll i=0; i<9; i++) for (ll j=0; j<9; j++) { K[i][j]=0; T[i][j]=0; }
int it = 0;
int i,j;
while (it < 81) {
  i = rand() % 9;
  j = rand() % 9;
  if (K[i][j] == 0) {
    it++;
    K[i][j] = 1;
    T[i][j] = 1;
    pepepoop = it;
    if (IsSolvable(Field(Sudoku,T)) == 0) {T[i][j]=0;}
    }
}
S.second = Field(Sudoku,T);
return S;
}

int main()
{
    pair<vector<vector<int>>,vector<vector<int>>> Field=Generate_Field();
    for (ll i=0; i<9; i++) {
    for (ll j=0; j<9; j++) {cout << Field.first[i][j] << " ";} cout << endl;}
    cout << endl;
    for (ll i=0; i<9; i++) {
    for (ll j=0; j<9; j++) {cout << Field.second[i][j] << " ";} cout << endl;}
    cout << endl;
    return 0;
}
