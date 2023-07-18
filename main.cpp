#include  "DxLib.h" 
#include"global.h"
#include "function.h"
#include"define.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(WIDTH, HEIGHT, 32);//横、縦、カラービットの順
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
			FpsTime[0] = GetNowCount();               //1周目の時間取得
		if (FpsTime_i == 49) {
			FpsTime[1] = GetNowCount();               //50周目の時間取得
			Fps = 1000.0f / ((FpsTime[1] - FpsTime[0]) / 50.0f);//測定した値からfpsを計算
			FpsTime_i = 0;//カウントを初期化
		}
		else
			FpsTime_i++;//現在何周目かカウント
		if (Fps != 0)
			//DrawFormatString(0,0, RGB(0,0,0), "FPS %.1f", Fps); //fpsを表示
		////


			ScreenFlip();
	}
	DxLib_End();          //DXライブラリを終了する 

	return 0;
}