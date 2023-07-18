#include "define.h"
struct S_light {
	double x;
	double y;
	double z;
};
struct S_start {
	int menu;
	int select;
	int count;
	double progress;
};
struct S_screen {
	double d;
	double x, y, z;
	double rx, ry, rz;
};
struct S_sky {
	double x, y;
	double vx;
	double cloud_x[CLOUD], cloud_y[CLOUD];
};
struct S_cloud {
	double x, y;
	double vx;
	double sx, sy;
	int chk;
	int texture;
};
struct S_grass {
	double point[3 * 3] = {
		-50,0,0,
		50,0,0,
		50,-100,0
	};
	double cx, cy, cz;
	double point_move[3 * 3];
	double ry;
	double sx, sy;
	int texture;
};
struct S_grass2 {
	double point[3 * 3] = {
		-50,0,0,
		50,0,0,
		50,0,100
	};
	double cx, cy, cz;
	double point_move[3 * 3];
	double ry;
	double sx, sy;
	int texture;
};
struct S_tree {
	int timer;
	int number;
	int leaf_number;
	double cx, cy, cz;
	double point[3 * 3] = {
		-50,0,0,
		0,0,0,
		0,-200,0
	};
	double point_leaf[3 * 3] = {
		-25,0,0,
		25,0,0,
		25,-50,0
	};
	double point_move[3 * 3];
	double point_leaf_move[3 * 3];
	double sx, sy;
	double leaf_mv[50];
	int texture[10];
	int leaf_texture[50];
	double leaf_x[50];
	int leaf_y[50];
	int leaf_z[50];
	int leaf_sx[50];
	int leaf_sy[50];
};

struct Z_sort {
	int count;
	double distance[Z_SORT_MESH];
	int number[Z_SORT_MESH];
	int check[Z_SORT_MESH];
	int draw_mode[Z_SORT_MESH];
	double x[Z_SORT_MESH][3];
	double y[Z_SORT_MESH][3];
	double z[Z_SORT_MESH][3];
	int texture[Z_SORT_MESH];
};

