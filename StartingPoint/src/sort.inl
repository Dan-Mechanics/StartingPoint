#define V2 ImVec2
#include <vector>
#include <array>
using namespace std;
int N = 64, S, J;
#define V vector<int>
V v = [] {
	V r;
	for (; J < N; J++) r.push_back(rand() % 180);
	return r;
	}();
vector<array<int, 4>> st{ { 0, N - 1, 0, 0} };
#define A st.back()[0]
#define B st.back()[1]
#define I st.back()[2]
void FX2(ImDrawList* d, V2 a, V2 b, V2 s, ImVec4, float t)
{
	float bs = s.x / N, y, c;
	for (int i = 0; i < N; i++) {
		y = a.y + v[i];
		c = 70 + v[i];
		d->AddRectFilled(V2(a.x + bs * i, y), V2(a.x + bs * (i + 1), b.y), IM_COL32(c, 255 - c, 255, 255));
	}
	d->AddText(a, 1u, "Quicksort");
	if (st.empty()) return;
	d->AddRect(V2(a.x + bs * A, a.y), V2(a.x + bs * (B + 1), b.y), 0xFF00FF00, 8, ImDrawFlags_RoundCornersTop, 2);
	switch (S) {
	case 0:case 5: if (A >= B)st.pop_back(), S += 3; else I = J = A, S++; break;
	case 1:case 6:
		if (v[J] > v[B])swap(v[I], v[J]), I++;
		if (++J > B)swap(v[I], v[B]), S++;
		break;
	case 2:case 7:st.push_back({ A,I - 1,A,3 }); S = 0; break;
	case 3:st.push_back({ I + 1,B,A,8 }); S = 5; break;
	case 8:S = st.back()[3]; st.pop_back();
	}
}