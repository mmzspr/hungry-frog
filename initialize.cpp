#include"DxLib.h" 
#include"extern.h"
//初期化
void initialize(void) {
	//	blend = MakeScreen(1000, 1000,FALSE);
		//GHandle = DrawExtendGraph(0, 0, 100, 100,load, TRUE);
		//BlendHandle = DrawExtendGraph(0, 0, 100, 100, load2, true); 

		////////GraphBlendRectBlt(load, load2,blend, 0,0,440,440, 0,0, 0, 0, 255, DX_GRAPH_BLEND_RGBA_SELECT_MIX,DX_RGBA_SELECT_SRC_R, DX_RGBA_SELECT_SRC_G, DX_RGBA_SELECT_SRC_B, DX_RGBA_SELECT_BLEND_A);

		//blend = LoadGraph("img/triangle4.png");
		//blend = GraphBlend(load,load2, 100, DX_RGBA_SELECT_BLEND_A);

	  //menu;
	start.menu = 1;
	start.select = 0;
	start.progress = 0;
	start.count = 0;
	score = 0;
	time = 1;
	//sky
	sky.x = 0;
	sky.y = 0;
	sky.vx = -0.2;
	//light
	light.x = -1;
	light.y = -1,
		light.z = 0;
	for (int i = 0; i < CLOUD; i++) {
		cloud[i].x = GetRand(WIDTH);
		cloud[i].y = GetRand(HEIGHT / 2);
		cloud[i].vx = -0.2 - (double)GetRand(10) / 10;
		cloud[i].sx = (double)GetRand(10) / 10;
		cloud[i].sy = 1;
		cloud[i].texture = img_cloud[GetRand(2)];
		cloud[i].chk = 1;
	}
	//frog
	for (int i = 0; i < 66 - 14; i++) {
		frog.point[66 * 3 + i * 3] = -frog.point[i * 3 + 14 * 3];
		frog.point[66 * 3 + i * 3 + 1] = frog.point[i * 3 + 14 * 3 + 1];
		frog.point[66 * 3 + i * 3 + 2] = frog.point[i * 3 + 14 * 3 + 2];
	}
	for (int i = 0; i < 116; i++) {
		frog.surface[116 * 3 + i * 3] = frog.surface[i * 3] + 52 * (frog.surface[i * 3] >= 14);
		frog.surface[116 * 3 + i * 3 + 1] = frog.surface[i * 3 + 2] + 52 * (frog.surface[i * 3 + 2] >= 14);
		frog.surface[116 * 3 + i * 3 + 2] = frog.surface[i * 3 + 1] + 52 * (frog.surface[i * 3 + 1] >= 14);
	}

	for (int i = 0; i < (21); i++) {
		frog.point_leg[21 * 3 + i * 3] = -frog.point_leg[i * 3];
		frog.point_leg[21 * 3 + i * 3 + 1] = frog.point_leg[i * 3 + 1];
		frog.point_leg[21 * 3 + i * 3 + 2] = frog.point_leg[i * 3 + 2];
	}
	for (int i = 0; i < 38; i++) {
		frog.surface_leg[38 * 3 + i * 3] = frog.surface_leg[i * 3] + 21;
		frog.surface_leg[38 * 3 + i * 3 + 1] = frog.surface_leg[i * 3 + 2] + 21;
		frog.surface_leg[38 * 3 + i * 3 + 2] = frog.surface_leg[i * 3 + 1] + 21;
	}
	for (int i = 0; i < (22); i++) {
		frog.point_arm[22 * 3 + i * 3] = -frog.point_arm[i * 3];
		frog.point_arm[22 * 3 + i * 3 + 1] = frog.point_arm[i * 3 + 1];
		frog.point_arm[22 * 3 + i * 3 + 2] = frog.point_arm[i * 3 + 2];
	}
	for (int i = 0; i < 39; i++) {
		frog.surface_arm[39 * 3 + i * 3] = frog.surface_arm[i * 3] + 22;
		frog.surface_arm[39 * 3 + i * 3 + 1] = frog.surface_arm[i * 3 + 2] + 22;
		frog.surface_arm[39 * 3 + i * 3 + 2] = frog.surface_arm[i * 3 + 1] + 22;
	}
	frog.vx = 0;
	frog.vy = 0;
	frog.clash = 0;
	frog.jump_chk = 0;
	frog.joint1 = -10;
	frog.joint2 = -10;
	frog.prey_chk = 0;
	frog.prey_catched = -1;
	frog.bella_length = 0;
	frog.center[0] = 100;
	frog.center[1] = -3000;
	frog.center[2] = -5000;
	frog.scale[0] = 150;
	frog.scale[1] = 150;
	frog.scale[2] = 150;
	frog.rotate[0] = 0;
	frog.rotate[1] = 0;
	frog.rotate[2] = 0;
	//スクリーン距離
	screen.d = -500;
	//カメラ
	screen.x = 0;
	screen.y = 10000;
	screen.z = 0;
	screen.rx = 0;
	screen.ry = 0;
	screen.rz = 0;
	//Ground
	ground.zz = 0;
	ground.count = 0;
	ground.texture_count = 0;
	for (int i = 0; i < GRAND; i++) {
		for (int ii = 0; ii < GRAND + 1; ii++) {
			ground.rand[i][ii][0] = GetRand(GHEIGHT) - GHEIGHT / 2;
			ground.rand[i][ii][1] = GetRand(GHEIGHT) - GHEIGHT / 2;
		}
	}

	for (int z = 0; z < GMESH; z++) {
		for (int x = 0; x < GMESH; x++) {
			ground.texture[x][z][0] = MakeScreen(1000 / GMESH, 1000 / GMESH, TRUE);
			ground.texture[x][z][1] = MakeScreen(1000 / GMESH, 1000 / GMESH, TRUE);
			GraphBlendRectBlt(img_ground, mask1, ground.texture[x][z][0], 1000 / GMESH * x, 1000 - 1000 / GMESH * (z + 1), 1000 / GMESH * (x + 1), 1000 - 1000 / GMESH * z, 0, 0, 0, 0, 255, DX_GRAPH_BLEND_RGBA_SELECT_MIX, DX_RGBA_SELECT_SRC_R, DX_RGBA_SELECT_SRC_G, DX_RGBA_SELECT_SRC_B, DX_RGBA_SELECT_BLEND_A);
			GraphBlendRectBlt(img_ground, mask2, ground.texture[x][z][1], 1000 / GMESH * x, 1000 - 1000 / GMESH * (z + 1), 1000 / GMESH * (x + 1), 1000 - 1000 / GMESH * z, 0, 0, 0, 0, 255, DX_GRAPH_BLEND_RGBA_SELECT_MIX, DX_RGBA_SELECT_SRC_R, DX_RGBA_SELECT_SRC_G, DX_RGBA_SELECT_SRC_B, DX_RGBA_SELECT_BLEND_A);
			ground.cr[x][z] = GetRand(50);
			ground.cg[x][z] = 150 + GetRand(10);
			ground.cb[x][z] = GetRand(50);
			ground.x[x][z] = -DEPTH / 2 + DEPTH * x / (GMESH - 1);
			ground.z[x][z] = -(z)*DEPTH / (GMESH - 1);
			double xx, zz, x1, x2, y1, y2;
			int r1, r2;
			xx = (double)(x % (GMESH / GRAND)) / (GMESH / GRAND);
			zz = (double)(z % (GMESH / GRAND)) / (GMESH / GRAND);
			r1 = ground.rand[(int)(x / (GMESH / GRAND))][(int)(z / (GMESH / GRAND))][0];
			r2 = ground.rand[(int)(x / (GMESH / GRAND))][(int)(z / (GMESH / GRAND))][1];
			x1 = (1 - 3 * xx * xx + 2 * xx * xx * xx) * (1 - 3 * zz * zz + 2 * zz * zz * zz) * (xx * r1 + zz * r2);
			xx -= 1;
			r1 = ground.rand[(int)(x / (GMESH / GRAND)) + 1][(int)(z / (GMESH / GRAND))][0];
			r2 = ground.rand[(int)(x / (GMESH / GRAND)) + 1][(int)(z / (GMESH / GRAND))][1];
			x2 = (1 - 3 * xx * xx - 2 * xx * xx * xx) * (1 - 3 * zz * zz + 2 * zz * zz * zz) * (xx * r1 + zz * r2);
			xx += 1;
			y1 = x1 - (x1 - x2) * (xx);

			zz -= 1;
			r1 = ground.rand[(int)(x / (GMESH / GRAND))][(int)(z / (GMESH / GRAND)) + 1][0];
			r2 = ground.rand[(int)(x / (GMESH / GRAND))][(int)(z / (GMESH / GRAND)) + 1][1];
			x1 = (1 - 3 * xx * xx + 2 * xx * xx * xx) * (1 - 3 * zz * zz - 2 * zz * zz * zz) * (xx * r1 + zz * r2);
			xx -= 1;
			r1 = ground.rand[(int)(x / (GMESH / GRAND)) + 1][(int)(z / (GMESH / GRAND)) + 1][0];
			r2 = ground.rand[(int)(x / (GMESH / GRAND)) + 1][(int)(z / (GMESH / GRAND)) + 1][1];
			x2 = (1 - 3 * xx * xx - 2 * xx * xx * xx) * (1 - 3 * zz * zz - 2 * zz * zz * zz) * (xx * r1 + zz * r2);
			xx += 1;
			zz += 1;
			y2 = x1 - (x1 - x2) * (xx);

			ground.y[x][z] = 1000 + (y1 - (y1 - y2) * zz) * 40;// +GetRand(10) - 5;
			//ground.y[x][z] = -900 + 100*(1 - 3 * xx * xx + 2 * xx * xx * xx * (1 - 2 * (xx < 0))) * (1 - 3 * zz * zz + 2 * zz * zz * zz * (1 - 2 * (zz < 0))) ;// +GetRand(10) - 5;
		}
	}
	//Me
	me.x = WIDTH / 2;
	me.y = HEIGHT / 2;
	me.vx = 0;
	me.vy = 0;
	me.vz = 0;
	me.speed = 1;

	for (int i = 0; i < ME_EFFECT; i++) {
		me_effect[i].x = 200;
		me_effect[i].y = 200;
	}


	//butterfly
	for (int i = 0; i < BUTTERFLY; i++) {
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
		butterfly[i].cz = -GetRand(DEPTH) + frog.center[2] - 5000;
		int rand = GetRand(500);
		butterfly[i].sx = 100 + rand;
		butterfly[i].sy = 100 + rand;
		butterfly[i].sz = 100 + rand;
		butterfly[i].rx = 0;
		butterfly[i].ry = 0;
		butterfly[i].rz = 0;
		for (int ii = 0; ii < 3; ii++) {
			butterfly[i].point[ii * 3 + 3 * 3] = -butterfly[i].point[ii * 3];
			butterfly[i].point[ii * 3 + 3 * 3 + 1] = butterfly[i].point[ii * 3 + 1];
			butterfly[i].point[ii * 3 + 3 * 3 + 2] = butterfly[i].point[ii * 3 + 2];
		}
	}



	//tree
	for (int i = 0; i < TREE; i++) {
		tree[i].timer = 1;
		tree[i].sx = 30;
		tree[i].sy = 30;
		tree[i].cx = GetRand(15000) - 7500;
		tree[i].cz = -GetRand(DEPTH) + frog.center[2] - 5000;
		tree[i].number = 2;
		tree[i].leaf_number = 10;
		for (int ii = GMESH - 2; ii >= 0; ii--) {
			for (int iii = 0; iii < GMESH - 1; iii++) {
				if (ground.x[iii][ii]< tree[i].cx && tree[i].cx <ground.x[iii + 1][ii] &&
					ground.z[iii][ii] + ground.zz > tree[i].cz && tree[i].cz> ground.z[iii][ii + 1] + ground.zz) {
					tree[i].cy = ground.y[iii][ii] + 1500;
				}
			}
		}
		for (int ii = 0; ii < tree[i].number; ii++) {
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
			tree[i].leaf_x[ii] = GetRand(5000) - 2500;
			tree[i].leaf_y[ii] = GetRand(100);
			tree[i].leaf_z[ii] = 250 + GetRand(2500) - 1000;
			tree[i].leaf_sx[ii] = 2 + GetRand(10) / 10;
			tree[i].leaf_sy[ii] = 2 + GetRand(10) / 10;
			tree[i].leaf_mv[ii] = (double)GetRand(100) / 100 * 2 * PAI;
		}

	}

	//Grass
	for (int i = 0; i < GRASS; i++) {
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
	//Grass2
	for (int i = 0; i < GRASS2; i++) {
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

	//cube
	/*
	for (int i = 0; i < CUBE; i++) {
		cube[i].sx = 30+GetRand(100);
		cube[i].sy = 30+GetRand(100);
		cube[i].sz = 30+GetRand(100);
		double x = cube[i].sx, y = cube[i].sy, z=cube[i].sz;

		double xyz[24] =
		  {-x,y,z ,
			x,y,z,
			-x,-y,z,
			x,-y,z,
			-x,y,-z,
			x,y,-z,
			-x,-y,-z,
			x,-y,-z
		  };
		for (int ii = 0; ii < 8; ii++) {
			cube[i].x[ii] = xyz[ii*3];
			cube[i].y[ii] = xyz[ii * 3+1];
			cube[i].z[ii] = xyz[ii * 3+2];
			cube[i].x2[ii] = 0;
			cube[i].y2[ii] = 0;
			cube[i].z2[ii] = 0;
		}
		cube[i].cx = GetRand(5000)-2500;
		cube[i].cy = GetRand(1500) - 2000;
		cube[i].cz = -GetRand(DEPTH);
		cube[i].vx = (GetRand(500) - 250)/150;
		cube[i].vy = (GetRand(500) - 250)/150;
		cube[i].vz = (GetRand(500) - 250)/150;
		cube[i].rx = 0;
		cube[i].ry = 0;
		cube[i].rz = 0;
		cube[i].rxx = PAI*(GetRand(200))/10000;
		cube[i].ryy = PAI*(GetRand(200)) / 10000;
		cube[i].rzz = PAI*(GetRand(200)/10000 ) ;
	}*/

}