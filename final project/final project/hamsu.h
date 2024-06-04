#pragma once
#define MaxV 120
#define MaxH 360
#define Move 10001
#define Gravity 10002
double mapsize{ 17.07 };
struct Box {
    RECT rect;
    int direct;
    int status;
    int x;
    int y;
    double theta;
    int shape;
    HBRUSH color;
    int size;
    bool Land;
    int x2;
    int y2;
};
bool IsRectOverlap(const RECT* rect1, const RECT* rect2) {
    if (rect1->right <= rect2->left || rect1->left >= rect2->right) {
        return false;
    }
    if (rect1->bottom <= rect2->top || rect1->top >= rect2->bottom) {
        return false;
    }
    return true;
}

BOOL InRectangle(RECT rect, int mx, int my) {
    if (mx <= rect.right && mx >= rect.left && my <= rect.bottom && my >= rect.top) {
        return true;
    }
    return false;
}
void UpdatePlayerPosition(Box& player, bool Up, bool Down, bool Left, bool Right) {
	if (Up) {
		player.rect.top -= mapsize;
		player.rect.bottom -= mapsize;
		player.y2 -= mapsize;
	}
	if (Down) {
		player.rect.top += mapsize;
		player.rect.bottom += mapsize;
		player.y2 += mapsize;
	}
	if (Left) {
		player.rect.left -= mapsize;
		player.rect.right -= mapsize;
		player.x2 -= mapsize;
	}
	if (Right) {
		player.rect.left += mapsize;
		player.rect.right += mapsize;
		player.x2 += mapsize;
	}
}

