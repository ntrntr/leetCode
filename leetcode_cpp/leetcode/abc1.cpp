#include <cstdio>
#include <cstring>
using namespace std;

int N, M;
char S[50004];
struct Splay
.{
	Splay *P, *L, *R;
	int v, c, d, f;// v : Value, d : Delta, c : Current, f : Cover;
	bool ff;// ff : Whether Cover;
	int Size;
	Splay()
	{
		P = L = R = NULL;
		v = c = d = f = 0;
		ff = false;
		Size = 1;
	}
	void Update()
	{
		Size = 1;
		if (L) Size += L->Size;
		if (R) Size += R->Size;
	}
}Data[50004], *Top;
inline void Zig(Splay *X)
{
	Splay *Y = X->P;
	if (Y->P) (Y->P->L == Y) ? Y->P->L = X : Y->P->R = X;
	X->P = Y->P, Y->P = X;
	Y->L = X->R, X->R = Y;
	if (Y->L) Y->L->P = Y;
	Y->Update();
}
inline void Zag(Splay *X)
{
	Splay *Y = X->P;
	if (Y->P) (Y->P->L == Y) ? Y->P->L = X : Y->P->R = X;
	X->P = Y->P, Y->P = X;
	Y->R = X->L, X->L = Y;
	if (Y->R) Y->R->P = Y;
	Y->Update();
}
Splay *T[50004];
int Cnt;
inline void Cover(Splay *X, int f)
{
	if (X)
	{
		X->ff = true;
		X->v = X->f = f;
		X->d = X->c = 0;
	}
}
inline void Plus(Splay *X, int c, int d)
{
	c = c % 26;
	if (c < 0) c += 26;
	X->v += c, X->c += c, X->d += d;
}
inline int Rs(Splay *X)
{
	return (X->R) ? X->R->Size : 0;
}
inline int Ls(Splay *X)
{
	return (X->L) ? X->L->Size : 0;
}
inline void Down(Splay *X)
{
	if (X->ff)
	{
		Cover(X->L, X->f), Cover(X->R, X->f);
		X->ff = false;
	}
	if (X->L) Plus(X->L, X->c - (Rs(X->L) + 1) * X->d, X->d);
	if (X->R) Plus(X->R, X->c + (Ls(X->R) + 1) * X->d, X->d);
	X->c = X->d = 0;
}
inline void splay(Splay *X)
{
	Splay *Y, *Z, *K;
	for (K = X, Cnt = 0; K; T[++ Cnt] = K, K = K->P);
	for (int i = Cnt; i; i --) Down(T[i]);
	while (X->P)
	{
		Y = X->P;
		if (Y->P)
		{
			Z = Y->P;
			if (Z->L == Y)
			{
				if (Y->L == X) Zig(Y), Zig(X);
				else Zag(X), Zig(X);
			}else
			{
				if (Y->R == X) Zag(Y), Zag(X);
				else Zig(X), Zag(X);
			}
		}else
		{
			if (Y->L == X) Zig(X);
			else Zag(X);
		}
	}
	X->Update(), Top = X;
}
Splay *Build(Splay *S, int Len, Splay *P = NULL)
{
	if (Len == 1)
	{
		S[1].P = P;
		return S + 1;
	}
	if (Len == 0) return NULL;
	int mid = (1 + Len) >> 1;
	S[mid].P = P;
	S[mid].L = Build(S, mid - 1, S + mid);
	S[mid].R = Build(S + mid, Len - mid, S + mid);
	S[mid].Update();
	return S + mid;
}
inline Splay *Find(int x)
{
	Splay *C = Top;
	int ss;
	while (true)
	{
		ss = Ls(C);
		if (ss + 1 == x) break;
		if (ss >= x) C = C->L;
		else {
			x -= ss + 1;
			C = C->R;
		}
	}
	splay(C);
	return C;
}
inline void CMD1()
{
	int i, j, X;
	scanf("%d%d%s", &i, &j, S);
	X = S[0] - 'A';
	if (i == j)
	{
		Find(j)->v = X;
		return;
	}
	Splay *u = Find(j), *v = Find(i);
	while (u->P != v)
	{
		Down(u->P);
		if (u->P->L == v) Zig(u);
		else Zag(u);
		u->Update();
	}
	Down(v), Down(u);
	Cover(u->L, X);
	v->v = u->v = X;
}
inline void CMD2()
{
	int i, j, X;
	scanf("%d%d%d", &i, &j, &X);
	if (i == j)
	{
		Find(j)->v ++;
		return;
	}
	Splay *u = Find(j), *v = Find(i);
	while (u->P != v)
	{
		Down(u->P);
		if (u->P->L == v) Zig(u);
		else Zag(u);
		u->Update();
	}
	Down(v), Down(u);
	v->v +=X, u->v +=X;
	if (u->L) Plus(u->L, X, 0);
}
inline void CMD3()
{
	int K;
	scanf("%d", &K);
	if (K == N) return;
	Splay *u = Find(K), *v = u->R;
	v->P = NULL;
	u->R = NULL, u->Update();
	u = Find(1), u->L = v;
	v->P = u, u->Update();
}
inline void CMD4()
{
	int i, j;
	scanf("%d%d", &i, &j);
	if (i == j)
	{
		Find(i)->v ++;
		return;
	}
	Splay *u = Find(j), *v = Find(i);
	while (u->P != v)
	{
		Down(u->P);
		if (u->P->L == v) Zig(u);
		else Zag(u);
		u->Update();
	}
	Down(v), Down(u);
	if (u->L) Plus(u->L, Ls(u->L) + 2, 1);
	v->v ++, u->v += j - i + 1;
}
inline void Print(Splay *X = Top)
{
	Down(X);
	if (X->L) Print(X->L);
	putchar('A' + X->v % 26);
	if (X->R) Print(X->R);
}
int main5()
{
	scanf("%d%d", &N, &M);
	scanf("%s", S + 1);
	for (int i = 1; i <= N; i ++) Data[i].v = S[i] - 'A';
	Top = Build(Data, N);
	for (int i = 1, opt; i <= M; i ++)
	{
		scanf("%s", S);
		scanf("%d", &opt);
		if (opt == 1) CMD1();
		if (opt == 2) CMD2();
		if (opt == 3) CMD3();
		if (opt == 4) CMD4();
	}
	Print();
	return 0;
}
