#include<math.h>
#include"DxLib.h"
#include"extern.h"
#include "function.h"

void clash(void) {
	if (frog.clash == 0) {
		if (start.menu == 0) {
			for (int i = 0; i < TREE; i++) {
				if ((frog.center[0] - tree[i].cx) * (frog.center[0] - tree[i].cx) + (frog.center[2] - tree[i].cz) * (frog.center[2] - tree[i].cz) < 1000000) {
					frog.clash = 1;
				}
			}
			if (frog.clash == 1) {
				PlaySoundMem(sound_clash, DX_PLAYTYPE_BACK);
				me.vz = 0;
				me.vx = 0;
				start.menu = 2;
				start.progress = 0;
			}
		}
	}
	else {
		frog.scale[0] *= 0.96;
		frog.scale[1] *= 0.96;
		frog.scale[2] *= 0.96;
		frog.rotate[1] += 0.5;
	}
}