void ApplyGravity(Box& player, const Box MAP[MaxV][MaxH]) {
	player.rect.top += 2;
	player.rect.bottom += 2;
	player.y2 = (player.rect.top + player.rect.bottom) / 2;
}
float LengthPts(int x1, int y1, int x2, int y2) {
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
void InitializeMap(Box MAP[MaxV][MaxH]) {
	//좌측 상단 블럭
	MAP[84 - 40][31].status = MAP[85 - 40][30].status = MAP[86 - 40][29].status = MAP[87 - 40][28].status = MAP[87 - 40][27].status = MAP[87 - 40][26].status = MAP[88 - 40][25].status = 1;
	MAP[89 - 40][24].status = MAP[90 - 40][23].status = MAP[91 - 40][23].status = MAP[92 - 40][23].status = MAP[93 - 40][23].status = MAP[94 - 40][23].status = MAP[95 - 40][23].status = 1;
	MAP[96 - 40][23].status = MAP[97 - 40][23].status = MAP[98 - 40][23].status = MAP[99 - 40][23].status = MAP[100 - 40][23].status = MAP[101 - 40][23].status = MAP[102 - 40][23].status = 1;
	MAP[102 - 40][24].status = MAP[102 - 40][25].status = MAP[103 - 40][25].status = MAP[104 - 40][25].status = MAP[105 - 40][25].status = MAP[105 - 40][26].status = MAP[106 - 40][26].status = 1;
	MAP[106 - 40][27].status = MAP[106 - 40][28].status = MAP[106 - 40][29].status = MAP[106 - 40][30].status = MAP[106 - 40][31].status = MAP[106 - 40][32].status = MAP[106 - 40][33].status = 1;
	MAP[106 - 40][34].status = MAP[107 - 40][35].status = MAP[107 - 40][36].status = MAP[107 - 40][37].status = MAP[106 - 40][38].status = MAP[106 - 40][35].status = MAP[106 - 40][37].status = 1;
	MAP[106 - 40][39].status = MAP[105 - 40][40].status = MAP[105 - 40][41].status = MAP[105 - 40][42].status = MAP[105 - 40][43].status = MAP[104 - 40][44].status = MAP[103 - 40][45].status = 1;
	MAP[102 - 40][45].status = MAP[101 - 40][45].status = MAP[98 - 40][46].status = MAP[100 - 40][46].status = MAP[99 - 40][46].status = MAP[98 - 40][47].status = MAP[98 - 40][48].status = 1;
	MAP[98 - 40][49].status = MAP[98 - 40][50].status = MAP[98 - 40][51].status = MAP[98 - 40][52].status = MAP[98 - 40][53].status = MAP[98 - 40][54].status = 1;
	MAP[92 - 40][56].status = MAP[97 - 40][55].status = MAP[96 - 40][56].status = MAP[95 - 40][56].status = MAP[94 - 40][56].status = MAP[93 - 40][56].status = 1;
	MAP[92 - 40][55].status = MAP[91 - 40][55].status = MAP[90 - 40][55].status = MAP[90 - 40][54].status = MAP[89 - 40][54].status = MAP[88 - 40][53].status = MAP[88 - 40][53].status = MAP[87 - 40][53].status = 1;
	MAP[86 - 40][52].status = MAP[85 - 40][51].status = MAP[84 - 40][51].status = MAP[83 - 40][50].status = MAP[83 - 40][49].status = MAP[83 - 40][48].status = MAP[83 - 40][47].status = 1;
	MAP[83 - 40][46].status = MAP[83 - 40][45].status = MAP[83 - 40][44].status = MAP[84 - 40][43].status = MAP[84 - 40][42].status = MAP[84 - 40][41].status = MAP[84 - 40][40].status = 1;
	MAP[84 - 40][39].status = MAP[84 - 40][38].status = MAP[84 - 40][37].status = MAP[84 - 40][36].status = MAP[84 - 40][35].status = MAP[84 - 40][34].status = MAP[84 - 40][33].status = MAP[84 - 40][32].status = 1;
	//우측상단 블럭
	MAP[84 - 40][356 - 31].status = MAP[85 - 40][356 - 30].status = MAP[86 - 40][356 - 29].status = MAP[87 - 40][356 - 28].status = MAP[87 - 40][356 - 27].status = MAP[87 - 40][356 - 26].status = MAP[88 - 40][356 - 25].status = 1;
	MAP[89 - 40][356 - 24].status = MAP[90 - 40][356 - 23].status = MAP[91 - 40][356 - 23].status = MAP[92 - 40][356 - 23].status = MAP[93 - 40][356 - 23].status = MAP[94 - 40][356 - 23].status = MAP[95 - 40][356 - 23].status = 1;
	MAP[96 - 40][356 - 23].status = MAP[97 - 40][356 - 23].status = MAP[98 - 40][356 - 23].status = MAP[99 - 40][356 - 23].status = MAP[100 - 40][356 - 23].status = MAP[101 - 40][356 - 23].status = MAP[102 - 40][356 - 23].status = 1;
	MAP[102 - 40][356 - 24].status = MAP[102 - 40][356 - 25].status = MAP[103 - 40][356 - 25].status = MAP[104 - 40][356 - 25].status = MAP[105 - 40][356 - 25].status = MAP[105 - 40][356 - 26].status = MAP[106 - 40][356 - 26].status = 1;
	MAP[106 - 40][356 - 27].status = MAP[106 - 40][356 - 28].status = MAP[106 - 40][356 - 29].status = MAP[106 - 40][356 - 30].status = MAP[106 - 40][356 - 31].status = MAP[106 - 40][356 - 32].status = MAP[106 - 40][356 - 33].status = 1;
	MAP[106 - 40][356 - 34].status = MAP[107 - 40][356 - 35].status = MAP[107 - 40][356 - 36].status = MAP[107 - 40][356 - 37].status = MAP[106 - 40][356 - 38].status = MAP[106 - 40][356 - 35].status = MAP[106 - 40][356 - 37].status = 1;
	MAP[106 - 40][356 - 39].status = MAP[105 - 40][356 - 40].status = MAP[105 - 40][356 - 41].status = MAP[105 - 40][356 - 42].status = MAP[105 - 40][356 - 43].status = MAP[104 - 40][356 - 44].status = MAP[103 - 40][356 - 45].status = 1;
	MAP[102 - 40][356 - 45].status = MAP[101 - 40][356 - 45].status = MAP[98 - 40][356 - 46].status = MAP[100 - 40][356 - 46].status = MAP[99 - 40][356 - 46].status = MAP[98 - 40][356 - 47].status = MAP[98 - 40][356 - 48].status = 1;
	MAP[102 - 40][356 - 45].status = MAP[101 - 40][356 - 45].status = MAP[98 - 40][356 - 46].status = MAP[100 - 40][356 - 46].status = MAP[99 - 40][356 - 46].status = MAP[98 - 40][356 - 47].status = MAP[98 - 40][356 - 48].status = 1;
	MAP[98 - 40][356 - 49].status = MAP[98 - 40][356 - 50].status = MAP[98 - 40][356 - 51].status = MAP[98 - 40][356 - 52].status = MAP[98 - 40][356 - 53].status = MAP[98 - 40][356 - 54].status = MAP[98 - 40][356 - 55].status = 1;
	MAP[92 - 40][356 - 56].status = MAP[97 - 40][356 - 56].status = MAP[97 - 40][356 - 56].status = MAP[96 - 40][356 - 56].status = MAP[95 - 40][356 - 56].status = MAP[94 - 40][356 - 56].status = MAP[93 - 40][356 - 56].status = 1;
	MAP[92 - 40][356 - 55].status = MAP[91 - 40][356 - 55].status = MAP[90 - 40][356 - 55].status = MAP[90 - 40][356 - 54].status = MAP[89 - 40][356 - 54].status = MAP[88 - 40][356 - 53].status = MAP[88 - 40][356 - 53].status = MAP[87 - 40][356 - 53].status = 1;
	MAP[86 - 40][356 - 52].status = MAP[85 - 40][356 - 51].status = MAP[84 - 40][356 - 51].status = MAP[83 - 40][356 - 50].status = MAP[83 - 40][356 - 49].status = MAP[83 - 40][356 - 48].status = MAP[83 - 40][356 - 47].status = 1;
	MAP[83 - 40][356 - 46].status = MAP[83 - 40][356 - 45].status = MAP[83 - 40][356 - 44].status = MAP[84 - 40][356 - 43].status = MAP[84 - 40][356 - 42].status = MAP[84 - 40][356 - 41].status = MAP[84 - 40][356 - 40].status = 1;
	MAP[84 - 40][356 - 39].status = MAP[84 - 40][356 - 38].status = MAP[84 - 40][356 - 37].status = MAP[84 - 40][356 - 36].status = MAP[84 - 40][356 - 35].status = MAP[84 - 40][356 - 34].status = MAP[84 - 40][356 - 33].status = MAP[84 - 40][356 - 32].status = 1;
	//좌측하단 블럭
	MAP[86][34].status = MAP[86][33].status = MAP[86][32].status = MAP[86][31].status = MAP[87][30].status = MAP[87][29].status = MAP[87][28].status = MAP[87][27].status = MAP[87][26].status = MAP[87][25].status = 1;
	MAP[88][24].status = MAP[89][23].status = MAP[90][22].status = MAP[91][21].status = MAP[91][20].status = MAP[92][19].status = MAP[93][19].status = MAP[94][19].status = MAP[95][20].status = 1;
	MAP[96][21].status = MAP[96][22].status = MAP[97][23].status = MAP[97][24].status = MAP[97][25].status = MAP[97][26].status = MAP[98][27].status = MAP[98][28].status = MAP[99][29].status = 1;
	MAP[100][30].status = MAP[100][31].status = MAP[100][32].status = MAP[100][33].status = MAP[100][34].status = MAP[100][35].status = MAP[100][36].status = MAP[100][37].status = MAP[100][38].status = 1;
	MAP[100][39].status = MAP[100][40].status = MAP[99][41].status = MAP[99][42].status = MAP[99][43].status = MAP[98][44].status = MAP[97][45].status = MAP[96][46].status = MAP[95][46].status = MAP[94][46].status = MAP[93][45].status = 1;
	MAP[92][45].status = MAP[92][44].status = MAP[92][43].status = MAP[91][42].status = MAP[90][41].status = MAP[89][40].status = MAP[88][39].status = MAP[88][38].status = MAP[87][37].status = MAP[86][36].status = MAP[86][35].status = 1;
	//우측하단 블럭
	MAP[86][356 - 34].status = MAP[86][356 - 33].status = MAP[86][356 - 32].status = MAP[86][356 - 31].status = MAP[87][356 - 30].status = MAP[87][356 - 29].status = MAP[87][356 - 28].status = MAP[87][356 - 27].status = MAP[87][356 - 26].status = MAP[87][356 - 25].status = 1;
	MAP[88][356 - 24].status = MAP[89][356 - 23].status = MAP[90][356 - 22].status = MAP[91][356 - 21].status = MAP[91][356 - 20].status = MAP[92][356 - 19].status = MAP[93][356 - 19].status = MAP[94][356 - 19].status = MAP[95][356 - 20].status = 1;
	MAP[96][356 - 21].status = MAP[96][356 - 22].status = MAP[97][356 - 23].status = MAP[97][356 - 24].status = MAP[97][356 - 25].status = MAP[97][356 - 26].status = MAP[98][356 - 27].status = MAP[98][356 - 28].status = MAP[99][356 - 29].status = 1;
	MAP[100][356 - 30].status = MAP[100][356 - 31].status = MAP[100][356 - 32].status = MAP[100][356 - 33].status = MAP[100][356 - 34].status = MAP[100][356 - 35].status = MAP[100][356 - 36].status = MAP[100][356 - 37].status = MAP[100][356 - 38].status = 1;
	MAP[100][356 - 39].status = MAP[100][356 - 40].status = MAP[99][356 - 41].status = MAP[99][356 - 42].status = MAP[99][356 - 43].status = MAP[98][356 - 44].status = MAP[97][356 - 45].status = MAP[96][356 - 46].status = MAP[95][356 - 46].status = MAP[94][356 - 46].status = MAP[93][356 - 45].status = 1;
	MAP[92][356 - 45].status = MAP[92][356 - 44].status = MAP[92][356 - 43].status = MAP[91][356 - 42].status = MAP[90][356 - 41].status = MAP[89][356 - 40].status = MAP[88][356 - 39].status = MAP[88][356 - 38].status = MAP[87][356 - 37].status = MAP[86][356 - 36].status = MAP[86][356 - 35].status = 1;
	//좌측 중앙 길
	MAP[78][70].status = MAP[77][69].status = MAP[77][68].status = MAP[77][67].status = MAP[77][66].status = MAP[77][65].status = MAP[77][64].status = MAP[77][63].status = MAP[77][62].status = MAP[77][61].status = MAP[77][60].status = MAP[78][59].status = 1;
	MAP[79][58].status = MAP[79][57].status = MAP[80][56].status = MAP[81][56].status = MAP[82][56].status = MAP[83][55].status = MAP[84][55].status = MAP[85][55].status = MAP[86][55].status = MAP[87][55].status = 1;
	MAP[88][56].status = MAP[89][57].status = MAP[90][58].status = MAP[90][59].status = MAP[91][60].status = MAP[91][61].status = MAP[91][62].status = MAP[91][63].status = MAP[91][64].status = MAP[91][65].status = MAP[91][66].status = 1;
	MAP[91][67].status = MAP[91][68].status = MAP[91][69].status = MAP[91][70].status = MAP[91][71].status = MAP[91][72].status = MAP[91][73].status = MAP[91][74].status = MAP[91][75].status = MAP[91][76].status = MAP[91][77].status = 1;
	MAP[91][78].status = MAP[91][79].status = MAP[91][80].status = MAP[91][81].status = MAP[91][82].status = MAP[91][83].status = MAP[78][71].status = MAP[78][72].status = MAP[78][73].status = MAP[77][74].status = 1;
	MAP[77][75].status = MAP[76][76].status = MAP[76][77].status = MAP[75][78].status = MAP[75][79].status = MAP[74][80].status = MAP[74][81].status = MAP[74][82].status = MAP[74][83].status = MAP[74][84].status = MAP[74][85].status = 1;
	MAP[74][86].status = MAP[74][87].status = MAP[75][88].status = MAP[74][89].status = MAP[74][90].status = MAP[74][91].status = MAP[74][92].status = MAP[74][93].status = MAP[75][94].status = MAP[75][95].status = MAP[76][95].status = 1;
	MAP[77][95].status = MAP[78][96].status = MAP[79][96].status = MAP[80][96].status = MAP[81][96].status = MAP[82][96].status = MAP[83][96].status = MAP[84][96].status = MAP[85][97].status = MAP[86][98].status = MAP[87][99].status = 1;
	MAP[88][100].status = MAP[88][101].status = MAP[88][102].status = MAP[88][103].status = MAP[88][104].status = MAP[88][105].status = MAP[89][106].status = MAP[90][107].status = MAP[91][108].status = MAP[91][109].status = 1;
	MAP[92][110].status = MAP[93][111].status = MAP[93][112].status = MAP[94][113].status = MAP[94][114].status = MAP[95][115].status = MAP[96][116].status = MAP[96][117].status = MAP[97][118].status = MAP[97][119].status = 1;
	MAP[98][120].status = MAP[99][121].status = MAP[100][121].status = MAP[101][122].status = MAP[102][123].status = MAP[103][124].status = MAP[104][125].status = MAP[104][126].status = MAP[105][127].status = MAP[106][127].status = 1;
	MAP[107][127].status = MAP[108][127].status = MAP[109][127].status = MAP[110][127].status = MAP[111][127].status = MAP[112][128].status = MAP[113][129].status = MAP[113][130].status = MAP[114][131].status = MAP[114][132].status = 1;
	MAP[114][133].status = MAP[113][134].status = MAP[113][135].status = MAP[113][136].status = MAP[112][137].status = MAP[112][138].status = MAP[112][139].status = MAP[112][140].status = MAP[112][141].status = MAP[112][142].status = 1;
	MAP[113][143].status = MAP[113][144].status = MAP[113][145].status = MAP[113][146].status = MAP[113][147].status = MAP[113][148].status = MAP[113][149].status = MAP[113][150].status = MAP[113][151].status = MAP[113][152].status = 1;
	MAP[114][153].status = MAP[113][154].status = MAP[113][155].status = MAP[113][156].status = MAP[113][157].status = MAP[113][158].status = MAP[114][159].status = MAP[114][160].status = MAP[114][161].status = MAP[115][162].status = 1;
	MAP[115][163].status = MAP[115][164].status = MAP[115][165].status = MAP[115][166].status = MAP[115][167].status = MAP[115][168].status = MAP[115][169].status = MAP[115][170].status = MAP[115][171].status = MAP[115][172].status = 1;
	MAP[115][173].status = MAP[115][174].status = MAP[114][175].status = MAP[114][176].status = MAP[114][177].status = MAP[115][178].status = MAP[114][179].status = MAP[114][180].status = MAP[114][181].status = MAP[114][182].status = 1;
	MAP[114][183].status = MAP[114][184].status = MAP[114][185].status = MAP[114][186].status = MAP[114][187].status = MAP[114][188].status = MAP[114][189].status = MAP[114][190].status = MAP[113][191].status = MAP[113][192].status = 1;
	MAP[113][193].status = MAP[113][194].status = MAP[112][195].status = MAP[112][196].status = MAP[112][197].status = MAP[112][198].status = MAP[112][199].status = MAP[112][200].status = MAP[112][201].status = MAP[112][202].status = 1;
	MAP[112][203].status = MAP[112][204].status = MAP[113][205].status = MAP[113][206].status = MAP[113][207].status = MAP[113][208].status = MAP[113][209].status = MAP[113][210].status = MAP[113][211].status = MAP[113][212].status = 1;
	MAP[112][213].status = MAP[112][214].status = MAP[112][215].status = MAP[112][216].status = MAP[112][217].status = MAP[113][218].status = MAP[113][219].status = MAP[113][220].status = MAP[113][221].status = MAP[114][222].status = 1;
	MAP[114][223].status = MAP[113][224].status = MAP[113][225].status = MAP[113][226].status = MAP[112][227].status = MAP[112][228].status = MAP[111][229].status = MAP[110][229].status = MAP[109][229].status = MAP[108][229].status = 1;
	MAP[108][229].status = MAP[107][229].status = MAP[106][229].status = MAP[105][229].status = MAP[104][230].status = MAP[103][231].status = MAP[102][232].status = MAP[101][233].status = MAP[100][234].status = MAP[99][235].status = MAP[98][236].status = 1;
	//
	MAP[91][84].status = MAP[91][85].status = MAP[92][86].status = MAP[93][86].status = MAP[94][87].status = MAP[95][88].status = MAP[96][89].status = MAP[97][90].status = MAP[98][91].status = MAP[99][92].status = MAP[100][93].status = 1;
	MAP[101][93].status = MAP[102][93].status = MAP[103][94].status = MAP[104][94].status = MAP[105][92].status = MAP[106][91].status = MAP[107][90].status = MAP[108][89].status = MAP[108][88].status = MAP[108][87].status = MAP[108][86].status = 1;
	MAP[105][93].status = MAP[108][85].status = MAP[108][84].status = MAP[107][83].status = MAP[106][82].status = MAP[105][81].status = MAP[105][80].status = MAP[105][79].status = MAP[105][78].status = MAP[105][77].status = MAP[105][78].status = 1;
	MAP[105][77].status = MAP[105][76].status = MAP[105][75].status = MAP[105][74].status = MAP[105][73].status = MAP[105][72].status = MAP[105][71].status = MAP[105][70].status = MAP[105][69].status = MAP[104][68].status = 1;
	MAP[103][68].status = MAP[102][68].status = MAP[101][68].status = MAP[100][67].status = MAP[99][66].status = MAP[98][65].status = MAP[97][64].status = MAP[97][63].status = MAP[98][62].status = MAP[98][61].status = MAP[98][60].status = 1;
	MAP[99][59].status = MAP[100][58].status = MAP[101][57].status = MAP[102][57].status = MAP[103][57].status = MAP[104][57].status = MAP[105][57].status = MAP[106][57].status = MAP[107][57].status = MAP[108][56].status = 1;
	MAP[108][55].status = MAP[108][54].status = MAP[107][53].status = MAP[107][52].status = MAP[107][51].status = MAP[107][50].status = MAP[107][49].status = MAP[107][48].status = MAP[107][47].status = MAP[107][46].status = 1;
	MAP[107][45].status = MAP[108][44].status = MAP[108][43].status = MAP[108][42].status = MAP[108][41].status = MAP[108][40].status = MAP[108][39].status = MAP[108][38].status = MAP[108][37].status = MAP[108][36].status = 1;
	MAP[109][35].status = MAP[109][34].status = MAP[109][33].status = MAP[109][32].status = MAP[109][31].status = MAP[109][30].status = MAP[109][29].status = MAP[108][28].status = MAP[108][27].status = MAP[108][26].status = 1;
	MAP[108][25].status = MAP[107][24].status = MAP[107][23].status = MAP[107][22].status = MAP[107][21].status = MAP[107][20].status = MAP[108][19].status = MAP[108][18].status = MAP[109][17].status = MAP[109][16].status = 1;
	MAP[109][15].status = MAP[109][14].status = MAP[108][13].status = MAP[108][12].status = MAP[107][11].status = MAP[106][11].status = MAP[105][10].status = MAP[104][10].status = MAP[103][10].status = MAP[102][10].status = 1;
	MAP[101][9].status = MAP[100][9].status = MAP[99][9].status = MAP[98][9].status = MAP[97][9].status = MAP[96][10].status = MAP[95][10].status = MAP[94][10].status = MAP[93][10].status = MAP[92][10].status = MAP[91][9].status = 1;
	MAP[90][9].status = MAP[89][9].status = MAP[88][8].status = MAP[87][8].status = MAP[86][8].status = MAP[85][7].status = MAP[84][7].status = MAP[83][7].status = MAP[82][7].status = MAP[81][7].status = MAP[80][8].status = MAP[79][9].status = 1;
	MAP[78][9].status = MAP[77][10].status = MAP[76][10].status = MAP[75][10].status = MAP[74][10].status = MAP[73][10].status = MAP[72][10].status = MAP[71][10].status = MAP[70][10].status = MAP[69][10].status = MAP[68][10].status = 1;
	MAP[67][10].status = MAP[66][11].status = MAP[65][11].status = MAP[64][11].status = MAP[63][11].status = MAP[62][11].status = MAP[61][11].status = MAP[60][11].status = MAP[59][11].status = MAP[58][12].status = MAP[57][12].status = 1;
	MAP[56][12].status = MAP[55][13].status = MAP[53][13].status = MAP[54][13].status = MAP[52][12].status = MAP[51][12].status = MAP[50][12].status = MAP[49][12].status = MAP[48][12].status = MAP[47][12].status = MAP[46][12].status = 1;
	MAP[45][12].status = MAP[44][12].status = MAP[43][12].status = MAP[42][12].status = MAP[41][13].status = MAP[40][14].status = MAP[39][14].status = MAP[38][15].status = MAP[37][15].status = MAP[36][16].status = MAP[35][17].status = 1;
	MAP[34][18].status = MAP[34][19].status = MAP[34][20].status = MAP[34][21].status = MAP[34][22].status = MAP[33][23].status = MAP[33][24].status = MAP[32][25].status = MAP[32][26].status = MAP[32][27].status = MAP[32][28].status = 1;
	MAP[31][29].status = MAP[31][30].status = MAP[31][31].status = MAP[31][32].status = MAP[31][33].status = MAP[31][34].status = MAP[31][35].status = MAP[31][36].status = MAP[31][37].status = MAP[31][38].status = MAP[32][39].status = 1;
	MAP[32][40].status = MAP[32][41].status = MAP[32][42].status = MAP[31][43].status = MAP[31][44].status = MAP[31][45].status = MAP[31][46].status = MAP[31][47].status = MAP[30][48].status = MAP[30][49].status = MAP[30][50].status = 1;
	MAP[30][51].status = MAP[30][52].status = MAP[31][53].status = MAP[32][54].status = MAP[33][55].status = MAP[34][56].status = MAP[34][57].status = MAP[35][58].status = MAP[36][59].status = MAP[37][60].status = MAP[38][61].status = 1;
	MAP[39][61].status = MAP[40][62].status = MAP[41][62].status = MAP[42][62].status = MAP[43][63].status = MAP[44][63].status = MAP[45][63].status = MAP[46][63].status = MAP[47][63].status = MAP[48][63].status = MAP[49][63].status = 1;
	MAP[50][63].status = MAP[51][63].status = MAP[52][63].status = MAP[53][63].status = MAP[54][63].status = MAP[55][63].status = MAP[56][64].status = MAP[57][64].status = MAP[58][64].status = MAP[59][64].status = MAP[60][65].status = 1;
	MAP[61][65].status = MAP[62][65].status = MAP[63][65].status = MAP[63][66].status = MAP[63][67].status = MAP[63][68].status = MAP[63][69].status = MAP[63][70].status = MAP[62][71].status = MAP[61][72].status = MAP[60][73].status = 1;
	MAP[60][74].status = MAP[59][75].status = MAP[59][76].status = MAP[59][77].status = MAP[58][78].status = MAP[58][79].status = MAP[57][80].status = MAP[57][81].status = MAP[56][82].status = MAP[55][83].status = MAP[55][84].status = 1;
	MAP[54][85].status = MAP[54][86].status = MAP[53][87].status = MAP[52][87].status = MAP[51][88].status = MAP[50][89].status = MAP[49][90].status = MAP[49][91].status = MAP[48][92].status = MAP[48][93].status = MAP[47][94].status = 1;
	MAP[47][95].status = MAP[47][96].status = MAP[46][97].status = MAP[46][98].status = MAP[46][99].status = MAP[45][100].status = MAP[44][101].status = MAP[43][102].status = MAP[42][103].status = MAP[41][104].status = MAP[40][104].status = 1;
	MAP[39][104].status = MAP[38][104].status = MAP[37][104].status = MAP[36][105].status = MAP[35][105].status = MAP[34][105].status = MAP[33][106].status = MAP[33][107].status = MAP[32][108].status = MAP[32][109].status = MAP[32][110].status = 1;
	MAP[32][111].status = MAP[32][112].status = MAP[33][113].status = MAP[33][114].status = MAP[33][115].status = MAP[33][116].status = MAP[34][117].status = MAP[34][118].status = MAP[34][119].status = MAP[35][120].status = 1;
	MAP[35][121].status = MAP[36][122].status = MAP[36][123].status = MAP[37][124].status = MAP[37][125].status = MAP[37][126].status = MAP[38][127].status = MAP[38][128].status = MAP[38][129].status = MAP[38][130].status = MAP[38][131].status = 1;
	MAP[37][132].status = MAP[37][133].status = MAP[36][134].status = MAP[35][135].status = 1;

	//
	MAP[91][356 - 356 - 84].status = MAP[91][356 - 85].status = MAP[92][356 - 86].status = MAP[93][356 - 86].status = MAP[94][356 - 87].status = MAP[95][356 - 88].status = MAP[96][356 - 89].status = MAP[97][356 - 90].status = MAP[98][356 - 91].status = MAP[99][356 - 92].status = MAP[100][356 - 93].status = 1;
	MAP[101][356 - 93].status = MAP[102][356 - 93].status = MAP[103][356 - 94].status = MAP[104][356 - 94].status = MAP[105][356 - 92].status = MAP[106][356 - 91].status = MAP[107][356 - 90].status = MAP[108][356 - 89].status = MAP[108][356 - 88].status = MAP[108][356 - 87].status = MAP[108][356 - 86].status = 1;
	MAP[105][356 - 93].status = MAP[108][356 - 85].status = MAP[108][356 - 84].status = MAP[107][356 - 83].status = MAP[106][356 - 82].status = MAP[105][356 - 81].status = MAP[105][356 - 80].status = MAP[105][356 - 79].status = MAP[105][356 - 78].status = MAP[105][356 - 77].status = MAP[105][356 - 78].status = 1;
	MAP[105][356 - 77].status = MAP[105][356 - 76].status = MAP[105][356 - 75].status = MAP[105][356 - 74].status = MAP[105][356 - 73].status = MAP[105][356 - 72].status = MAP[105][356 - 71].status = MAP[105][356 - 70].status = MAP[105][356 - 69].status = MAP[104][356 - 68].status = 1;
	MAP[103][356 - 68].status = MAP[102][356 - 68].status = MAP[101][356 - 68].status = MAP[100][356 - 67].status = MAP[99][356 - 66].status = MAP[98][356 - 65].status = MAP[97][356 - 64].status = MAP[97][356 - 63].status = MAP[98][356 - 62].status = MAP[98][356 - 61].status = MAP[98][356 - 60].status = 1;
	MAP[99][356 - 59].status = MAP[100][356 - 58].status = MAP[101][356 - 57].status = MAP[102][356 - 57].status = MAP[103][356 - 57].status = MAP[104][356 - 57].status = MAP[105][356 - 57].status = MAP[106][356 - 57].status = MAP[107][356 - 57].status = MAP[108][356 - 56].status = 1;
	MAP[108][356 - 55].status = MAP[108][356 - 54].status = MAP[107][356 - 53].status = MAP[107][356 - 52].status = MAP[107][356 - 51].status = MAP[107][356 - 50].status = MAP[107][356 - 49].status = MAP[107][356 - 48].status = MAP[107][356 - 47].status = MAP[107][356 - 46].status = 1;
	MAP[107][356 - 45].status = MAP[108][356 - 44].status = MAP[108][356 - 43].status = MAP[108][356 - 42].status = MAP[108][356 - 41].status = MAP[108][356 - 40].status = MAP[108][356 - 39].status = MAP[108][356 - 38].status = MAP[108][356 - 37].status = MAP[108][356 - 36].status = 1;
	MAP[109][356 - 35].status = MAP[109][356 - 34].status = MAP[109][356 - 33].status = MAP[109][356 - 32].status = MAP[109][356 - 31].status = MAP[109][356 - 30].status = MAP[109][356 - 29].status = MAP[108][356 - 28].status = MAP[108][356 - 27].status = MAP[108][356 - 26].status = 1;
	MAP[108][356 - 25].status = MAP[107][356 - 24].status = MAP[107][356 - 23].status = MAP[107][356 - 22].status = MAP[107][356 - 21].status = MAP[107][356 - 20].status = MAP[108][356 - 19].status = MAP[108][356 - 18].status = MAP[109][356 - 17].status = MAP[109][356 - 16].status = 1;
	MAP[109][356 - 15].status = MAP[109][356 - 14].status = MAP[108][356 - 13].status = MAP[108][356 - 12].status = MAP[107][356 - 11].status = MAP[106][356 - 11].status = MAP[105][356 - 10].status = MAP[104][356 - 10].status = MAP[103][356 - 10].status = MAP[102][356 - 10].status = 1;
	MAP[101][356 - 9].status = MAP[100][356 - 9].status = MAP[99][356 - 9].status = MAP[98][356 - 9].status = MAP[97][356 - 9].status = MAP[96][356 - 10].status = MAP[95][356 - 10].status = MAP[94][356 - 10].status = MAP[93][356 - 10].status = MAP[92][356 - 10].status = MAP[91][356 - 9].status = 1;
	MAP[90][356 - 9].status = MAP[89][356 - 9].status = MAP[88][356 - 8].status = MAP[87][356 - 8].status = MAP[86][356 - 8].status = MAP[85][356 - 7].status = MAP[84][356 - 7].status = MAP[83][356 - 7].status = MAP[82][356 - 7].status = MAP[81][356 - 7].status = MAP[80][356 - 8].status = MAP[79][356 - 9].status = 1;
	MAP[78][356 - 9].status = MAP[77][356 - 10].status = MAP[76][356 - 10].status = MAP[75][356 - 10].status = MAP[74][356 - 10].status = MAP[73][356 - 10].status = MAP[72][356 - 10].status = MAP[71][356 - 10].status = MAP[70][356 - 10].status = MAP[69][356 - 10].status = MAP[68][356 - 10].status = 1;
	MAP[67][356 - 10].status = MAP[66][356 - 11].status = MAP[65][356 - 11].status = MAP[64][356 - 11].status = MAP[63][356 - 11].status = MAP[62][356 - 11].status = MAP[61][356 - 11].status = MAP[60][356 - 11].status = MAP[59][356 - 11].status = MAP[58][356 - 12].status = MAP[57][356 - 12].status = 1;
	MAP[56][356 - 12].status = MAP[55][356 - 13].status = MAP[53][356 - 13].status = MAP[54][356 - 13].status = MAP[52][356 - 12].status = MAP[51][356 - 12].status = MAP[50][356 - 12].status = MAP[49][356 - 12].status = MAP[48][356 - 12].status = MAP[47][356 - 12].status = MAP[46][356 - 12].status = 1;
	MAP[45][356 - 12].status = MAP[44][356 - 12].status = MAP[43][356 - 12].status = MAP[42][356 - 12].status = MAP[41][356 - 13].status = MAP[40][356 - 14].status = MAP[39][356 - 14].status = MAP[38][356 - 15].status = MAP[37][356 - 15].status = MAP[36][356 - 16].status = MAP[35][356 - 17].status = 1;
	MAP[34][356 - 18].status = MAP[34][356 - 19].status = MAP[34][356 - 20].status = MAP[34][356 - 21].status = MAP[34][356 - 22].status = MAP[33][356 - 23].status = MAP[33][356 - 24].status = MAP[32][356 - 25].status = MAP[32][356 - 26].status = MAP[32][356 - 27].status = MAP[32][356 - 28].status = 1;
	MAP[31][356 - 29].status = MAP[31][356 - 30].status = MAP[31][356 - 31].status = MAP[31][356 - 32].status = MAP[31][356 - 33].status = MAP[31][356 - 34].status = MAP[31][356 - 35].status = MAP[31][356 - 36].status = MAP[31][356 - 37].status = MAP[31][356 - 38].status = MAP[32][356 - 39].status = 1;
	MAP[32][356 - 40].status = MAP[32][356 - 41].status = MAP[32][356 - 42].status = MAP[31][356 - 43].status = MAP[31][356 - 44].status = MAP[31][356 - 45].status = MAP[31][356 - 46].status = MAP[31][356 - 47].status = MAP[30][356 - 48].status = MAP[30][356 - 49].status = MAP[30][356 - 50].status = 1;
	MAP[30][356 - 51].status = MAP[30][356 - 52].status = MAP[31][356 - 53].status = MAP[32][356 - 54].status = MAP[33][356 - 55].status = MAP[34][356 - 56].status = MAP[34][356 - 57].status = MAP[35][356 - 58].status = MAP[36][356 - 59].status = MAP[37][356 - 60].status = MAP[38][356 - 61].status = 1;
	MAP[39][356 - 61].status = MAP[40][356 - 62].status = MAP[41][356 - 62].status = MAP[42][356 - 62].status = MAP[43][356 - 63].status = MAP[44][356 - 63].status = MAP[45][356 - 63].status = MAP[46][356 - 63].status = MAP[47][356 - 63].status = MAP[48][356 - 63].status = MAP[49][356 - 63].status = 1;
	MAP[50][356 - 63].status = MAP[51][356 - 63].status = MAP[52][356 - 63].status = MAP[53][356 - 63].status = MAP[54][356 - 63].status = MAP[55][356 - 63].status = MAP[56][356 - 64].status = MAP[57][356 - 64].status = MAP[58][356 - 64].status = MAP[59][356 - 64].status = MAP[60][356 - 65].status = 1;
	MAP[61][356 - 65].status = MAP[62][356 - 65].status = MAP[63][356 - 65].status = MAP[63][356 - 66].status = MAP[63][356 - 67].status = MAP[63][356 - 68].status = MAP[63][356 - 69].status = MAP[63][356 - 70].status = MAP[62][356 - 71].status = MAP[61][356 - 72].status = MAP[60][356 - 73].status = 1;
	MAP[60][356 - 74].status = MAP[59][356 - 75].status = MAP[59][356 - 76].status = MAP[59][356 - 77].status = MAP[58][356 - 78].status = MAP[58][356 - 79].status = MAP[57][356 - 80].status = MAP[57][356 - 81].status = MAP[56][356 - 82].status = MAP[55][356 - 83].status = MAP[55][356 - 84].status = 1;
	MAP[54][356 - 85].status = MAP[54][356 - 86].status = MAP[53][356 - 87].status = MAP[52][356 - 87].status = MAP[51][356 - 88].status = MAP[50][356 - 89].status = MAP[49][356 - 90].status = MAP[49][356 - 91].status = MAP[48][356 - 92].status = MAP[48][356 - 93].status = MAP[47][356 - 94].status = 1;
	MAP[47][356 - 95].status = MAP[47][356 - 96].status = MAP[46][356 - 97].status = MAP[46][356 - 98].status = MAP[46][356 - 99].status = MAP[45][356 - 100].status = MAP[44][356 - 101].status = MAP[43][356 - 102].status = MAP[42][356 - 103].status = MAP[41][356 - 104].status = MAP[40][356 - 104].status = 1;
	MAP[39][356 - 104].status = MAP[38][356 - 104].status = MAP[37][356 - 104].status = MAP[36][356 - 105].status = MAP[35][356 - 105].status = MAP[34][356 - 105].status = MAP[33][356 - 106].status = MAP[33][356 - 107].status = MAP[32][356 - 108].status = MAP[32][356 - 109].status = MAP[32][356 - 110].status = 1;
	MAP[32][356 - 111].status = MAP[32][356 - 112].status = MAP[33][356 - 113].status = MAP[33][356 - 114].status = MAP[33][356 - 115].status = MAP[33][356 - 116].status = MAP[34][356 - 117].status = MAP[34][356 - 118].status = MAP[34][356 - 119].status = MAP[35][356 - 120].status = 1;
	MAP[35][356 - 121].status = MAP[36][356 - 122].status = MAP[36][356 - 123].status = MAP[37][356 - 124].status = MAP[37][356 - 125].status = MAP[37][356 - 126].status = MAP[38][356 - 127].status = MAP[38][356 - 128].status = MAP[38][356 - 129].status = MAP[38][356 - 130].status = MAP[38][356 - 131].status = 1;
	MAP[37][356 - 132].status = MAP[37][356 - 133].status = MAP[36][356 - 134].status = MAP[35][356 - 135].status = 1;
	//우측 중앙길
	MAP[78][356 - 70].status = MAP[77][356 - 69].status = MAP[77][356 - 68].status = MAP[77][356 - 67].status = MAP[77][356 - 66].status = MAP[77][356 - 65].status = MAP[77][356 - 64].status = MAP[77][356 - 63].status = MAP[77][356 - 62].status = MAP[77][356 - 61].status = MAP[77][356 - 60].status = MAP[78][356 - 59].status = 1;
	MAP[79][356 - 58].status = MAP[79][356 - 57].status = MAP[80][356 - 56].status = MAP[81][356 - 56].status = MAP[82][356 - 56].status = MAP[83][356 - 55].status = MAP[84][356 - 55].status = MAP[85][356 - 55].status = MAP[86][356 - 55].status = MAP[87][356 - 55].status = 1;
	MAP[88][356 - 56].status = MAP[89][356 - 57].status = MAP[90][356 - 58].status = MAP[90][356 - 59].status = MAP[91][356 - 60].status = MAP[91][356 - 61].status = MAP[91][356 - 62].status = MAP[91][356 - 63].status = MAP[91][356 - 64].status = MAP[91][356 - 65].status = MAP[91][356 - 66].status = 1;
	MAP[91][356 - 67].status = MAP[91][356 - 68].status = MAP[91][356 - 69].status = MAP[91][356 - 70].status = MAP[91][356 - 71].status = MAP[91][356 - 72].status = MAP[91][356 - 73].status = MAP[91][356 - 74].status = MAP[91][356 - 75].status = MAP[91][356 - 76].status = MAP[91][356 - 77].status = 1;
	MAP[91][356 - 78].status = MAP[91][356 - 79].status = MAP[91][356 - 80].status = MAP[91][356 - 81].status = MAP[91][356 - 82].status = MAP[91][356 - 83].status = MAP[78][356 - 71].status = MAP[78][356 - 72].status = MAP[78][356 - 73].status = MAP[77][356 - 74].status = 1;
	MAP[77][356 - 75].status = MAP[76][356 - 76].status = MAP[76][356 - 77].status = MAP[75][356 - 78].status = MAP[75][356 - 79].status = MAP[74][356 - 80].status = MAP[74][356 - 81].status = MAP[74][356 - 82].status = MAP[74][356 - 83].status = MAP[74][356 - 84].status = MAP[74][356 - 85].status = 1;
	MAP[74][356 - 86].status = MAP[74][356 - 87].status = MAP[75][356 - 88].status = MAP[74][356 - 89].status = MAP[74][356 - 90].status = MAP[74][356 - 91].status = MAP[74][356 - 92].status = MAP[74][356 - 93].status = MAP[75][356 - 94].status = MAP[75][356 - 95].status = MAP[76][356 - 95].status = 1;
	MAP[77][356 - 95].status = MAP[78][356 - 96].status = MAP[79][356 - 96].status = MAP[80][356 - 96].status = MAP[81][356 - 96].status = MAP[82][356 - 96].status = MAP[83][356 - 96].status = MAP[84][356 - 96].status = MAP[85][356 - 97].status = MAP[86][356 - 98].status = MAP[87][356 - 99].status = 1;
	MAP[88][356 - 100].status = MAP[88][356 - 101].status = MAP[88][356 - 102].status = MAP[88][356 - 103].status = MAP[88][356 - 104].status = MAP[88][356 - 105].status = MAP[89][356 - 106].status = MAP[90][356 - 107].status = MAP[91][356 - 108].status = MAP[91][356 - 109].status = 1;
	MAP[92][356 - 110].status = MAP[93][356 - 111].status = MAP[93][356 - 112].status = MAP[94][356 - 113].status = MAP[94][356 - 114].status = MAP[95][356 - 115].status = MAP[96][356 - 116].status = MAP[96][356 - 117].status = MAP[97][356 - 118].status = MAP[97][356 - 119].status = 1;

	//중앙좌측블럭
	MAP[65][100].status = MAP[64][101].status = MAP[63][102].status = MAP[62][103].status = MAP[61][104].status = MAP[60][105].status = MAP[59][106].status = MAP[58][107].status = MAP[57][108].status = MAP[56][108].status = MAP[55][109].status = MAP[54][110].status = MAP[54][111].status = 1;
	MAP[53][112].status = MAP[53][113].status = MAP[52][114].status = MAP[52][115].status = MAP[51][116].status = MAP[51][117].status = MAP[51][118].status = MAP[51][119].status = MAP[52][120].status = MAP[52][121].status = MAP[53][122].status = MAP[54][122].status = MAP[55][123].status = 1;
	MAP[56][123].status = MAP[57][124].status = MAP[58][124].status = MAP[59][125].status = MAP[60][125].status = MAP[61][125].status = MAP[62][126].status = MAP[63][126].status = MAP[64][126].status = MAP[65][126].status = MAP[66][127].status = MAP[67][128].status = MAP[68][129].status = 1;
	MAP[68][129].status = MAP[69][129].status = MAP[70][130].status = MAP[71][131].status = MAP[72][132].status = MAP[72][133].status = MAP[72][134].status = MAP[73][135].status = MAP[73][136].status = MAP[73][137].status = MAP[74][138].status = MAP[74][139].status = MAP[74][140].status = 1;
	MAP[74][141].status = MAP[74][142].status = MAP[73][143].status = MAP[73][144].status = MAP[73][145].status = MAP[73][146].status = MAP[73][147].status = MAP[73][148].status = MAP[73][149].status = MAP[73][150].status = MAP[73][151].status = MAP[73][152].status = MAP[73][153].status = 1;
	MAP[73][154].status = MAP[73][155].status = MAP[74][156].status = MAP[75][157].status = MAP[76][157].status = MAP[77][158].status = MAP[78][158].status = MAP[79][158].status = MAP[80][157].status = MAP[81][156].status = MAP[82][155].status = MAP[83][154].status = MAP[83][153].status = 1;
	MAP[83][152].status = MAP[83][151].status = MAP[83][150].status = MAP[83][149].status = MAP[84][148].status = MAP[85][147].status = MAP[86][146].status = MAP[87][145].status = MAP[88][144].status = MAP[89][143].status = MAP[89][142].status = MAP[90][141].status = MAP[90][140].status = 1;
	MAP[90][140].status = MAP[90][139].status = MAP[90][138].status = MAP[90][137].status = MAP[91][136].status = MAP[91][135].status = MAP[92][134].status = MAP[92][133].status = MAP[92][132].status = MAP[92][131].status = MAP[93][130].status = MAP[93][129].status = MAP[93][128].status = 1;
	MAP[93][127].status = MAP[93][126].status = MAP[93][125].status = MAP[93][124].status = MAP[92][123].status = MAP[91][122].status = MAP[91][121].status = MAP[90][120].status = MAP[89][119].status = MAP[89][118].status = MAP[88][117].status = MAP[87][117].status = MAP[86][116].status = 1;
	MAP[85][115].status = MAP[84][115].status = MAP[83][114].status = MAP[82][114].status = MAP[81][114].status = MAP[81][115].status = MAP[81][116].status = MAP[81][117].status = MAP[81][118].status = MAP[81][119].status = MAP[80][120].status = MAP[79][120].status = MAP[78][120].status = 1;
	MAP[77][120].status = MAP[76][120].status = MAP[75][120].status = MAP[74][120].status = MAP[73][120].status = MAP[72][119].status = MAP[71][118].status = MAP[71][117].status = MAP[71][116].status = MAP[71][115].status = MAP[71][114].status = MAP[71][113].status = MAP[70][112].status = 1;
	MAP[70][111].status = MAP[70][110].status = MAP[70][109].status = MAP[69][108].status = MAP[69][107].status = MAP[69][106].status = MAP[68][105].status = MAP[68][104].status = MAP[67][103].status = MAP[67][102].status = MAP[66][101].status = MAP[65][100].status = 1;
	//중앙우측블럭
	MAP[65][356 - 100].status = MAP[64][356 - 101].status = MAP[63][356 - 102].status = MAP[62][356 - 103].status = MAP[61][356 - 104].status = MAP[60][356 - 105].status = MAP[59][356 - 106].status = MAP[58][356 - 107].status = MAP[57][356 - 108].status = MAP[56][356 - 108].status = MAP[55][356 - 109].status = MAP[54][356 - 110].status = MAP[54][356 - 111].status = 1;
	MAP[53][356 - 112].status = MAP[53][356 - 113].status = MAP[52][356 - 114].status = MAP[52][356 - 115].status = MAP[51][356 - 116].status = MAP[51][356 - 117].status = MAP[51][356 - 118].status = MAP[51][356 - 119].status = MAP[52][356 - 120].status = MAP[52][356 - 121].status = MAP[53][356 - 122].status = MAP[54][356 - 122].status = MAP[55][356 - 123].status = 1;
	MAP[56][356 - 123].status = MAP[57][356 - 124].status = MAP[58][356 - 124].status = MAP[59][356 - 125].status = MAP[60][356 - 125].status = MAP[61][356 - 125].status = MAP[62][356 - 126].status = MAP[63][356 - 126].status = MAP[64][356 - 126].status = MAP[65][356 - 126].status = MAP[66][356 - 127].status = MAP[67][356 - 128].status = MAP[68][356 - 129].status = 1;
	MAP[68][356 - 129].status = MAP[69][356 - 129].status = MAP[70][356 - 130].status = MAP[71][356 - 131].status = MAP[72][356 - 132].status = MAP[72][356 - 133].status = MAP[72][356 - 134].status = MAP[73][356 - 135].status = MAP[73][356 - 136].status = MAP[73][356 - 137].status = MAP[74][356 - 138].status = MAP[74][356 - 139].status = MAP[74][356 - 140].status = 1;
	MAP[74][356 - 141].status = MAP[74][356 - 142].status = MAP[73][356 - 143].status = MAP[73][356 - 144].status = MAP[73][356 - 145].status = MAP[73][356 - 146].status = MAP[73][356 - 147].status = MAP[73][356 - 148].status = MAP[73][356 - 149].status = MAP[73][356 - 150].status = MAP[73][356 - 151].status = MAP[73][356 - 152].status = MAP[73][356 - 153].status = 1;
	MAP[73][356 - 154].status = MAP[73][356 - 155].status = MAP[74][356 - 156].status = MAP[75][356 - 157].status = MAP[76][356 - 157].status = MAP[77][356 - 158].status = MAP[78][356 - 158].status = MAP[79][356 - 158].status = MAP[80][356 - 157].status = MAP[81][356 - 156].status = MAP[82][356 - 155].status = MAP[83][356 - 154].status = MAP[83][356 - 153].status = 1;
	MAP[83][356 - 152].status = MAP[83][356 - 151].status = MAP[83][356 - 150].status = MAP[83][356 - 149].status = MAP[84][356 - 148].status = MAP[85][356 - 147].status = MAP[86][356 - 146].status = MAP[87][356 - 145].status = MAP[88][356 - 144].status = MAP[89][356 - 143].status = MAP[89][356 - 142].status = MAP[90][356 - 141].status = MAP[90][356 - 140].status = 1;
	MAP[90][356 - 140].status = MAP[90][356 - 139].status = MAP[90][356 - 138].status = MAP[90][356 - 137].status = MAP[91][356 - 136].status = MAP[91][356 - 135].status = MAP[92][356 - 134].status = MAP[92][356 - 133].status = MAP[92][356 - 132].status = MAP[92][356 - 131].status = MAP[93][356 - 130].status = MAP[93][356 - 129].status = MAP[93][356 - 128].status = 1;
	MAP[93][356 - 127].status = MAP[93][356 - 126].status = MAP[93][356 - 125].status = MAP[93][356 - 124].status = MAP[92][356 - 123].status = MAP[91][356 - 122].status = MAP[91][356 - 121].status = MAP[90][356 - 120].status = MAP[89][356 - 119].status = MAP[89][356 - 118].status = MAP[88][356 - 117].status = MAP[87][356 - 117].status = MAP[86][356 - 116].status = 1;
	MAP[85][356 - 115].status = MAP[84][356 - 115].status = MAP[83][356 - 114].status = MAP[82][356 - 114].status = MAP[81][356 - 114].status = MAP[81][356 - 115].status = MAP[81][356 - 116].status = MAP[81][356 - 117].status = MAP[81][356 - 118].status = MAP[81][356 - 119].status = MAP[80][356 - 120].status = MAP[79][356 - 120].status = MAP[78][356 - 120].status = 1;
	MAP[77][356 - 120].status = MAP[76][356 - 120].status = MAP[75][356 - 120].status = MAP[74][356 - 120].status = MAP[73][356 - 120].status = MAP[72][356 - 119].status = MAP[71][356 - 118].status = MAP[71][356 - 117].status = MAP[71][356 - 116].status = MAP[71][356 - 115].status = MAP[71][356 - 114].status = MAP[71][356 - 113].status = MAP[70][356 - 112].status = 1;
	MAP[70][356 - 111].status = MAP[70][356 - 110].status = MAP[70][356 - 109].status = MAP[69][356 - 108].status = MAP[69][356 - 107].status = MAP[69][356 - 106].status = MAP[68][356 - 105].status = MAP[68][356 - 104].status = MAP[67][356 - 103].status = MAP[67][356 - 102].status = MAP[66][356 - 101].status = MAP[65][356 - 100].status = 1;
	//중앙 하단블럭
	MAP[88][171].status = MAP[88][172].status = MAP[88][173].status = MAP[88][174].status = MAP[88][175].status = MAP[88][176].status = MAP[88][177].status = MAP[88][178].status = MAP[88][179].status = MAP[88][180].status = MAP[88][181].status = MAP[88][182].status = MAP[88][183].status = 1;
	MAP[88][184].status = MAP[88][185].status = MAP[88][186].status = MAP[89][187].status = MAP[90][188].status = MAP[91][189].status = MAP[92][189].status = MAP[93][189].status = MAP[94][189].status = MAP[95][188].status = MAP[96][188].status = MAP[97][187].status = MAP[98][187].status = 1;
	MAP[99][186].status = MAP[99][185].status = MAP[99][184].status = MAP[99][183].status = MAP[99][182].status = MAP[99][181].status = MAP[99][180].status = MAP[99][179].status = MAP[100][178].status = MAP[100][177].status = MAP[100][176].status = MAP[100][175].status = MAP[100][174].status = 1;
	MAP[100][173].status = MAP[100][172].status = MAP[100][171].status = MAP[99][170].status = MAP[98][169].status = MAP[97][168].status = MAP[96][167].status = MAP[95][167].status = MAP[94][167].status = MAP[93][167].status = MAP[92][167].status = MAP[91][167].status = 1;
	MAP[90][168].status = MAP[89][169].status = MAP[89][170].status = 1;
	//중앙 상단블럭
	MAP[37][148].status = MAP[36][148].status = MAP[35][149].status = MAP[34][149].status = MAP[33][150].status = MAP[32][150].status = MAP[31][151].status = MAP[31][152].status = MAP[30][153].status = MAP[30][154].status = MAP[30][155].status = MAP[30][156].status = 1;
	MAP[30][157].status = MAP[30][158].status = MAP[30][159].status = MAP[30][160].status = MAP[30][161].status = MAP[30][162].status = MAP[30][163].status = MAP[31][164].status = MAP[31][165].status = MAP[31][166].status = MAP[30][167].status = MAP[29][168].status = MAP[28][169].status = 1;
	MAP[28][170].status = MAP[28][171].status = MAP[27][172].status = MAP[27][173].status = MAP[27][174].status = MAP[27][173].status = MAP[27][174].status = MAP[27][175].status = MAP[27][176].status = MAP[27][177].status = MAP[27][178].status = MAP[27][179].status = 1;
	MAP[27][180].status = MAP[27][181].status = MAP[27][182].status = MAP[27][183].status = MAP[27][184].status = MAP[28][185].status = MAP[28][186].status = MAP[28][187].status = MAP[29][188].status = MAP[30][189].status = MAP[31][190].status = MAP[31][191].status = MAP[31][192].status = 1;
	MAP[30][193].status = MAP[30][194].status = MAP[30][195].status = MAP[30][196].status = MAP[30][197].status = MAP[30][198].status = MAP[30][199].status = MAP[30][200].status = MAP[30][201].status = MAP[30][202].status = MAP[30][203].status = MAP[31][204].status = 1;
	MAP[32][205].status = MAP[33][205].status = MAP[34][206].status = MAP[34][207].status = MAP[35][207].status = MAP[36][207].status = MAP[37][208].status = MAP[38][208].status = MAP[39][207].status = MAP[40][206].status = MAP[40][205].status = MAP[41][204].status = 1;
	MAP[42][203].status = MAP[42][202].status = MAP[42][201].status = MAP[42][200].status = MAP[42][199].status = MAP[42][198].status = MAP[42][197].status = MAP[42][196].status = MAP[42][195].status = MAP[42][194].status = MAP[42][193].status = MAP[42][192].status = 1;
	MAP[42][191].status = MAP[42][190].status = MAP[42][189].status = MAP[42][188].status = MAP[42][187].status = MAP[42][186].status = MAP[42][185].status = MAP[42][184].status = MAP[42][183].status = MAP[42][182].status = MAP[42][181].status = MAP[42][180].status = 1;
	MAP[42][179].status = MAP[42][178].status = MAP[42][177].status = MAP[42][176].status = MAP[42][175].status = MAP[42][174].status = MAP[42][173].status = MAP[42][172].status = MAP[42][171].status = MAP[42][170].status = MAP[42][169].status = MAP[42][168].status = 1;
	MAP[42][167].status = MAP[42][166].status = MAP[42][165].status = MAP[42][164].status = MAP[42][163].status = MAP[42][162].status = MAP[42][161].status = MAP[42][160].status = MAP[42][159].status = MAP[42][158].status = MAP[42][157].status = MAP[42][156].status = 1;
	MAP[42][155].status = MAP[42][154].status = MAP[42][153].status = MAP[42][152].status = MAP[42][151].status = MAP[41][150].status = MAP[40][149].status = MAP[39][148].status = MAP[38][148].status = 1;
	//중앙 상단 천장
	MAP[34][136].status = MAP[33][136].status = MAP[32][137].status = MAP[31][137].status = MAP[30][137].status = MAP[29][137].status = MAP[28][137].status = MAP[27][137].status = MAP[26][137].status = MAP[25][138].status = MAP[24][139].status = MAP[23][140].status = 1;
	MAP[22][141].status = MAP[21][142].status = MAP[20][142].status = MAP[19][143].status = MAP[18][144].status = MAP[17][144].status = MAP[16][144].status = MAP[15][145].status = MAP[14][146].status = MAP[13][146].status = MAP[12][146].status = MAP[11][146].status = 1;
	MAP[10][146].status = MAP[9][146].status = MAP[8][147].status = MAP[8][148].status = MAP[8][149].status = MAP[8][150].status = MAP[8][151].status = MAP[8][152].status = MAP[8][153].status = MAP[8][154].status = MAP[8][155].status = MAP[8][156].status = MAP[8][157].status = 1;
	MAP[8][158].status = MAP[8][159].status = MAP[8][160].status = MAP[8][161].status = MAP[8][162].status = MAP[8][163].status = MAP[8][164].status = MAP[8][165].status = MAP[8][166].status = MAP[8][167].status = MAP[8][168].status = MAP[8][169].status = MAP[8][170].status = 1;
	MAP[8][170].status = MAP[8][171].status = MAP[8][172].status = MAP[8][173].status = MAP[8][174].status = MAP[8][175].status = MAP[8][176].status = MAP[8][177].status = MAP[8][178].status = 1;

	MAP[34][356 - 136].status = MAP[33][356 - 136].status = MAP[32][356 - 137].status = MAP[31][356 - 137].status = MAP[30][356 - 137].status = MAP[29][356 - 137].status = MAP[28][356 - 137].status = MAP[27][356 - 137].status = MAP[26][356 - 137].status = MAP[25][356 - 138].status = MAP[24][356 - 139].status = MAP[23][356 - 140].status = 1;
	MAP[22][356 - 141].status = MAP[21][356 - 142].status = MAP[20][356 - 142].status = MAP[19][356 - 143].status = MAP[18][356 - 144].status = MAP[17][356 - 144].status = MAP[16][356 - 144].status = MAP[15][356 - 145].status = MAP[14][356 - 146].status = MAP[13][356 - 146].status = MAP[12][356 - 146].status = MAP[11][356 - 146].status = 1;
	MAP[10][356 - 146].status = MAP[9][356 - 146].status = MAP[8][356 - 147].status = MAP[8][356 - 148].status = MAP[8][356 - 149].status = MAP[8][356 - 150].status = MAP[8][356 - 151].status = MAP[8][356 - 152].status = MAP[8][356 - 153].status = MAP[8][356 - 154].status = MAP[8][356 - 155].status = MAP[8][356 - 156].status = MAP[8][356 - 157].status = 1;
	MAP[8][356 - 158].status = MAP[8][356 - 159].status = MAP[8][356 - 160].status = MAP[8][356 - 161].status = MAP[8][356 - 162].status = MAP[8][356 - 163].status = MAP[8][356 - 164].status = MAP[8][356 - 165].status = MAP[8][356 - 166].status = MAP[8][356 - 167].status = MAP[8][356 - 168].status = MAP[8][356 - 169].status = MAP[8][356 - 170].status = 1;
	MAP[8][356 - 170].status = MAP[8][356 - 171].status = MAP[8][356 - 172].status = MAP[8][356 - 173].status = MAP[8][356 - 174].status = MAP[8][356 - 175].status = MAP[8][356 - 176].status = MAP[8][356 - 177].status = MAP[8][356 - 178].status = 1;

}