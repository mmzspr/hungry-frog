#include"DxLib.h" 
#include"extern.h"
void load_img() {
	img_title = LoadGraph("img/title.png");
	img_butterfly[0] = LoadGraph("img/butterfly.png");
	img_butterfly[1] = LoadGraph("img/butterfly2.png");
	img_butterfly[2] = LoadGraph("img/butterfly3.png");
	img_grass[0] = LoadGraph("img/grass1.png");
	img_grass[1] = LoadGraph("img/grass2.png");
	img_grass[2] = LoadGraph("img/grass3.png");
	img_grass2[0] = LoadGraph("img/g_grass1.png");
	img_grass2[1] = LoadGraph("img/g_grass2.png");
	img_tree[0] = LoadGraph("img/tree1.png");
	img_tree[1] = LoadGraph("img/tree2.png");
	img_tree[2] = LoadGraph("img/tree3.png");
	img_tree[3] = LoadGraph("img/tree4.png");
	img_tree[4] = LoadGraph("img/tree5.png");
	img_leaf[0] = LoadGraph("img/leaf1.png");
	img_leaf[1] = LoadGraph("img/leaf2.png");
	img_leaf[2] = LoadGraph("img/leaf3.png");
	img_ground = LoadGraph("img/grass.png");
	img_sky = LoadGraph("img/sky.jpg");
	img_cloud[0] = LoadGraph("img/cloud1.png");
	img_cloud[1] = LoadGraph("img/cloud2.png");
	img_cloud[2] = LoadGraph("img/cloud3.png");
	mask1 = LoadGraph("img/triangle4.png");
	mask2 = LoadGraph("img/triangle2.png");
	img_start[0] = LoadGraph("img/start.png");
	img_start[1] = LoadGraph("img/quit.png");
}