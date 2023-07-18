#include<math.h>
#include"DxLib.h"
#include"extern.h"
#include "function.h"




void draw(void) {
	z_sort.count = 0;


	for (int i = 0; i < DEPTH; i++) {

		if (i % 1500 == 0 && i > 10) {
			z_sort.draw_mode[z_sort.count] = 3;
			z_sort.x[z_sort.count][0] = 0;
			z_sort.y[z_sort.count][0] = 0;
			z_sort.z[z_sort.count][0] = -i;
			z_sort.x[z_sort.count][1] = 100;
			z_sort.y[z_sort.count][1] = 100;
			z_sort.z[z_sort.count][1] = -i;
			z_sort.x[z_sort.count][2] = 100;
			z_sort.y[z_sort.count][2] = 0;
			z_sort.z[z_sort.count][2] = -i;
			z_sort.texture[z_sort.count] = 0;
			z_sort.count++;
		}
		if (i % 400 == 0 && i > 200) {
			z_sort.draw_mode[z_sort.count] = 4;
			z_sort.x[z_sort.count][0] = 0;
			z_sort.y[z_sort.count][0] = 0;
			z_sort.z[z_sort.count][0] = -i;
			z_sort.x[z_sort.count][1] = 100;
			z_sort.y[z_sort.count][1] = 100;
			z_sort.z[z_sort.count][1] = -i;
			z_sort.x[z_sort.count][2] = 100;
			z_sort.y[z_sort.count][2] = 0;
			z_sort.z[z_sort.count][2] = -i;
			z_sort.texture[z_sort.count] = 0;
			z_sort.count++;
		}
	}


	for (int ii = GMESH - 2; ii >= 0; ii--) {
		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 5);
		//SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		for (int i = 0; i < GMESH - 1; i++) {
			for (int j = 0; j < 2; j++) {

				int a = frog.surface_leg[i * 3];
				int b = frog.surface_leg[i * 3 + 1];
				int c = frog.surface_leg[i * 3 + 2];
				z_sort.draw_mode[z_sort.count] = j + 1;
				z_sort.x[z_sort.count][0] = ground.x[i + 1 * j][ii];
				z_sort.y[z_sort.count][0] = ground.y[i + 1 * j][ii];
				z_sort.z[z_sort.count][0] = ground.z[i + 1 * j][ii] + ground.zz;
				z_sort.x[z_sort.count][1] = ground.x[i + 1][ii + 1 * j];
				z_sort.y[z_sort.count][1] = ground.y[i + 1][ii + 1 * j];
				z_sort.z[z_sort.count][1] = ground.z[i + 1][ii + 1 * j] + ground.zz;
				z_sort.x[z_sort.count][2] = ground.x[i][ii + 1];
				z_sort.y[z_sort.count][2] = ground.y[i][ii + 1];
				z_sort.z[z_sort.count][2] = ground.z[i][ii + 1] + ground.zz;
				z_sort.texture[z_sort.count] = ground.texture[i][ii][j];

				if (z_sort.x[z_sort.count][0] < frog.center[0] && frog.center[0] < z_sort.x[z_sort.count][1] &&
					z_sort.z[z_sort.count][0]> frog.center[2] && frog.center[2] > z_sort.z[z_sort.count][2] &&
					z_sort.y[z_sort.count][0] - 250 < frog.center[1]
					||
					z_sort.x[z_sort.count][2] < frog.center[0] && frog.center[0] < z_sort.x[z_sort.count][1] &&
					z_sort.z[z_sort.count][0] > frog.center[2] && frog.center[2] > z_sort.z[z_sort.count][1] &&
					z_sort.y[z_sort.count][0] - 250 < frog.center[1]
					) {
					if (CheckSoundMem(sound_grass == 0)) {
						PlaySoundMem(sound_grass, DX_PLAYTYPE_BACK);
					}
					frog.center[1] = z_sort.y[z_sort.count][0] - 250;
					frog.vy = 0;
					frog.jump_chk = 0;
				}
				z_sort.count++;
			}

		}
	}


	//tree
	for (int i = 0; i < TREE; i++) {
		for (int ii = 0; ii < 3; ii++) {
			tree[i].point_move[ii * 3] = tree[i].point[ii * 3];
			tree[i].point_move[ii * 3 + 1] = tree[i].point[ii * 3 + 1];
			tree[i].point_move[ii * 3 + 2] = tree[i].point[ii * 3 + 2];
			tree[i].point_leaf_move[ii * 3] = tree[i].point_leaf[ii * 3];
			tree[i].point_leaf_move[ii * 3 + 1] = tree[i].point_leaf[ii * 3 + 1];
			tree[i].point_leaf_move[ii * 3 + 2] = tree[i].point_leaf[ii * 3 + 2];
		}
	}
	for (int i = 0; i < TREE; i++) {
		for (int n = 0; n < tree[i].number; n++) {
			z_sort.draw_mode[z_sort.count] = 5;
			for (int ii = 0; ii < 3; ii++) {
				make_rotate(tree[i].point_move[ii * 3], tree[i].point_move[ii * 3 + 1], tree[i].point_move[ii * 3 + 2], 0, 2 * PAI * n / tree[i].number, 0, tree[i].point_move[ii * 3], tree[i].point_move[ii * 3 + 1], tree[i].point_move[ii * 3 + 2]);
				z_sort.x[z_sort.count][ii] = tree[i].cx + tree[i].point_move[ii * 3] * tree[i].sx;
				z_sort.y[z_sort.count][ii] = tree[i].cy + tree[i].point_move[ii * 3 + 1] * tree[i].sy;
				z_sort.z[z_sort.count][ii] = tree[i].cz + tree[i].point_move[ii * 3 + 2];
			}
			z_sort.texture[z_sort.count] = tree[i].texture[n];
			z_sort.count++;
		}


		for (int n = 0; n < tree[i].leaf_number; n++) {
			z_sort.draw_mode[z_sort.count] = 5;
			for (int ii = 0; ii < 3; ii++) {
				//make_rotate(tree[i].point_leaf_move[ii * 3], tree[i].point_leaf_move[ii * 3 + 1], tree[i].point_leaf_move[ii * 3 + 2], 0,- PAI * n / tree[i].leaf_number, 0, tree[i].point_leaf_move[ii * 3], tree[i].point_leaf_move[ii * 3 + 1], tree[i].point_leaf_move[ii * 3 + 2]);
				z_sort.x[z_sort.count][ii] = tree[i].cx + tree[i].leaf_x[n] + tree[i].point_leaf_move[ii * 3] * tree[i].sx * tree[i].leaf_sx[n] + sin(tree[i].leaf_mv[n]) * 50;
				z_sort.y[z_sort.count][ii] = tree[i].cy + (tree[i].point[7] + tree[i].leaf_y[n] + tree[i].point_leaf_move[ii * 3 + 1] * tree[i].leaf_sy[n]) * tree[i].sy;
				z_sort.z[z_sort.count][ii] = tree[i].cz + tree[i].leaf_z[n] + tree[i].point_leaf_move[ii * 3 + 2];
			}
			z_sort.texture[z_sort.count] = tree[i].leaf_texture[n];
			z_sort.count++;
		}
	}

	//grass

	for (int i = 0; i < GRASS; i++) {
		z_sort.draw_mode[z_sort.count] = 5;
		z_sort.texture[z_sort.count] = grass[i].texture;
		for (int ii = 0; ii < 3; ii++) {
			//make_rotate(tree[i].point_leaf_move[ii * 3], tree[i].point_leaf_move[ii * 3 + 1], tree[i].point_leaf_move[ii * 3 + 2], 0,- PAI * n / tree[i].leaf_number, 0, tree[i].point_leaf_move[ii * 3], tree[i].point_leaf_move[ii * 3 + 1], tree[i].point_leaf_move[ii * 3 + 2]);
			z_sort.x[z_sort.count][ii] = grass[i].cx + grass[i].point[ii * 3] * grass[i].sx;
			z_sort.y[z_sort.count][ii] = grass[i].cy + grass[i].point[ii * 3 + 1] * grass[i].sy;
			z_sort.z[z_sort.count][ii] = grass[i].cz + grass[i].point[ii * 3 + 2];
		}
		z_sort.count++;
	}
	//grass

	for (int i = 0; i < GRASS2; i++) {
		z_sort.draw_mode[z_sort.count] = 5;
		z_sort.texture[z_sort.count] = grass2[i].texture;
		for (int ii = 0; ii < 3; ii++) {
			//make_rotate(tree[i].point_leaf_move[ii * 3], tree[i].point_leaf_move[ii * 3 + 1], tree[i].point_leaf_move[ii * 3 + 2], 0,- PAI * n / tree[i].leaf_number, 0, tree[i].point_leaf_move[ii * 3], tree[i].point_leaf_move[ii * 3 + 1], tree[i].point_leaf_move[ii * 3 + 2]);
			z_sort.x[z_sort.count][ii] = grass2[i].cx + grass2[i].point[ii * 3] * grass2[i].sx;
			z_sort.y[z_sort.count][ii] = grass2[i].cy + grass2[i].point[ii * 3 + 1];
			z_sort.z[z_sort.count][ii] = grass2[i].cz + grass2[i].point[ii * 3 + 2] * grass2[i].sy;
		}
		z_sort.count++;
	}

	//Butterfly
	for (int i = 0; i < BUTTERFLY; i++) {
		for (int ii = 0; ii < 3 * 2; ii++) {
			make_rotate(butterfly[i].point[ii * 3], butterfly[i].point[ii * 3 + 1], butterfly[i].point[ii * 3 + 2], butterfly[i].rx, butterfly[i].ry, butterfly[i].rz, butterfly[i].point_move[ii * 3], butterfly[i].point_move[ii * 3 + 1], butterfly[i].point_move[ii * 3 + 2]);
		}
	}
	for (int i = 0; i < BUTTERFLY; i++) {
		for (int ii = 0; ii < 3 * 2; ii++) {
			make_rotate(butterfly[i].point[ii * 3], butterfly[i].point[ii * 3 + 1], butterfly[i].point[ii * 3 + 2], 0, 0, cos(2 * PAI * butterfly[i].flap) * (1 - 2 * (ii >= 3)), butterfly[i].point_move[ii * 3], butterfly[i].point_move[ii * 3 + 1], butterfly[i].point_move[ii * 3 + 2]);
		}
	}
	for (int i = 0; i < BUTTERFLY; i++) {
		//(butterfly[i].vx* butterfly[i].vx + butterfly[i].vy * butterfly[i].vy+ butterfly[i].vz* butterfly[i].vz)
		double rx = -butterfly[i].vy / sqrt(butterfly[i].vy * butterfly[i].vy + butterfly[i].vz * butterfly[i].vz);
		double ry = butterfly[i].vx / sqrt(butterfly[i].vx * butterfly[i].vx + butterfly[i].vz * butterfly[i].vz);
		for (int ii = 0; ii < 3 * 2; ii++) {
			make_rotate(butterfly[i].point_move[ii * 3], butterfly[i].point_move[ii * 3 + 1], butterfly[i].point_move[ii * 3 + 2], PAI * rx / 2, PAI * ry / 2, 0, butterfly[i].point_move[ii * 3], butterfly[i].point_move[ii * 3 + 1], butterfly[i].point_move[ii * 3 + 2]);
		}
	}

	for (int i = 0; i < BUTTERFLY; i++) {
		for (int count = 0; count < 2; count++) {
			z_sort.draw_mode[z_sort.count] = 5;

			if (i == frog.prey_catched) {
				butterfly[i].cx = frog.point_bella_move[6];
				butterfly[i].cy = frog.point_bella_move[7];
				butterfly[i].cz = frog.point_bella_move[8];
			}
			for (int ii = 0; ii < 3; ii++) {
				z_sort.x[z_sort.count][ii] = butterfly[i].cx + butterfly[i].point_move[ii * 3 + 3 * 3 * count] * butterfly[i].sx;
				z_sort.y[z_sort.count][ii] = butterfly[i].cy + butterfly[i].point_move[ii * 3 + 1 + 3 * 3 * count] * butterfly[i].sy;
				z_sort.z[z_sort.count][ii] = butterfly[i].cz + butterfly[i].point_move[ii * 3 + 2 + 3 * 3 * count] * butterfly[i].sz;
			}
			z_sort.texture[z_sort.count] = butterfly[i].texture;
			z_sort.count++;
		}
	}


	//frog leg
	for (int i = 0; i < 21 * 2; i++) {
		frog.point_leg_move[i * 3] = frog.point_leg[i * 3];
		frog.point_leg_move[i * 3 + 1] = frog.point_leg[i * 3 + 1];
		frog.point_leg_move[i * 3 + 2] = frog.point_leg[i * 3 + 2];
	}
	for (int i = 10; i < 21; i++) {
		for (int ii = 0; ii < 2; ii++) {
			make_rotate(frog.point_leg_move[21 * 3 * ii + i * 3] - frog.point_leg[9 * 3], frog.point_leg_move[21 * 3 * ii + i * 3 + 1] - frog.point_leg[9 * 3 + 1], frog.point_leg_move[21 * 3 * ii + i * 3 + 2] - frog.point_leg[9 * 3 + 2], -PAI * 0.75 * pow(1.1, -(frog.joint1 * frog.joint1)), 0, 0, frog.point_leg_move[21 * 3 * ii + i * 3], frog.point_leg_move[21 * 3 * ii + i * 3 + 1], frog.point_leg_move[21 * 3 * ii + i * 3 + 2]);
			frog.point_leg_move[21 * 3 * ii + i * 3] += frog.point_leg[9 * 3];
			frog.point_leg_move[21 * 3 * ii + i * 3 + 1] += frog.point_leg[9 * 3 + 1];
			frog.point_leg_move[21 * 3 * ii + i * 3 + 2] += frog.point_leg[9 * 3 + 2];
		}
	}
	for (int i = 7; i < 21; i++) {
		for (int ii = 0; ii < 2; ii++) {
			make_rotate(frog.point_leg_move[21 * 3 * ii + i * 3] - frog.point_leg[4 * 3], frog.point_leg_move[21 * 3 * ii + i * 3 + 1] - frog.point_leg[4 * 3 + 1], frog.point_leg_move[21 * 3 * ii + i * 3 + 2] - frog.point_leg[4 * 3 + 2], PAI * 0.75 * pow(1.1, -(frog.joint1 * frog.joint1)), 0, 0, frog.point_leg_move[21 * 3 * ii + i * 3], frog.point_leg_move[21 * 3 * ii + i * 3 + 1], frog.point_leg_move[21 * 3 * ii + i * 3 + 2]);
			frog.point_leg_move[21 * 3 * ii + i * 3] += frog.point_leg[4 * 3];
			frog.point_leg_move[21 * 3 * ii + i * 3 + 1] += frog.point_leg[4 * 3 + 1];
			frog.point_leg_move[21 * 3 * ii + i * 3 + 2] += frog.point_leg[4 * 3 + 2];
		}
	}
	for (int i = 3; i < (21); i++) {
		for (int ii = 0; ii <= 1; ii++) {
			make_rotate(frog.point_leg_move[(i + 21 * ii) * 3] - frog.point_leg[0], frog.point_leg_move[(i + 21 * ii) * 3 + 1] - frog.point_leg[1], frog.point_leg_move[(i + 21 * ii) * 3 + 2] - frog.point_leg[2], -PAI / 1 * pow(1.1, -(frog.joint1 * frog.joint1)), 0, 0, frog.point_leg_move[(i + 21 * ii) * 3], frog.point_leg_move[(i + 21 * ii) * 3 + 1], frog.point_leg_move[(i + 21 * ii) * 3 + 2]);
			frog.point_leg_move[(i + 21 * ii) * 3] += frog.point_leg[0];
			frog.point_leg_move[(i + 21 * ii) * 3 + 1] += frog.point_leg[1];
			frog.point_leg_move[(i + 21 * ii) * 3 + 2] += frog.point_leg[2];
		}
	}
	for (int i = 0; i < (21) * 2; i++) {
		make_rotate(frog.point_leg_move[i * 3], frog.point_leg_move[i * 3 + 1], frog.point_leg_move[i * 3 + 2], 0.25 * PAI * pow(1.1, -(frog.joint1 * frog.joint1)), 0, 0, frog.point_leg_move[i * 3], frog.point_leg_move[i * 3 + 1], frog.point_leg_move[i * 3 + 2]);
		make_rotate(frog.point_leg_move[i * 3], frog.point_leg_move[i * 3 + 1], frog.point_leg_move[i * 3 + 2], frog.rotate[0], frog.rotate[1], frog.rotate[2], frog.point_leg_move[i * 3], frog.point_leg_move[i * 3 + 1], frog.point_leg_move[i * 3 + 2]);
		//make_3d_2d(frog.point_leg_move[i * 3] * frog.scale[0] + frog.center[0], -frog.point_leg_move[i * 3 + 1] * frog.scale[1] + frog.center[1], frog.point_leg_move[i * 3 + 2] * frog.scale[2] + frog.center[2], frog.draw_leg[i * 2], frog.draw_leg[i * 2 + 1]);
		//DrawCircle(frog.draw_leg[i * 2], frog.draw_leg[i * 2 + 1], 1, RGB(0, 0, 255), TRUE);
		//SetFontSize(10);
		//DrawFormatString(frog.draw_leg[i * 2], frog.draw_leg[i * 2 + 1], RGB(255, 0, 0), "%d", i);
	}


	for (int i = 0; i < 38 * 2; i++) {
		int a = frog.surface_leg[i * 3];
		int b = frog.surface_leg[i * 3 + 1];
		int c = frog.surface_leg[i * 3 + 2];
		z_sort.draw_mode[z_sort.count] = 0;
		z_sort.x[z_sort.count][0] = frog.point_leg_move[a * 3] * frog.scale[0] + frog.center[0];
		z_sort.y[z_sort.count][0] = -frog.point_leg_move[a * 3 + 1] * frog.scale[1] + frog.center[1];
		z_sort.z[z_sort.count][0] = frog.point_leg_move[a * 3 + 2] * frog.scale[2] + frog.center[2];
		z_sort.x[z_sort.count][1] = frog.point_leg_move[b * 3] * frog.scale[0] + frog.center[0];
		z_sort.y[z_sort.count][1] = -frog.point_leg_move[b * 3 + 1] * frog.scale[1] + frog.center[1];
		z_sort.z[z_sort.count][1] = frog.point_leg_move[b * 3 + 2] * frog.scale[2] + frog.center[2];
		z_sort.x[z_sort.count][2] = frog.point_leg_move[c * 3] * frog.scale[0] + frog.center[0];
		z_sort.y[z_sort.count][2] = -frog.point_leg_move[c * 3 + 1] * frog.scale[1] + frog.center[1];
		z_sort.z[z_sort.count][2] = frog.point_leg_move[c * 3 + 2] * frog.scale[2] + frog.center[2];
		double d = shade(z_sort.x[z_sort.count][0], z_sort.y[z_sort.count][0], z_sort.z[z_sort.count][0], z_sort.x[z_sort.count][1], z_sort.y[z_sort.count][1], z_sort.z[z_sort.count][1], z_sort.x[z_sort.count][2], z_sort.y[z_sort.count][2], z_sort.z[z_sort.count][2]);
		z_sort.texture[z_sort.count] = RGB(100 * (d)+50 * (1 - d), 50 + 200 * d, 50 + 100 * d);
		if (frog.clash) {
			z_sort.texture[z_sort.count] = RGB(100 * (d)+50 * (1 - d), 50 + 200 * d, 200 + 50 * d);
		}
		z_sort.count++;
	}

	//frog arm

	for (int i = 0; i < 22 * 2; i++) {
		frog.point_arm_move[i * 3] = frog.point_arm[i * 3];
		frog.point_arm_move[i * 3 + 1] = frog.point_arm[i * 3 + 1];
		frog.point_arm_move[i * 3 + 2] = frog.point_arm[i * 3 + 2];
	}
	for (int i = 7; i < 22; i++) {
		for (int ii = 0; ii < 2; ii++) {
			make_rotate(frog.point_arm_move[22 * 3 * ii + i * 3] - frog.point_arm[(6 * (1 - ii) + 28 * ii) * 3], frog.point_arm_move[22 * 3 * ii + i * 3 + 1] - frog.point_arm[(6 * (1 - ii) + 28 * ii) * 3 + 1], frog.point_arm_move[22 * 3 * ii + i * 3 + 2] - frog.point_arm[(6 * (1 - ii) + 28 * ii) * 3 + 2], 0, 0, (1 - 2 * ii) * PAI * 0.5 * pow(1.1, -(frog.joint1 * frog.joint1)), frog.point_arm_move[22 * 3 * ii + i * 3], frog.point_arm_move[22 * 3 * ii + i * 3 + 1], frog.point_arm_move[22 * 3 * ii + i * 3 + 2]);
			frog.point_arm_move[22 * 3 * ii + i * 3] += frog.point_arm[(6 * (1 - ii) + 28 * ii) * 3];
			frog.point_arm_move[22 * 3 * ii + i * 3 + 1] += frog.point_arm[(6 * (1 - ii) + 28 * ii) * 3 + 1];
			frog.point_arm_move[22 * 3 * ii + i * 3 + 2] += frog.point_arm[(6 * (1 - ii) + 28 * ii) * 3 + 2];
		}
	}
	for (int i = 7; i < 22; i++) {
		for (int ii = 0; ii < 2; ii++) {
			make_rotate(frog.point_arm_move[22 * 3 * ii + i * 3] - frog.point_arm[6 * 3], frog.point_arm_move[22 * 3 * ii + i * 3 + 1] - frog.point_arm[6 * 3 + 1], frog.point_arm_move[22 * 3 * ii + i * 3 + 2] - frog.point_arm[6 * 3 + 2], PAI * 0.8 * pow(1.1, -(frog.joint1 * frog.joint1)), 0, 0, frog.point_arm_move[22 * 3 * ii + i * 3], frog.point_arm_move[22 * 3 * ii + i * 3 + 1], frog.point_arm_move[22 * 3 * ii + i * 3 + 2]);
			frog.point_arm_move[22 * 3 * ii + i * 3] += frog.point_arm[6 * 3];
			frog.point_arm_move[22 * 3 * ii + i * 3 + 1] += frog.point_arm[6 * 3 + 1];
			frog.point_arm_move[22 * 3 * ii + i * 3 + 2] += frog.point_arm[6 * 3 + 2];
		}
	}
	for (int i = 3; i < 22; i++) {
		for (int ii = 0; ii < 2; ii++) {
			make_rotate(frog.point_arm_move[22 * 3 * ii + i * 3] - frog.point_arm[(1 * (1 - ii) + 23 * ii) * 3], frog.point_arm_move[22 * 3 * ii + i * 3 + 1] - frog.point_arm[(1 * (1 - ii) + 23 * ii) * 3 + 1], frog.point_arm_move[22 * 3 * ii + i * 3 + 2] - frog.point_arm[(1 * (1 - ii) + 23 * ii) * 3 + 2], 0, (1 - 2 * ii) * PAI * 0.25 * pow(1.1, -(frog.joint1 * frog.joint1)), 0, frog.point_arm_move[22 * 3 * ii + i * 3], frog.point_arm_move[22 * 3 * ii + i * 3 + 1], frog.point_arm_move[22 * 3 * ii + i * 3 + 2]);
			frog.point_arm_move[22 * 3 * ii + i * 3] += frog.point_arm[(1 * (1 - ii) + 23 * ii) * 3];
			frog.point_arm_move[22 * 3 * ii + i * 3 + 1] += frog.point_arm[(1 * (1 - ii) + 23 * ii) * 3 + 1];
			frog.point_arm_move[22 * 3 * ii + i * 3 + 2] += frog.point_arm[(1 * (1 - ii) + 23 * ii) * 3 + 2];
		}
	}
	for (int i = 0; i < (22) * 2; i++) {
		make_rotate(frog.point_arm_move[i * 3], frog.point_arm_move[i * 3 + 1], frog.point_arm_move[i * 3 + 2], 0.25 * PAI * pow(1.1, -(frog.joint1 * frog.joint1)), 0, 0, frog.point_arm_move[i * 3], frog.point_arm_move[i * 3 + 1], frog.point_arm_move[i * 3 + 2]);
		make_rotate(frog.point_arm_move[i * 3], frog.point_arm_move[i * 3 + 1], frog.point_arm_move[i * 3 + 2], frog.rotate[0], frog.rotate[1], frog.rotate[2], frog.point_arm_move[i * 3], frog.point_arm_move[i * 3 + 1], frog.point_arm_move[i * 3 + 2]);
		//make_3d_2d(frog.point_arm_move[i * 3] * frog.scale[0] + frog.center[0], -frog.point_arm_move[i * 3 + 1] * frog.scale[1] + frog.center[1], frog.point_arm_move[i * 3 + 2] * frog.scale[2] + frog.center[2], frog.draw_arm[i * 2], frog.draw_arm[i * 2 + 1]);
		//DrawCircle(frog.draw_arm[i * 2], frog.draw_arm[i * 2 + 1], 1, RGB(0, 0, 255), TRUE);
		//SetFontSize(10);
		//DrawFormatString(frog.draw_arm[i * 2], frog.draw_arm[i * 2 + 1], RGB(255, 0, 0), "%d", i);
	}
	for (int i = 0; i < 39 * 2; i++) {
		int a = frog.surface_arm[i * 3];
		int b = frog.surface_arm[i * 3 + 1];
		int c = frog.surface_arm[i * 3 + 2];
		z_sort.draw_mode[z_sort.count] = 0;
		z_sort.x[z_sort.count][0] = frog.point_arm_move[a * 3] * frog.scale[0] + frog.center[0];
		z_sort.y[z_sort.count][0] = -frog.point_arm_move[a * 3 + 1] * frog.scale[1] + frog.center[1];
		z_sort.z[z_sort.count][0] = frog.point_arm_move[a * 3 + 2] * frog.scale[2] + frog.center[2];
		z_sort.x[z_sort.count][1] = frog.point_arm_move[b * 3] * frog.scale[0] + frog.center[0];
		z_sort.y[z_sort.count][1] = -frog.point_arm_move[b * 3 + 1] * frog.scale[1] + frog.center[1];
		z_sort.z[z_sort.count][1] = frog.point_arm_move[b * 3 + 2] * frog.scale[2] + frog.center[2];
		z_sort.x[z_sort.count][2] = frog.point_arm_move[c * 3] * frog.scale[0] + frog.center[0];
		z_sort.y[z_sort.count][2] = -frog.point_arm_move[c * 3 + 1] * frog.scale[1] + frog.center[1];
		z_sort.z[z_sort.count][2] = frog.point_arm_move[c * 3 + 2] * frog.scale[2] + frog.center[2];
		double d = shade(z_sort.x[z_sort.count][0], z_sort.y[z_sort.count][0], z_sort.z[z_sort.count][0], z_sort.x[z_sort.count][1], z_sort.y[z_sort.count][1], z_sort.z[z_sort.count][1], z_sort.x[z_sort.count][2], z_sort.y[z_sort.count][2], z_sort.z[z_sort.count][2]);
		z_sort.texture[z_sort.count] = RGB(100 * (d)+50 * (1 - d), 50 + 200 * d, 50 + 100 * d);
		if (frog.clash) {
			z_sort.texture[z_sort.count] = RGB(100 * (d)+50 * (1 - d), 50 + 200 * d, 200 + 50 * d);
		}
		z_sort.count++;
	}
	//frog_bella
	//if (frog.prey[0] || frog.prey[1] || frog.prey[2]) {
	if (frog.prey_chk) {
		//if (butterfly[frog.prey_catched].cz < frog.center[2]) { frog.prey_chk = 0; }
		for (int i = 0; i < 3; i++) {
			make_rotate(frog.point_bella[i * 3], frog.point_bella[i * 3 + 1], frog.point_bella[i * 3 + 2], 0.25 * PAI * pow(1.1, -(frog.joint1 * frog.joint1)), 0, 0, frog.point_bella_move[i * 3], frog.point_bella_move[i * 3 + 1], frog.point_bella_move[i * 3 + 2]);
			make_rotate(frog.point_bella_move[i * 3], frog.point_bella_move[i * 3 + 1], frog.point_bella_move[i * 3 + 2], frog.rotate[0], frog.rotate[1], frog.rotate[2], frog.point_bella_move[i * 3], frog.point_bella_move[i * 3 + 1], frog.point_bella_move[i * 3 + 2]);
		}

		frog.point_bella_move[6] = frog.prey[0] * sin(frog.bella_length) + (frog.point_bella_move[6] * frog.scale[0] + frog.center[0]) * (1 - sin(frog.bella_length));
		frog.point_bella_move[7] = frog.prey[1] * sin(frog.bella_length) + (frog.point_bella_move[7] * frog.scale[1] + frog.center[1]) * (1 - sin(frog.bella_length));
		frog.point_bella_move[8] = frog.prey[2] * sin(frog.bella_length) + (frog.point_bella_move[8] * frog.scale[2] + frog.center[2]) * (1 - sin(frog.bella_length));
		for (int i = 0; i < 1; i++) {
			z_sort.draw_mode[z_sort.count] = 6;
			for (int ii = 0; ii < 2; ii++) {
				z_sort.x[z_sort.count][ii] = frog.point_bella_move[ii * 3] * frog.scale[0] + frog.center[0];
				z_sort.y[z_sort.count][ii] = -frog.point_bella_move[ii * 3 + 1] * frog.scale[1] + frog.center[1];
				z_sort.z[z_sort.count][ii] = frog.point_bella_move[ii * 3 + 2] * frog.scale[2] + frog.center[2];
			}
			z_sort.x[z_sort.count][2] = frog.point_bella_move[6];
			z_sort.y[z_sort.count][2] = frog.point_bella_move[7];
			z_sort.z[z_sort.count][2] = frog.point_bella_move[8];
			z_sort.texture[z_sort.count] = RGB(100, 100, 255);
			z_sort.count++;
		}
	}




	//frog body

	for (int i = 0; i < FROG_POINT; i++) {
		make_rotate(frog.point[i * 3], frog.point[i * 3 + 1], frog.point[i * 3 + 2], 0.25 * PAI * pow(1.1, -(frog.joint1 * frog.joint1)), 0, 0, frog.point_move[i * 3], frog.point_move[i * 3 + 1], frog.point_move[i * 3 + 2]);
		make_rotate(frog.point_move[i * 3], frog.point_move[i * 3 + 1], frog.point_move[i * 3 + 2], frog.rotate[0], frog.rotate[1], frog.rotate[2], frog.point_move[i * 3], frog.point_move[i * 3 + 1], frog.point_move[i * 3 + 2]);
		//make_3d_2d(frog.point_move[i * 3] * frog.scale[0] + frog.center[0], -frog.point_move[i * 3 + 1] * frog.scale[1] + frog.center[1], frog.point_move[i * 3 + 2] * frog.scale[2] + frog.center[2], frog.draw[i * 2], frog.draw[i * 2 + 1]);
		//DrawCircle(frog.draw[i * 2], frog.draw[i * 2 + 1], 1, RGB(0,0,0), TRUE);
		//SetFontSize(10);
		//DrawFormatString(frog.draw[i * 2], frog.draw[i * 2 + 1], RGB(0, 0, 0), "%d", i);
	}

	for (int i = 0; i < 232; i++) {
		int a = frog.surface[i * 3];
		int b = frog.surface[i * 3 + 1];
		int c = frog.surface[i * 3 + 2];
		z_sort.draw_mode[z_sort.count] = 0;
		z_sort.x[z_sort.count][0] = frog.point_move[a * 3] * frog.scale[0] + frog.center[0];
		z_sort.y[z_sort.count][0] = -frog.point_move[a * 3 + 1] * frog.scale[1] + frog.center[1];
		z_sort.z[z_sort.count][0] = frog.point_move[a * 3 + 2] * frog.scale[2] + frog.center[2];
		z_sort.x[z_sort.count][1] = frog.point_move[b * 3] * frog.scale[0] + frog.center[0];
		z_sort.y[z_sort.count][1] = -frog.point_move[b * 3 + 1] * frog.scale[1] + frog.center[1];
		z_sort.z[z_sort.count][1] = frog.point_move[b * 3 + 2] * frog.scale[2] + frog.center[2];
		z_sort.x[z_sort.count][2] = frog.point_move[c * 3] * frog.scale[0] + frog.center[0];
		z_sort.y[z_sort.count][2] = -frog.point_move[c * 3 + 1] * frog.scale[1] + frog.center[1];
		z_sort.z[z_sort.count][2] = frog.point_move[c * 3 + 2] * frog.scale[2] + frog.center[2];
		double d = shade(z_sort.x[z_sort.count][0], z_sort.y[z_sort.count][0], z_sort.z[z_sort.count][0], z_sort.x[z_sort.count][1], z_sort.y[z_sort.count][1], z_sort.z[z_sort.count][1], z_sort.x[z_sort.count][2], z_sort.y[z_sort.count][2], z_sort.z[z_sort.count][2]);
		z_sort.texture[z_sort.count] = RGB(100 * (d)+50 * (1 - d), 50 + 200 * d, 50 + 100 * d);
		if (frog.clash) {
			z_sort.texture[z_sort.count] = RGB(100 * (d)+50 * (1 - d), 50 + 200 * d, 200 + 50 * d);
		}
		z_sort.count++;
		//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		//if (check_surface(frog.point_move[a * 3] * frog.scale[0] + frog.center[0], -frog.point_move[a * 3 + 1] * frog.scale[1] + frog.center[1], frog.point_move[a * 3 + 2] * frog.scale[2] + frog.center[2], frog.point_move[b * 3] * frog.scale[0] + frog.center[0], -frog.point_move[b * 3 + 1] * frog.scale[1] + frog.center[1], frog.point_move[b * 3 + 2] * frog.scale[2] + frog.center[2], frog.point_move[c * 3] * frog.scale[0] + frog.center[0], -frog.point_move[c * 3 + 1] * frog.scale[1] + frog.center[1], frog.point_move[c * 3 + 2] * frog.scale[2] + frog.center[2])) {
			//DrawTriangle(frog.draw[a * 2], frog.draw[a * 2 + 1], frog.draw[b * 2], frog.draw[b * 2 + 1], frog.draw[c * 2], frog.draw[c * 2 + 1], RGB(100, 255, 100), TRUE);
		//}
	}



	for (int i = 0; i < z_sort.count; i++) {
		if (check_surface(z_sort.x[i][0], z_sort.y[i][0], z_sort.z[i][0], z_sort.x[i][1], z_sort.y[i][1], z_sort.z[i][1], z_sort.x[i][2], z_sort.y[i][2], z_sort.z[i][2]) || z_sort.draw_mode[i] == 5 || z_sort.draw_mode[i] == 6) {
			z_sort.distance[i] = sqrt((z_sort.x[i][0] + z_sort.x[i][1] + z_sort.x[i][2] - ((me.x - WIDTH / 2) * 5 + screen.x) * 3) * (z_sort.x[i][0] + z_sort.x[i][1] + z_sort.x[i][2] - ((me.x - WIDTH / 2) * 5 + screen.x) * 3) / 100000) +
				sqrt((z_sort.y[i][0] + z_sort.y[i][1] + z_sort.y[i][2] - ((me.y - HEIGHT / 2) * 5 - screen.y) * 3) * (z_sort.y[i][0] + z_sort.y[i][1] + z_sort.y[i][2] - ((me.y - HEIGHT / 2) * 5 - screen.y) * 3) / 100000) +
				sqrt((z_sort.z[i][0] + z_sort.z[i][1] + z_sort.z[i][2]) * (z_sort.z[i][0] + z_sort.z[i][1] + z_sort.z[i][2]) / 1000);
			z_sort.check[i] = 1;
		}
		else {
			z_sort.distance[i] = 0;
			z_sort.check[i] = 0;
		}
	}
	for (int i = 0; i < z_sort.count; i++) {
		z_sort.number[i] = i;
	}
	/*
	for (int i = 0; i < z_sort.count-1; i++) {
		int j=i;
		for (int ii =i+1 ; ii < z_sort.count; ii++) {
			if (z_sort.distance[j] < z_sort.distance[ii]) { j = ii;}
		}
		double a = z_sort.distance[i];
		z_sort.distance[i] = z_sort.distance[j];
		z_sort.distance[j] = a;
		int b = z_sort.number[i];
		z_sort.number[i] = z_sort.number[j];
		z_sort.number[j] = b;
	}
	*/
	quicksort(z_sort.distance, z_sort.number, 0, z_sort.count - 1);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	DrawGraph(sky.x, sky.y, img_sky, TRUE);
	DrawGraph(2400 + sky.x, sky.y, img_sky, TRUE);
	for (int i = 0; i < CLOUD; i++) {
		DrawGraph(cloud[i].x, cloud[i].y, cloud[i].texture, TRUE);
	}
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);



	for (int i = 0; i < z_sort.count; i++) {
		int a = z_sort.number[i];
		if (z_sort.check[a]) {
			double x1, y1;
			double x2, y2;
			double x3, y3;
			make_3d_2d(z_sort.x[a][0], z_sort.y[a][0], z_sort.z[a][0], x1, y1);
			make_3d_2d(z_sort.x[a][1], z_sort.y[a][1], z_sort.z[a][1], x2, y2);
			make_3d_2d(z_sort.x[a][2], z_sort.y[a][2], z_sort.z[a][2], x3, y3);
			if (z_sort.z[a][0] < -DEPTH * 2 / 3) {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * ((1 + (z_sort.z[a][0] + DEPTH * 2 / 3) / (DEPTH * 1 / 3))));
			}
			else {
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
			}
			if (z_sort.draw_mode[a] == 0) {//
				DrawTriangle(x1, y1, x2, y2, x3, y3, z_sort.texture[a], TRUE);
			}
			if (z_sort.draw_mode[a] == 1) {
				double x4, y4;
				make_3d_2d(z_sort.x[a][1] + z_sort.x[a][2] - z_sort.x[a][0], z_sort.y[a][1] + z_sort.y[a][2] - z_sort.y[a][0], z_sort.z[a][1] + z_sort.z[a][2] - z_sort.z[a][0], x4, y4);
				//////DrawModiGraph(x3, y3, x2 +x3 - x1, y2 + y3 -y1, x2,y2, x1, y1, z_sort.texture[a], TRUE);
				DrawModiGraph(x3, y3, x4, y4, x2, y2, x1, y1, z_sort.texture[a], TRUE);
			}
			if (z_sort.draw_mode[a] == 2) {
				double x4, y4;
				make_3d_2d(z_sort.x[a][0] + z_sort.x[a][2] - z_sort.x[a][1], z_sort.y[a][0] + z_sort.y[a][2] - z_sort.y[a][1], z_sort.z[a][0] + z_sort.z[a][2] - z_sort.z[a][1], x4, y4);
				//////DrawModiGraph(x3, y3, x2, y2 , x1, y1, x1+x3-x2, y1+y3-y2, z_sort.texture[a], TRUE);
				DrawModiGraph(x3, y3, x2, y2, x1, y1, x4, y4, z_sort.texture[a], TRUE);
			}

			if (z_sort.draw_mode[a] == 3) {//effect
				SetDrawBlendMode(DX_BLENDMODE_ALPHA, 6);
				DrawBox(0, 0, 800, 600, RGB(255, 255, 255), TRUE);
			}
			if (z_sort.draw_mode[a] == 4) {//effect
				SetDrawBlendMode(DX_BLENDMODE_ADD, 1.5);
				DrawBox(0, 0, 800, 600, RGB(255, 255, 255), TRUE);
			}

			if (z_sort.draw_mode[a] == 5) {//butterfly
				if (z_sort.z[a][0] > -DEPTH / 8)SetDrawBlendMode(DX_BLENDMODE_ALPHA, -255 * z_sort.z[a][0] / (DEPTH / 8));
				double x4, y4;
				make_3d_2d(z_sort.x[a][0] + z_sort.x[a][2] - z_sort.x[a][1], z_sort.y[a][0] + z_sort.y[a][2] - z_sort.y[a][1], z_sort.z[a][0] + z_sort.z[a][2] - z_sort.z[a][1], x4, y4);
				DrawModiGraph(x4, y4, x3, y3, x2, y2, x1, y1, z_sort.texture[a], TRUE);
				//DrawModiGraph(x3 + x1 - x2, y3 + x1 - x2, x3, y3, x2, y2, x1, y1, z_sort.texture[a], TRUE);
			}
			if (z_sort.draw_mode[a] == 6) {//
				DrawTriangle(x1, y1, x2, y2, x3, y3, z_sort.texture[a], TRUE);
			}
		}
	}
	if (start.menu == 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		SetFontSize(50);
		DrawFormatString(600, 0, RGB(255, 255, 255), "%d", score);
	}
	if (start.menu == 1) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		DrawRotaGraph(300, 200, 0.8, 0, img_title, TRUE);
		DrawRotaGraph(620, 400, 1 + 0.1 * (start.select == 0), 0, img_start[0], TRUE);
		DrawRotaGraph(620, 520, 1 + 0.1 * (start.select == 1), 0, img_start[1], TRUE);
		SetFontSize(30);
		DrawFormatString(30, 500, RGB(255, 255, 255), " ← →  ：いどう");
		DrawFormatString(30, 550, RGB(255, 255, 255), "スペース：ジャンプ");
		if (start.progress < 1) {
			start.progress += 0.1;
			SetDrawBlendMode(DX_BLENDMODE_ADD, 255 - 255 * start.progress);
			DrawBox(0, 0, 800, 600, RGB(255, 255, 255), TRUE);
		}


		//DrawGraph(500,300, img_start[0], TRUE);
		//DrawGraph(500, 420, img_start[1], TRUE);
		/*
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		DrawBox(50, 50, WIDTH-50, HEIGHT-50,RGB(255,255,255),TRUE);
		SetFontSize(25);
		DrawFormatString(60,160, RGB(0, 0, 0), "シミュレーションです。見てお楽しみください・");
		DrawFormatString(60, 240, RGB(0, 0, 0), "　移動　:　 ← →");
		DrawFormatString(60, 280, RGB(0, 0, 0), "ジャンプ: スペース");
		*/
	}
	if (start.menu == 2) {
		start.count++;
		if (start.progress < 1) {
			start.progress += 0.1;
		}
		else {
			start.progress = 1;
		}
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		SetFontSize(50 + 50 * start.progress);
		DrawFormatString(600 - 300 * start.progress, HEIGHT / 2 * start.progress - 50, RGB(255, 255, 255), "%d", score); //fpsを表示
	}
	//SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	//DrawModiGraph( 0 , 0 , 440 , 0 , 440,440 , 0 , 440 , img_grass, TRUE ) ;


	if (start.menu == 3) {
		start.progress += 0.05;
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
		SetFontSize(100);
		DrawFormatString(600 - 300, HEIGHT / 2 - 50, RGB(255, 255, 255), "%d", score); //fpsを表示
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255 * start.progress);
		// SetDrawBlendMode(DX_BLENDMODE_ADD, 200 * start.progress);
		DrawBox(0, 0, 800, 600, RGB(255, 255, 255), TRUE);
		if (start.progress >= 1) {
			initialize();
		}
	}

}