struct S_frog {
	double vx, vy;
	double ground;
	double point_move[FROG_POINT * 3];
	double point_leg_move[(21) * 2 * 3];
	double point_arm_move[(22) * 2 * 3];
	double point_bella_move[3 * 3];
	double draw[FROG_POINT * 2];
	double draw_leg[(21) * 2 * 2];
	double draw_arm[(22) * 2 * 2];
	int jump_chk;
	int clash;
	double joint1, joint2;
	double center[3];
	double scale[3];
	double rotate[3];
	double point_bella[3 * 3] = {
		-1,4,-6,
		1,4,-6,
		0,4,-10
	};
	double bella_length;
	double prey[3];
	int prey_chk;
	int prey_catched;
	double point[FROG_POINT * 3] = {
		0,3,0,//center
		0,2,1,
		0,2,3,
		0,1,4.2,
		0,-1,5,
		0,-2,4,
		0,-1.5,-2,
		0,1,-3,
		0,2,-5.5,
		0,3.3,-8,
		0,4,-5.7,
		0,4,-4.2,
		0,4,-2.7,
		0,4,-1.2,
		1,3,0,//1
		1,-1,5,
		1,-2,1,
		1,2,-5.3,
		1,3.3,-7.5,
		1,4,-5.5,
		1,4.5,-6.8,
		1,4,-4.2,
		1,4.6,-4.2,
		1,5,-3.7,
		1,5.2,-3.2,
		1,5.2,-2.2,
		1,4.8,-1.2,
		1,4,-1.2,
		2,3,0,//2
		2,2,1,
		2,1.5,3,
		2,0.5,4.2,
		2,-1,4,
		2,-2,2,
		2,-1.7,1,
		2.5,-1.2,-1.1,
		2,0,-2,
		2,1,-3,
		2,2,-5,
		2,3.3,-7,
		2,4,-5.4,
		2,4,-4.2,
		2,4.8,-4.2,
		2,5.5,-3.7,
		2,6,-3.2,
		2,6,-2.2,
		2,5.5,-1.7,
		2,4.8,-1.2,
		2,4,-1.2,
		3,2.5,0,//3
		3.5,1.5,1,
		3,0,3,
		3.5,-1,1,
		3.5,0,-1.1,
		3,1,-2,
		3,2,-3,
		3,3,-5,
		2.5,3.3,-6,
		2.8,4,-5.2,
		3,4,-4.2,
		3,4.6,-4.2,
		3,5,-3.7,
		3,5.2,-3.2,
		3,5.2,-2.2,
		3,5,-1.7,
		3,4,-1.2,
	};
	int surface[232 * 3] = {
		0,1,14,
		1,29,14,
		1,2,29,
		14,29,28,
		2,30,29,
		2,3,30,
		3,4,15,
		3,15,31,
		3,31,30,
		15,32,31,
		31,32,51,
		4,5,15,
		5,32,15,
		5,33,32,
		33,51,32,
		33,52,51,
		31,51,30,
		51,50,30,
		30,50,29,
		51,52,50,
		29,50,49,
		29,49,28,
		52,53,50,
		50,53,49,
		53,54,49,
		5,16,33,
		33,16,34,
		33,34,52,
		5,6,16,
		16,6,35,
		16,35,34,
		34,35,52,
		52,35,53,
		6,36,35,
		35,36,53,
		6,7,36,
		36,7,37,
		53,36,54,
		54,36,37,
		37,55,54,
		7,8,17,
		7,17,37,
		37,17,38,
		37,38,55,
		55,38,56,
		54,55,49,
		49,55,65,
		55,59,65,
		55,56,59,
		49,65,28,
		28,65,48,
		28,48,14,
		14,48,27,
		14,27,0,
		0,27,13,
		8,9,18,
		8,18,17,
		17,18,39,
		17,39,38,
		38,39,57,
		38,57,56,
		9,20,18,
		18,20,39,
		9,10,20,
		10,19,20,
		19,40,20,
		40,39,20,
		57,39,40,
		57,40,58,
		57,58,56,
		56,58,59,
		27,26,13,
		27,48,26,
		48,47,26,
		48,65,47,
		65,64,47,
		64,46,47,
		47,46,26,
		13,25,12,
		13,26,25,
		26,46,25,
		46,45,25,
		46,64,63,
		46,63,45,
		63,62,45,
		45,62,44,
		45,44,25,
		25,44,24,
		25,24,12,
		19,10,11,
		19,11,21,
		19,21,40,
		40,21,41,
		40,41,58,
		58,41,59,
		59,41,60,
		65,59,64,
		64,59,63,
		63,59,62,
		59,61,62,
		60,43,61,
		59,60,61,
		61,44,62,
		60,42,43,
		61,43,44,
		41,42,60,
		24,44,43,
		23,24,43,
		42,23,43,
		42,22,23,
		41,22,42,
		41,21,22,
		11,12,21,
		12,22,21,
		12,23,22,
		12,24,23
	};



