#include  "DxLib.h" 
#include  "math.h" 
#include"extern.h"
#include "function.h"

void move(void) {
	if (time < 4 && frog.jump_chk) {
		time += 0.0002;
	}
	//menu
	if (start.menu == 1) {
		if (CheckHitKey(KEY_INPUT_UP) != 0) {
			start.select -= 1 * (start.select != 0);
		}
		if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
			start.select += 1 * (start.select != 1);
		}
		if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
			if (start.select == 0) {
				start.menu = 0;
			}
			if (start.select == 1) {
				DxLib_End();
			}
		}
	}
	//end
	if (start.menu == 2 && start.count > 100) {
		if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
			start.progress = 0;
			start.menu = 3;
		}
	}
	//sky
	sky.x += sky.vx;
	if (sky.x < -2400) { sky.x += 2400; }
	for (int i = 0; i < CLOUD; i++) {
		if (cloud[i].chk) {
			cloud[i].x += cloud[i].vx;
			if (cloud[i].x < -200) {
				cloud[i].chk = 0;
			}
		}
		else if (GetRand(100) == 1) {
			cloud[i].x = WIDTH + 100;
			cloud[i].y = GetRand(HEIGHT / 2);
			cloud[i].vx = -0.2 - (double)GetRand(10) / 10;
			cloud[i].sx = 1;
			cloud[i].sy = 1;
			cloud[i].texture = img_cloud[GetRand(2)];
			cloud[i].chk = 1;
		}
	}
	//カメラ
	/*
	if (CheckHitKey(KEY_INPUT_W) != 0) {
	  screen.x += 100;
	}
	if (CheckHitKey(KEY_INPUT_Q) != 0) {
		screen.x -= 100;
	}
	if (CheckHitKey(KEY_INPUT_S) != 0) {
		screen.y += 100;
	}
	if (CheckHitKey(KEY_INPUT_A) != 0) {
		screen.y -= 100;
	}
	if (CheckHitKey(KEY_INPUT_X) != 0) {
		screen.z += 100;
	}
	if (CheckHitKey(KEY_INPUT_Z) != 0) {
		screen.z -= 100;
	}
	*/
	//ME
	//減速
	me.vx *= 0.98;
	me.vy *= 0.98;
	me.vz *= 0.98;
	//加速
	if (start.menu == 0) {
		if (CheckHitKey(KEY_INPUT_RIGHT) != 0) {
			me.vx += 0.4;
		}
		if (CheckHitKey(KEY_INPUT_LEFT) != 0) {
			me.vx -= 0.4;
		}
	}
	/*
	if (CheckHitKey(KEY_INPUT_UP) != 0) {
		me.vy -= 0.5;
	}
	if (CheckHitKey(KEY_INPUT_DOWN) != 0) {
		me.vy += 0.5;
	}
	if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
		me.vz += 8;
	}
	*/
	ground.zz += me.vz;
	for (int i = 0; i < BUTTERFLY; i++) {
		butterfly[i].cz += me.vz;
	}
	for (int i = 0; i < TREE; i++) {
		if (tree[i].timer) {
			tree[i].cz += me.vz;
		}
	}
	for (int i = 0; i < GRASS; i++) {
		grass[i].cz += me.vz;
	}
	for (int i = 0; i < GRASS2; i++) {
		grass2[i].cz += me.vz;
	}
	//座標加算
	me.x += me.vx;
	me.y += me.vy;
	if (me.x > WIDTH) { me.x = WIDTH; me.vx = 0; }
	if (0 > me.x) { me.x = 0; me.vx = 0; }
	if (me.y > HEIGHT) { me.y = HEIGHT; me.vy = 0; }
	if (0 > me.y) { me.y = 0; me.vy = 0; }
	//エフェクト座標
	for (int i = ME_EFFECT - 2; i >= 0; i--) {
		me_effect[i + 1].x = me_effect[i].x;
		me_effect[i + 1].y = me_effect[i].y;
		me_effect[i + 1].v = me_effect[i].v;
	}
	me_effect[0].x = me.x;
	me_effect[0].y = me.y;
	me_effect[0].v = me.vx * me.vx + me.vy * me.vy;

	//CUBE
	for (int i = CUBE - 1; i >= 0; i--) {
		cube[i].rx += cube[i].rxx;
		cube[i].ry += cube[i].ryy;
		cube[i].rz += cube[i].rzz;
		cube[i].cx += cube[i].vx;
		cube[i].cy += cube[i].vy;
		cube[i].cz += cube[i].vz + me.vz;
		if (cube[i].cz > 0) {

			cube[i].cx = GetRand(5000) - 2500;
			cube[i].cy = GetRand(2000) - 2000;
			cube[i].cz = -DEPTH;
			cube[i].vx = (GetRand(500) - 250) / 100;
			cube[i].vy = (GetRand(500) - 250) / 100;
			cube[i].vz = (GetRand(500) - 250) / 100;
			cube[i].rx = 0;
			cube[i].ry = 0;
			cube[i].rz = 0;
			cube[i].rxx = PAI * (GetRand(200)) / 10000;
			cube[i].ryy = PAI * (GetRand(200)) / 10000;
			cube[i].rzz = PAI * (GetRand(200) / 10000);
		}
	}

	//frog


	//////////////
	if (CheckHitKey(KEY_INPUT_R) != 0) {
		frog.rotate[0] += 0.1;
	}
	if (CheckHitKey(KEY_INPUT_T) != 0) {
		frog.rotate[1] += 0.1;
	}
	if (CheckHitKey(KEY_INPUT_Y) != 0) {
		frog.rotate[2] += 0.1;
	}
	if (CheckHitKey(KEY_INPUT_Y) != 0) {
		frog.rotate[2] += 0.1;
	}
	////////////

	if (start.menu == 0) {
		if ((CheckHitKey(KEY_INPUT_SPACE) != 0 || GetJoypadInputState(DX_INPUT_PAD1) & PAD_INPUT_4 & PAD_INPUT_1) && frog.jump_chk == 0) {
			frog.jump_chk = 1;
			frog.joint1 = frog.joint2 = -10;
			frog.vy = -250;
			me.vz = 150 * time;
		}
		if (frog.jump_chk == 1) {
			frog.joint1 += 0.5;
		}
		if (frog.joint1 > 10) {
			frog.jump_chk = 2;
		}
		if ((CheckHitKey(KEY_INPUT_RIGHT) != 0) && frog.jump_chk != 0) {
			frog.vx += 4 * time;
		}
		if ((CheckHitKey(KEY_INPUT_LEFT) != 0) && frog.jump_chk != 0) {
			frog.vx -= 4 * time;
		}
	}
	frog.vx /= 1.01;
	frog.vy += 10.00;
	if (frog.center[0] < -5000) { frog.vx = 2; }
	if (frog.center[0] > 5000) { frog.vx = -2; }
	frog.center[1] += frog.vy;
	frog.center[0] += frog.vx;
	double sq = sqrt((butterfly[frog.prey_catched].cx - frog.center[0]) * (butterfly[frog.prey_catched].cx - frog.center[0]) + (butterfly[frog.prey_catched].cz - frog.center[2]) * (butterfly[frog.prey_catched].cz - frog.center[2]));
	if (frog.clash == 0) {
		frog.rotate[1] = (PAI * (2 / (1 + pow(1.01, frog.vx)) - 1) / 2) * (1 - sin(frog.bella_length)) + PAI * ((butterfly[frog.prey_catched].cx - frog.center[0])) / sq * (1 - 2) * sin(frog.bella_length);
	}
	if (frog.prey_chk) {
		frog.bella_length += 0.2;
		if (frog.bella_length > PAI) {
			score += 100;
			frog.prey_chk = 0;
			butterfly[frog.prey_catched].cz = 0;
			frog.prey_catched = -1;
		}
	}
	//Butterfly
	double butterfly_distance = 0;
	for (int i = 0; i < BUTTERFLY; i++) {
		if (frog.prey_chk == 0) {
			double r = sqrt((butterfly[i].cx - frog.center[0]) * (butterfly[i].cx - frog.center[0]) + (butterfly[i].cy - frog.center[1]) * (butterfly[i].cy - frog.center[1]) + (butterfly[i].cz - frog.center[2]) * (butterfly[i].cz - frog.center[2]));
			if (((butterfly_distance > r && r < 100000 || butterfly_distance == 0) && r < 3000) && frog.clash == 0) {
				frog.prey[0] = butterfly[i].cx;
				frog.prey[1] = butterfly[i].cy;
				frog.prey[2] = butterfly[i].cz;
				butterfly_distance = r;
				frog.prey_catched = i;
				frog.prey_chk = 1;
				frog.bella_length = 0;
				PlaySoundMem(sound_eat, DX_PLAYTYPE_BACK);
			}
		}

		butterfly[i].flap += 0.05;
		if (butterfly[i].flap > 1) { butterfly[i].flap = 0; }
		butterfly[i].cx += butterfly[i].vx;
		butterfly[i].cy += butterfly[i].vy;
		butterfly[i].cz += butterfly[i].vz;
		if (butterfly[i].cz > -1000) {
			butterfly[i].cz = -DEPTH;
			butterfly[i].vx = (GetRand(500) - 250) / 30;
			butterfly[i].vy = (GetRand(500) - 250) / 200;
			butterfly[i].vz = (GetRand(500) - 250) / 100;

			butterfly[i].flap = GetRand(100);
			butterfly[i].flap /= 100;
			if (GetRand(20) > 7) {
				butterfly[i].texture = img_butterfly[2];
			}
			else if (GetRand(20) > 4) {
				butterfly[i].texture = img_butterfly[0];
			}
			else {
				butterfly[i].texture = img_butterfly[1];
			}
			butterfly[i].cx = GetRand(15000) - 7500;
			butterfly[i].cy = GetRand(8000) - 7500;
			int rand = GetRand(500);
			butterfly[i].sx = 100 + rand;
			butterfly[i].sy = 100 + rand;
			butterfly[i].sz = 100 + rand;
		}
	}
	for (int i = 0; i < TREE; i++) {
		if (tree[i].cz > -1000) { tree[i].timer = 0;	tree[i].cz = -DEPTH; }
		if (tree[i].timer == 0 && GetRand(10) == 1) {
			tree[i].timer = 1;
			tree[i].sx = 30;
			tree[i].sy = 30;
			tree[i].cx = GetRand(15000) - 7500;
			tree[i].cz = -DEPTH;
			for (int ii = GMESH - 2; ii >= 0; ii--) {
				for (int iii = 0; iii < GMESH - 1; iii++) {
					if (ground.x[iii][ii]< tree[i].cx && tree[i].cx <ground.x[iii + 1][ii] &&
						ground.z[iii][ii] + ground.zz > tree[i].cz && tree[i].cz> ground.z[iii][ii + 1] + ground.zz) {
						tree[i].cy = ground.y[iii][ii] + 1500;
					}
				}
			}
			tree[i].number = 2;
			for (int ii = 0; ii < TREE; ii++) {
				tree[i].texture[ii] = img_tree[GetRand(4)];
			}

			for (int ii = 0; ii < tree[i].leaf_number; ii++) {
				tree[i].leaf_texture[ii] = img_leaf[GetRand(2)];
			}
			tree[i].leaf_x[0] = 0;
			tree[i].leaf_y[0] = 25;
			tree[i].leaf_z[0] = 250;
			tree[i].leaf_sx[0] = 1;
			tree[i].leaf_sy[0] = 1;
			for (int ii = 1; ii < tree[i].leaf_number; ii++) {
				tree[i].leaf_mv[ii] += (double)GetRand(5) / 100;
				if (tree[i].leaf_mv[ii] > 2 * PAI) { tree[i].leaf_mv[ii] = 0; }
			}
		}
	}
	//Grass
	for (int i = 0; i < GRASS; i++) {
		if (grass[i].cz > 0) {
			grass[i].sx = 5;
			grass[i].sy = 5;
			grass[i].cx = GetRand(15000) - 7500;
			grass[i].cz = -GetRand(DEPTH);
			for (int ii = GMESH - 2; ii >= 0; ii--) {
				for (int iii = 0; iii < GMESH - 1; iii++) {
					if (ground.x[iii][ii]< grass[i].cx && grass[i].cx <ground.x[iii + 1][ii] &&
						ground.z[iii][ii] + ground.zz > grass[i].cz && grass[i].cz> ground.z[iii][ii + 1] + ground.zz) {
						grass[i].cy = ground.y[iii][ii] + 50;
					}
				}
			}
			grass[i].texture = img_grass[GetRand(2)];
		}
	}
	//Grass
	for (int i = 0; i < GRASS2; i++) {
		if (grass2[i].cz > 0) {
			grass2[i].sx = 5;
			grass2[i].sy = 5;
			grass2[i].cx = GetRand(15000) - 7500;
			grass2[i].cz = -GetRand(DEPTH);
			for (int ii = GMESH - 2; ii >= 0; ii--) {
				for (int iii = 0; iii < GMESH - 1; iii++) {
					if (ground.x[iii][ii]< grass2[i].cx && grass2[i].cx <ground.x[iii + 1][ii] &&
						ground.z[iii][ii] + ground.zz > grass2[i].cz && grass2[i].cz> ground.z[iii][ii + 1] + ground.zz) {
						grass2[i].cy = ground.y[iii][ii] - 50;
					}
				}
			}
			grass2[i].texture = img_grass2[GetRand(1)];
		}
	}
	//ground
	double ground_height = HEIGHT - 50;
	int ground_check = 1;
	for (int y = 0; y < GMESH; y++) {//地面当たり判定　最高点ジャッジ
		if (ground.z[0][y] + ground.zz < 0) {
			for (int x = 0; x < GMESH; x++) {
				if (ground.y[x][y] - (me.y - HEIGHT / 2) * 5 + HEIGHT / 2 + screen.y - 1500 < ground_height && ground.x[x][y] - (me.x - WIDTH / 2) * 5 + WIDTH / 2 - screen.x > 0 && ground.x[x][y] - (me.x - WIDTH / 2) * 5 + WIDTH / 2 - screen.x < WIDTH) {
					ground_check = 0;
					ground_height = ground.y[x][y] - (me.y - HEIGHT / 2) * 5 + HEIGHT / 2 + screen.y - 1500;
				}
			}
			y = GMESH;
		}
	}
	screen.y -= (ground_height - HEIGHT) / 10;
	if (ground_check) {
		screen.y /= 1.015;
	}/*aaaaa*/
	/*
	for (int x = 0; x < GMESH; x++) {
		for (int z = 0; z < GMESH; z++) {
			make_3d_2d(ground.x[x][z], ground.y[x][z], ground.z[x][z] + ground.zz, ground.x2[x][z], ground.y2[x][z]);
		}
	}*/
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
	for (int ii = GMESH - 2; ii >= 0; ii--) {
		for (int i = 0; i < GMESH - 1; i++) {
			if (ground.z[i][ii] + ground.zz < 0 && ground.z[i + 1][ii] + ground.zz < 0 && ground.z[i][ii + 1] + ground.zz < 0 && ground.z[i + 1][ii + 1] + ground.zz < 0) {
				/*aaaaaa*/
				/*

				double white = -255 * (ground.z[i][ii] + ground.zz) / DEPTH;
				double w = 1 + (ground.z[i][ii] + ground.zz) / DEPTH;
				int rgb = RGB(white + ground.cr[i][ii] * w, white + ground.cg[i][ii] * w, white + ground.cb[i][ii] * w);
				if (check_surface(ground.x[i][ii], ground.y[i][ii], ground.z[i][ii] + ground.zz, ground.x[i + 1][ii], ground.y[i + 1][ii], ground.z[i + 1][ii] + ground.zz, ground.x[i + 1][ii + 1], ground.y[i + 1][ii + 1], ground.z[i + 1][ii + 1] + ground.zz)) {
					DrawTriangle(ground.x2[i][ii], ground.y2[i][ii], ground.x2[i + 1][ii], ground.y2[i + 1][ii], ground.x2[i + 1][ii + 1], ground.y2[i + 1][ii + 1], rgb, TRUE);
				}
				if (check_surface(ground.x[i][ii], ground.y[i][ii], ground.z[i][ii] + ground.zz, ground.x[i + 1][ii + 1], ground.y[i + 1][ii + 1], ground.z[i + 1][ii + 1] + ground.zz, ground.x[i][ii + 1], ground.y[i][ii + 1], ground.z[i][ii + 1] + ground.zz)) {
					DrawTriangle(ground.x2[i][ii], ground.y2[i][ii], ground.x2[i][ii + 1], ground.y2[i][ii + 1], ground.x2[i + 1][ii + 1], ground.y2[i + 1][ii + 1], rgb, TRUE);
				}
				*/
			}
			else {
				ground.count++;
				for (int z = 0; z < GMESH - 1; z++) {
					for (int x = 0; x < GMESH; x++) {
						ground.x[x][z] = ground.x[x][z + 1];
						ground.y[x][z] = ground.y[x][z + 1];
						ground.z[x][z] = ground.z[x][z + 1];
						ground.cr[x][z] = ground.cr[x][z + 1];
						ground.texture[x][z][0] = ground.texture[x][z + 1][0];
						ground.texture[x][z][1] = ground.texture[x][z + 1][1];
						ground.cg[x][z] = ground.cg[x][z + 1];
						ground.cb[x][z] = ground.cb[x][z + 1];
					}
				}
				int z = GMESH - 1 + ground.count;
				if ((int)(z / (GMESH / GRAND)) > GRAND) {
					for (int zz = 0; zz < GMESH; zz++) {
						for (int xx = 0; xx < GMESH; xx++) {
							ground.z[xx][zz] += DEPTH / (GRAND);
						}
					}
					for (int zz = 0; zz < GRAND + 1; zz++) {
						for (int xx = 0; xx < GRAND; xx++) {
							ground.rand[xx][zz][0] = ground.rand[xx][zz + 1][0];
							ground.rand[xx][zz][1] = ground.rand[xx][zz + 1][1];
						}
					}
					for (int xx = 0; xx < GRAND; xx++) {
						ground.rand[xx][GRAND + 1][0] = GetRand(GHEIGHT) - GHEIGHT / 2;
						ground.rand[xx][GRAND + 1][1] = GetRand(GHEIGHT) - GHEIGHT / 2;
					}
					ground.zz -= DEPTH / (GRAND);
					z = GMESH;
					ground.count = 1;
				}
				ground.texture_count++;
				for (int x = 0; x < GMESH; x++) {
					ground.texture[x][GMESH - 1][0] = ground.texture[x][0][0];
					ground.texture[x][GMESH - 1][1] = ground.texture[x][0][1];
					ground.cr[x][GMESH - 1] = GetRand(50);
					ground.cg[x][GMESH - 1] = 150 + GetRand(10);
					ground.cb[x][GMESH - 1] = GetRand(50);
					ground.x[x][GMESH - 1] = -DEPTH / 2 + DEPTH * x / (GMESH - 1);
					ground.z[x][GMESH - 1] = -(z)*DEPTH / (GMESH - 1);
					double xx, zz, x1, x2, y1, y2;
					int r1, r2;
					xx = (double)(x % (GMESH / GRAND)) / (GMESH / GRAND);
					zz = (double)(z % (GMESH / GRAND)) / (GMESH / GRAND);
					r1 = ground.rand[(int)(x / (GMESH / GRAND))][GRAND][0];
					r2 = ground.rand[(int)(x / (GMESH / GRAND))][GRAND][1];
					x1 = (1 - 3 * xx * xx + 2 * xx * xx * xx) * (1 - 3 * zz * zz + 2 * zz * zz * zz) * (xx * r1 + zz * r2);
					xx -= 1;
					r1 = ground.rand[(int)(x / (GMESH / GRAND)) + 1][GRAND][0];
					r2 = ground.rand[(int)(x / (GMESH / GRAND)) + 1][GRAND][1];
					x2 = (1 - 3 * xx * xx - 2 * xx * xx * xx) * (1 - 3 * zz * zz + 2 * zz * zz * zz) * (xx * r1 + zz * r2);
					xx += 1;
					y1 = x1 - (x1 - x2) * (xx);

					zz -= 1;
					r1 = ground.rand[(int)(x / (GMESH / GRAND))][GRAND + 1][0];
					r2 = ground.rand[(int)(x / (GMESH / GRAND))][GRAND + 1][1];
					x1 = (1 - 3 * xx * xx + 2 * xx * xx * xx) * (1 - 3 * zz * zz - 2 * zz * zz * zz) * (xx * r1 + zz * r2);
					xx -= 1;
					r1 = ground.rand[(int)(x / (GMESH / GRAND)) + 1][GRAND + 1][0];
					r2 = ground.rand[(int)(x / (GMESH / GRAND)) + 1][GRAND + 1][1];
					x2 = (1 - 3 * xx * xx - 2 * xx * xx * xx) * (1 - 3 * zz * zz - 2 * zz * zz * zz) * (xx * r1 + zz * r2);
					xx += 1;
					zz += 1;
					y2 = x1 - (x1 - x2) * (xx);
					ground.y[x][GMESH - 1] = 440 + (y1 - (y1 - y2) * zz) * 40;
				}
			}
		}
	}


}