///////////////////////////////////////////////////////////////////////////////////////////
void make_rotate(double x, double y, double z, double rx, double ry, double rz, double& xx, double& yy, double& zz) {

	double x2, y2, z2;
	//x軸
	x2 = x;
	y2 = y * cos(rx) - z * sin(rx);
	z2 = y * sin(rx) + z * cos(rx);

	//y軸
	x = x2 * cos(ry) + z2 * sin(ry);
	y = y2;
	z = -x2 * sin(ry) + z2 * cos(ry);
	//z軸
	xx = x * cos(rz) - y * sin(rz);
	yy = x * sin(rz) + y * cos(rz);
	zz = z;

	/*
	double x1, y1, z1;
	double x2, y2, z2;
	double x3, y3, z3;
	x1 = x;
	y1 = y * cos(rx) - z * sin(rx);
	z1 = y * sin(rx) + z * cos(rx);
	x = x * cos(ry) + z * sin(ry);
	y = y;
	z = -x * sin(ry) + z * cos(ry);
	*/
}

void make_3d_2d(double x, double y, double z, double& xx, double& yy) {
	y += z * z / 250000;
	x -= (me.x - WIDTH / 2) * 5;
	y -= (me.y - HEIGHT / 2) * 5;
	xx = WIDTH / 2 + (x - screen.x) / (1 + (z + screen.z) / screen.d);
	yy = HEIGHT / 2 + (y + screen.y) / (1 + (z + screen.z) / screen.d);
}
int check_surface(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
	x1 -= (me.x - WIDTH / 2) * 5 + screen.x;
	y1 -= (me.y - HEIGHT / 2) * 5 - screen.y;
	z1 += screen.z;
	x2 -= (me.x - WIDTH / 2) * 5 + screen.x;
	y2 -= (me.y - HEIGHT / 2) * 5 - screen.y;
	z2 += screen.z;
	x3 -= (me.x - WIDTH / 2) * 5 + screen.x;
	y3 -= (me.y - HEIGHT / 2) * 5 - screen.y;
	z3 += screen.z;
	z1 *= -1;
	z2 *= -1;
	z3 *= -1;
	double vx = (y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1);
	double vy = (z2 - z1) * (x3 - x1) - (x2 - x1) * (z3 - z1);
	double vz = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	double cx = -x1;
	double cy = -y1;
	double cz = -z1 + screen.d;
	if (0 <= vx * cx + vy * cy + vz * cz) {
		return 1;
	}
	else {
		return 0;
	}
}