	double point_leg[(21) * 2 * 3] = {
		1.5,-2,3,
		3,-1,2.5,
		3.5,-1.5,2,
		3,-2,3,
		3.5,-1,-2,
		4.4,-1,-1,
		4.4,0,-1.5,
		4,-1.5,-2.2,
		2.5,-2,1,
		3.5,-2,0.5,
		2.2,-1.5,-0.5,
		2.8,-1.5,-0.5,
		3.2,-1.5,-0.5,
		3.8,-1.5,-0.5,
		2.2,-2,-0.5,
		2.8,-2,-0.5,
		3.2,-2,-0.5,
		3.8,-2,-0.5,
		2,-2,-2,
		3,-2,-2,
		4,-2,-2,
	};
	int surface_leg[38 * 3 * 2] = {
		3,1,0,
		3,2,1,
		2,6,1,
		2,5,6,
		1,6,0,
		0,6,4,
		2,3,5,
		3,4,5,
		3,0,4,
		7,4,6,
		7,6,5,
		7,5,9,
		7,8,4,
		9,5,4,
		9,4,8,
		11,7,12,
		13,7,9,
		12,7,13,
		10,7,11,
		8,7,10,
		13,9,17,
		14,8,10,
		18,10,11,
		19,11,12,
		20,12,13,
		18,14,10,
		18,11,15,
		19,15,11,
		19,12,16,
		20,16,12,
		20,13,17,
		18,15,14,
		19,16,15,
		20,17,16,
		17,9,16,
		16,9,15,
		15,9,8,
		15,8,14,
	};
	double point_arm[(22) * 2 * 3] = {
		3,1.2,-0.5,
		3,1.4,-1,
		3,0.8,-1,
		4.5,0.8,-0.5,//
		4.8,1,-1,
		4.5,0.4,-1,
		4.1,0.8,-1.2,//
		3.8,-1.5,-3,
		3,-1.5,-3,
		3.8,-2,-2.7,
		3,-2,-2.7,
		4,-2,-3.5,
		3.6,-1.5,-3.5,
		3.2,-1.5,-3.5,
		2.8,-1.5,-3.5,
		4,-1.5,-3.5,
		3.6,-2,-3.5,
		3.2,-2,-3.5,
		2.8,-2,-3.5,
		4.4,-2,-4,
		3.4,-2,-4,
		2.4,-2,-4,
	};
	int surface_arm[39 * 3 * 2] = {
		0,6,1,
		0,3,6,
		2,5,3,
		2,3,0,
		6,2,1,
		3,4,6,
		3,5,4,
		5,2,6,
		5,9,4,
		4,9,7,
		10,9,5,
		4,7,8,
		4,8,6,
		8,5,6,
		10,5,8,
		8,13,14,
		8,12,13,
		8,7,12,
		7,15,12,
		9,11,7,
		7,11,15,
		9,16,11,
		9,17,16,
		9,10,17,
		10,18,17,
		10,14,18,
		8,14,10,
		11,19,15,
		19,16,12,
		16,20,12,
		20,17,13,
		17,21,13,
		21,18,14,
		19,12,15,
		20,13,12,
		21,14,13,
		19,11,16,
		20,16,17,
		21,17,18
	};
};
struct S_ground {
	double x[GMESH][GMESH], y[GMESH][GMESH], z[GMESH][GMESH];
	double x2[GMESH][GMESH], y2[GMESH][GMESH];
	int texture[GMESH][GMESH][2];
	int texture_count;
	int cr[GMESH][GMESH], cg[GMESH][GMESH], cb[GMESH][GMESH];
	double zz;
	int rand[GRAND + 1][GRAND + 2][2];
	int count;
};
struct S_butterfly {
	int texture;
	double point[3 * 3 * 2] = {
		0,0,-0.5,
		1,0,-0.5,
		1,0,0.5
	};
	double point_move[3 * 3 * 2];
	double cx, cy, cz;		//中心座標
	double vx, vy, vz;		//速度
	double rx, ry, rz;		//回転
	double rxx, ryy, rzz;		//回転速度
	double sx, sy, sz;       //大きさ
	double flap;
};
struct S_me {
	double vx, vy, vz;
	double x, y;
	double speed;
};
struct S_me_effect {
	double x;
	double y;
	double v;
};

struct S_cube {
	double x[8], y[8], z[8]; //3d座標用
	double x2[8], y2[8], z2[8]; //2d座標描画用
	double cx, cy, cz;		//中心座標
	double vx, vy, vz;		//速度
	double rx, ry, rz;		//回転
	double rxx, ryy, rzz;		//回転速度
	double sx, sy, sz;       //大きさ
};