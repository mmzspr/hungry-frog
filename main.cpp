#include  "DxLib.h" 
#include"global.h"
#include "function.h"
#include"define.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(WIDTH, HEIGHT, 32);//���A�c�A�J���[�r�b�g�̏�
	SetBackgroundColor(255, 255, 255);
	SetMainWindowText("Frog");
	if (DxLib_Init() == -1) {
		return -1;
	}
	ChangeFontType(DX_FONTTYPE_ANTIALIASING_8X8);
	sound_clash = LoadSoundMem("music/clash.mp3");
	ChangeVolumeSoundMem(255 * 0.6, sound_clash);
	sound_eat = LoadSoundMem("music/eat.mp3");
	ChangeVolumeSoundMem(255 * 0.3, sound_eat);
	sound_grass = LoadSoundMem("music/grass.mp3");
	load_img();
	initialize();
	PlaySound("music/music.mp3", DX_PLAYTYPE_LOOP);

	////  FPS standard-45fps
	int counter = 0, FpsTime[2] = { 0, }, FpsTime_i = 0;
	// int color_white;
	double Fps = 0.0;
	////
	while (ProcessMessage() == 0) {

		ClearDrawScreen();

		move();
		clash();
		draw();


		////    FPS
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 128);
		SetFontSize(30);
		if (FpsTime_i == 0)
			FpsTime[0] = GetNowCount();               //1���ڂ̎��Ԏ擾
		if (FpsTime_i == 49) {
			FpsTime[1] = GetNowCount();               //50���ڂ̎��Ԏ擾
			Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//���肵���l����fps���v�Z
			FpsTime_i = 0;//�J�E���g��������
		}
		else
			FpsTime_i++;//���݉����ڂ��J�E���g
		if (Fps != 0)
			//DrawFormatString(0,0, RGB(0,0,0), "FPS %.1f", Fps); //fps��\��
		////


			ScreenFlip();
	}
	DxLib_End();          //DX���C�u�������I������ 

	return 0;
}