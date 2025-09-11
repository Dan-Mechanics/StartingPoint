#define min(x,y) ((x)<(y)?x:y)
#define wh(a) ImColor(1.f,1.f,1.f,a)
void FX(ImDrawList* d, ImVec2 a, ImVec2 b, ImVec2 sz, ImVec2, float t) {
    static float fl;
    if ((rand() % 500) == 0) fl = t;
    if ((t - fl) > 0) {
        auto ft = 0.25f;
        d->AddRectFilled(a, b, wh((ft - (t - fl)) / ft));
    }

    for (int i = 0; i < 2000; ++i) {
        unsigned h = ImGui::GetID(d + i + int(t / 4));
        auto f = fmodf(t + fmodf(h / 777.f, 99), 99);
        auto tx = h % (int)sz.x;
        auto ty = h % (int)sz.y;
        if (f < 1) {
            auto py = ty - 1000 * (1 - f);
            d->AddLine({ a.x + tx, a.y + py }, { a.x + tx, a.y + min(py + 10,ty) }, (ImU32)-1);
        }
        else if (f < 1.2f)
            d->AddCircle({ a.x + tx, a.y + ty }, (f - 1) * 10 + h % 5, wh(1 - (f - 1) * 5.f));
    }
}