double shade(double x1, double y1, double z1, double x2, double y2, double z2, double x3, double y3, double z3) {
	x1 -= (me.x - WIDTH / 2) * 5 + screen.x;
	y1 -= (me.y - HEIGHT / 2) * 5 - screen.y;
	z1 += screen.z;
	x2 -= (me.x - WIDTH / 2) * 5 + screen.x;
	y2 -= (me.y - HEIGHT / 2) * 5 - screen.y;
	z2 += screen.z;
	x3 -= (me.x - WIDTH / 2) * 5 + screen.x;
	y3 -= (me.y - HEIGHT / 2) * 5 - screen.y;
	z3 += screen.z;
	z1 *= -1;
	z2 *= -1;
	z3 *= -1;
	double vx = (y2 - y1) * (z3 - z1) - (z2 - z1) * (y3 - y1);
	double vy = (z2 - z1) * (x3 - x1) - (x2 - x1) * (z3 - z1);
	double vz = (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1);
	return ((vx * light.x + vy * light.y + vz * light.z) / (sqrt(vx * vx + vy * vy + vz * vz) * sqrt(light.x * light.x + light.y * light.y + light.z * light.z)) + 1) / 2;
}



//クイックソート
/* x, y, z の中間値を返す */
double med3(double x, double y, double z) {
	if (x < y) {
		if (y < z) return y; else if (z < x) return x; else return z;
	}
	else {
		if (z < y) return y; else if (x < z) return x; else return z;
	}
}

/*
 * a     : ソートする配列
 * left  : ソートするデータの開始位置
 * right : ソートするデータの終了位置
 */
void quicksort(double a[], int b[], int left, int right) {
	if (left < right) {
		int i = left, j = right;
		double tmp, pivot = med3(a[i], a[i + (j - i) / 2], a[j]); /* (i+j)/2 ではオーバーフローしてしまう */
		while (1) { /* a[] を pivot 以上と以下の集まりに分割する */
			while (a[i] > pivot) i++; /* a[i] >= pivot となる位置を検索 */
			while (pivot > a[j]) j--; /* a[j] <= pivot となる位置を検索 */
			if (i >= j) break;
			tmp = a[i]; a[i] = a[j]; a[j] = tmp; /* a[i], a[j] を交換 */
			tmp = b[i]; b[i] = b[j]; b[j] = tmp;
			i++; j--;
		}
		quicksort(a, b, left, i - 1);  /* 分割した左を再帰的にソート */
		quicksort(a, b, j + 1, right); /* 分割した右を再帰的にソート */
	}
}